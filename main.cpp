#include <iostream>
//#include <algorithm>
//#include "Student.h"
#include "SortTestHelper.h"
#include "MaxHeap.h"
#include "IndexMaxHeap.h"
#include "FileOps.h"
#include "BST.h"
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
#include "ReadWeightGraph.h"
#include "WeightedDenseGraph.h"
#include <iomanip>
#include "WeightedSparseGraph.h"
#include "LazyPrim.h"
#include "Prim.h"
#include "Krusk.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
using namespace std;

template<typename T,typename N>
bool comp_more(T t,N n){
    if(t > n)
        return true;
    else
        return false;
};
template<typename T ,typename N>
bool comp_less(T t,N n){
    if(t < n)
        return true;
    else
        return false;

}
//根据索引
template<typename T>
void selectionSort(T arr[] , int n){
    for (int i = 0; i < n; ++i) {
        int min = i ;
        for (int j = i+1; j < n ; ++j) {
            bool flag = comp_more(arr[min],arr[j]);
            if(flag) {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

//根据值
template<typename T>
void selectionSortForData(T arr[] , int n){
    for (int i = 0; i < n; ++i) {
        for(int j = i+1; j<n ; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
template<typename T>
void insertSortByBoundary(T t[] , int l , int r){
    for(int i = l+1 ; i <=r ; i++){
        T tmp = t[i];
        int j;
        for(j = i ; j > l ; j--){
           if(comp_less(tmp,t[j-1]))
               t[j] = t[j-1];
            else
               break;
        }
        t[j] = tmp;
    }
}
//插排
template<typename T>
void insertSort(T t[] , int n){
    for(int i = 1 ; i < n ; i ++){
       for(int j = i ; j > 0 ; j--) {
           if(comp_less(t[j],t[j-1]))
               swap(t[j],t[j-1]);
           else
               break;
       }
    }
}
template<typename T>
void insertSortEnhance(T t[] , int n){
    for(int i = 1 ; i < n ; i++){
        int tmp = t[i];
        int j;
       for( j = i ; j > 0 ; j--) {
           if(comp_less(tmp,t[j-1]))
               t[j] = t[j-1];
           else
               break;
       }
        swap(t[j],tmp);
    }
}

template<typename T>
void shellSort(T arr[], int n){

    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...

    while( h >= 1 ){

        // h-sort the array
        for( int i = h ; i < n ; i ++ ){

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }

        h /= 3;
    }
}
// 合并数据
template<typename T>
void __mergeArray(T t[],int mid ,int l ,int r){
    //创建新数组
    T  aux[r-l+1];
    for(int i = l ; i < r+1 ; i++ ){
        aux[i-l] = t[i];
    }

    int i = l ;
    int j = mid+1;
    for(int k = l ; k < r+1 ; k++){
        if(i > mid){
            t[k] = aux[j-l];
            j++;
        }else if(j > r){
            t[k] = aux[i-l];
            i++;
        }
        else if(comp_less(aux[i-l],aux[j-l])){
            t[k] = aux[i-l];
            i++;
        }
        else{
            t[k] = aux[j-l];
            j++;
        }
    }

}


//归并排序子方法
template<typename T>
void __mergeSort(T t[], int n , int l , int r){
    if(l >= r){
        return ;
    }
    int mid = (l + r)/2;
    __mergeSort(t,n,l,mid);
    __mergeSort(t,n,mid+1,r);
    __mergeArray(t,mid,l,r);
}
//归并排序(BU)
template<typename T>
void mergeSortBU(T t[] , int n){
    for(int sz = 1; sz <= n ; sz += sz){
        for(int i = 0 ; i+sz < n ; i += sz +sz){
            __mergeArray(t,i+sz-1,i,min(i+sz+sz-1,n-1));
        }
    }
}


//归并排序
template<typename T>
void mergeSort(T t[] , int n){
    int l = 0;
    int r = n-1;
    __mergeSort(t,n,l,r);
}
template<typename T>
void __mergeSortForNearlyOrderedArray(T t[] , int l , int r){
    if( l >= r)
        return ;
    int mid = (l+r)/2;
    __mergeSortForNearlyOrderedArray(t,l,mid);
    __mergeSortForNearlyOrderedArray(t,mid+1,r);
    if(t[mid] > t[mid+1])
        __mergeArray(t,mid,l,r);

}
//归并排序(近乎有序数组)
template<typename T>
void mergeSortForNearlyOrderedArray(T t[] , int n){
    int l = 0;
    int r = n-1;
    __mergeSortForNearlyOrderedArray(t , l , r);
}
template<typename T>
int __partition(T t[],int l , int r){
    swap(t[l],t[rand()%(r-l+1)+l]);
    T tmp = t[l];
    int j = l;
    for(int i = l+1; i <= r ; i++){
        if(comp_less(t[i],tmp)){
            swap(t[j+1],t[i]);
            j++;
        }
    }
    swap(t[l],t[j]);
    return j;
}

template<typename T>
void __quickSort(T t[] , int l , int r){
    if(l >=  r){
        return ;
    }
//    if(r-l <=15){
//        insertSortByBoundary(t,l,r);
//        return ;
//    }
    int index = __partition(t,l,r);
    __quickSort(t,l,index);
    __quickSort(t,index+1,r);
}
//快速排序(单路)
template<typename T>
void quickSort(T t[] , int n){
    srand(time(NULL));
    __quickSort(t,0,n-1);
}
template<typename T>
int __partition2(T t[] , int l ,int r){
    swap(t[l],t[rand()%(r-l+1)+l]);
    T tmp = t[l];
    int i = l+1;
    int j = r;
    while(true){
        while(i <= r && comp_less(t[i],tmp)) i++;
        while(j >= l+1 && comp_more(t[j],tmp)) j--;
        if(i>j) break;
        swap(t[i],t[j]);
        i++;
        j--;
    }
    swap(t[j],t[l]);
    return j;
}
template<typename T>
void __quickSort2(T t[],int l , int r){
    if(l >= r){
        return;
    }
    int index = __partition2(t,l,r);
    __quickSort2(t,l,index);
    __quickSort2(t,index+1,r);
}
template<typename T>
void quickSort2(T t[],int n){
    srand(time(NULL));
    __quickSort2(t,0,n-1);
}
template<typename T>
void __quickSort3ways(T t[] , int l ,int r){
    if(l >= r){
        return ;
    }
   swap(t[l],t[rand()%(r-l+1)+l]) ;
    T tmp = t[l];
    int i = l+1;
    int lt = l;
    int gt = r+1;
    while(i < gt){
       if(comp_less(t[i],tmp)){
           swap(t[lt+1],t[i]);
           i++;
           lt++;
       }else if(comp_more(t[i],tmp)){
           swap(t[gt-1],t[i]);
           gt--;
       }else{
           i++;
       }
    }
    swap(t[l],t[lt]);
    __quickSort3ways(t,l,lt-1);
    __quickSort3ways(t,gt,r);
}
template<typename T>
void quickSort3ways(T t[],int n){
    srand(time(NULL));
    __quickSort3ways(t,0,n-1);
}

template<typename T>
void heapSort(T t[],int n ){
    MaxHeap<T> h = MaxHeap<T>(n);
   for(int i = 0 ; i < n ; i++) {
       h.insert(t[i]);
   }
    for(int i = n-1 ; i>=0 ; i --){
        t[i] = h.extract();
    }
}
template<typename T>
void heapSort2(T t[], int n){
    MaxHeap<T> h = MaxHeap<T>(t,n);
    for(int i = n-1; i >=0; i--){
        t[i] = h.extract();
    }
}
template<typename T>
void __shiftDown(T t[], int n , int k){
        while(2*k+1 < n){
            int i = 2*k+1;
            if(i+1 < n && t[i] < t[i+1])
                i++;
            if(t[i] <= t[k])
                break;
            swap(t[k],t[i]);
            k = i;
        }
}
template<typename T>
void heapSortBySingleArray(T t[],int n){
    //heapify
    for(int i = (n-1)/2; i>=0 ; i-- )
        __shiftDown(t,n,i);
    for(int i = n-1; i > 0 ; i--){
        swap(t[0],t[i]);
        __shiftDown(t,i,0);
    }
}
template<typename T>
void heapSortByIndex(T t[],int n){
   IndexMaxHeap<T> imh = IndexMaxHeap<T>(n);
    for(int i = 0 ; i< n ; i++){
        imh.insert(i,t[i]);
    }
    for(int i = n-1; i>=0 ; i--){
        t[i] = imh.extractData();
    }
}
template<typename T>
int binarySearch(T t[],int n,T target){
    int l = 0 , r = n-1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(t[mid] == target)
            return mid;
        else if(t[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}
template<typename T>
int __BSR(T t[],int l,int r,T target){
    if(l > r){
        return -1;
    }
    int mid = l+(r-l)/2;
    if(t[mid] == target){
        return mid;
    }else if(t[mid] < target){
        l = mid+1;
        return __BSR(t,l,r,target);
    }else{
        r = mid -1;
        return __BSR(t,l,r,target);
    }
    return -1;
}
template<typename T>
int BSBYRcoursion(T t[] , int n , T target){
    int l = 0 , r = n-1;
    return __BSR(t , l ,r ,target);
}
int main11() {
//    int a[10] = {10,9,8,7,6,5,4,3,2,1};
//    selectionSort(a,10);
//    float b[4] = {4.4,3.3,2.1,1.2};
////    selectionSortForData(a,10);
//    for(int i = 0 ; i<10; i++){
//        std::cout << a[i] << " ";
//    }
//    cout << endl;
//    selectionSortForData(b,4);
//    for(int i = 0; i<4; i++){
//        cout << b[i] << " ";
//    }
//
//    cout << endl;
//
//    string c[4] = {"D","C","A","B"};
////    selectionSortForData(c,4);
////    for(int i = 0; i<4;i++){
////        cout << c[i] << " " ;
////    }
////    cout << endl;
//
//    selectionSort(c,4);
//    for(int i = 0 ; i < 4; i++){
//        cout << c[i] << " ";
//    }
//    cout << endl;
//    Student s[3] = {{"b",34},{"c",13},{"a",43}};
//    selectionSort(s,3 );
//    for(int i = 0 ; i < 3; i++){
//        cout<< s[i];
//    }
//    cout << endl;
////    std::cout << "Hello, World!" << std::endl;
//    int n = 20 ;
//    int *arr = SortTestHelper::generateRandomArray(n,1,100);
//    selectionSort(arr,n);
//    for(int i = 0 ; i < n ; i++) {
//        cout << arr[i] << " " ;
//    }
//    cout << endl;
//    int n = 30;
//    int *arr = SortTestHelper::generateRandomArray(n,1,100);
//    insertSort(arr,n);
//    insertSortEnhance(arr,n);
//    SortTestHelper::printArray(arr,n);
//    SortTestHelper::printArray(arr,n);
//    SortTestHelper::testSort("insert",insertSortEnhance,arr,n);
//    SortTestHelper::printArray(arr,n);
//    int *arr2 = SortTestHelper::generateNearlyOrderedArray(n,5);
//    SortTestHelper::printArray(arr2,n);
//    SortTestHelper::printArray(arr,n);
//    SortTestHelper::testSort("insert",insertSort,arr,n);
//    SortTestHelper::testSort("insertEnhance",insertSortEnhance,arr2,n);
//    delete[] arr;
    int n = 20 ;
    int *arr = SortTestHelper::generateRandomArray(n,0,100);
//    SortTestHelper::printArray(arr,n);
//    mergeSort(arr,n);
//    mergeSortForNearlyOrderedArray(arr,n);
//    insertSortByBoundary(arr,0,3);
//    mergeSortBU(arr,n);
//    quickSort2(arr,n);
//    int arr1[] = {7,6,5,4,3,2,1};
//    shellSort(arr1,n);
    quickSort3ways(arr,n);
    SortTestHelper::printArray(arr,n);
    delete[] arr;
    return 0;
}
int main12(){
//    MaxHeap<int> h = MaxHeap<int>(100);
//    srand(time(NULL));
//    for(int i = 0 ; i < 15; i++){
//        int k = rand()%100;
//        cout << k << " ";
//        h.insert(k);
//    }
//    cout << endl;
////    h.testPrint();
//    while(!h.isEmpty()){
//         cout <<h.extract()<< " ";
//    }
//    cout << endl;
    int n = 10;
    int *arr = SortTestHelper::generateRandomArray(n,0,100);
//    heapSort(arr,n);
//    heapSort2(arr,n);
//    heapSortBySingleArray(arr,n);
//    int arr2[] = {10,8,3,4,5,6,7,2,9,1};
//    int arr3[] = {11,12,13,14,15};
//
    SortTestHelper::printArray(arr,n);
//    IndexMaxHeap<int> imh = IndexMaxHeap<int>(100);
//    for(int i = 0 ; i< 10 ; i++){
//        imh.insert(i,arr2[i]);
//    }
//    for(int i = 0; i<5 ;i++){
//       cout<< imh.extractData()<< " ";
//    }
//    cout<< endl;
//   for(int i = 0; i<5 ; i++) {
//       imh.insert(i+5,arr3[i]);
//   }
//    while(!imh.isEmpty()){
//        cout << imh.extractData() << " ";
//    }
//    cout << endl;

    heapSortByIndex(arr,n);
    SortTestHelper::printArray(arr,n);
    delete [] arr;
    return 0;
}
//int main(){
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    int index = BSBYRcoursion(arr, 10 ,10);
//    cout << index << endl;
//int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/bible.txt";
//    vector<string> words;
//    if(FileOps::readFile(filename,words)){
//        cout << "There are totally " << words.size() << " words in " << filename << endl;
//
//        cout << endl;
//    }
//    time_t startTime = clock();
//    BST<string, int> bst = BST<string, int>();
//    for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//        int *res = bst.search(*iter);
//        if (res == NULL)
//            bst.insert(*iter, 1);
//        else
//            (*res)++;
//    }
//
//    cout << "'god' : " << *bst.search("god") << endl;
//    time_t endTime = clock();
//    cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//
//    cout << endl;
//}
//int main23(){
//   string filename = "/Users/cztzc520/WorkSpace/practice/testG1.txt";
//    SparseGraph g1(13,false);
//    ReadGraph<SparseGraph> r(g1,filename);
//    g1.show();
//    DenseGraph g2(13,false);
//    ReadGraph<DenseGraph> r2(g2,filename);
//    g2.show();
//    Component<SparseGraph> c1(g1) ;
//    cout << c1.getCcount() << " " << endl;
//}
//int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG2.txt";
//    SparseGraph g1(7,false);
//    ReadGraph<SparseGraph> r(g1,filename);
////    g1.show();
////    cout << endl;
////    Path<SparseGraph> p1(g1,0);
////    cout << "DFS: ";
////    p1.showPath(6);
//    shortestPath<SparseGraph> p1(g1,0);
//    p1.showPath(6);
//    return 0;
//}
//int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG5.txt";
//    int V = 8;
//    cout <<fixed << setprecision(2);

//    WeightedDenseGraph<double> g1 = WeightedDenseGraph<double>(V,false);
//    ReadWeightGraph<WeightedDenseGraph<double>,double> r1(g1,filename);
//    g1.show();
//    cout << endl;
//    WeightedSparseGraph<double> sg1 = WeightedSparseGraph<double>(V,false);
//    ReadWeightGraph<WeightedSparseGraph<double>,double> sr1(sg1,filename);
//    sg1.show();
//    cout << endl;
//}
//int main45(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG5.txt";
//    int V = 8 ;
//    WeightedSparseGraph<double> sg1 = WeightedSparseGraph<double>(V,false);
//    ReadWeightGraph<WeightedSparseGraph<double>,double> sr1(sg1,filename);
//    sg1.show();
//    cout <<endl;
//    cout << sg1.E() << endl;
//    LazyPrim<WeightedSparseGraph<double>,double> lp(sg1);
//    vector<Edge<double>> vec = lp.mstEdges();
//    for(int i = 0 ; i < vec.size() ; i++){
//        cout << vec[i] << endl;
//    }
//    cout << lp.result() << endl;
//}
//int main111(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG5.txt";
//    int V= 8;
//    WeightedSparseGraph<double> sg1 = WeightedSparseGraph<double>(V,false);
//    ReadWeightGraph<WeightedSparseGraph<double>,double>  sr1(sg1,filename);
//    sg1.show();
//    cout << endl;
//    Prim<WeightedSparseGraph<double>,double> p = Prim<WeightedSparseGraph<double>,double>(sg1);
//    vector<Edge<double>> v = p.getMst();
//    for(int i = 0 ; i < v.size(); i++){
//        cout << v[i] << endl;
//    }
//    cout << endl;
//    cout << p.getMstWeight()<< endl;
//}
//int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG5.txt";
//    int V= 8;
//    WeightedSparseGraph<double> sg1 = WeightedSparseGraph<double>(V,false);
//    ReadWeightGraph<WeightedSparseGraph<double>,double>  sr1(sg1,filename);
//    sg1.show();
//    cout << endl;
//    Krusk<WeightedSparseGraph<double>,double> k = Krusk<WeightedSparseGraph<double>,double>(sg1);
//    vector<Edge<double>> v = k.mesEdges();
//    for(int i = 0 ; i < v.size() ; i++){
//        cout << v[i] << endl;
//    }
//    cout << endl;
//    cout << k.result() << endl;
//}
//int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG6.txt";
//    int V = 5;
//    WeightedSparseGraph<int> sg1 = WeightedSparseGraph<int>(V,false);
//    ReadWeightGraph<WeightedSparseGraph<int>,int> sr1(sg1,filename);
//    sg1.show();
//    cout << endl;
//    Dijkstra<WeightedSparseGraph<int>,int> d(sg1,0);
//    for(int i = 1 ; i < V ; i++){
//        cout << "shortest path to " << i << " : " << d.shortestPathTo(i) << endl;
//        d.showPath(i);
//        cout << "---------" <<endl;
//    }
//}
int main(){
//    string filename = "/Users/cztzc520/WorkSpace/practice/testG7.txt";
    string filename = "/Users/cztzc520/WorkSpace/practice/testG110.txt";
    int V = 5;
    WeightedSparseGraph<int > sg1 = WeightedSparseGraph<int>(V,true);
    ReadWeightGraph<WeightedSparseGraph<int>,int> sr1(sg1,filename);
    sg1.show();
    cout << endl;
    BellmanFord<WeightedSparseGraph<int>,int> b(sg1,0);
    if(b.negativeCycle()){
        cout << "contains negative Cycle" << endl;
    }
    else{
        for(int i = 1 ; i < V ; i++){
            cout << "shortest path to " << i << " : " << b.shortestPathTo(i) <<endl;
            b.showPath(i);
            cout << "-------------" <<endl;
        }
    }

}