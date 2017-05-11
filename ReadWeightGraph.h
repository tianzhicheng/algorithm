//
// Created by 田植成 on 17/5/8.
//

#ifndef PRACTICE_READWEIGHTGRAPH_H
#define PRACTICE_READWEIGHTGRAPH_H
#include<iostream>
#include<sstream>
#include<cassert>
#include<string>
using namespace std;
template<typename Graph,typename Weight>
class ReadWeightGraph{
public:
    ReadWeightGraph(Graph &G,const string &filename){
       ifstream file(filename);
        string line;
        int V,E;
        assert(file.is_open());
        assert(getline(file,line));
        stringstream ss(line);
        ss >> V >> E;
        assert(V == G.V());
        for(int i = 0 ; i < E ; i ++){
            assert(getline(file,line));
            stringstream ss(line);
            int a,b;
            Weight weight;
            ss >> a >> b >> weight;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            G.addEdge(a,b,weight);

        }
    }
};
#endif //PRACTICE_READWEIGHTGRAPH_H
