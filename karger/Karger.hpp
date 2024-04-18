#ifndef KARGER_H
#define KARGER_H

#include <vector>

typedef struct{
  int v1;
  int v2;
}tEdges;



class Karger{
    public:
        Karger(std::vector < tEdges > * edges, int n);
        void init();

    private:
      std::vector < tEdges > *edges;
      int n;
      std::vector < int > setDj; // Conjuntos disjuntos
      std::vector < int > rank;
};
#endif
