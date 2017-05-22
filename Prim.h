//
// Created by 田植成 on 17/5/14.
//

#ifndef PRACTICE_PRIM_H
#define PRACTICE_PRIM_H
#include<cassert>
#include"IndexMinHeap.h"
#include<vector>
#include "Edge.h"
using namespace std;
template<typename Graph , typename Weight>
class Prim{
private:
    Graph &G;
    bool *marked;
    IndexMinHeap<Weight> ipq;
    vector<Edge<Weight> *> edgeTo;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v){
        marked[v] = true;
        typename Graph::adjIterator adj(G,v);
            for(Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next()){
                int w = e->other(v);
                if(!marked[w]){
                   if(!edgeTo[w]){
                       edgeTo[w] = e;
                       ipq.insert(w,e->wt());
                   }
                    if(edgeTo[w]->wt() > e->wt()){
                        edgeTo[w] = e;
                        ipq.change(w,e->wt());
                    }
                }
            }
        ipq.show();
    }
public:
    Prim(Graph &graph):G(graph),ipq(IndexMinHeap<Weight>(G.V())){
        marked = new bool[G.V()];
        for(int i = 0 ; i < G.V() ; i++){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();
        //PRIM
        visit(0);
        while(!ipq.isEmpty()){
            int index = ipq.extractMinIndex();
//            cout << index << endl;
//            cout << edgeTo[index] <<endl;
            assert(edgeTo[index]);
            mst.push_back(*edgeTo[index]);
            visit(index);
        }
        mstWeight = 0;
        for(int i = 0 ; i < mst.size() ; i++){
            mstWeight += mst[i].wt();
        }
    }
    ~Prim() {
        delete[] marked;
    }
    vector<Edge<Weight>> getMst(){
        return mst;
    }
    Weight getMstWeight(){
        return mstWeight;
    }


};
#endif //PRACTICE_PRIM_H
