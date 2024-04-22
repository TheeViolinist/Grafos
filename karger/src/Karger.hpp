#ifndef KARGER_H
#define KARGER_H

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>


struct tEdges{
  int nodeA;
  int nodeB;
  tEdges(int v1, int v2){
      nodeA = v1;
      nodeB = v2;
  }
};



class Karger{
    public:
        Karger(std::vector < tEdges >  edges, int n, std::vector < std::vector < int >> *matrixAdj);
        void init();
        int algorithm();
        int findSet(int node, int);
        int setUnion(int nodeA, int nodeB);

    private:
      std::vector < tEdges > edges;
      std::vector < std::vector < int >> *matrixAdj;
      int n;
      std::vector < int > setDj; // Conjuntos disjuntos
      std::vector < int > rank;
};
#endif
