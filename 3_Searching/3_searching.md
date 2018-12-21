代码链接:   
https://github.com/ISCASTEAM/Algorithm    

# Elementray Tables  
>无序链表   
key: 插入时间O(1)  查找时间O(N)  
note: 新元素直接插入链表头部  
>有序数组  
key:查找使用二分查找  
key: 插入时间O(N)  查找时间O(lgN)  
note: 插入元素  

# BinarySearchTree  
>1.基本实现  
get/put 时间复杂度O(1.39lgN)  
note: put操作 节点总是最后一层的leaf  
note: 随机的数据可能导致树的不平衡  复杂度为1.39lgN  

>2.有序性相关API  
flooring 向下取整    
向下取整:  tree中的节点 不大于给定查找值key  
ceiling 向上取整    
select rank  
max最后一层最右边的节点  min最后一层最左边的节点  
  
>3.删除delete  
删除的节点使用其右子树的最小值替换  
```java
private Node delete(Node x, Key key) {
    if (x == null) return null;

    int cmp = key.compareTo(x.key);
    if      (cmp < 0) x.left  = delete(x.left,  key);
    else if (cmp > 0) x.right = delete(x.right, key);
    else {
        if (x.right == null) return x.left;
        if (x.left  == null) return x.right;
        //TODO 待删除节点x 有左右子树
        //TODO min(x.right) x右子树最小节点替换待删除节点x
        Node t = x;
        x = min(t.right);   //min也是寻找最小节点的函数
        x.right = deleteMin(t.right);//删掉右子树最小值
        x.left = t.left;
    }
    x.size = size(x.left) + size(x.right) + 1;
    return x;
}
```
>4. 范围查找    
note: 中序遍历的二叉搜索树是有序的;  queue;    
note: 掌握inorder的递归代码格式  P268    
  
# BalancedSearchTree    
>1. 2-3树    
key数目是2, value数目是3(小于,中间,大于)    
note: 生长方式=自下而上    
理解 不同情况的下的插入变换方法    

>2. 红黑树    
note: 时间复杂度 1.00lgN  (对比二叉树),因为红黑树是平衡的    
note: 思考:新插入的节点都是红色的    

C++重构 lite版本的  代码链接:https://github.com/ISCASTEAM/Algorithm/tree/master/Tree
重点: 两种旋转 + 颜色转换 P280    

P275   
各种插入情况 汇总为三句话  
*c++插入实现*  
```cpp
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
```

*左右旋转 + 颜色转换*  
```cpp
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
```
*BST删除操作 P291*  


# HashTable  
*get put 都是常数时间*  
key:散列函数将key转化为数组索引; 处理碰撞冲突  
e.g java return (key.hashcode() & 0x7fffffff) % M  
note: 缺点 =》 有序性的API无法支持  
>1. 拉链法 P297  
相同key,链表串起来val   
  
>2. 线性探测法  
碰撞发生时,检测下一个位置是否为Null  
note: 删除操作,两个方法1.后面非空元素重新put一遍 2.置空NULL + 需要将后面元素前移一位    

  
# Application   
思考:  
稀疏矩阵 * vector如何在常数时间内完成  特别是当矩阵非常大时候  
P323  
