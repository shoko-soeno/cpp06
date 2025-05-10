#include "convertScalar.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << "<literal>" << std::endl;
        return 1;
    }
    ConvertScaler convert(argv[1]);
    return 0;
}