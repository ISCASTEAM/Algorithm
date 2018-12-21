#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "func.h"
class Graph{
private:
    int V;
    int E;
    vector<vector<int>> adj;            //邻接链表
    void addEdge(int v,int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
public:
    Graph(int v):V(v),E(0){adj.resize(v,vector<int>());};
    Graph(string file){
        std::ifstream infile(file);
        string tmp;
        int lineNum = 0;
        while(std::getline(infile,tmp)){
            std::istringstream iss(tmp);
            int v1,v2;
            if(lineNum==0) {iss>>V; adj.resize(V,vector<int>());}
            else if(lineNum==1) iss>>E;
            else {
                iss>>v1>>v2;
                addEdge(v1,v2);
            }
            lineNum++;
        }
    };
    int getV(){return V;}
    int getE(){return E;}
    int degree(int v){return adj[v].size();}
    vector<int> getadj(int v){return adj[v];}

};


#endif // GRAPH_H_INCLUDED
