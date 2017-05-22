//
// Created by 田植成 on 17/5/13.
//

#ifndef PRACTICE_LAZYPRIM_H
#define PRACTICE_LAZYPRIM_H
#include <iostream>
#include <cassert>
#include "MinHeap.h"
#include "Edge.h"
using namespace std;
//最小生成树
template<typename Graph,typename Weight>
class LazyPrim{
private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;
    void visit(int v){
        marked[v] = true;
        typename Graph::adjIterator adj(G,v);
        Edge<Weight> *e = adj.begin();
        for(; !adj.end(); e = adj.next()){
            if(!marked[e->other(v)])
                pq.insert(*e);
        }
    }
public:
    LazyPrim(Graph &graph):G(graph),pq(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); i++) {
            marked[i] = false;
        }
        mst.clear();
        visit(0);
        while (!pq.empty()) {
            Edge<Weight> e = pq.extract();
            if (marked[e.v()] == marked[e.w()])
                continue;
            mst.push_back(e);
            if (!marked[e.v()])
                visit(e.v());
            else
                visit(e.w());
        }
            mstWeight = mst[0].wt();
            for (int i = 1; i < mst.size(); i++) {
                mstWeight += mst[i].wt();
            }
    }
    ~LazyPrim(){
        delete [] marked;
    }
    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
    Weight result(){
        return mstWeight;
    }

};
#endif //PRACTICE_LAZYPRIM_H
