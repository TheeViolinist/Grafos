#include "Karger.hpp"




Karger::Karger(std::vector < tEdges > * edges, int n){
    this->edges = edges;
    this->n = n;
}


void Karger::init(){
    /* Inicializa os conjuntos disjuntos sendo cada vértice como raiz de si mesma */ 
    for(int i = 0; i <= n; i++){
        setDj.push_back(i);
        rank.push_back(0);
    }
}






