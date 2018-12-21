#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include"func.h"

/*
堆排序
1.构建有序堆(最大堆)
2.不断取出maxVal,在重新有序化即可
3.直到堆中不存在新元素

note:有序化API
swim 上浮
sink 下沉
*/

//e.g.   1....n序号的数组进行排序
class HeapSort{
public:
    static void hsort(vector<int>& nums){
        int n = nums.size();
        for(int k=n/2;k>=1;k--)
            sink(nums,k,n);
        while(n>1){
            swap(nums,1,n--);        //最大值放在数组后面保存
            sink(nums,1,n);
        }
    }
private:
    //父节点k 不断下沉  直到k大于两个子节点
    static void sink(vector<int>& nums,int k,int n){
        while(2*k<=n){
            //k的子节点2k 2k+1中val较大值为j
            int j=2*k;
            if(j<n && less(nums,j,j+1)) j++;

            if(!less(nums,k,j))
                break;
            swap(nums,k,j);
            k=j;
        }
    }

    //helper function
    //由于数组由0开始作为需要标记
    static void swap(vector<int>&nums,int i,int j){
        int tmp = nums[i-1];
        nums[i-1]=nums[j-1];
        nums[j-1]=tmp;
    }
    static bool less(vector<int>&nums,int i,int j){
        return nums[i-1]<nums[j-1];
    }
};


#endif // HEAPSORT_H_INCLUDED
