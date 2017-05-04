//
// Created by 田植成 on 17/4/15.
//

#ifndef PRACTICE_UNIONFIND_H
#define PRACTICE_UNIONFIND_H
#include <cassert>
class UnionFind1{
    int* id;
    int count;
public:
    UnionFind1(int n){
        count = n;
        for(int i = 0; i < n ; i++){
           id[i]  = i;
        }
    }
    ~UnionFind1(){
        delete[] id;
    }
    int find(int p){
        assert(p <=count);
        return id[p];
    }
    bool isConnection(int p , int q){
       int pid = find(p);
        int qid = find(q);
        return pid == qid;
    }
    void unionEle(int p , int q){
        int pid = find(p);
        int qid = find(q);
        if(pid == qid){
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(id[i] = pid)
                id[i] = qid;
        }
    }
};
#endif //PRACTICE_UNIONFIND_H
