//
// Created by 田植成 on 17/5/29.
//

#include <iostream>
#include "move_zeros/let283.h"
using namespace std;

int main(){
    vector<int> vec= {0,1,0,3,12};
    let283().moveZeros(vec) ;
    for(int i = 0 ; i < vec.size(); i++){
        cout << vec[i] << " " ;
    }
    cout << endl;
}
