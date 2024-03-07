#include <iostream>
#include "ReadInstance.h"
#include "Dfs.h"






int main(int argc, char** argv){

    ReadInstance instance(argv[2]);
    std::vector < std::vector < int >> *listAdj = instance.getListAdj();
    DFS dfs(listAdj);
    dfs.procedure(1);
    dfs.writeOutput(std::stoi(argv[1]));
    return 0;
}