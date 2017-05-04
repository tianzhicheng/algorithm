//
// Created by 田植成 on 17/5/1.
//

#ifndef PRACTICE_READGRAPH_H
#define PRACTICE_READGRAPH_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;
template<typename Graph>
class ReadGraph{
public:
    ReadGraph(Graph &graph , const string &filename){
        ifstream file(filename);
        string line;
        int V,E;
        assert(file.is_open());
        assert(getline(file,line));
        stringstream ss(line);
            ss >> V >> E;
        assert(V == graph.V());
        for(int i = 0 ; i < E ; i++){
            assert(getline(file,line));
            stringstream ss(line);
            int a,b;
            ss >> a >> b;
            assert(a >= 0 && a <E);
            assert(b >= 0 && b <E);
            graph.addEdge(a,b);
        }
    }
};
#endif //PRACTICE_READGRAPH_H