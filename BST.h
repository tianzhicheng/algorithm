//
// Created by 田植成 on 17/4/13.
//


#ifndef PRACTICE_BST_H
#define PRACTICE_BST_H
#include <queue>
template<typename Key,typename Value>
class BST{

private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key , Value value){
            this->key = key;
            this->value = value;
            this->left = this->right =NULL;
        }
        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };
    Node *root;
    int count;
public:
    BST(){
        root = NULL;
        count = 0 ;
    }
    ~BST(){
        destory(root);
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count ==0 ;
    }
    void insert(Key key,Value value){
        root = insertNode(root,key,value);
    }
    Value* search(Key key){
        Value * val = searchData(root,key);
        return val;
    }
    bool contain(Key key){
        return containKey(root,key);
    }
    void preOrder(){
        preOrder(root);
    }
    void inOrder(){
        preOrder(root);
    }
    void postOrder(){
        postOrder(root);
    }
    void levelOrder(){
        std::queue<Node*> q;
        q.push(root);
        while(!q.isEmpty()){
            Node* node = q.front();
            q.pop();
            cout << node->value << endl;
            if(node->left != NULL){
                q.push(node ->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
    }
    Key minimum(){
        assert(count != 0);
        Node* node =  minimum(root);
        return node->key;
    }
    Key maxmum(){
        assert(count != 0);
        Node* node = maxmum(root);
        return node->key;
    }
    void removeMin(){
        assert(count != 0);
        root = removeMin(root);
    }
    void removeMax(){
        assert(count != 0);
        root = removeMax(root);
    }
    void removeNode(Key key){
        assert(count > 0 );
        root = removeNode(root,key);
    }

private:
    Node* maxmum(Node* node){
        if(node->right == NULL){
            return node;
        }
        else{
            return maxmum(node->right);
        }
    }
    Node* minimum(Node* node){
        if(node-> left == NULL)
            return node;
        else{
            Node * node1 = minimum(node->left);
            return node1;
        }

    }
    void postOrder(Node *node){
        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout << node -> value << " "<< endl;
        }
    }
    void inOrder(Node *node){
        if(node != NULL){
            inOrder(node->left);
            cout << node->value << " " << endl;
            inOrder(node->right);
        }
    }
    void preOrder(Node *node){
        if(node != NULL){
            cout << node->value << " "<< endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    bool containKey(Node *node , Key key){
        if(node == NULL)
            return false;
        if(node -> key == key)
            return true;
        else if(node->key < key)
            return containKey(node->right,key);
        else
            return containKey(node->left,key);
    }
    Value* searchData(Node *node ,Key key){
        if(node == NULL) {
            return NULL;
        }
        Value * val;
        if(node->key == key)
            return &(node->value);
        else if(node->key < key)
            val = searchData(node->right,key);
        else
            val = searchData(node->left,key);
        return val;
    }
    Node* insertNode(Node *node , Key key , Value value){
       if(node == NULL) {
           count++;
           return new Node(key,value);
       }
        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node-> left =  insertNode(node->left ,key,value);
        else
            node->right =  insertNode(node->right , key ,value);
        return node;
    }
    void destory(Node *node){
        if(node != NULL){
            destory(node->left);
            destory(node->right);
            delete node;
            count--;
        }
    }
    Node* removeMin(Node* node){
        if(node == NULL)
            return NULL;
        if(node->left != NULL){
            node->left = removeMin(node->left);
            return node;
        }else{
            Node* nodeRight = node->right;
            delete node;
            count--;
            return nodeRight;
        }

    }
    Node* removeMax(Node* node){
        if(node == NULL)
            return NULL;
        if(node->right != NULL){
             node->right = removeMax(node->right);
            return node;
        }else{
            Node* leftNode = node-leftNode;
            delete node;
            count--;
            return leftNode;
        }
    }
    Node* removeNode(Node* node,Key key){
       if(node == NULL)
           return NULL;
        if(key < node->key){
            node->left = removeNode(node->left,key);
            return node;
        }
        if(key > node->key){
            node->right = removeNode(node->right,key);
            return node;
        }
        if(node->left == NULL){
            Node *right = node->right;
            delete node;
            count --;
            return right;
        }
        if(node->right == NULL){
            Node* left = node->left;
            delete node;
            count --;
            return left;
        }
        Node* successor = new Node(minimum(node->right));
        delete node;
        count++;
        successor->right = removeMin(node->right);
        successor->left = node->left;
        count--;
        return successor;
    }
};
#endif //PRACTICE_BST_H
