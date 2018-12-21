#ifndef FLOWEDGE_H_INCLUDED
#define FLOWEDGE_H_INCLUDED

#include"func.h"
/*
maxFlow最大流问题
相比较无向图Edge,添加两个变量和两个API
*/

class FlowEdge{
private:
    int V;      //边的起点
    int W;
    double capacity;
    double flow;        //实际流量

public:
    FlowEdge():V(0),W(0),capacity(0.0){}
    FlowEdge(int v,int w,double c)
    :V(v),W(w),capacity(c),flow(0.0){}

    //边的剩余容量 传入参数是边的enpoint
    double residualCapacityTo(int vertex){
        if(vertex==V) return flow;      //backward edge
        else if(vertex==W) return capacity-flow;    //forward edge
        return (double)-1;
    }
    //增加流量 传入参数是边的终点
    void addResidualFlowTo(int vertex, double delta){
        if(vertex==V) flow -= delta;    //反向边
        else if(vertex==W) flow+=delta; //正向边
    }

    //其它API
    int from()const {return V;}
    int to()const {return W;}
    double getCapacity()const {return capacity;}
    double getFlow(){return flow;}
    int other(int vertex){
        if(vertex==V) return W;
        if(vertex==W) return V;
        return -1;
    }
    void setFlow(double delta){flow += delta;}
    bool operator==(const FlowEdge& that){return V==that.from() && W==that.to() && capacity==that.getCapacity();}
};

#endif // FLOWEDGE_H_INCLUDED
