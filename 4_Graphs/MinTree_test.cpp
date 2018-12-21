#include"EdgeWeightedGraph.h"
#include"LazyPrimMST.h"
#include"PrimMST.h"
#include"KruskalMST.h"

int main(){
    EdgeWeightedGraph* G = new EdgeWeightedGraph("./data/tinyEWG.txt");      //tinyDAG无环有向图

    //基础测试
    cout<<G->getE()<<endl;
    cout<<G->getV()<<endl;
    cout<<G->degree(0)<<endl;

    //最小生成树测试
    //1.延时删除Prim算法
    cout<<endl;
    LazyPrimMST* mst = new LazyPrimMST(G);
    queue<Edge> res = mst->getMST(G);
    while(!res.empty()){
        Edge e = res.front();
        res.pop();
        cout<<e.either()<<"-"<<e.other(e.either())<<" "<<e.getWeight()<<endl;
    }
    cout<<"min total_weight = "<<mst->getWeight()<<endl;
    cout<<endl;


    //2.即时删除Prim算法
    PrimMST* pmst = new PrimMST(G);
    vector<Edge> res2 = pmst->getMST(G);
    for(Edge e:res2){
        cout<<e.either()<<"-"<<e.other(e.either())<<" "<<e.getWeight()<<endl;
    }
    cout<<"min total_weight = "<<pmst->getWeight()<<endl;
    cout<<endl;


    //3.克鲁斯卡尔算法
    KruskalMST* kmst = new KruskalMST(G);
    queue<Edge> res3 = kmst->getRes();
    while(!res3.empty()){
        Edge e = res3.front();
        res3.pop();
        cout<<e.either()<<"-"<<e.other(e.either())<<" "<<e.getWeight()<<endl;
    }
    cout<<"min total_weight = "<<kmst->getWeight()<<endl;



    return 0;
}
