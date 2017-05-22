//
// Created by 田植成 on 17/5/6.
//

#ifndef PRACTICE_INDEXMINHEAP_H
#define PRACTICE_INDEXMINHEAP_H
#include <cassert>
//最小索引堆
template<typename Item>
class IndexMinHeap{
private:
    int capacity;
    int count;
    Item *data;
    int *indexes;
    int *reverse;
    void shiftDown(int k){
        while(k*2 <= count){
            int j = k*2;
           if(j+1 <= count && data[indexes[j+1]] < data[indexes[j]]) j++;
            if(data[indexes[j]] >= data[indexes[k]]) break;
            swap(indexes[j],indexes[k]);
            reverse[indexes[j]] = k;
            reverse[indexes[k]] = j;
            k = j;
        }
    }
    void shiftUp(int k){
        while(k > 1  && data[indexes[k]] < data[indexes[k/2]]){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k]] = k/2;
            reverse[indexes[k/2]] = k;
            k /= 2;
        }
    }
public:
    IndexMinHeap(int capacity){
        this->capacity = capacity;
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        this->count = 0;
        for(int i = 0 ; i < capacity; i++){
           reverse[i] = 0;
        }
    }
    ~IndexMinHeap(){
        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }
    int getMinIndex(){
        assert(count > 0);
        return indexes[1]-1;
    }
    void change(int index , Item item){
        assert(contain(index));
        index++;
        data[index] = item;
        shiftUp(reverse[index]);
        shiftDown(reverse[index]);
    }
    Item getMinItem(){
        assert(count > 0);
        return data[indexes[1]];
    }
    bool contain(int index){
        return reverse[index+1] != 0;
    }
    Item extract(){
        assert(count > 0);
        Item ret = data[indexes[1]];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    void insert(int index,Item item){
        assert(index > 0 && index +1 <= capacity);
        assert(count+1 <= capacity);
        index ++;
        data[index] = item;
        indexes[count+1] = index;
        reverse[index] = count+1;
        count++;
        shiftUp(count);
    }
    Item getItem(int index){
        assert(contain(index));
        return data[index+1];
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    int extractMinIndex(){
        assert(count > 0);
        int ret = indexes[1] -1;
        swap(indexes[1],indexes[count]);
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }
    void show(){
        for(int i = 1 ; i <= count ; i++){
           cout << indexes[i] << " ";
        }
        cout << endl;
    }

};
#endif //PRACTICE_INDEXMINHEAP_H
