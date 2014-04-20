## pair 类模板

pair 类模板源码片段:

```c++
template <class _T1, class _T2>
struct pair {
    _T1 first;
    _T2 second;

    // 无参构造函数
    pair(): first(), second() {}

    // 使用两个对象初始化
    pair(const _T1 & __a, const _T2 __b): first(__a), second(__b) {}

    // 使用另一个 pair 对象初始化 pair
    template <class U1, class U2>
    pair(const pair<U1, U2> & __p): first(__p.first), second(__p.second) {}
};
```

## set

set 即有序集合，其特点为:

- 内部元素有序排列，新插入的元素的位置取决于其值的大小
- set 内不允许存在重复的元素，当插入已有元素时，会忽略插入
- 由于 set 已经内部排好序，所以查找速度很快

set 除了包含其它容器通用的成员函数外，还包含以下特有的成员函数:

- find 查找等于某个值的元素，返回指向该元素的迭代器。
  注意这里的相等指的是 x < y 与 y < x 同时不成立。
- lower_bound 查找某个下界
- upper_bound 查找某个上界
- equal_range 同时查找上界和下界
- count 返回等于某个值的元素的个数(注意这里的相等)
- insert 插入一个元素或一个区间

### set 示例

```c++
#include <iostream>
#include <set>
using namespace std;
int main() {
    typedef set<int>::iterator IT;
    int a[5] = {3, 4, 6, 1, 2};
    set<int> st(a, a + 5);
    pair<IT, bool> result = st.insert(5);
    if (result.second) {
        cout << *result.first << " inserted" << endl;
    }
    if (st.insert(5).second) {
        cout << *result.first << endl;
    } else {
        cout << *result.first << " already exists" << endl;
    }
    pair<IT, IT> bounds = st.equal_range(4);
    cout << *bounds.first << ',' << *bounds.second << endl;
    return 0;
}
```

程序输出:

```
5 inserted
5 already exists
4,5
```

## multiset

与 set 不同之处在于，multiset 允许存在重复的元素。其定义如下:

```c++
template <class key, class Pred = less<Key>, class A = allocator<Key> >
class multiset { ... };
```

Pred 类型的对象决定了 multiset 中每一个元素的大小是如何定义的。其缺省类型为 less<Key>:

```c++
template <class T>
struct less: public binary_function<T, T, bool> {
    bool operator () (const T & x, const T & y) const {
        return x < y;
    }
}
```

### multiset 特有的成员函数

- iterator find(const T & value);
  在容器中查找元素为 value 的迭代器，如果找不到，返回 end()
- iterator insert(const T & value);
  将 value 插入到容器中，并返回指向该 value 的迭代器
- void insert(iterator first, iterator last);
  将左闭右开的区间插入到容器 ([first, last))
- int count(const T & value);
  统计容器中与 value 相等的元素的个数
- iterator lower_bound(const T & value);
  查找一个最大的位置 it，使得 [begin(), it) 之间的所有元素的值都比 value 小
- iterator upper_bound(const T & value);
  查找一个最小的位置 it，使得 [it, end()) 之间的所有元素的值都比 value 大
- pair<iterator, iterator> equal_range(const T & value);
  同时求得 lower_bound 和 upper_bound
- iterator erase(iterator it);
  删除 it 指向的元素。返回其后面元素的迭代器(返回值非C++标准规定，但是大部分编译器如此处理)

当我们向 set/multiset 中插入对象时，如果没指定 Pred 类型的对象，
则集合会默认使用 `less<Key>` 进行排序，由上面的 `less<key>` 源码可知，其需要对进行排序的对象使用小于号比较。

下面是一个错误的示例:

```c++
class A {};
int main() {
    multiset<A> s;
    s.insert(A()); // error
}
```
