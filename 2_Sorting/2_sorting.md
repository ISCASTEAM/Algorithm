代码链接:   
https://github.com/ISCASTEAM/Algorithm   

# 1.Elementray Sorts  
> Select sort P156  
key:选择第i小的元素放入a[i]位置  
note:运行时间和输入顺序无关  
   
>Insertion sort P157  
key:当前索引左边的所有元素是有序的,但是最终位置尚不确定  
note:运行时间和输入顺序相关(1.部分有序 2.小数组)建议使用insert sort  
note2:有稳定性  
res: time(insert) < time(select)  
  
>Shell sort P162  
key:数组中间隔h步长的元素是有序的, h从N/3递减为1  
key2:基于插入排序((只会交换相邻元素),shell sort是交换h步长的元素  
note:避免插入排序的极端情况--最后一位是最小元素--插入排序需要逐步移动到起始位置  
  
# 2.Merge Sort  
key:归并两个有序的数组;     
key2:递归到小数组;在进行归并(辅助数组N)    
note:有稳定性    
improvement:1.加快小数组排序(n < 8,则使用插入排序) 2.递归中交换参数避免重复辅助数组的赋值(MergeX file)      

# 3.Quick Sort  
key: partition切分   
improvement:1.n < 8,则使用插入排序 2.中位数作为a[lo] 3.random shuffle   
4.三向快排   
```java
// quicksort the subarray a[lo .. hi] using 3-way partitioning
void sort(Comparable[] a, int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo, gt = hi;
    Comparable v = a[lo];
    int i = lo + 1;
    //TODO  小于v的值放在lt左侧 大于v的值放在gt右侧
    //TODO 等于v的值在 (lt,i)之间
    while (i <= gt) {
        int cmp = a[i].compareTo(v);
        if      (cmp < 0) exch(a, lt++, i++);       //a[i] < v  交换a[i]和a[lt]
        else if (cmp > 0) exch(a, i, gt--);         //a[i] > v  交换a[i]和a[gt]
        else              i++;
    }

    // a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi].
    sort(a, lo, lt-1);
    sort(a, gt+1, hi);
    assert isSorted(a, lo, hi);
}  
```

# 4.Priority Queue   
key: ordered array实现 或者 unordered array实现 或者 二叉树实现   
key2: 二叉树findMax+insert 都是是O(logN)  
note: 无法利用缓存 因为数组元素很少直接和相邻元素比较  
> heap   
key: 父节点序号k,则子节点为2k,2k+.  子节点为k,父节点为k/2   
key:sink swim要掌握   
```java
void sort(Comparable[] pq) {
    int n = pq.length;
    //TODO 构建有序堆
    //TODO 相当于从倒数第二层开始遍历到root  sink下沉构建
    for (int k = n/2; k >= 1; k--)
        sink(pq, k, n);
    //TODO 当前最大值pq[1]和最后一位交换 + 重新sink剩余(n-1)个元素
    while (n > 1) {
        exch(pq, 1, n--);
        sink(pq, 1, n);
    }
}

void sink(Comparable[] pq, int k, int n) {
    while (2*k <= n) {
        //TODO k的子节点2k, 2k+1 中val较大的值 == j
        int j = 2*k;
        if (j < n && less(pq, j, j+1)) j++;
        //TODO  不需要交换 则break
        if (!less(pq, k, j)) break;
        exch(pq, k, j);
        k = j;
    }
}
```
