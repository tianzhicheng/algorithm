//
// Created by 田植成 on 17/4/17.
//

#ifndef PRACTICE_UNIONFIND3_H
#define PRACTICE_UNIONFIND3_H
class UnionFind3{
private:
    int *parent;
    int count;
    int *rank;
public:
    UnionFind3(int count){
        this->count = count;
        parent = new int[count];
        rank = new int[count];
        for(int i=0; i<count ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind3(){
        delete [] parent;
        delete [] rank;
    }
    int find(int p){
//        while(p != parent[p]){
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
//        return p;
        while(p != parent[p]){
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }
    bool isconnected(int p ,int q){
        return find(p) == find(q);
    }
    void unionEle(int p , int q){
        int proot = find(p);
        int qroot = find(q);
        if(qroot = qroot)
            return;
        if(rank[proot] < rank[qroot]){
           parent[proot] = qroot;
        }else if(rank[qroot] < rank[proot]){
           parent[qroot]  = proot;
        }else{
           parent[proot]  = qroot;
            rank[qroot] ++;
        }
    }

};
#endif //PRACTICE_UNIONFIND3_H
