#ifndef READ_INSTANCE_H
#include <iostream>
#include <vector>

class ReadInstance{
    public:
        ReadInstance(const char *pathFile);
        std::vector<std::vector<int>>*getMatrixAdj(){return &(this->matrixAdj);}
        std::vector<std::vector<int>>*getListAdj(){return &(this->listAdj);}
    private:
        std::vector < std::vector <int>> matrixAdj;
        std::vector <std::vector <int>> listAdj;
};






#endif