//
// Created by 田植成 on 17/4/13.
//

#ifndef PRACTICE_INDEXMAXHEAP_H
#define PRACTICE_INDEXMAXHEAP_H
#include <cassert>
template<typename Item>
class IndexMaxHeap{
private:
    Item* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;
public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for(int i = 0 ; i < capacity+1 ; i++){
            reverse[i] = 0;
        }
        this->count = 0;
        this->capacity = capacity;
    }
    ~IndexMaxHeap(){
        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }
    bool isEmpty(){
        return 0 == count;
    }
    int size(){
        return count;
    }
    void insert(int i,Item item){
       assert(count+1 <= capacity);
        assert(i+1 >=1 && i+1<=capacity);
        i++;
        data[i] = item;
        indexes[count+1] = i;
        reverse[count+1] = i;
        count ++;
        shiftUp(count);
    }
    int extractIndex(){
        assert(count >=1);
        int index = indexes[1];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[count] = 0 ;
        count --;
        shiftDown(1);
        return index;
    }

    Item extractData(){
        assert(count >= 1);
        Item  ret = data[indexes[1]];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[count] = 0;
        count -- ;
        shiftDown(1);
        return ret;
    }
    bool contain(int i){
        assert(i+1 >=1 && i+1<=capacity);
        return reverse[i+1] != 0;
    }
    Item getItem(int i){
        return indexes[i+1];
    }
    int getMaxIndex(){
        assert(count >0);
        return indexes[1]-1;
    }
    int getMaxData(){
        return data[indexes[1]];
    }
    void change(int i , Item item){
        assert(contain(i));
        i++;
        data[i] = item;
//        int j ;
//        for(j = 1 ; j<=count ; j++){
//            if(indexes[j] == i){
//                shiftUp(j);
//                shiftDown(j);
//                break;
//            }
//        }
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }
private:
    void shiftUp(int k){
        while(k >1 && data[indexes[k]] > data[indexes[k/2]]){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k = k/2;
        }
    }
    void shiftDown(int k){
        while(2*k <= count) {
            int i = k*2;
            if(i+1 <= count && data[indexes[i]] < data[indexes[i+1]]) i++;
            if(data[indexes[i]] <= data[indexes[k]]) break;
            swap(indexes[i],indexes[k]);
            reverse[indexes[k]] = k;
            reverse[indexes[i]] = i;
            k = i;
        }
    }
};
#endif //PRACTICE_INDEXMAXHEAP_H
