#ifndef TOPOSHORTESTPATH_H_INCLUDED
#define TOPOSHORTESTPATH_H_INCLUDED
#include"EdgeWeightedDigraph.h"
#include"DFSTopo.h"

/*
Dijkstra 非负权重的有向图单源最短路径

TopoSp 无环有向图
1.线性时间找最短路径 + Weight可以为负 + 变换权重正负号寻找最长路径
idea:
按照topological顺序relax所有顶点
证明 P426

note: 1.将weight全部取相反数  或者2.交换所有大小判断符号
*/

class TopoLP{
private:
    vector<double> distTo;
    vector<DiEdge> edgeTo;
    void relax(EdgeWeightedDigraph* G,int v){
        for(DiEdge e:G->getadj(v)){
            int w = e.to();
            if(distTo[w] < distTo[v]+e.getWeight()){            //注意符号方向
                distTo[w] = distTo[v]+e.getWeight();
                edgeTo[w]=e;
            }
        }
    }

public:
    TopoLP(EdgeWeightedDigraph* G){
        edgeTo.resize(G->getV());
        distTo.resize(G->getV(),std::numeric_limits<double>::min());        //double最小值
    }
    void getTopoLP(EdgeWeightedDigraph* G,int s){
        distTo[s]=0.0;
        DFSTopo* topo_order = new DFSTopo(G);
        for(int v:topo_order->getTopo(G))
            relax(G,v);
    }

    //其他API
    double getdistTo(int v){return distTo[v];}
    bool hasPathTo(int v){return distTo[v] > std::numeric_limits<double>::min();}
    vector<DiEdge> pathTo(int v){
        vector<DiEdge> pathRes;
        stack<DiEdge> path;
        if(!hasPathTo(v)) return vector<DiEdge>();
        for(DiEdge e=edgeTo[v]; e!=DiEdge();e=edgeTo[e.from()])
            path.push(e);
        while(!path.empty()){
            DiEdge e = path.top();
            path.pop();
            pathRes.push_back(e);
        }
        return pathRes;  //未包含起点
    }
};

#endif // TOPOSHORTESTPATH_H_INCLUDED
