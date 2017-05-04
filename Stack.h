//
// Created by 田植成 on 17/4/29.
//

#ifndef PRACTICE_STACK_H
#define PRACTICE_STACK_H
#include<iostream>
#include<cassert>
template<typename T>
class Stack{
private:
    int m_size;
    int m_top;
    T* t;
public:
template<typename T>
Stack<T>::Stack(int size){
    this->m_size = size;
    this->t = new T[size];
    this->mtop = 0;
}
template<typename T>
Stack<T>::~Stack(){
    delete [] t;
}
template<typename T>
bool Stack<T>::isEmpty() {
    return this->m_top==0 ? true:false;
}
template<typename T>
bool Stack<T>::isFull() {
    return this->m_size == this->m_top ? true:false;
}
template<typename T>
void Stack<T>::clearStack() {
    this->m_top=0;
}
template<typename T>
int Stack<T>::getLength(){
    return this->m_top;
}
template<typename T>
void Stack<T>::push(T t){
    assert(!isFull());
    this->t[m_top++] = t;
}
template<typename T>
T Stack<T>::pop(){
    assert(!isEmpty());
    return this->t[--m_top];
}
template<typename T>
void Stack<T>::traverseEle(bool direction) {
    if(direction){
        for(int i = 0 ; i < m_top ; i++) {
            cout << this->t[i] <<" " <<endl;
        }
    }else {
        for (int i = this->m_top; i >= 0; i--) {
            cout << this->t[i] << " " << endl;
        }
    }
}

};
#endif //PRACTICE_STACK_H
