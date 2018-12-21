代码链接:
xxxxxxxxxxxx
  
# 无向图  
Graph.h 实现图的API 邻接链表保存边  
DFS BFS的核心代码  
>应用  
连通性||单点路径 DFS or BFS  
单点最短路径  BFS  
其它:  
1.连通分量个数  DFS         
2.检测环 DFS  
3.双色问题 DFS  
   
# 有向图  
Digraph.h 实现图的API 邻接链表保存边  
>应用  
单点可达性||单点有向路径 DFS orBFS  
单点最短路径 BFS  
其它:  
1.有向环检测  DFS  
2.拓扑排序 DFS+stack  
  
# 最小生成树  
Edge.h 实现有权重边的API  
EdgeWeightedGraph.h 实现图的API  
>prim 普里姆算法  
所有可达边中选择最小边加入Tree(注意跳过失效边)  
1.延时更新   
marked[] 记录顶点已在最小树上  
priority_queue记录有效的可达边  
lazyPrimMST.h  
2.即时更新  
distTo[w]记录w到最小树的距离,跳过Edge.Weight > distTo[w]的顶点  
map_indexMin_queue 记录有效横切边 (常数空间大小)  
  
>kruskal 克鲁斯卡尔算法  
所有边的最小值加入Tree(跳过v,w在同一个连通集的边,即新加入的边不构成环路)  
终止条件:  
所有边都遍历完 或者 MST的边数==G的顶点数目-1  
UnionFind数据结构  
UF判断Edge 的v,w顶点,从而跳过或者union(v,w)  
  
# 最短路径  
加权 有向图  
DiEdge.h 实现有权重,有方向边的API  
EdgeWeightedDigraph.h 实现图的API  
>Dijkstra 算法  
前提:  边的权重必须为正  
由起点开始,按照最小distTo[]顺序,relax松弛所有顶点  
终止条件: map map_indexMin_queue为空  
  
> 拓扑排序  
前提: 无环图  
线性时间解决问题=> 按照topo顺序relax顶点  
拓展: 如何计算最长路径？变换符号 或者取权重相反数  
关键路径定义:  限制优先级问题得到有向图,计算最长路径  
  
> Bellman-Ford 算法  
>基于队列  
前提: 不存在负权重的环  
任意顺序relax顶点,重复V轮  
优化: 一轮意味着执行一次relax？ 只有relax才可能导致distTo的变化  
queue fifo保存即将被放松的顶点  
bool[] 判断顶点是否已经存在于queue  
  
应用: 金融套汇问题  =》 换汇的乘积转换为ln求和 =》寻找负权重的环  ==》获利  
