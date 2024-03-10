#include "Bfs.h"
#include <iostream>
#include <sstream>
#include<fstream>

Bfs::Bfs(std::vector<std::vector<int>>* listAdj){
    this->t = 0;
    this->n = listAdj->size();
    this->listAdj = listAdj;
    this->L.resize(n, 0);
    this->nivel.resize(n, 0);
    this->fathers.resize(n, 0);
    std::vector < int > colorLine(n, 0);

    for(int i = 0; i < n; i++){
        matrixColor.push_back(colorLine);
    }
}

void Bfs::procedure(int root){
    this->fila.push_back(root); /* Coloca v no final da fila*/
    std::cout << "here" << std::endl;
    while(!fila.empty()){

        int v = this->fila.front();
        
        fila.pop_front();
        std::vector < int > neighbors = this->listAdj->at(v);
        int sizeNeighbors = neighbors.size();
        std::cout << v << std::endl;
        for(int i = 0; i < sizeNeighbors; i++){
            
            int w = neighbors[i];
            std::cout << w << std::endl;
            //getchar();
            if(L[w] == 0){
                fathers[w] = v;
                nivel[w] = nivel[v] + 1;
                this->t += 1;
                L[w] = t;
                this->fila.push_back(w);
                matrixColor[v][w] = matrixColor[w][v] = 1;
                std::cout << "oi" << std::endl;
            }
            else{
                if((nivel[w] == nivel[v])){
                    if(this->fathers[v] == this->fathers[w]){
                        matrixColor[v][w] = matrixColor[w][v] =  2;  
                    }
                    else{
                        matrixColor[v][w] = matrixColor[w][v] =  3;
                    }
                }
                else if (nivel[w] == nivel[v] + 1){
                    matrixColor[v][w] = matrixColor[w][v] =  4;
                
                }
            }
           
           
        }


    }
}

void Bfs::writeOutput(int numberInstance){
    std::stringstream outputStream;
    outputStream << "results/graph_" << numberInstance << "_bfs.gdf";
    std::fstream output(outputStream.str(), std::ios::out);
    if(!output.is_open()){
        std::cout << "Não foi possivel abrir o arquivo." << std::endl;
        std::exit(1);
    }
    output << "nodedef>name VARCHAR,label VARCHAR\n";
    for(int i = 1; i < n; i++){
        output << i <<"," << i << "\n";

    }
    output << "edgedef>node1 VARCHAR,node2 VARCHAR,directed BOOLEAN,color VARCHAR\n";

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n; j++){
            /* Essa é a cor azul */
            if(matrixColor[i][j] == 1){
                output << i << "," << j << ",false," << "'0,0,255'\n";
            }
            else if(matrixColor[i][j] == 2){
                output << i << "," << j << ",false," << "'255,0,0'\n";
            }
            else if(matrixColor[i][j] == 3){
                output << i << "," << j << ",false," << "'255,255,0'\n";
            }
            else if(matrixColor[i][j] == 4){
                output << i << "," << j << ",false," << "'0,255,0'\n";
            }
        }
    }
    output.close();

   
}