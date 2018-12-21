#ifndef DFSDIRECTEDCYCLE_H_INCLUDED
#define DFSDIRECTEDCYCLE_H_INCLUDED
#include"Digraph.h"
/*
有向图 判断是否存在有向环

不存在环路 topological order算法的前提
*/

class DFSDirectedCycle{
private:
    vector<bool> marked;
    vector<int> edgeTo;
    vector<bool> onstack;
    stack<int> cycle;

public:
    DFSDirectedCycle(Digraph* G){
        marked.resize(G->getV(),false);
        edgeTo.reserve(G->getV());
        onstack.resize(G->getV(),false);
    }
    bool hasCycle(Digraph* G){
        for(int v=0;v<G->getV();v++){
           if(!marked[v] && cycle.empty())
                dfs(G,v);
        }
        if(cycle.empty()) return false;
        else return true;
    }
    void dfs(Digraph* G,int v){
        marked[v]=true;
        onstack[v]=true;

        //正常的dfs流程
        for(int w:G->getadj(v)){
            if(!cycle.empty()) return;
            else if(!marked[w]){
                edgeTo[w]=v;
                dfs(G,w);
            }
            //判断是否构成环路
            else if(onstack[w]){
                for(int tmp=v;tmp!=w;tmp=edgeTo[tmp])
                    cycle.push(tmp);
                cycle.push(w); //子节点w是环的终点
            }
        }

        onstack[v]=false;
    }
};


#endif // DFSDIRECTEDCYCLE_H_INCLUDED
