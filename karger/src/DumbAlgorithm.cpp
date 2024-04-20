#include "DumbAlgorithm.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>


DumbAlgorithm::DumbAlgorithm(int n, std::vector < std::vector < int >> *matrixAdj){
    this->n = n;
    this->matrixAdj = matrixAdj;
}


int DumbAlgorithm::algorithm(){
    std::vector < int > setA;
    std::vector < int > setB;

    /* O algoritmo será da seguinte forma:
  * Vamos calcular o tamanho do conjunto A aleatoriamente, restringir seu tamanho
  * para n - 1, pois o segundo conjunto tem q ter pelo menos 1 elemento, após isso o 
  * tamanho do segundo é o complementar do primeiro. Vamos calcular aleatoriamente
  * os elementos do segundo e aqueles que não estão no segundo estarão no primeiro */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dist(1, this->n - 1);
    int sizeSetA = dist(gen);
    int sizeSetB = this->n - sizeSetA;
    
    std::uniform_int_distribution<>dist1(1, this->n);
     
    int inserted = 0;
    std::vector < int > nodesInserted(this->n + 1, 0); /* Cria um vetor booleano que indica se o nó de indice i ja foi inserido em algum conjunto */
    
    /* Adiciona nós aleatoriamente no conjunto B */
    while(inserted < sizeSetB){
        int random_node = dist1(gen);
        if(!nodesInserted[random_node]){
          setB.push_back(random_node);
          nodesInserted[random_node] = 1;
          inserted++;
        }
    }
    for(int i = 1; i <= n; i++){
      /* Se for igual ao  endereço final é porque nao foi encontrado, então adicionamos no outro conjunto */
      if(!nodesInserted[i]){
          setA.push_back(i);
          nodesInserted[i] = 1;
      }
    }
    
    int minCut = 0;
    for(int i = 0; i < sizeSetA; i++){
      for(int j = 0; j < sizeSetB; j++){
          
          if((*this->matrixAdj)[setA[i]][setB[j]]){
              minCut++;
          }
      }
    }
    /*
    if(minCut == 1){
        for(int i = 0; i < sizeSetA; i++){
            std::cout << setA[i] << " ";
        }
        std::cout << "\n";
        for(int i = 0; i < sizeSetB; i++){
            std::cout << setB[i] <<" ";
        }
        std::cout << "\n";
        getchar();
     }
    */
    return minCut;

}
