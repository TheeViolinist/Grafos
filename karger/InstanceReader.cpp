#include "InstanceReader.hpp"


InstanceReader::InstanceReader(const char* inputFileName){
    this->inputStream.open(inputFileName, std::ios_base::in); 
}


/* Função realiza a leitura da instancia  */
void InstanceReader::readInstance(){
    
    std::string line;
    std::getline(inputStream, line);
    this->n = stoi(line); 
    
    /* Como vamos criar uma matriz que inicializa em 1, logo primeira linha e primeira coluna zeradas */
    std::vector < int > zeroValues(n + 1, 0);
    std::vector < int > lineValues;
    this->matrixAdj.push_back(zeroValues);

    for(int i = 1; i <= n; i++){
        
        std::getline(inputStream, line);
        std::stringstream streamLine(line);
        
        lineValues.push_back(0);
        while(std::getline(streamLine, line, ' ')){
          lineValues.push_back(stoi(line));
        }
        this->matrixAdj.push_back(lineValues);
        lineValues.clear();
    }
    

}
