class Image
{
    //Constructor declared
public:
    Image();
    Image(const unsigned int &width, const unsigned int &height);

    //Destructor declared
    ~Image();

private:
    unsigned int m_width;
    unsigned int m_height;
};
