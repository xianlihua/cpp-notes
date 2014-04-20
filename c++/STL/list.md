## list

list 是 C++ STL 中提供的双向链表容器，具体特点：

- 在任何指定位置插入/删除元素的时间复杂度为 O(1)
- 不支持下标随机存取

list 容器除了支持顺序容器都有的成员函数外，另支持以下8个成员函数:

- push_front 在链表最前面插入元素
- pop_front 删除链表最前面的元素
- sort 这是list容器自有的 sort 算法，list 不支持 STL 的 sort 算法
- remove 删除和指定值相等的所有元素
- unique 删除所有和前一个元素相等的元素
- merge 合并两个链表，并清空被合并的链表
- reverse 颠倒链表
- splice 在指定链表的前面插入一个或多个元素，并在另一个链表中删除被插入的元素

### list 容器的 sort 函数

由于 STL 中的 sort 算法需要被排序容器支持随机存取下标的支持，故 list 不能使用。
list 提供了自己的 sort 算法:

```c++
list<T> classname
classname.sort(compare); // 自定义比较函数
classname.sort(); // 无参版本默认按照 < 比较
```

### list 容器的迭代器

list 在物理存储上为链表结构，指向每一个相邻的元素的迭代器无法直接比较大小。
所以只能使用**双向迭代器**。

```c++
template <class T>
void printList(const List<T> & lst) {
    int len = lst.size();
    if (len > 0) {
        typename list<T>::const_operator i;
        for (i = lst.begin(); i != lst.end(); i++) {
            cout << *i << endl;
        }
    }
}
```

注: `typename` 用于说明 `list<T>::const_operator` 是一个类型。