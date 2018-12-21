#ifndef INSERTION_H_INCLUDED
#define INSERTION_H_INCLUDED
#include"func.h"
class Insertion{
    //class 默认private
public:
    static void insort(vector<int>& nums){
        int len = nums.size();
        for(int i=1;i<len;i++){
            for(int j=i; j>0&&nums[j]<nums[j-1]; j--)
                std::swap(nums[j],nums[j-1]);
        }
    }
};


#endif // INSERTION_H_INCLUDED
