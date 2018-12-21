#ifndef BELLMANFORDSP_H_INCLUDED
#define BELLMANFORDSP_H_INCLUDED
#include"EdgeWeightedDigraph.h"
/*
定理:
1.distTo[S]=0,其他点无穷大。任意顺序relax所有边
2.1 重复V(顶点个数)轮  则停止
2.2 edgeTo[]存在负权重环  则停止

3.note:优化:
idea: 只有上一轮distTo[]发生变化的顶点指出的边才可能改变其他distTo[]的值,FIFO队列记录这样的顶点
==》 一轮代表执行一次relax(G,v)  ？？
queue1 保存即将被放松的顶点
bool[] 判断顶点是否已经存在于queue1
*/

class BellmanSP{
private:
    vector<double> distTo;
    vector<DiEdge> edgeTo;
    vector<bool> onQ;
    queue<int> fifo;        //待执行relax的顶点
    int relaxCalls;
    void relax(EdgeWeightedDigraph* G,int v){
        for(DiEdge e:G->getadj(v)){
            int w = e.to();
            if(distTo[w] > distTo[v]+e.getWeight()){            //注意符号方向
                distTo[w] = distTo[v]+e.getWeight();
                edgeTo[w]=e;
                //加入queue
                if(onQ[w]==false){
                    fifo.push(w);
                    onQ[w]=true;
                }
            }
            if(relaxCalls% G->getV()==0){
//                findNegativeCycle();  //这里我就不实现了
//                if(hasNCycle) return;
            }
        }
    }

public:
    BellmanSP(EdgeWeightedDigraph* G){
        edgeTo.resize(G->getV());
        distTo.resize(G->getV(),std::numeric_limits<double>::max());
        onQ.resize(G->getV(),false);
        relaxCalls=0;
    }

    void getBellmanSP(EdgeWeightedDigraph* G,int s){
        distTo[s]=0.0;
        onQ[s]=true;
        fifo.push(s);
//        while(!fifo.empty() && !hasNegativeCycle())
        while(!fifo.empty()){
            int v=fifo.front();
            fifo.pop();
            onQ[v]=false;
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


#endif // BELLMANFORDSP_H_INCLUDED
