//
// Created by 田植成 on 17/5/6.
//

#ifndef PRACTICE_EDGE_H
#define PRACTICE_EDGE_H
#include <cassert>
//权边(用于有权图)
template<typename Weight>
class Edge{
private:
    int a,b;
    Weight weight;
public:
    Edge(int a,int b,Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    Edge(){

    }
    ~Edge(){

    }
    int v(){
        return a;
    }
    int w(){
        return b;
    }
    Weight wt(){
        return weight;
    }
    int other(int v){
       assert(v == a || v == b) ;
        return v==a ? b : a;
    }
    friend ostream& operator<<(ostream &os , const Edge &e){
        os << e.a << "-" << e.b<<": " <<e.weight;
        return os;
    }
    bool operator<(Edge<Weight> e){
        return weight < e.wt();
    }
    bool operator==(Edge<Weight> e){
        return weight == e.wt();
    }
    bool operator>(Edge<Weight> e){
        return weight > e.wt();
    }
    bool operator>=(Edge<Weight> e){
        return weight >= e.wt();
    }
    bool operator<=(Edge<Weight> e){
        return weight <= e.wt();
    }
};
#endif //PRACTICE_EDGE_H
