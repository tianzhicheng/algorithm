//
// Created by 田植成 on 17/5/6.
//

#ifndef PRACTICE_WEIGHTEDSPARSEGRAPH_H
#define PRACTICE_WEIGHTEDSPARSEGRAPH_H
#include<iostream>
#include<cassert>
#include<vector>
#include "Edge.h"
//有权稀疏图
template<typename Weight>
class WeightedSparseGraph{
private:
    int m ,n ;
    bool directed;
    vector<vector<Edge<Weight>*>> g;
public:
    WeightedSparseGraph(int n,bool directed){
       this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0 ; i < n ; i++){
            g.push_back(vector<Edge<Weight>*>());
        }
    }
    ~WeightedSparseGraph(){
       for(int i = 0 ; i < n ; i++) {
           for(int j = 0 ; j < g[i].size(); j++){
               delete g[i][j];
           }
       }
    }
    int V(){
        return n;
    }
    int E(){
        return m;
    }
    void addEdge(int v,int w,Weight weight){
        assert(v >= 0 && v <n);
        assert(w >= 0 && w <n);
        g[v].push_back(new Edge<Weight>(v,w,weight));
        if(v != w && !directed){
            g[w].push_back(new Edge<Weight>(w,v,weight));
        }
    }
    bool hasEdge(int v , int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for(int i = 0 ; i < g[v].size() ; i++){
            if(g[v][i]->other() == w)
                return true;
        }
        return false;
    }
    void show(){
        for(int i = 0 ; i < n ; i++){
            cout << "vertex: " ;
            for(int j = 0 ; j <g[i].size(); j++){
                cout << "( to:" << g[i][j]->w() << ",wt " <<g[i][j]->wt() <<")\t";
            }
            cout << endl;
        }
    }
    class adjIterator{
    private:
        WeightedSparseGraph &G;
        int index;
        int v;
    public:
        adjIterator(WeightedSparseGraph &graph,int v):G(graph){
           this->index = 0;
            this->v = v;
        }
        ~adjIterator(){

        }
        Edge<Weight> * begin(){
           this->index = 0;
            return this->next();
        }
        Edge<Weight>* next(){
           for(; index < G[index].size(); index++) {
               return G[v][index];
           }
        }
        bool end(){
            return index > G.V();
        }
    };

};
#endif //PRACTICE_WEIGHTEDSPARSEGRAPH_H
