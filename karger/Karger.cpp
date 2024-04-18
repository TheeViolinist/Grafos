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


/*A função findSet é uma função recursiva que tem a intenção de retornar a raiz daquela arvore
 * Sendo assim, o caso base é quando o pai do nó eh o proprio no pai[x] = x*/
int Karger::findSet(int node){
   
    int i = setDj[node];
    
    /* caso base, verifica se o pai dele é ele próprio, e retorna a raiz */ 
    if(i == node){
        return i;
    }
    /* Caso recursivo, tentamos encontrar a raiz do proximo valor na arvore
     * caso for a raiz, quando sairmos da função atualizamos o pai dos anteriores  */
    else{
        int raiz = findSet(i);
        this->setDj[node] = raiz;
        return raiz;
    }
}


int Karger::setUnion(int nodeA, int nodeB){
    return 0;
}
void Karger::algorithm(){
    init();
    
    while(1){
      //int sizeEdges = this->edges.size();
      //std::random_device rd;
      //std::mt19937 gen(rd());
      
      //std::uniform_int_distribution<> dist(0, sizeEdges - 1); /* Retira um indice aleatorio */
      std::cout << "Digite as arestas para retirar: ";
      int i, j;
      std::cin >> i >> j;

    }
}






