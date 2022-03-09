#include <iostream>

#include "Matrix.h"
#include "Timer.h"
#include "omp.h"
/**
 * Serial: 20000.4 ms
 *      2: 19898.1 ,s
 *      4:  2900.83 ms
 *      6:  2660.00 ms
 *      8:  2885.87 ms
 */

int main()
{
    cppmath::Matrix<double> m1(250, 250, -1.0);
    cppmath::Matrix<double> m2(250, 250, -1.0);

    uint32_t num_runs = 1'000U;
    double total_time = 0.0;

    for (uint32_t i = 0; i < num_runs; i++)
    {
        cpptiming::Timer t;
        cppmath::Matrix<double> m3 = m1 * m2;
        total_time += t.elapsed_time<cpptiming::microsecs, double>();
    }
    std::cout << "Mean time: " << total_time / num_runs << " us" << std::endl;

    return 0;
}
