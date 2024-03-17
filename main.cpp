#include <iostream>
#include "ReadInstance.h"
#include "Dfs.h"
#include "Bfs.h"
#include <algorithm>
#include <math.h>



int main(int argc, char** argv){

    if(argc < 3){
        std::cout << "input format: numberInstance graph" << std::endl;
        exit(1);
    }
    ReadInstance instance(argv[2]);
    std::vector < std::vector < int >> *listAdj = instance.getListAdj();
    DFS dfs(listAdj);
    dfs.procedure(1);
    dfs.writeOutput(std::stoi(argv[1]));
    Bfs bfs(listAdj);
    bfs.procedure(1);
    bfs.writeOutput(std::stoi(argv[1]));
    std::vector < int > exce; // Excentricidade de cada vértice

    /* A maior distancia de um vértice a outro, sua excentricidade
    será dada pela altura da árvore em largura, maior valor de L*/
    exce.push_back(bfs.getHeightTree());
    double distancia_media = 0;
    std::vector < int > *nivel;
    nivel = bfs.getNivel();
    for(int j = 2; j < nivel->size(); j++){
        distancia_media += (*nivel)[j];
    }
    bfs.clear();
    

    for(int i = 2; i < listAdj->size(); i++){
        Bfs *bfs1 = new Bfs(listAdj);
        bfs1->procedure(i);
        exce.push_back(bfs1->getHeightTree());
        nivel = bfs1->getNivel();
        for(int j = i + 1; j < nivel->size(); j++){
            distancia_media += (*nivel)[j];
        }
        delete bfs1;
    }
    double n = (listAdj->size() - 1);

    
    double q = (std::tgamma(n + 1)) / ((std::tgamma(2 + 1)) * (std::tgamma(n - 2 + 1)));

    std:: cout << "Diametro e raio do grafo consecutivamente: ";
    std::cout << *std::max_element(exce.begin(), exce.end()) << " ";
    std::cout << *std::min_element(exce.begin(), exce.end()) << std::endl;
    std::cout << "A distancia media vale: " << distancia_media / q << std::endl;
    return 0;
}