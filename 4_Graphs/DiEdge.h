#ifndef DIEDGE_H_INCLUDED
#define DIEDGE_H_INCLUDED
#include "func.h"
/*
区别于无向边,v->w == v,w具有固定的含义
API from v to w
*/
class DiEdge{
private:
    int v;
    int w;
    double weight;

public:
    DiEdge()
    :v(0),w(0),weight(0.0){}
    DiEdge(int v,int w,double weight)
    :v(v),w(w),weight(weight){}
    int from()const { return v;}
    int to()const {return w;}
    double getWeight()const {return weight;}        //const成员函数 不改变类对象的内部数据

    friend bool operator<(const DiEdge& a,const DiEdge& b);
    friend bool operator>(const DiEdge& a,const DiEdge& b);
    friend bool operator==(const DiEdge& a,const DiEdge& b);
    friend bool operator!=(const DiEdge& a,const DiEdge& b);

};

bool operator<(const DiEdge& a,const DiEdge& b){
    return a.getWeight() < b.getWeight();
}
bool operator>(const DiEdge& a,const DiEdge& b){
    return a.getWeight() > b.getWeight();
}
bool operator==(const DiEdge& a,const DiEdge& b){
    return a.getWeight()==b.getWeight() && a.from()==b.from() && a.to()==b.to();
}

bool operator!=(const DiEdge& a,const DiEdge& b){
    return a.getWeight()!=b.getWeight() || a.from()!=b.from() || a.to()!=b.to();
}

#endif // DIEDGE_H_INCLUDED
