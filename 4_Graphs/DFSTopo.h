#ifndef DFSTOPO_H_INCLUDED
#define DFSTOPO_H_INCLUDED
#include"Digraph.h"
#include"EdgeWeightedDigraph.h"
/*
拓扑排序  DFS+一行代码

BFS是将入度为零的先加入queue
*/

class DFSTopo{
private:
    vector<bool> marked;
    stack<int> reversePost;

public:
    DFSTopo(Digraph* G){
        marked.resize(G->getV(),false);
    }

    vector<int> getTopo(Digraph* G){
        for(int v=0;v<G->getV();v++){     //可能是多连通分量图
            if(!marked[v])
                dfs(G,v);
        }

        vector<int> res;
        while(!reversePost.empty()){
            res.push_back(reversePost.top());
            reversePost.pop();
        }
        return res;
    }

    void dfs(Digraph* G,int v){
        marked[v] = true;
        for(int w:G->getadj(v)){
            if(!marked[w])
                dfs(G,w);
        }
        reversePost.push(v);
    }

//****************************关于加权Weighted 有向图的重载
    DFSTopo(EdgeWeightedDigraph* G){
        marked.resize(G->getV(),false);
    }

    vector<int> getTopo(EdgeWeightedDigraph* G){
        for(int v=0;v<G->getV();v++){     //可能是多连通分量图
            if(!marked[v])
                dfs(G,v);
        }

        vector<int> res;
        while(!reversePost.empty()){
            res.push_back(reversePost.top());
            reversePost.pop();
        }
        return res;
    }

    void dfs(EdgeWeightedDigraph* G,int v){
        marked[v] = true;
        for(DiEdge e:G->getadj(v)){
            if(!marked[e.to()])
                dfs(G,e.to());
        }
        reversePost.push(v);
    }
};
#endif // DFSTOPO_H_INCLUDED
