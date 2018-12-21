#include"BinarySearchTree.h"

int main(){
    BST* bst = new BST();
    std::ostringstream ss;
    for(int i=0;i<10;i++){
        ss << i;
        bst->put(i,ss.str());
    }

    bst->deleteKey(5);
    vector<int> BFS = bst->print();
    for(auto i:BFS) //按照层级输出
        cout<<i<<" ";
}
