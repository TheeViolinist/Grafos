#ifndef DUMB_ALGORITHM_H
#define DUMB_ALGORITHM_H

#include <vector>

class DumbAlgorithm{
  public:
      DumbAlgorithm(int n, std::vector < std::vector < int >>* matrixAdj);
      int algorithm();    

  private:
      int n;
      std::vector < std::vector < int >>*matrixAdj;
}; 
#endif
