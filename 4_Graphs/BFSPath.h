#ifndef BFSPATH_H_INCLUDED
#define BFSPATH_H_INCLUDED

#include"Graph.h"
class BFSPath{
private:
    vector<bool> marked;
    vector<int> edgeto;     //父节点
public:
    BFSPath(Graph* G){
        marked.resize(G->getV(),false);
        edgeto.reserve(G->getV());
    }

    void bfs(Graph* G, int s){
        /*
        input:  图结构Graph, 起始点S
        */
        queue<int> q;
        marked[s] = true;
        q.push(s);

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int w:G->getadj(v)){
                if(!marked[w]){
                    edgeto[w] = v;          //区别于BFS代码
                    marked[w]=true;
                    q.push(w);
                }
            }
        }
    }
    //从起始点S到节点V的路径
    void pathTo(stack<int>& path,int s,int v){
        for(int i=v;i!=s;i=edgeto[i])
            path.push(i);
        path.push(s);
    }

};

#endif // BFSPATH_H_INCLUDED
