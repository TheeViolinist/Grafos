#ifndef DFS_H
#define DFS_H
#include <vector>


class DFS{
    public:
        DFS(std::vector<std::vector<int>>*listAdj);
        void procedure(int v);
        void writeOutput(int numberInstance);

    private:
        std::vector < std::vector <int>>* listAdj;
        /*  1 representa a cor azul e 2 para a cor vermelha */
        std::vector < std::vector < int>> matrixColor; /* Matriz que indica as cores das arestas*/
        std::vector < int > PS;
        std::vector < int > PE;
        std::vector < int > v_fathers; /* Pais de cada vértice */
        int n; /* Quantia de vértices */
        int t; /* Tempo global para o PS e PE*/
};












#endif