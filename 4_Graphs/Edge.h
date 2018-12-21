#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include"func.h"
/*
有权重的无向图
边
*/

class Edge{
private:
    int v;
    int w;
    double weight;

public:
    Edge()
    :v(0),w(0),weight(0.0){}
    Edge(int v,int w,double weight)
    :v(v),w(w),weight(weight){}
    double getWeight()const {return weight;}

    //either other获取边的两个顶点
    int other(int vTmp){
        if(vTmp==v) return w;
        else return v;
    }
    int either(){return v;}

    //compare重载
    //const成员函数不允许修改类数据 + const对象只能使用const函数
    friend bool operator<(const Edge& a,const Edge& b);
    friend bool operator>(const Edge& a,const Edge& b);
    friend bool operator==(const Edge& a,const Edge& b);

};

bool operator<(const Edge& a,const Edge& b){
    return a.getWeight() < b.getWeight();
}
bool operator>(const Edge& a,const Edge& b){
    return a.getWeight() > b.getWeight();
}
bool operator==(const Edge& a,const Edge& b){
    return a.getWeight() == b.getWeight();
}

#endif // EDGE_H_INCLUDED
