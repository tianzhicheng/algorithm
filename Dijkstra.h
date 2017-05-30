//
// Created by 田植成 on 17/5/29.
//

#ifndef PRACTICE_DIJKSTRA_H
#define PRACTICE_DIJKSTRA_H
#include <vector>
#include <cassert>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"
using namespace std;
template<typename Graph,typename Weight>
class Dijkstra{
private:
    Graph &G;
    Weight* distTo;
    bool* marked;
    vector<Edge<Weight> *> from;
    int s;
public:
    Dijkstra(Graph &graph,int s):G(graph){
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for(int i = 0 ; i < G.V(); i++){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
       IndexMinHeap<Weight> ipq = IndexMinHeap<Weight>(G.V());
        distTo[s] = Weight();
        marked[s] = true;
        ipq.insert(s,distTo[s]);
        while(!ipq.isEmpty()){
           int v = ipq.extractMinIndex();
            marked[v] = true;
            typename Graph::adjIterator iter(G,v);
            for(Edge<Weight> * e = iter.begin() ; !iter.end() ; e = iter.next()){
                int w = e->other(v);
                if(!marked[w]){
                    if(from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
                        distTo[w] = distTo[v]+e->wt();
                        from[w] = e;
                        if(ipq.contain(w)){
                            ipq.change(w,distTo[w]);
                        }else{
                            ipq.insert(w,distTo[w]);
                        }

                    }
                }
            }
        }
    }
    ~Dijkstra(){
        delete [] marked;
        delete [] distTo;
    }
    Weight shortestPathTo(int w){
        assert(w >= 0 && w < G.V());
        return distTo[w];
    }
    bool hasPathTo(int w){
        assert(w >= 0 && w < G.V());
        return marked[w];
    }
    void shortestPath(int w,vector<Edge<Weight>> &vec){
       assert(w >= 0 && w < G.V());
        stack<Edge<Weight> * > s;
        Edge<Weight> * e = from[w];
        while(e->v() != this->s){
           s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        while(!s.empty()){
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }
    void showPath(int w){
        assert(w >= 0 && w < G.V());
        vector<Edge<Weight>> vec;
        shortestPath(w,vec);
        for(int i = 0 ; i < vec.size() ; i++){
            cout << vec[i].v() << "->";
            if(i == vec.size()-1){
                cout << vec[i].w() << endl;
            }
        }
    }

};
#endif //PRACTICE_DIJKSTRA_H
