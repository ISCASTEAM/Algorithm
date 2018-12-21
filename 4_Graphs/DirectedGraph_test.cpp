#include"Digraph.h"
#include"DFSDirectedCycle.h"
#include"DFSTopo.h"

int main(){
    Digraph* G = new Digraph("./data/tinyDAG.txt");      //tinyDAG无环有向图

    //基础测试
    cout<<G->getE()<<endl;
    cout<<G->getV()<<endl;
    cout<<G->degree(0)<<endl;

    //单点路径问题(DFS判断存在性 BFS求最短)

    //有向图是否存在环？
    cout<<endl;
    DFSDirectedCycle* dfsDC = new DFSDirectedCycle(G);
    cout<<true<<endl;
    cout<<dfsDC->hasCycle(G)<<endl;

    //顶点的三种遍历顺序
    //topological拓扑排序 解决优先级问题
    //思路:  DFS+ revesePost顺序 证明P376  + P388 BFS
    cout<<endl;
    DFSTopo* dfsTopo = new DFSTopo(G);
    for(auto i:dfsTopo->getTopo(G))
        cout<<i<<" ";


    //思考题:
    //P380 强连通分量 Kosaraju算法
    //总结P385
    return 0;
}
