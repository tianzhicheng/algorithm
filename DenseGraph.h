//
// Created by 田植成 on 17/4/17.
//

#ifndef PRACTICE_DENSEGRAPH_H
#define PRACTICE_DENSEGRAPH_H
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
//稠密图 邻接矩阵
class DenseGraph{
private:
    int m;
    //点
    int n;
    vector<vector<bool>> g;
    bool director;
public:
    DenseGraph(int n,bool director){
        this->n = n;
        this->m = 0;
        this->director = director;
        for(int i = 0 ; i < n ; i++){
            g.push_back(vector<bool>(n,false));
        }
    }
    ~DenseGraph(){

    }
    //返回点数
    int V(){
            return n;
    };

    //返回边数
    int E(){
        return m;
    }
    void show(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++){
                cout << g[i][j] << "\t";
            }
            cout << endl;
        }
    }
    //添加边
    void addEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if(hasEdge(v,w))
            return ;
        g[v][w] = true;
        if(!director)
            g[w][v] = true;
        m++;
    }
    //判断边是否已经存在
    bool hasEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        return g[v][w];
    }
//    void show(){
//        for(int i = 0 ; i < n ; i++){
//            for(int j = 0 ; j < n ; j++){
//                cout << g[i][j] << "\t";
//            }
//            cout << endl;
//        }
//    }
    class adjInterator{
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjInterator(DenseGraph &graph,int v):G(graph){
            this->v = v;
            this->index = -1;
        }
        int begin(){
            index = -1;
            return next();
        }
        int next(){
            for(index += 1 ; index < G.V();index ++){
                if(G.g[v][index]){
                    return index;
                }
            }
            return -1;
        }
        bool end(){
            return index >= G.V();
        }

    };

};
#endif //PRACTICE_DENSEGRAPH_H
