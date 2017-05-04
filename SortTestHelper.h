//
// Created by 田植成 on 17/4/10.
//

#ifndef UNTITLED_SORTTESTHELPER_H
#define UNTITLED_SORTTESTHELPER_H
#include <iostream>
#include <cassert>
using namespace std;
 namespace SortTestHelper{
    int* generateRandomArray(int n , int rangL, int rangR){
        assert(rangL < rangR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0 ; i < n ; i++){
            arr[i] = rand() %(rangL-rangR +1 ) + rangL;
        }
        return arr;
    }

     //生成近乎有序数组
    int * generateNearlyOrderedArray(int n , int swapTime){
       int * arr = new int[n] ;
        for(int i = 0 ; i < n ; i++){
            arr[i] = i;
        }
       srand(time(NULL));
        for(int i = 0 ; i < swapTime ; i++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx] , arr[posy]);
        }
        return arr;
    }
    template<typename T>
    void printArray(T t[] , int n ){
        for( int i = 0 ; i < n ; i++){
            cout << t[i] << " ";
        }
        cout << endl;
    }
    template<typename T>
    bool isSorted(T t[],int n ){
        for(int i = 0 ; i < n-1 ; i++){
            if(t[i] > t[i+1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(const string &name, void(*sort)(T[] , int ),T t[],int n ) {
        clock_t startTime = clock();
        sort(t, n);
        clock_t endTime = clock();
        assert(isSorted(t,n));
        cout << name << " : " <<
        double(endTime
        -startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

     //整形数组拷贝
     int* copyIntArray(int arr[] , int n){
         int* n_arr = new int[n];
         copy(arr,arr+n,n_arr);
         return n_arr;
     }
}
#endif //UNTITLED_SORTTESTHELPER_H
