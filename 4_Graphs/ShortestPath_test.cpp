#include"DijkstraSP.h"
#include"TopoLongestPath.h"
#include"BellmanFordSP.h"

int main(){
    EdgeWeightedDigraph* G = new EdgeWeightedDigraph("./data/tinyEWD.txt");      //tinyDAG无环有向图

    //基础测试
    cout<<G->getE()<<endl;
    cout<<G->getV()<<endl;
    cout<<G->degree(0)<<endl;

    //Dijkstra shortest path测试
    cout<<endl;
    int startV=0;
    int endV = 6;
    DijkstraSP* dSP = new DijkstraSP(G,startV);
    dSP->getSP(G,startV);
    cout<<"hasPathTo endVertex="<<endV<<" is "<<(bool)dSP->hasPathTo(endV)<<endl;
    double totalW=0.0;
    for(DiEdge e:dSP->pathTo(endV)){
        cout<<e.from()<<"-"<<e.to()<<" "<<e.getWeight()<<endl;
        totalW += e.getWeight();
    }
    cout<<"from 0 to 6, shortestpath="<<totalW<<endl;
    cout<<endl;


    //无环图 LongestPath测试
    startV=5;
    endV = 2;
    G = new EdgeWeightedDigraph("./data/tinyEWDAG.txt");
    TopoLP* topoLP = new TopoLP(G);
    topoLP->getTopoLP(G,startV);
    totalW=0.0;
    for(DiEdge e:topoLP->pathTo(endV)){
        cout<<e.from()<<"-"<<e.to()<<" "<<e.getWeight()<<endl;
        totalW += e.getWeight();
    }
    cout<<"from 5 to 2, longestpath="<<totalW<<endl;
    //思考:
    //应用: 限制优先级问题
    //idea: 将限制条件转化为有向图 P431  => 加权有向图最长路径


    //一般性问题  Bellman-Ford
    //不存在权重值之和为负的还 有向图
    cout<<endl;
    startV=0;
    endV = 3;
    G = new EdgeWeightedDigraph("./data/tinyEWDnc.txt");
    BellmanSP* bSP = new BellmanSP(G);
    bSP->getBellmanSP(G,startV);
    totalW=0.0;
    for(DiEdge e:bSP->pathTo(endV)){
        cout<<e.from()<<"-"<<e.to()<<" "<<e.getWeight()<<endl;
        totalW += e.getWeight();
    }
    cout<<"from 0 to 1, longestpath="<<totalW<<endl;

    //思考:
    //金融套汇问题  ==》 转化为寻找负权重之和的环  P444

}
