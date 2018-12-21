#include"Graph.h"
#include"DFSCC.h"
#include"BFSPath.h"

int initG(){
    std::ifstream infile("./data/tinyG.txt");
    string tmp;
    int E,V;
    int lineNum = 0;
    while(std::getline(infile,tmp)){
        std::istringstream iss(tmp);
        int v1,v2;
        if(lineNum==0) iss>>E;
        else if(lineNum==1) iss>>V;
        else iss>>v1>>v2;
        lineNum++;
    }
}
int main(){
    Graph* G = new Graph("./data/tinyG.txt");

    //基础测试
    cout<<G->getE()<<endl;
    cout<<G->getV()<<endl;
    cout<<G->degree(0)<<endl;

    //DFS得到图中连通集的数量
    cout<<endl;
    DFSCC* cc = new DFSCC(G);
    cout<<cc->getSetNum(G)<<endl;   //3个连通分量
    //DFS思考:
    //判断是否存在从节点V到节点W的路径？
    //判断图是否存在环？
    //判断图是否可以只用两种颜色标记？
    //P599 两点之间最长路径 DFS变型



    //BFS得到最短单点路径问题
    cout<<endl;
    BFSPath* bfs = new BFSPath(G);
    stack<int> path;
    bfs->bfs(G,0);
    bfs->pathTo(path,0,3);
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }

    return 0;
}
