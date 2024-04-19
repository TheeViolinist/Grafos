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
    
    int root_a = findSet(nodeA);
    int root_b = findSet(nodeB);
    
    /* Se eles estiverem na mesma arvore nao tem como unir */
    if(root_a == root_b)
        return 0;
    /* Vamos colocar a raiz de menor rank como sendo filho da raiz de maior rank */
    if(this->rank[root_a] >= this->rank[root_b]){
        this->setDj[root_b] = root_a;
        this->rank[root_a] += this->rank[root_b] + 1;
    }else{
        this->setDj[root_a] = root_b;
        this->rank[root_b] += this->rank[root_a] + 1;
    }

    return 1;
}

void Karger::algorithm(){
    init();

    while(1){
        int sizeEdges = this->edges->size();
        std::random_device rd;
        std::mt19937 gen(rd());
      
        std::uniform_int_distribution<> dist(0, sizeEdges - 1); /* Retira um indice aleatorio */
        int id = dist(gen);
        tEdges *edge = &(*this->edges)[id];  /* aresta aleatoria */
          
        int result_union = setUnion(edge->nodeA, edge->nodeB);
        if(result_union){
            /* Exclui a aresta selecionada aleatoriamente em O(1) */
            std::swap((*this->edges)[id], (*this->edges)[sizeEdges - 1]);
            this->edges->pop_back();
        }
        /* O algoritmo so termina quuando tiver apenas 2 raizes */ 
        
        int roots = 0;
        for(int i = 1; i <= n; i++){
            if(setDj[i] == i)
                roots++;
        }
        if(roots == 2)
            break;
    }

    for(int i = 0; i <= this->n; i++){
        std::cout << setDj[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i <= this->n; i++){
        std::cout << rank[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "min cut: " << this->edges->size() << "\n";
}






