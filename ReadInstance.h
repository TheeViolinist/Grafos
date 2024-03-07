#ifndef READ_INSTANCE_H
#include <iostream>
#include <vector>

class ReadInstance{
    public:
        ReadInstance(const char *pathFile);
    private:
        std::vector < std::vector <int>> matrixAdj;
        std::vector <std::vector <int>> listAdj;
};






#endif