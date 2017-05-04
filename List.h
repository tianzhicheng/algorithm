//
// Created by 田植成 on 17/4/29.
//

#ifndef PRACTICE_LIST_H
#define PRACTICE_LIST_H
template <typename Elem>
#include <cassert>
#include <iostream>
using namespace std;

class List{
private:
    Elem *m_list;
    int m_size;
    int m_length;

public:
    List(int size) {
        this->m_size = size;
        this->m_list = new int[size];
        this->m_length = 0;
    }
    ~List(){
        delete []m_list;
        this->m_list = NULL;
    }
    void clearList() {
        this->m_length=0;
    }
    bool listEmpty() {
        return m_length == 0? true:false;
    }
    int listLength() {
        return this->m_length;
    }
    Elem getElem(int i) {
        assert(i>=0 && i < size);
        return this->m_list[i];
    }
    int locateElem(Elem *e) {
        for(int i = 0 ; i < m_length ; i ++){
            if(m_list[i] == *e)
                return i;
        }
        return -1;
    }
    Elem priorElem(Elem *e){
       int i = locateElem(e);
        assert(i != -1 && i != 0);
        return m_list[--i];
    }
    Elem nextElem(Elem *e){
        int i = locateElem(e);
        assert(i != -1 && i < m_length);
        return m_list[++i];
    }
    void insert(int index ,Elem *e){
        assert(i >=0 && i < m_length && m_length < m_size);
        for( int i = m_length ; i> index ; i--){
            m_list[i] = m_list[i-1];
        }
        m_list[index] = *e;
        m_length++;
    }
    void deleteEle(int index , Elem *e){
        assert(i >= 0 && i < m_length );
        for(int i = index; i < m_length; i++){
            m_list[i]  = m_list[i+1];
        }
        m_length--;
    }




};
#endif //PRACTICE_LIST_H
