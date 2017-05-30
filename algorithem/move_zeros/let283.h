//
// Created by 田植成 on 17/5/29.
//

#ifndef PRACTICE_LET283_H
#define PRACTICE_LET283_H
#include <iostream>
#include <vector>
using namespace std;
class let283{
public:
    void moveZeros(vector<int> &nums){
        vector<int> nonZerosVec;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i])
                nonZerosVec.push_back(nums[i]);
        }
        for(int i = 0 ; i < nonZerosVec.size(); i++){
            nums[i] = nonZerosVec[i];
        }
        for(int i = nonZerosVec.size(); i < nums.size();i++){
            nums[i] = 0;
        }
    }
};
#endif //PRACTICE_LET283_H
