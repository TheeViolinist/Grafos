#ifndef INSTANCE_READER
#define INSTANCE_READER

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class InstanceReader{
    public:
        InstanceReader(const char* inputFileName);
        void readInstance();
        std::vector < std::vector < int >>* getMatrixAdj(){ return &this->matrixAdj;};
        int getSize(){return this->n;};
    private:
        std::vector < std::vector < int >> matrixAdj;
        int n;
        std::fstream inputStream;
}; 










#endif
