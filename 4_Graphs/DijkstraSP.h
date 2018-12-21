#ifndef DIJKSTRASP_H_INCLUDED
#define DIJKSTRASP_H_INCLUDED
#include"DiEdge.h"
#include"EdgeWeightedDigraph.h"
/*
非负权重 有向图
类似于即时的prim算法
1.将dist[Start]=0,其他distTo[]初始化为无穷大
2.重复将distTo[]中最小非树节点V =>relax(G,V)
3.直到所有顶点都在树或所有非树顶点distTo无限大
*/

class DijkstraSP{
private:
    vector<DiEdge> edgeTo;
    vector<double> distTo;
    map<int,double> minPQ;      //非树节点vertex和distTo
    int getPQmin(){
        double minval = std::numeric_limits<double>::max();
        int key = 0;
        for(map<int,double>::iterator iter=minPQ.begin();iter!=minPQ.end();iter++){
            if(iter->second < minval){
                key = iter->first;
                minval = iter->second;
            }
        }
        return key;
    }
    void erasePQ(int v){
        map<int,double>::iterator it = minPQ.find(v);
        minPQ.erase(it);
    }

    //relax 松弛API
    void relax(EdgeWeightedDigraph* G,int v){
        for(DiEdge e:G->getadj(v)){
            int v=e.from();
            int w=e.to();
            //w到s的距离更新
            if(distTo[v]+e.getWeight() < distTo[w]){
                distTo[w]= distTo[v]+e.getWeight();
                edgeTo[w]=e;
                minPQ[w]=distTo[w];     //update or insert
            }
        }
    }

public:
    DijkstraSP(EdgeWeightedDigraph* G,int s){
        edgeTo.resize(G->getV());
        distTo.resize(G->getV(),std::numeric_limits<double>::max());
    }
    void getSP(EdgeWeightedDigraph* G,int s){
        distTo[s]=0.0;
        minPQ[s]=distTo[s];
        while(!minPQ.empty()){
            int v = getPQmin();
            erasePQ(v);
            relax(G,v);
        }
    }

    //其他API
    double getdistTo(int v){return distTo[v];}
    bool hasPathTo(int v){return distTo[v]<std::numeric_limits<double>::max();}
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
#endif // DIJKSTRASP_H_INCLUDED
