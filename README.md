# 使用说明  
本项目C++实现基础算法库,重构于Algorithm4th java代码  

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
> 连通集   UnionFind.h      
    
*排序*   
> 初级排序  Insertion.h         
> 归并排序   
> 三向快速排序    Quick3way.h           
> 优先队列  HeapSort.h        
  
*查找*  
> 符号表    
> 二叉树   BinarySearchTree.h   
> 平衡二叉树 RedBlackTree.h     
> 散列表  
  
*图*    
> 无向图   Edge.h  Graph.h  
1.图连通集数量    DFSCC.h  
2.单点最短路径    BFSPath.h  
> 有向图    DiEdge.h    DiGraph.h  
1.环路判断  DFSDirectedCycle.h  
2.拓扑排序  DFSTopo.h  
> 最小生成树 DiEdge.h    EdgeWeightedGraph.h  
1.延时Prim算法  LazyPrimMST.h  
2.即时Prim算法  PrimMST.h    
3.Kruskal算法 KruskalMST.h  
>最短路径   DiEdge.h    EdgeWeightedDiGraph.h  
 1.Dijkstra算法   DijkstraSP.h  
 2.无环图Topo最长路径    TopoLongestPath.h  
 3.Bellman-Ford算法   BellmanFordSP.h  
  
*字符串*  
> 字符串数组排序    Quick3String.h  
> 单词查找树  
> 子串查找  
> 正则表达式  
> 数据压缩  Huffman.h  
    
*背景*    
> 粒子碰撞      
> B-树      
> 后缀数组  SuffixArray.h    
> 网络最大流问题 FlowEdge.h    FlowNetWork.h   FlowFordFulkerson.h    
> 归约问题  
> 不可解性  
  
# 引用  
*Algorithm 4th Edition*    
Author: Robert SedgeWick and Kevin Wayne  
[Website:](https://algs4.cs.princeton.edu/home/) https://algs4.cs.princeton.edu/home/  
