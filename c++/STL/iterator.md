## iterator

迭代器(iterator)提供了对容器元素访问的一种通用机制。
迭代器的底层是利用指针实现的，在行为上与指针也类似。

### 获取迭代器

支持迭代器的类型需要实现迭代器的接口，此时该类型便具有了 begin() 和 end() 方法，以返回指定元素的迭代器。

```c++
vector<int> v;
vector<int>::const_iterator i;
i = v.begin(); // 迭代器 i 指向容器 v 的第一个元素
i = v.end(); // 迭代器 i 指向容器最后一个元素的下一个位置
```

### 迭代器的移动

迭代器使用递增运算符(++)将迭代器向前移动一个位置。
同理，使用递减运算符(--)将迭代器向后移动一个位置。

```c++
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
for (vector<int>::const_iterator i = v.begin(); i != v.end(); i++) {
    cout << *i << endl; // 与指针类似，使用 * 号获取迭代器指向的元素的引用
}
```