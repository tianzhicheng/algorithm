//
// Created by 田植成 on 17/5/14.
//

#ifndef PRACTICE_KRUSK_H
#define PRACTICE_KRUSK_H
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"
#include "UnionFind4.h"
#include <vector>
using namespace std;
template<typename Graph,typename Weight>
class Krusk{
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;
public:
    Krusk(Graph &g){
       MinHeap<Edge<Weight>>  pq(g.E());
        UnionFind4 uf = UnionFind4(g.V());
        for(int i = 0 ; i < g.V() ; i++){
            typename Graph::adjIterator adj(g,i);
            for(Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next()){
                if(e->v() < e->w())
                    pq.insert(*e);
            }
        }
       while(!pq.empty() && mst.size() < g.V()-1) {
           Edge<Weight> e = pq.extract();
           if(!uf.isConnected(e.v(),e.w())){
               mst.push_back(e);
               uf.unionELe(e.v(),e.w());
           }
       }

        mstWeight = 0;
        for( int i = 0 ; i < mst.size() ; i++){
            mstWeight += mst[i].wt();
        }
    }
    ~Krusk(){

    }
    vector<Edge<Weight>> mesEdges(){
        return mst;
    }
    Weight result(){
        return mstWeight;
    }

};
#endif //PRACTICE_KRUSK_H
