#include "Timer.h"
#include <array>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>

constexpr std::uint32_t NUM_THREADS = 3;
constexpr std::uint32_t NUM_INCREMENTS = 100'000;
std::mutex mutex;
std::uint32_t global_counter = 0;

void function(const int input, int &output)
{
    output = input * 2;

    for (std::uint32_t i = 0; i < NUM_INCREMENTS; i++)
    {
        std::lock_guard<std::mutex> guard(mutex);
        ++global_counter;
    }
}

int main()
{
    std::array<std::thread, NUM_THREADS> threads;
    std::array<std::int32_t, NUM_THREADS> inputs{};
    std::array<std::int32_t, NUM_THREADS> outputs{};

    std::iota(inputs.begin(), inputs.end(), 0);
    std::fill(outputs.begin(), outputs.end(), 0);

    cpptiming::Timer timer;

    for (std::uint32_t i = 0; i < NUM_THREADS; i++)
    {
        threads[i] = std::thread(function, inputs[i], std::ref(outputs[i]));
    }

    for (std::uint32_t i = 0; i < NUM_THREADS; i++)
    {
        threads[i].join();
    }
    auto time_us = timer.elapsed_time<cpptiming::nanosecs, double>();
    std::cout << "Time in um: " << time_us << '\n';

    for (std::uint32_t i = 0; i < NUM_THREADS; i++)
    {
        std::cout << "Result[" << i << "] = " << outputs[i] << '\n';
    }


    std::cout << "Global counter = " << global_counter << '\n';

    return 0;
}
