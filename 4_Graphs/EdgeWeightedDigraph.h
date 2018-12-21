#ifndef EDGEWEIGHTEDDIGRAPH_H_INCLUDED
#define EDGEWEIGHTEDDIGRAPH_H_INCLUDED
#include"DiEdge.h"
/*
加权 有向图的定义
*/
class EdgeWeightedDigraph{
private:
    int V;
    int E;
    vector<vector<DiEdge>> adj;
    void addEdge(int v,int w,double weight){
        DiEdge tmp(v,w,weight);
        adj[v].push_back(tmp);
    }
public:
    EdgeWeightedDigraph(string file){
        std::ifstream infile(file);
        string tmp;
        int lineNum = 0;
        while(std::getline(infile,tmp)){
            std::istringstream iss(tmp);
            int v1,v2;
            double weight;
            if(lineNum==0) {iss>>V; adj.resize(V,vector<DiEdge>());}
            else if(lineNum==1) iss>>E;
            else {
                iss>>v1>>v2>>weight;
                addEdge(v1,v2,weight);
            }
            lineNum++;
        }
    }
    int getV(){return V;}
    int getE(){return E;}
    int degree(int v){return adj[v].size();}
    vector<DiEdge> getadj(int v){ return adj[v];}
    set<DiEdge> getAllEdges(){
        set<DiEdge> allEdges;
        for(vector<DiEdge> tmp:adj){
            for(DiEdge e:tmp){
                allEdges.insert(e);
            }
        }
        return allEdges;
    }
};


#endif // EDGEWEIGHTEDDIGRAPH_H_INCLUDED
