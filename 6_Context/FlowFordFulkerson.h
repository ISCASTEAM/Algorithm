#ifndef FLOWFORDFULKERSON_H_INCLUDED
#define FLOWFORDFULKERSON_H_INCLUDED
#include"FlowNetwork.h"
/*
Ford-Fulkerson方法
1.BFS判断剩余网络中是否存在
2.直到增广路径不存在

增广路径: 能从s到达t,路径上正向边不饱和而且反向边非零
*/

class FlowFordFulkerson{
private:
    vector<bool> marked;
    vector<FlowEdge> edgeTo;
    double totalVal;
    //BFS判断s到t是否存在增广路径
    bool hasAugmentingPath(FlowNetwork*G,int s,int t){
        edgeTo.assign(G->getV(),FlowEdge());
        marked.assign(G->getV(),false);
        queue<int> pq;
        pq.push(s);
        marked[s]=true;

        while(!pq.empty() && !marked[t]){
            int v = pq.front();
            pq.pop();
            for(FlowEdge e : G->getadj(v)){
                int w = e.other(v);
                //v->w边存在剩余容量则是非饱和边
                if(e.residualCapacityTo(w)>0 && !marked[w]){
                    edgeTo[w]=e;
                    marked[w]=true;
                    pq.push(w);
                }
            }
        }
        return marked[t];       //增广路径能否遍历到t
    }

public:
    FlowFordFulkerson(FlowNetwork* G){
        marked.resize(G->getV(),false);
        edgeTo.resize(G->getV());
        totalVal=0.0;
    }
    void calMaxFlow(FlowNetwork* G,int s,int t){
        totalVal = 0.0;
        while(hasAugmentingPath(G,s,t)){
            double delta = std::numeric_limits<double>::max();
            //edgeTo增广路径中的最小可增加的流量
            for(int v=t;v!=s;v=edgeTo[v].other(v)){
                delta = std::min(delta,edgeTo[v].residualCapacityTo(v));
            }
            //对于路径上每条边增加流量
            for(int v=t;v!=s;v=edgeTo[v].other(v)){
//                edgeTo[v].addResidualFlowTo(v,delta);         //由于java里面传递引用,需要C++稍作变化
                G->addResidualFlowTo(edgeTo[v],v,delta);
            }

            totalVal += delta;
        }
    }
    double getMaxFlow(){return totalVal;}
};

#endif // FLOWFORDFULKERSON_H_INCLUDED
