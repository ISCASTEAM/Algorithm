
#include "RedBlackTree.h"

int main(){
    string test = "ABCDEFG";
    RedBlackTree* rbt = new RedBlackTree();
    for(int i=0;i<7;i++){
//        cout<<string(1,test[i])<<endl;
        rbt->put(i,string(1,test[i]));
    }
    cout<<"root="<<rbt->getRoot()<<endl;
    cout<<"isBalanced="<<rbt->isBalanced()<<endl;
    cout<<"tree size="<<rbt->getsize()<<endl;
    cout<<"key min="<<rbt->getmin()<<endl;
    cout<<"key max="<<rbt->getmax()<<endl;

    cout<<endl;
    cout<<"Testing:"<<endl;
    //inorder to get key
    queue<int> res;
    rbt->getKeys(res);
    while(!res.empty()) {cout<<res.front()<<" "; res.pop();}
    cout<<endl;
    cout<<"get key==3, val="<<rbt->get(3)<<endl;
    return 0;
}
