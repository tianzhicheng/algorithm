//
// Created by 田植成 on 17/5/5.
//

#ifndef PRACTICE_SHORTESTPATH_H
#define PRACTICE_SHORTESTPATH_H
#include<queue>
#include<iostream>
#include<cassert>
#include<vector>
#include<stack>
using namespace std;
template<typename Graph>
class shortestPath{
private:
    Graph &G;
    int* ord;
    int s;
    bool* visited;
    int* from;
public:
    shortestPath(Graph &g,int s):G(g){
        assert(s >= 0 && s < G.V());
        this->s = s;
        ord = new int[G.V()];
        from = new int[G.V()];
        visited = new bool[G.V()];
        for(int i = 0 ; i < G.V(); i++){
            ord[i] = 0;
            visited[i] = false;
            from[i] = -1;
        }
        queue<int> que;
        que.push(s);
        visited[s] = true;
        ord[s] = 0;

        while(!que.empty()){
            int head = que.front();
            que.pop();
            typename Graph::adjIterator adj(G,head);
            for(int i = adj.begin(); !adj.end() ; i = adj.next()){
                if(!visited[i]){
                    visited[i] = true;
                    que.push(i);
                    from[i] = head;
                    ord[i] = ord[head] +1;

                }
            }
        }
    }
    ~shortestPath(){
        delete []ord;
        delete []from;
        delete []visited;
    }
    bool hasPath(int v){
       return visited[v];
    }
    void path(int v, vector<int> &vec){
       stack<int> s ;
        int p = v;
        while(p != -1){
            s.push(p);
            p = from[p];
        }
        while(!s.empty()){
            int p = s.top();
            s.pop();
            vec.push_back(p);
        }
    }
    void showPath(int v){
       vector<int> vec;
        path(v,vec);
        for(int i = 0 ; i < vec.size() ; i++){
          cout << vec[i];
            if(i == vec.size()-1)
                cout << endl;
            else
                cout << "->";
        }
    }
    int getlength(int v){
        assert(v >= 0 && v < G.V());
        return ord[v];
    }

};

#endif //PRACTICE_SHORTESTPATH_H
