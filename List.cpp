////
//// Created by 田植成 on 17/4/29.
////
//#include "List.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//List::List(int size) {
//    this->m_size = size;
//    this->m_list = new int[size];
//    this->m_length = 0;
//}
//List::~List(){
//    delete []m_list;
//    this->m_list = NULL;
//}
//void List::clearList() {
//    this->m_length=0;
//}
//bool List::listEmpty() {
//    return m_length == 0? true:false;
//}
//int List::listLength() {
//    return this->m_length;
//}
//Elem List::getElem(int i) {
//    assert(i>=0 && i < size);
//    return this->m_list[i];
//}
//int List::locateElem(Elem *e) {
//    for(int i = 0 ; i < m_length ; i ++){
//        if(m_list[i] == *e)
//            return i;
//    }
//    return -1;
//}
