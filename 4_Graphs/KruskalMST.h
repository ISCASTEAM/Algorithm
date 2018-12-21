#ifndef KRUSKALMST_H_INCLUDED
#define KRUSKALMST_H_INCLUDED
#include"EdgeWeightedGraph.h"
#include"UnionFind.h"
/*
克鲁斯卡尔
idea: 不断从所有边中寻找最小值,要求不能构成环路(不在同一个连通集)
note: 相同于不断合并不同的连通分量
note: unionFind数据结构
*/

class KruskalMST{
private:
    queue<Edge> result;
    double totalWeight;
    priority_queue<Edge,vector<Edge>,std::greater<Edge>> minpq;     //初始加入所有边

public:
    KruskalMST(EdgeWeightedGraph* G)
    :totalWeight(0.0){
        UnionFind* uf = new UnionFind(G->getV());
        for(Edge e:G->getAllEdges())
            minpq.push(e);

        //生成MST
        while(!minpq.empty() && result.size()<G->getV()-1){
            Edge e = minpq.top();
            minpq.pop();
            int v=e.either(); int w=e.other(v);

            //已经在同一个连通集合
            if(uf->connected(v,w)) continue;
            else{
                uf->unionV(v,w);
                result.push(e);
                totalWeight += e.getWeight();
            }
        }
    }
    queue<Edge> getRes(){ return result;}
    double getWeight(){return totalWeight;}

};

#endif // KRUSKALMST_H_INCLUDED
