#ifndef QUICK3WAY_H_INCLUDED
#define QUICK3WAY_H_INCLUDED
#include"func.h"
/*
三向快速排序
每次递归将 小数组首元素相同的元素放在相邻位置

优点:
对于大量重复的元素的数组排序 优于传统快排
*/

class Quick3way{
public:
    static void q3sort(vector<int>& nums){
        q3sort(nums,0,(int)nums.size()-1);
    }
    static void q3sort(vector<int>& nums,int lo, int hi){
        if(hi<lo) return;
        int lt=lo,gt=hi,i=lo+1;
        int v=nums[lo];

        while(i<=gt){
            if(nums[i]<v)   std::swap(nums[lt++],nums[i++]);
            else if(nums[i]>v) std::swap(nums[i],nums[gt--]);
            else i++;
        }
        //得到  nums[lo..lt-1] < v=nums[lt..gt] < nums[gt+1...hi]
        q3sort(nums,lo,lt-1);
        q3sort(nums,gt+1,hi);
    }
};


#endif // QUICK3WAY_H_INCLUDED
