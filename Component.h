//
// Created by 田植成 on 17/5/3.
//

#ifndef PRACTICE_COMPONENT_H
#define PRACTICE_COMPONENT_H
#include <iostream>
#include <cassert>
template<typename Graph>
class Component{
private:
    Graph &G;
    int ccount;
    bool *visited;
    int *id;
    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G,v);
        for(int i = adj.begin(); !adj.end() ; i = adj.next()){
            if(!visited[i]){
                dfs(i);
            }
        }
    }
public:
    Component(Graph &g):G(g){
        this->ccount = 0 ;
        this->visited = new bool[G.V()];
        this->id = new int[G.V()];
        for(int i = 0 ; i < G.V() ; i++){
            visited[i] = false;
            id[i] = -1;
        }
        for(int i = 0 ; i < G.V() ; i++){
            if(!visited[i]){
                dfs(i);
                ccount++;
            }
        }
    }
    ~Component(){
        delete [] visted;
        delete [] id;
    }
    int getCcount(){
        return ccount;
    }
    bool isConnected(int v , int w){
        assert(v>=0 && v <G.V());
        assert(w>=0 && w < G.V());
        return id[v] == id[w];
    }
};
#endif //PRACTICE_COMPONENT_H
