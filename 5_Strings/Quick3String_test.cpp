#include"Quick3string.h"
/*
字符串数组排序

LGD or MGD or quick3string 适用情况 P471
当字符串具有公共前缀时 三向快速排序更合适
quick3string 更加通用

note:
剩余15个字符可以使用插入排序
*/


int main(){
    vector<string> a;
    a.push_back("abb2");
    a.push_back("aab1");
    a.push_back("abb6");
    a.push_back("abc5");
    Quick3string* q3s = new Quick3string();
    q3s->vectorStrSort(a);

    for(auto i:a)
        cout<<i<<endl;
}
