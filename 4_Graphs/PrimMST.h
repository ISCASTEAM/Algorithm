#ifndef PRIMMST_H_INCLUDED
#define PRIMMST_H_INCLUDED

#include "EdgeWeightedGraph.h"

/*
即时删除的prim最小生成树
idea: 随机起点 + 可到达边的最小值加入tree
note:
1.lazy模式 会将Edge都加入queue ==》 priority queue
2.即时 在加入queue进行判断: 无效边+非最小边 被拒绝
3.数据结构:
edgeTo[w] w距离tree最近的edge 或者NULL
dist[w]=edgeTo[w].weight
indexQueue 用map<w,weight>实现,保存待遍历的横切边

相比较于Lazy模式  indexPQ中的可达边数量是常数级别
*/

class PrimMST{
private:
    vector<Edge> edgeTo;
    vector<double> distTo;
    vector<bool> marked;
    map<int,double> indexPQ;
    double totalWeight;

    //indexPQ min_val对应的顶点
    int getPQmin(){
        double minval = std::numeric_limits<double>::max();
        int key = 0;
        for(map<int,double>::iterator iter=indexPQ.begin();iter!=indexPQ.end();iter++){
            if(iter->second < minval){
                key = iter->first;
                minval = iter->second;
            }
        }
        return key;
    }
    void erasePQ(int v){
        map<int,double>::iterator it = indexPQ.find(v);
        indexPQ.erase(it);
    }

public:
    PrimMST(EdgeWeightedGraph* G):totalWeight(0.0){
        edgeTo.resize(G->getV());           //reserve并不会真实开辟空间
        distTo.resize(G->getV(),std::numeric_limits<double>::max());
        marked.resize(G->getV(),false);
    }

    vector<Edge> getMST(EdgeWeightedGraph* G){
        distTo[0]=0.0;
        indexPQ[0]=0.0;
        while(!indexPQ.empty()){
            int v = getPQmin();     //相比较于Lazy模式  indexPQ中的可达边数量是常数级别
            totalWeight += indexPQ[v];
            erasePQ(v);
            visit(G,v);     //最近节点加入树中
        }
        return edgeTo;
    }

    //节点v所有可达边
    void visit(EdgeWeightedGraph* G,int v){
        marked[v]=true;
        for(Edge e: G->getadj(v)){
            int w = e.other(v);
            if(marked[w]) continue;
            else if(e.getWeight() >= distTo[w]) continue;
            else{
                edgeTo[w] = e;
//                cout<<e.either()<<"-"<<e.other(e.either())<<" "<<e.getWeight()<<endl;
                distTo[w] = e.getWeight();
                indexPQ[w]=distTo[w];           //map中不存在w 则会添加
            }
        }
    }

    double getWeight(){ return totalWeight;}
    vector<Edge> getEdgeTo(){ return edgeTo;}

};

#endif // PRIMMST_H_INCLUDED
