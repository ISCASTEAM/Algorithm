#ifndef QUICK3STRING_H_INCLUDED
#define QUICK3STRING_H_INCLUDED

#include"func.h"
/*
字符串数组排序

LGD or MGD or quick3string 适用情况 P471
当字符串具有公共前缀时 三向快速排序更合适
quick3string 更加通用

note:
剩余15个字符可以使用插入排序
*/
class Quick3string{
private:
    int charAt(string s,int d){
        if(d==(int)s.size()) return -1;
        return s[d];
    }
    void swap(vector<string>& a,int i,int j){
        string tmp = a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    //高位优先形式 对dth位置字符三向切分
    void quick3string(vector<string>& a,int lo,int hi,int d){
        if(lo>= hi) return;
        int lt=lo;
        int gt=hi;
        int i=lo+1;
        int v=charAt(a[lo],d);
        while(i<=gt){
            int tmp = charAt(a[i],d);
            if(tmp < v) swap(a,lt++,i++);
            else if(tmp > v) swap(a,i,gt--);
            else i++;
        }

        //a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi].
        quick3string(a,lo,lt-1,d);
        if(v>=0) quick3string(a,lt,gt,d+1);
        quick3string(a,gt+1,hi,d);
    }
public:
    void vectorStrSort(vector<string>& a){
        quick3string(a,0,a.size()-1,0);
    }
};

#endif // QUICK3STRING_H_INCLUDED
