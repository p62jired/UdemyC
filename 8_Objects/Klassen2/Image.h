#include <vector>
using uchar = unsigned char;
using GrayscaleMatrix = std::vector<std::vector<uchar>>;


class Image
{
    //Constructor declared
public:
    Image();
    Image(const unsigned int &width, const unsigned int &height);

    //Destructor declared
    ~Image();

    void save_image(const char *file_name) const;

private:
    unsigned int m_width;
    unsigned int m_height;
    GrayscaleMatrix m_matrix;
};
