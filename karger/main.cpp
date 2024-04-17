#include <iostream>
#include "InstanceReader.hpp"









int main(int argc, char** argv){
    
    if(argc <  2 || argc > 3)
        std::cout << "Digite apenas o caminho do grafo de entrada.\n";
    
    InstanceReader instance(argv[1]);
    instance.readInstance();

      return 0;
}
