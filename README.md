# 使用说明  
e.g. 以插入排序为例  
```java
//1.添加算法所需头文件
#include"Insertion.h"

int main(){
    vector<int> test={5,4,-1,2,7};
//2. 调用算法
    Insertion::insort(test);
    for(auto i:test)
        cout<<i<<" "<<endl;
}
//3.其他算法使用样例 请查阅对应*_test.cpp文件
```
  
# 算法-头文件对应  
*基础*  
> 背包,队列,栈  
> 连通集                 UnionFind.h    

*排序*
> 初级排序               Insertion.h        Insertion_test.cpp  
> 归并排序
> 三向快速排序            Quick3way.h         Qucik3way_test.cpp  
> 优先队列                HeapSort.h        Heapsort_test.cpp  

*查找*
> 符号表  
> 二叉树                   BinarySearchTree.h BinarySearchTree_test.cpp  
> 平衡二叉树             RedBlackTree.h      RedBlackTree_test.cpp   
