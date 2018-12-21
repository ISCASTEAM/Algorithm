#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include"func.h"
/*
key: Int
val: string
*/

class BST{
private:
    class Node{
    public:
        int key;
        string val;
        int Size;
        Node* left;
        Node* right;
        Node(int k,string v,int s)
        :key(k),val(v),Size(s){
            left=NULL;
            right=NULL;
        }
    };
    Node* root;
public:
    BST(){root=NULL;}
    int sizeTree(Node* root){if(root==NULL) return 0;else return root->Size;}
    int sizeTree(){return sizeTree(root);}
    bool isEmpty(){return sizeTree()==0;}
    bool contains(int key){ return get(key)!="";}
    string get(int key){return get(root,key);}
    string get(Node* root,int key){
        if(root->key==key) return root->val;
        else if(root->key > key)
            return get(root->left,key);
        else
            return get(root->right,key);
    }
    //插入新元素 或者 更新val
    void put(int key,string val){
//        cout<<key<<" "<<val<<endl;
        root = put(root,key,val);
    }
    Node* put(Node* root,int key,string val){
        if(root==NULL)
            return new Node(key,val,1);
        if(root->key == key)
            root->val = val;
        else if(root->key > key)
            root->left = put(root->left,key,val);
        else
            root->right = put(root->right,key,val);

        root->Size = 1+sizeTree(root->left)+sizeTree(root->right);
        return root;
    }
    //删除极小值
    void deleteMin(){root=deleteMin(root);}
    Node* deleteMin(Node* root){
        if(root->left==NULL) return root->right;    //删除根节点
        root->left = deleteMin(root->left);
        root->Size = sizeTree(root->left) + sizeTree(root->right);
        return root;
    }
    //删除
    void deleteKey(int key){root = deleteKey(root,key);}
    Node* deleteKey(Node* root, int key){
        if(root->key > key)
            root->left = deleteKey(root->left,key);
        else if(root->key < key)
            root->right = deleteKey(root->right,key);
        else{
            if(root->right==NULL) return root->left;
            if(root->left==NULL) return root->right;
            //待删除节点 左右子树均不为空
            //右子树最小节点替换待删除节点
            Node* tmp = root;
            root = minLeaf(root->right);    //右子树最小节点
            root->right = deleteMin(tmp->right);
            root->left = tmp->left;
        }
    }
    //寻找最小leaf
    Node* minLeaf(Node* root){
        if(root->left==NULL) return root;
        else return minLeaf(root->left);
    }
    vector<int> print(){
        vector<int> BFS;
        queue<Node*> pq;
        pq.push(root);
        while(!pq.empty()){
            Node* tmp = pq.front();
            pq.pop();
            BFS.push_back(tmp->key);
            if(tmp->left!=NULL)
                pq.push(tmp->left);
            if(tmp->right!=NULL)
                pq.push(tmp->right);
        }
        return BFS;
    }

};


#endif // BINARYSEARCHTREE_H_INCLUDED
