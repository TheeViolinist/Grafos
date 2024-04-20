#ifndef INSTANCE_READER
#define INSTANCE_READER

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class InstanceReader{
    public:
        InstanceReader(const char* inputFileName, const char* minCutFileName);
        void readInstance();
        std::vector < std::vector < int >>* getMatrixAdj(){ return &this->matrixAdj;};
        int getSize(){return this->n;};
        int getMinCut(){return this->minCut;};
    private:
        std::vector < std::vector < int >> matrixAdj;
        int n;
        int minCut;
        std::fstream inputStream;
        std::fstream minCutStream;
}; 










#endif
