#include "Dfs.h"
#include <iostream>
#include <sstream>
#include <fstream>

/*  Construtor responsável por criar a estrutura básica do DFS
    A estrutura básica se baseia em dois vector de PS e PE para cada vértice*/
DFS::DFS(std::vector<std::vector<int>>*listAdj){
    this->listAdj = listAdj;
    this->n = listAdj->size();
    /* Dando n + 1, pois vamos de 1 até n*/
    PS.resize(n + 1, 0);
    PE.resize(n + 1, 0);
    v_fathers.resize(n + 1, 0);
    /* Inicializando as configurações iniciais */
    this->t = 0;
    /* Inicializando as cores das arestas todas como preto */
    std::vector < int > noColor(n + 1, 0);
    for(int i = 1; i <= n; i++){
        this->matrixColor.push_back(noColor);
    }
}

void DFS::procedure(int v){
    this->t += 1;
    PE[v] = this->t;
    std::vector < int > neighbors = listAdj->at(v);
    int sizeNeighbors = neighbors.size();
    for(int i = 0; i < sizeNeighbors; i++){
        int w = neighbors[i];
        /* Se estamos descobrindo o vizinho agora 
        logo o vértice anterior é o pai desse vizinho
        vamos marcar a aresta como azul*/
        if(PE[w] == 0){
            matrixColor[v][w] = matrixColor[w][v] = 1;
            v_fathers[w] = v;
            procedure(w);

        }
        /* Se o vértice já foi descoberto, mas ainda não saimos da sua chamada
        e ele não é filho de v, logo é uma aresta de retorno e marcamos como vermelho*/
        else{
            if(PS[w] == 0 and w != v_fathers[v]){
                matrixColor[v][w] = matrixColor[w][v] = 2;
            }
        }
    }
    this->t += 1;
    PS[v] = this->t;
}

void DFS::writeOutput(int numberInstance){
    std::stringstream outputStream;
    outputStream << "results/graph_" << numberInstance << "_dfs.gdf";
    std::fstream output(outputStream.str(), std::ios::out);
    if(!output.is_open()){
        std::cout << "Não foi possivel abrir o arquivo." << std::endl;
        std::exit(1);
    }
    output << "nodedef>name VARCHAR,label VARCHAR\n";
    for(int i = 1; i <= n; i++){
        output << i <<"," << i << "\n";

    }
    output << "edgedef>node1 VARCHAR,node2 VARCHAR,directed BOOLEAN,color VARCHAR\n";

    for(int i = 1; i <= n; i++){
        if(i == 1){
            std::
        }
        for(int j = i + 1; j <= n; j++){
            /* Essa é a cor azul */
            if(matrixColor[i][j] == 1){
                output << i << "," << j << ",false," << "'0,0,255'\n";
            }
            else if(matrixColor[i][j] == 2){
                output << i << "," << j << ",false," << "'255,0,0'\n";
            }
        }
    }
    output.close();

   
}