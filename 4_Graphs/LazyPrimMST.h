#ifndef LAZYPRIMMST_H_INCLUDED
#define LAZYPRIMMST_H_INCLUDED

#include "EdgeWeightedGraph.h"

/*
延时删除的prim最小生成树
pre: 图是连通
idea: 随机起点 + 可到达边的最小值加入tree
note: 删除无效边(可达边的两个节点都已经标记)
*/

class LazyPrimMST{
private:
    queue<Edge> mst;
    double totalWeight;
    vector<bool> marked;
    priority_queue<Edge,vector<Edge>,std::greater<Edge>> minpq;

public:
    LazyPrimMST(EdgeWeightedGraph* G):totalWeight(0.0){
        marked.resize(G->getV(),false);
    }

    queue<Edge> getMST(EdgeWeightedGraph* G){
        visit(G,0);
        while(!minpq.empty()){
            Edge e = minpq.top();
            minpq.pop();
            int v = e.either();
            int w = e.other(v);
            if(marked[v] && marked[w]) continue;
            //加入最小生成树
            mst.push(e);
            totalWeight += e.getWeight();
            //visit新顶点
            if(!marked[v]) visit(G,v);
            else visit(G,w);
        }
        return mst;
    }

    //节点v所有可达边
    void visit(EdgeWeightedGraph* G,int v){
        marked[v]=true;
        for(Edge e : G->getadj(v)){
            int w = e.other(v);
            if(!marked[w])
                minpq.push(e);
        }
    }

    double getWeight(){ return totalWeight;}

};

#endif // LAZYPRIMMST_H_INCLUDED
