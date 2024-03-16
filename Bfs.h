#ifndef BFS_H
#define BFS_H
#include <vector>
#include <list>

class Bfs{
    public:
        Bfs(std::vector<std::vector<int>>* listAdj);
        void procedure(int v);
        void writeOutput(int numberInstance);
        int getHeightTree();
        void clear();
    private:
        std::vector<std::vector<int>>* listAdj;
    /*  1 representa a cor azul, 2 para a cor vermelha, 3 para amarelo e 4 para verde */
        std::vector < std::vector < int>> matrixColor; /* Matriz que indica as cores das arestas*/
        std::vector < int > L; /* Vector de largura para o vértice */
        std::vector < int > fathers; /* Pai de cada vértice */
        std::vector < int > nivel; /* nivel de cada vértice */
        int t;
        int n;
        std::list < int > fila; /*Fila para achar as arestas*/
        std::vector < int > v_listed; /* Vertices que ja foram encontrados */
        
};











#endif