#include <iostream>
#include "InstanceReader.hpp"
#include "Karger.hpp"

int main(int argc, char** argv){
    
    if(argc <  2 || argc > 3)
        std::cout << "Digite apenas o caminho do grafo de entrada.\n";
    
    InstanceReader instance(argv[1]);
    instance.readInstance();
    std::vector < std::vector < int > > *matrixAdj = instance.getMatrixAdj();
    std::vector < tEdges > edges;
    int n = instance.getSize();
    
    /* Só precisamos pegar as arestas do triangulo superior */
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            
            if((*matrixAdj)[i][j]){
                tEdges edge(i, j);
                edges.push_back(edge);          
            }
        }  
    }

    Karger karger(&edges, n);
    karger.algorithm();
    return 0;
}
