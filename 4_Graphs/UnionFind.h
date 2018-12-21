#ifndef UNIONFIND_H_INCLUDED
#define UNIONFIND_H_INCLUDED
#include"func.h"
/*
实现weighted union find
小树加入大树 从而减少树的高度
*/

class UnionFind{
private:
    vector<int> parent;
    vector<int> sz;
    int unionCount;
public:
    UnionFind(int vertexNum)
    :unionCount(vertexNum){
        parent.resize(vertexNum);
        sz.resize(vertexNum,1);
        for(int i=0;i<vertexNum;i++)
            parent[i]=i;
    }
    int getUnionNum(){return unionCount;}

    //API= find,union,connected
    bool connected(int v,int w){
        return findRoot(v) == findRoot(w);
    }
    int findRoot(int p){
        while(p != parent[p])
            p=parent[p];
        return p;
    }
    void unionV(int v,int w){
        int i=findRoot(v);
        int j=findRoot(w);
        if(i==j) return;
        if(sz[i]<sz[j]){parent[i]=j; sz[j]+=sz[i];}
        else{parent[j]=i; sz[i]+=sz[j];}
        unionCount--;
    }
};

#endif // UNIONFIND_H_INCLUDED
