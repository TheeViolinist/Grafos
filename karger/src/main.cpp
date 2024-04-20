#include <iostream>
#include "InstanceReader.hpp"
#include "Karger.hpp"
#include "DumbAlgorithm.hpp"

int main(int argc, char** argv){
    
    if(argc <  3 || argc > 4){
        std::cout << "Digite o caminho do grafo de entrada e o arquivo onde está o valor do corte .\n";
        exit(1);
    }
    InstanceReader instance(argv[1], argv[2]);
    instance.readInstance();
    std::vector < std::vector < int > > *matrixAdj = instance.getMatrixAdj();
    std::vector < tEdges > edges;
    int n = instance.getSize();
    int minCut = instance.getMinCut();
    /* Só precisamos pegar as arestas do triangulo superior */
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            
            if((*matrixAdj)[i][j]){
                tEdges edge(i, j);
                edges.push_back(edge);          
            }
        }  
    }
    
    int nExec = 5;
    
    while(nExec <= 20){
      
      int cMinCutFoundKarger = 0;
      int cMinCutFoundDumb = 0;
      int counter = 0;

      while(counter < 10000){
        int bestMinCutKarger = 1000000;
        int bestMinCutDumb = 1000000;

        for(int i = 0; i < nExec; i++){
          Karger *karger = new Karger(edges, n, matrixAdj);
          DumbAlgorithm* dumb = new DumbAlgorithm(n, matrixAdj);
          
          int minCutDumb = dumb->algorithm();
          int minCutKarger = karger->algorithm();
          if(minCutKarger < bestMinCutKarger){
            bestMinCutKarger = minCutKarger;
          }
          if(minCutDumb < bestMinCutDumb){
            bestMinCutDumb = minCutDumb;
          }
          delete karger;
          delete dumb;
        }
        if(bestMinCutKarger == minCut){
          cMinCutFoundKarger++;
        }
        if(bestMinCutDumb == minCut){
          cMinCutFoundDumb++;
        }
        counter++;
      }
      
      std::cout << nExec << " " << (double)((double)cMinCutFoundKarger/10000) * 100 << " " << (double)((double)cMinCutFoundDumb/10000) * 100 << "\n";
      nExec += 5;
    }
    return 0;
}

