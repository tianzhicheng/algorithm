//
// Created by 田植成 on 17/4/30.
//

#ifndef PRACTICE_LINKLIST_H
#define PRACTICE_LINKLIST_H
template<typename T>
class LinkList{
private:
    Node *head;
    int m_length;

public:
    struct Node{
        Node *next;
        T data;
        Node(){
            data = NULL;
            next = NULL;
        }
    };
    LinkList(){
       this->head = NULL;
       int m_length = 0;
    }
    ~LinkList(){
//        Node *concurrentNode = this->head;
//        while(concurrentNode != NULL){
//            Node *temp = concurrentNode->next;
//            delete concurrentNode;
//            concurrentNode = temp;
//        }
        clearList();
    }
    bool isEmpty(){
        return this->m_length==0?true:false;
    }
    int getLength(){
        return this->m_length;
    }
    void clearList(){
        Node *current = this->head;
        while(current != NULL){
            Node *tmp = current->next;
            delete current;
            current = tmp;
        }
        this->head = NULL;
    }
    void addHead(Node *node){
        Node *old = this->head;
        this->head = node;
        node->next = old;
        m_length++;
    }
    void addTail(Node *node){
        Node *old = this->head;
        if(this->head == NULL){
            this->head = node;
        }else{
            while(old->next != NULL){
               old = old->next;
            }
            old->next = node;
        }
        m_length++;

    }
    Node* getElem(int index){
        assert(i >= 0 && i < m_length);
        for(int i = 0 ; i < m_length ; i++){
            Node node = this->head;
            if( i == index){
                return node;
            }
            node = node->next;
        }
    }
    int locateElem(Node *node){
        int index = 0;
        T t = node->data;
        Node *old = this->head;
        while(old != NULL){
            T tmp = old->data;
            if(t == tmp){
                return index;
            }
            else{
                old = old->next;
                index++;
            }
        }
        return -1;
    }
    Node* priorElem(Node *node){
        assert(m_length > 0);
        Node *old = this->head;
        Node *before = NULL;
        for(int i = 0 ; i < m_length ; i++){
            if(node->data == old->data && node->next == old->next){
                return before;
            }
            before = old;
            old = old->next;
        }
    }
//    Node* nextElem(Node *node){
//        assert(m_length > 0);
//        Node *old = this->head;
//        for(int i = 0 ; i < m_length ; i++){
//            if(node->data == old->data && node->next == old->next){
//                return old->next;
//            }
//            old = this->next;
//        }
//    }
    void insert(int i,Node *node){
        assert(i>=0 && i<m_length);
        Node *old = this->head;
        for( int index = 0 ; index < i ; index ++ ){
            old = old->next;
        }
        if(old == NULL){
            old = node;
        }else{
            Node *tmp = old->next;
            old->next = node;
            node->next = tmp;
        }
        m_length++;
    }
    void deleteElem(int index) {
        assert(index >= 0 && index < m_length);
        Node *old = this->head;
        Node *beforeNode = NULL;
        for(int i = 0 ; i < index ; i ++ ){
            beforeNode = old;
           old = old->next;
        }
        beforeNode->next = old->next;
        delete old;
        m_length--;
    }
    void addElem(T t){
        Node *tail = getTail();
        Node *newNode = new Node();
        newNode->data = t;
        newNode->next = NULL;
        if(tail == NULL){
            this->head = newNode;
        }else{
            tail->next = newNode;
        }
        m_length++;
    }
    void remove(T t){
        if(m_length <= 0)
            return;
        Node *old = this->head;
        if(old->data == t){
            this->head = old->next;
            delete old;
            m_length--;
            return;
        }
        Node *before = NULL;
        for(int i = 0 ; i < m_length ; i++){
            if(old->data == t) {
               before->next = old->next;
                delete old;
                m_length--;
               return;
            }
            before = old;
            old = old->next;
        }
    }
    Node* getTail(){
        Node *tmp = this->head;
        if(tmp == NULL)
            return NULL;
        for(int i = 0 ; i < m_length ; i++) {
           tmp = tmp->next;
        }
        return tmp;
    }
};
#endif //PRACTICE_LINKLIST_H
