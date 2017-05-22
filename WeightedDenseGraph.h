//
// Created by 田植成 on 17/5/6.
//

#ifndef PRACTICE_WEIGHTEDDENSEGRAPH_H
#define PRACTICE_WEIGHTEDDENSEGRAPH_H
#include<cassert>
#include<vector>
#include<iostream>
#include"Edge.h"
//有权稠密图
template<typename Weight>
class WeightedDenseGraph{
private:
    int n,m;
    vector<vector<Edge<Weight>*>> g;
    bool directed;

public:
    WeightedDenseGraph(int n,bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0 ; i < n ; i++){
            g.push_back(vector<Edge<Weight>*>(n,NULL));
        }
    }
    ~WeightedDenseGraph(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(g[i][j] != NULL)
                    delete g[i][j];
            }
        }
    }
    int E(){
        return m;
    }
    int V(){
        return n;
    }
    void addEdge(int v, int w,Weight weight){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if(!hasEdge(v,w)){
            delete g[v][w];
            if(!directed){
                delete g[w][v];
                m--;
            }
        }
        g[v][w] = new Edge<Weight>(v,w,weight);
        if(!directed){
            g[w][v] = new Edge<Weight>(w,v,weight);
        }
        m++;
    }
    bool hasEdge(int v,int w){
        return g[v][w] != NULL;
    }
    void show(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(g[i][j] != NULL)
                 cout << g[i][j]->wt()<<"\t";
                else
                    cout << "NULL\t";
            }
            cout << endl;
        }
    }
    class adjIterator{
    private:
        WeightedDenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(WeightedDenseGraph &g,int n):G(g){
            this->v = v;
            this->index = -1;
        }
        ~adjIterator(){

        }
        Edge<Weight>* begin(){
           this->index = -1;
            return this->next();
        }
        Edge<Weight>* next(){
            for(index += 1 ; index < G.V(); index++){
                if(G.g[v][index] != NULL)
                    return G.g[v][index];
            }
            return NULL;
        }
        bool end(){
           return index >= G.V();
        }
    };

};
#endif //PRACTICE_WEIGHTEDDENSEGRAPH_H
