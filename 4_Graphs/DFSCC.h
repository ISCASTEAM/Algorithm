#ifndef DFSCC_H_INCLUDED
#define DFSCC_H_INCLUDED

/*TODO   判断图存在多少个连通分量
思路:
所有未标记的节点 执行一遍完整DFS遍历
DFS代表从某一个节点出发 能到达的所有节点都会被标记
*/
#include"Graph.h"

class DFSCC{
private:
    vector<bool> marked;
    vector<int> id;     //id[v]表示所在连通集的编号
public:
    int setCount = 0;
    DFSCC(Graph* G){
        marked.reserve(G->getV());
        id.reserve(G->getV());
    }

    void dfs(Graph* G, int v){
        marked[v] = true;
        id[v]=setCount;             //在DFS代码上添加
        for(int w : G->getadj(v)){
            if(!marked[w])
                dfs(G,w);
        }

    }
    int getSetNum(Graph* G){
        for(int v=0;v<G->getV();v++){
            if(!marked[v]){
                dfs(G,v);
                setCount++;
            }
        }
        return setCount;
    }
};

#endif // DFSCC_H_INCLUDED
