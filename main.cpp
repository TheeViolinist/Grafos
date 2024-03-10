#include <iostream>
#include "ReadInstance.h"
#include "Dfs.h"
#include "Bfs.h"





int main(int argc, char** argv){

    if(argc < 3){
        std::cout << "input format: numberInstance graph" << std::endl;
        exit(1);
    }
    ReadInstance instance(argv[2]);
    std::vector < std::vector < int >> *listAdj = instance.getListAdj();
    DFS dfs(listAdj);
    dfs.procedure(1);
    dfs.writeOutput(std::stoi(argv[1]));
    Bfs bfs(listAdj);
    bfs.procedure(1);
    bfs.writeOutput(std::stoi(argv[1]));

    return 0;
}