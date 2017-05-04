//
// Created by 田植成 on 17/4/17.
//

#ifndef PRACTICE_UNIONFIND2_H
#define PRACTICE_UNIONFIND2_H
#include <assert.h>
namespace UF3{
    template<typename T>
    class UnionFind{
    private:
        int* parent;
        int* sz;
        int count;
    public:
       UnionFind(int count){
           this->count = count;
            parent = new int[count];
            id = new int[count];
            for(int i = 0 ; i < count; i++){
                parent[i] = i;
                sz[i] = 1;
            }
       }
        ~UnionFind(){
            delete [] parent;
            delete [] sz;
        }
        int find(int p){
           assert(p >= 0 && p<count);
            while(p != parent[p]){
                p = parent[p];
            }
            return p;
        }
        bool isconnected(int p,int q){
            return find(p) == find(q);
        }
        void unionEle(int p , int q){
            int proot = find(p);
            int qroot = find(q);
            if(qroot == proot)
                return;
            if(sz[qroot] < sz[proot]){
                parent[qroot]  =proot;
                sz[proot] +=sz[qroot];
            }else{
                parent[proot] = qroot;
                sz[qroot] += sz[proot];
            }
        }
    };
}
#endif //PRACTICE_UNIONFIND2_H
