#include "ReadInstance.h"
#include <fstream>
#include <sstream>

/*Função responsável pela leitura do arquivo */
ReadInstance::ReadInstance(const char *pathFile){
    std::fstream file(pathFile, std::ios::in);
    std::string line;

    std::getline(file, line);
    int n = stoi(line);
    
    
    std::vector < int > dataLine(n +1, 0);
    std::vector < int > neighborhood; /*Valores da lista adj*/
    neighborhood.clear();
    
    this->matrixAdj.push_back(dataLine);
    this->listAdj.push_back(neighborhood);
    dataLine.resize(0);
    /*Leitura das linhas do arquivo*/
    for(int i = 1; i <= n; i++){
        std::getline(file, line);
        std::stringstream data(line);

        dataLine.push_back(0); /* Começando o primeiro valor como zero */
        while(std::getline(data, line, ' ')){
            dataLine.push_back(stoi(line));
        }
        this->matrixAdj.push_back(dataLine);
        dataLine.clear();
        this->listAdj.push_back(neighborhood);
        

    }
    std::cout << "Matriz de Adjacencia" << std::endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            std::cout << matrixAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*  Vamos ler apenas o triangulo superior para criação da lista de adj
        Tanto a lista como a matriz iniciam de 1 até n para facilitar o código
        Devemos adicionar no indice i o valor de j, como no indice j o valor de i
        justamente por estarmos no triangulo superior e estar em ordem crescente*/
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(matrixAdj[i][j]){
                this->listAdj[i].push_back(j);
                this->listAdj[j].push_back(i);
            }
        }
    }

    std::cout << "Lista de adjacencia" << std::endl;
    for(int i = 1; i <= n; i++){
        std::vector < int > neigh = this->listAdj[i];
        for(int j = 0; j < neigh.size(); j++){
            std::cout << neigh[j] << " ";
        }
        std::cout << std::endl;
    }

    file.close();


}