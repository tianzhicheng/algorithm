//
// Created by 田植成 on 17/4/17.
//

#ifndef PRACTICE_SPARSEGRAPH_H
#define PRACTICE_SPARSEGRAPH_H
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
class SparseGraph{
private :
    int m,n;
    vector<vector<int>> g;
    bool director;
public:
    SparseGraph(int n,bool director){
       this->m = 0;
       this->n = n;
        this->director = director;
        for(int i = 0 ; i < n ; i++){
            g.push_back(vector<int>());
        }
    }
    ~SparseGraph(){

    }
    void addEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if(hasEdge(v,w)){
            return ;
        }
        g[v].push_back(w);
        if(!director){
            g[w].push_back(v);
        }
        m++;
    }
    bool hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for(int i = 0 ; i < g[v].size() ; i++){
            if(g[v][i] == w){
                return true;
            }
        }
        return false;
    }
    void show(){
        for(int i = 0 ; i < n ; i++){
            cout << "vertex" << i << ":\t";
            for(int j = 0 ; j < g[i].size(); j++){
                cout << g[i][j] << "\t";
            }
            cout << endl;
        }
    }
    int E(){
       return m;
    }

    int V(){
       return n;
    }
public:
    class adjIterator{
       SparseGraph &G;
        int index;
        int v;

    public:
        adjIterator(SparseGraph &graph,int v):G(graph){
            this->v = v;
            this->index = 0;
        }
        int begin(){
           this->index = 0;
            if(G.g[v].size()){
                return G.g[v][index];
            }
           return -1;
        }
        int next(){
            index ++;
            if(index <= G.g[v].size()){
                return G.g[v][index];
            }
            return -1;
        }
        bool end(){
            return index >= G.g[v].size();
        }
//        void show(){
//           for(int i = 0 ; i < n ; i++) {
//               cout << "vertex " << i << ":\t";
//               for(int j = 0 ; j < g[i].size() ; j++){
//                   cout << g[i][j] << " " ;
//               }
//               cout << endl;
//           }
//        }

    };
};
#endif //PRACTICE_SPARSEGRAPH_H
