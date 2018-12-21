#include"HeapSort.h"
/*
堆排序
1.构建有序堆(最大堆)
2.不断取出maxVal,在重新有序化即可
3.直到堆中不存在新元素

note:有序化API
swim 上浮
sink 下沉
*/
int main(){
    vector<int> test={5,4,4,4,44,-1,2,7};
    HeapSort::hsort(test);
    for(auto i:test)
        cout<<i<<" "<<endl;
}
