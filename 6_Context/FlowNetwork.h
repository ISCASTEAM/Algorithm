#ifndef FLOWNETWORK_H_INCLUDED
#define FLOWNETWORK_H_INCLUDED
#include"FlowEdge.h"
/*
由FlowEdge构成的图 和无向图的结构相同
*/

class FlowNetwork{
private:
    int V;      //顶点个数
    int E;      //边的个数
    vector<vector<FlowEdge>> adj;
    void addEdge(int v,int w,double capacity){
        adj[v].push_back(FlowEdge(v,w,capacity));
        adj[w].push_back(FlowEdge(v,w,capacity));
    }

public:
    FlowNetwork(int v,int e)
    :V(v),E(e){
        adj.resize(v,vector<FlowEdge>());
    }
    FlowNetwork(string  file){
        std::ifstream infile(file);
        string tmp;
        int lineNum = 0;
        while(std::getline(infile,tmp)){
            std::istringstream iss(tmp);
            int v1,v2;
            double capacity;
            if(lineNum==0) {iss>>V; adj.resize(V,vector<FlowEdge>());}
            else if(lineNum==1) iss>>E;
            else {
                iss>>v1>>v2>>capacity;
//                cout<<v1<<" "<<v2<<" "<<capacity<<" "<<endl;
                addEdge(v1,v2,capacity);
            }
            lineNum++;
        }
    }

    //其他API
    int getV(){return V;}
    int getE(){return E;}
    vector<FlowEdge> getadj(int v){return adj[v];}
    void addResidualFlowTo(FlowEdge& e,int v,double delta){     //传入参数V是边的endPoint
        for(vector<FlowEdge>& i:adj){
            for(FlowEdge& j:i){
                if(j==e){
                    if(j.from()==v) j.setFlow(-delta);        //backward Edge
                    else if(j.to()==v) j.setFlow(delta);     //forward Edge
                }
            }
        }
    }
};


#endif // FLOWNETWORK_H_INCLUDED
