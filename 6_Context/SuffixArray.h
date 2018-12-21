#ifndef SUFFIXARRAY_H_INCLUDED
#define SUFFIXARRAY_H_INCLUDED
#include"func.h"
#include"Quick3String.h"
//连续字符 子字符串
//非连续字符 子序列

/*
问题: string至少重复两次的最长子串
后缀数组
idea: sorted 后缀数组最长重复子串在相邻位置

API:
i 已排序的后缀数组的元素序号
1.select(i) 已排序的后缀数组第i元素
2.index(i) select(i)在原有的后缀数组序号
3.lcp(i) select(i)和select(i-1)的最长公共前缀长度
4.rank(string key) 小于key的字符串的数量
*/

class SuffixArray{
private:
    vector<string> suffixes;
    int N;
    int lcp(string str1,string str2){       //两个字符串的最长公共前缀
        int len = std::min(str1.size(),str2.size());
        for(int i=0;i<len;i++)
            if(str1[i]!=str2[i])
                return i;
        return len;
    }
public:
    //sorted 后缀数组
    SuffixArray(string str){
        N = str.size();
        suffixes.resize(N,"");
        for(int i=0;i<N;i++)
            suffixes[i]=str.substr(i);  //substr(i,N-i);
        Quick3string* q3s = new Quick3string();
        q3s->vectorStrSort(suffixes);
    }
    int lcp(int i){
        return lcp(suffixes[i],suffixes[i-1]);
    }
    //不断比较相邻的两个字符串的公共前缀长度
    string getLRS(){
        string longReaptedStr="";
        for(int i=1;i<(int)suffixes.size();i++){
            int len = lcp(i);
            //更新 lrs
            if((int)longReaptedStr.size() < len)
                longReaptedStr = suffixes[i].substr(0,len);
        }
        return longReaptedStr;
    }

    int rankSuffix(string key){
        //二分查找
        int lo=0;
        int hi=N-1;
        while(lo <= hi){
            int mid=lo+(hi-lo)/2;
            if(key == suffixes[mid])
                return mid;
            else if(key < suffixes[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }
        return lo;
    }

    //其它API
    vector<string> getSuffix(){ return suffixes;}
    int length(){return N;}
    string select(int i){return suffixes[i];}
    int index(int i){return N-select(i).size();}

};

#endif // SUFFIXARRAY_H_INCLUDED
