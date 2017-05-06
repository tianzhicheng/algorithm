//
// Created by 田植成 on 17/5/4.
//

#ifndef PRACTICE_PATH_H
#define PRACTICE_PATH_H
#include<vector>
#include<iostream>
#include<cassert>
#include<stack>
using namespace std;
template<typename Graph>
class Path{
private:
    Graph &G;
    int s;
    bool *visted;
    int* from;
    void dfs(int v){
       visted[v]  = true;
        typename Graph::adjIterator adj(G,v);
        for(int i = adj.begin() ; !adj.end() ; i = adj.next()){
            if(!visted[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }
public:
    Path(Graph &g,int s):G(g){
        assert(s >= 0 && s < G.V());
        this->s = s;
        from = new int[G.V()];
        visted = new bool[G.V()];
        for(int i = 0 ; i < G.V(); i++){
            visted[i] =false;
            from[i] = -1;
        }
        dfs(s);
    }
    ~Path(){
        delete []from;
        delete []visted;
    }
    bool hasPath(int v){
        return visted[v];
    }
    void path(int v , vector<int> &vec){
        assert(v >= 0 && v < G.V());
        stack<int> s;
        int p = v;
        while(p != -1){
            s.push(p);
            p = from[p];
        }
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }
    void showPath(int v){
        assert(v >= 0 && v < G.V());
        vector<int> vec;
        path(v,vec);
        for(int i = 0 ; i < vec.size() ; i++){
            cout << vec[i];
            if(i == vec.size()-1){
                cout << endl;
            }else{
                cout <<  "->";
            }
        }
    }
};
#endif //PRACTICE_PATH_H
