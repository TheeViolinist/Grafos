#include "Karger.hpp"



Karger::Karger(std::vector < tEdges >  edges, int n, std::vector < std::vector < int >> *matrixAdj){
    this->edges = edges;
    this->n = n;
    this->matrixAdj = matrixAdj;
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
int Karger::findSet(int node, int enableAtRoot){
   
    int i = setDj[node];
    
    /* caso base, verifica se o pai dele é ele próprio, e retorna a raiz */ 
    if(i == node){
        return i;
    }
    /* Caso recursivo, tentamos encontrar a raiz do proximo valor na arvore
     * caso for a raiz, quando sairmos da função atualizamos o pai dos anteriores  */
    else{
        int raiz = findSet(i, 1);
        if(enableAtRoot)
          this->setDj[node] = raiz;
        return raiz;
    }
}





int Karger::setUnion(int nodeA, int nodeB){
    
    int root_a = findSet(nodeA, 1);
    int root_b = findSet(nodeB, 1);
    
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

int Karger::algorithm(){
    init();
    int root_a = 0;
    int root_b = 0;

    while(1){
        int sizeEdges = this->edges.size();
        std::random_device rd;
        std::mt19937 gen(rd());
      
        std::uniform_int_distribution<> dist(0, sizeEdges - 1); /* Retira um indice aleatorio */
        int id = dist(gen);
        tEdges *edge = &(this->edges)[id];  /* aresta aleatoria */
          
        int result_union = setUnion(edge->nodeA, edge->nodeB);
        if(result_union){
            /* Exclui a aresta selecionada aleatoriamente em O(1) */
            std::swap((this->edges)[id], (this->edges)[sizeEdges - 1]);
            this->edges.pop_back();
        }
        /* O algoritmo so termina quuando tiver apenas 2 raizes */ 
        
        int roots = 0;
        for(int i = 1; i <= n; i++){
            if(setDj[i] == i and roots == 0){
                roots++;
                root_a = i;
            }else if(setDj[i] == i and roots != 0){
                roots++;
                root_b = i;
            }
              
        }
        if(roots == 2)
            break;
    }
    
    /* Vamos dar um findSet para todo vertice e achar para qual raizes eles pertencem */
    
    std::vector < int > nodesRoot_a;
    std::vector < int > nodesRoot_b;
    
    for(int i = 1; i <= n; i++){
    
        if(findSet(i,0) == root_a){
            nodesRoot_a.push_back(i);
        }
        else{
            nodesRoot_b.push_back(i);
        }
    }
    
    int counterMinCut = 0;
    int sizeNodesA = nodesRoot_a.size();
    int sizeNodesB = nodesRoot_b.size();

    for(int i = 0; i < sizeNodesA ; i++){
      
      for(int j = 0; j < sizeNodesB; j++){
          /* Se existir essa aresta é porque está no corte minimo   */ 
          if((*this->matrixAdj)[nodesRoot_a[i]][nodesRoot_b[j]]){
              counterMinCut++;
          }
      }
    }
    
    return counterMinCut;
}






