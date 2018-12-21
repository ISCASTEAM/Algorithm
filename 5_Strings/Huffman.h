#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include"func.h"
class Huffman{
private:
    const int R = 256;
    class Node{
//    private:
    public:
        char ch;        //非叶子节点是'\0'
        int freq;
        Node* left;
        Node* right;  //leaf.left and right is NULL

        Node(char c,int f,Node* l,Node*r)
        :ch(c),freq(f),left(l),right(r){}
        char getVal(){return ch;}
        bool isLeaf(){return left==NULL&&right==NULL;}
        bool operator<(const Node&that){return freq <that.freq;}
    };

    Node* buildTrie(const vector<int>& freq){
        priority_queue<Node*,vector<Node*>,std::greater<Node*>> minPQ;
        for(int i=0;i<R;i++)
            if(freq[i]>0)
                minPQ.push(new Node(i,freq[i],NULL,NULL));
        while(minPQ.size()>=2){
            Node* left = minPQ.top();
            minPQ.pop();
            Node* right = minPQ.top();
            minPQ.pop();
            Node* parent = new Node('\0',left->freq+right->freq,
                                    left,right);
            minPQ.push(parent);
        }
        Node* root = minPQ.top();
        minPQ.pop();
        return root;
    }
    void buildCode(vector<string>& st,Node* root,string s){
        if(!root->isLeaf()){
            buildCode(st,root->left,s+"0");
            buildCode(st,root->right,s+"1");
        }else{
            st[(int)root->getVal()]=s;
        }

    }

public:
    vector<string> st;
    Huffman(){st.resize(R,"");}
    int getR(){return R;}

    void compress(string s){
        //1.统计字符频率
        vector<int> freq(R,0);
        for(char c:s)
            freq[c]++;

        //2.构建huffman trie tree
        Node* root = buildTrie(freq);

        //3.构建编译表
        buildCode(st,root,"");
    }
    /*  encode compress
        前提:  已经得到Huffman编译表
        这里简单的将"|"作为分隔符
    */
    string encodeStr(string str){
        string ans="";
        for(char c:str)
            ans += st[c]+"|";
        return ans;
    }

};


#endif // HUFFMAN_H_INCLUDED
