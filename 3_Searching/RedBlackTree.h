#include "func.h"

class RedBlackTree{
public:
    RedBlackTree():_root(NULL),_size(0){};
    string get(int key){ return get(_root,key);}
    void put(int key,string val){
        _root = put(_root,key,val);
        _root->color = _black;
    }

private:
    class Node{
    public:
        Node(int key,string val,bool color)
        :_key(key),_val(val),color(color){
            left = NULL;
            right = NULL;
        }
    //private:
        int _key;
        string _val;
        Node* left;
        Node* right;
        bool color;
    };
    Node* _root;
    int _size;

    string get(Node*,int);
    Node* put(Node*,int,string);

    Node* rotateRight(Node* h){
        Node* tmp = h->left;
        h->left = tmp->right;
        tmp->right = h;
        tmp->color = h->color;
        h->color = _red;
        return tmp;
    }
    Node* rotateLeft(Node* h){
        Node* tmp = h->right;
        h->right = tmp->left;
        tmp->left = h;
        tmp->color = h->color;
        h->color = _red;
        return tmp;
    }
    void flipColors(Node* h){
        h->color = _red;
        h->left->color = _black;
        h->right->color = _black;
    }
    bool isRed(Node* x){
        if(x == NULL) return false;
        return x->color == _red;
    }
    int getmin(Node* root){
        int key = -1;
        while(root!=NULL){
            key = root->_key;
            root =  root->left;
        }
        return key;
    }
    int getmax(Node* root){
        int key = -1;
        while(root!=NULL){
            key = root->_key;
            root = root->right;
        }
        return key;
    }
    void getKeys(Node* root,queue<int>& res){
        //inorder BFS
        if(root==NULL) return;
        getKeys(root->left,res);
        res.push(root->_key);
        getKeys(root->right,res);
    }
public:
    bool contains(int){ return _size;}
    int getsize(){return this->_size;}
    int getmin(){ return getmin(_root);}
    int getmax(){return getmax(_root);}
    void getKeys(queue<int>& res){ return getKeys(_root,res);}
    int getRoot(){return _root->_key;}
    //each path from root to leaf has the same black number
    bool isBalanced(){
        int black = 0;
        Node* root = _root;
        while(root!=NULL){
            if(!isRed(root)) black++;
            root = root->left;
        }
        return isBalanced(root,black);
    }
    bool isBalanced(Node* root, int numBlack){
        if(root==NULL) return numBlack==0;
        if(isRed(root)) numBlack--;
        return isBalanced(root->left,numBlack) &&isBalanced(root,numBlack);
    }
protected:
    const bool _red = true;
    const bool _black = false;

};

string RedBlackTree::get(Node* x, int key){
    while(x != NULL){
        if(x->_key == key) return x->_val;
        else if(x->_key > key) return get(x->left,key);
        else return get(x->right,key);
    }
    return NULL;
}

RedBlackTree::Node* RedBlackTree::put(Node* h,int key,string val){
    if(h==NULL){
        _size ++;
        return new RedBlackTree::Node(key,val,_red);
    }
    if(h->_key == key) h->_val = val;
    else if(h->_key > key) h->left = put(h->left,key,val);
    else h->right = put(h->right,key,val);

    //TODO fix-up links
    if(isRed(h->right) && !isRed(h->left))  h = rotateLeft(h);
    if(isRed(h->left) && isRed(h->left->left))h = rotateRight(h);
    if(isRed(h->left) && isRed(h->right)) flipColors(h);

    return h;
}


