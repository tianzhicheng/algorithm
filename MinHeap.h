//
// Created by 田植成 on 17/5/6.
//

#ifndef PRACTICE_MINHEAP_H
#define PRACTICE_MINHEAP_H
#include <cassert>
//最小堆
template<typename Item>
class MinHeap{
private:
    int capacity;
    Item* arr;
    int count;
    void shiftDown(int k){
        while(k*2 <= count){
            int j = 2*k;
            if(j+1 <= count && arr[j] > arr[j+1]) j++;
            if(arr[j] > arr[k]) break;
            swap(arr[j],arr[k]);
            k = j ;
        }
    }
    void shiftUp(int k){
        while(k>1){
            if(arr[k/2] > arr[k])
                swap(arr[k/2],arr[k]);
            k /= 2;
        }
    }
public:
    MinHeap(int capacity){
        this->count = 0;
        this->capacity = capacity;
        this->arr = new Item[capacity+1];
    }
    ~MinHeap(){
       delete [] arr;
    }
    MinHeap(Item data[],int n){
        this->count = n;
        this->capacity = n;
        this-arr = new Item[n+1];
        for(int i = 0 ; i < n ; i++){
            arr[i+1] =  data[i];
        }
        for(int i = count/2 ; i >= 1 ; i--) {
            shiftDown(i);
        }
    }
    int getMin(){
        assert(count > 0 );
        return arr[1];
    }
    Item extract(){
        assert(count > 0);
        Item item = arr[1];
        swap(arr[1],arr[count]);
        count--;
        shiftDown(1);
        return item;
    }
    void insert(Item item){
        assert(count < capacity);
        arr[++count] = item;
        shiftUp(count);
    }
    int size(){
        return count;
    }
    int empty(){
        return count == 0;
    }

};
#endif //PRACTICE_MINHEAP_H
