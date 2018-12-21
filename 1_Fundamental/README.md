代码链接:
xxxxxxxxx
  
# 1.binary search   
url get data练习  
edu.princeton.cs.algs4 普林斯顿算法 jar包   
  
# 2.dataStruct   
queue stack bag  链表实现   
  
# 3.Union Find  
连通集的查找   
API: union find connected  
key: 辅助数组id   
>Quick find   
id[] 相同集合的元素,id[]相同   
   
>Quick union  
id[] 当前元素的root节点序号  
  
>Weighted QuickUnion  
union操作加入size判断  使得较小的子树root指向较大的子树root
小树加到大树上 避免origin quick union depth的过深   

代码不在这里加了   一定要掌握   


``` java
//TODO iterator()方法返回一个实现hasnext() 和 next()方法的迭代器

//first是自己定义的node类型 含有item和next结构

public Iterator<Item> iterator()  {
    return new ListIterator<Item>(first);
}

// an iterator, doesn't implement remove() since it's optional
private class ListIterator<Item> implements Iterator<Item> {
    private Node<Item> current;

    public ListIterator(Node<Item> first) {
        current = first;
    }

    public boolean hasNext()  { return current != null;                     }
    public void remove()      { throw new UnsupportedOperationException();  }

    public Item next() {
        if (!hasNext()) throw new NoSuchElementException();
        Item item = current.item;
        current = current.next;
        return item;
    }
}
```
