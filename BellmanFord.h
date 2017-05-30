//
// Created by 田植成 on 17/5/29.
//

#ifndef PRACTICE_BELLMANFORD_H
#define PRACTICE_BELLMANFORD_H
#include <cassert>
#include <vector>
#include "Edge.h"
#include <stack>
using namespace std;
template<typename Graph,typename Weight>
class BellmanFord{
private:
    int s;
    Graph &G;
    vector<Edge<Weight> *> from;
    Weight* distTo;
    bool hasNegativeCycle;
    bool detectNegativeCycle(){
        for(int i = 0 ; i < G.V() ; i++){
            typename Graph::adjIterator adj(G,i);
            for(Edge<Weight>* e = adj.begin() ; !adj.end(); e = adj.next()){
                cout << from[e->w()] << endl;
                if(!from[e->w()] || distTo[e->v()]+e->wt() < distTo[e->w()]){
                    return true;
                }
            }
        }
        return false;
    }
public:
    BellmanFord(Graph &graph,int s):G(graph) {
        this->s = s;
        distTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); i++) {
            from.push_back(NULL);
        }
        distTo[s] = Weight();
        for(int pass = 1 ; pass < G.V() ; pass++){
            for(int i = 0 ; i < G.V(); i++){
                typename Graph::adjIterator iter(G,i);
                for(Edge<Weight>* e = iter.begin(); !iter.end(); e = iter.next()){
                   if(!from[e->w()] || distTo[e->v()]+e->wt() < distTo[e->w()]) {
                      distTo[e->w()]  =  distTo[e->v()]+ e->wt();
                       from[e->w()] = e;
                   }
                }
            }
        }
        hasNegativeCycle = detectNegativeCycle();
    }
    ~BellmanFord(){
        delete [] distTo;
    }
    Weight shortestPathTo(int w){
       assert(w>=0 && w < G.V());
       assert(!hasNegativeCycle);
       return distTo[w];
    }
    bool hasPathTo(int w){
        assert( w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        return from[w] == NULL;
    }
    bool negativeCycle(){
        return hasNegativeCycle;
    }
    void showPath(int w){
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        vector<Edge<Weight>> vec;
        shortestPath(w,vec);
        for(int i = 0 ; i < vec.size() ; i++){
            cout << vec[i].v() << "->";
            if(i == vec.size()-1)
                cout << vec[i].w() << endl;
        }
    }
    void shortestPath(int w , vector<Edge<Weight>> &vec){
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while(e->v() != this->s){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        while(!s.empty()){
           e = s.top();
//            cout << e->v() << "," << e->w() << " " << e <<endl;
           vec.push_back(*e);
           s.pop();
        }
    }
};
#endif //PRACTICE_BELLMANFORD_H
