//
// Created by 田植成 on 17/5/18.
//

#ifndef PRACTICE_UNIONFIND4_H
#define PRACTICE_UNIONFIND4_H
#include <iostream>
#include <cassert>
class UnionFind4{
private:
    int * parent;
    int * rank;
    int count;
public:
    UnionFind4(int count){
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for(int i = 0 ; i < count ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind4(){
        delete [] parent;
        delete [] rank;
    }
    bool isConnected(int p ,int q){
        return find(p) == find(q);
    }
    int find(int p){
        assert(p < count);
        while (p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void unionELe(int p ,int q){
        assert(q < count);
        assert(p < count);

        int pRoot = find(p);
        int qRoot = find(q);
        if(qRoot == pRoot)
            return;
        else if(rank[qRoot] < rank[pRoot])
           parent[qRoot]  = pRoot;
        else if(rank[qRoot] > rank[pRoot])
            parent[pRoot] = qRoot;
        else
            parent[qRoot] = pRoot;

    }
    void show(){
        for(int i = 0 ; i < count ; i++){
            cout << i << ":" << parent[i] << endl;
        }
    }
};
#endif //PRACTICE_UNIONFIND4_H
