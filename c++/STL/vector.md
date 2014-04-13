## vector

vector 可以看作是变长的数组，它是一个类模板。
由于 vector 是模板而非类型，所以由 vector 生成的类型必须包含 vector 中元素的类型。

```c++
vector <int> ivec;
```

上述代码中，ivec 的类型是 `vector<int>`，而非 vector.

### 初始化 vector 对象

```c++
vector<int> ivec; // 初始化空的 vector
vector<int> ivec2(ivec); // 复制 ivec 给 ivec2 初始化
vector<int> ivec3 = ivec; // 同 ivec2
vector<int> ivec4(5); // 5个元素，每个元素都初始化为0
vector<int> ivec5(5, 1); // 5个 int 型元素，每个都初始化为1
```

### 向 vector 对象中添加元素

通常使用 vector 的场景是，创建 vector 对象时，我们并不清楚实际需要的元素个数，元素的值也无法确定。
利用 **push_back** 可以动态的添加数据到 vector 对象.

```c++
vector<int> v;
for (int i = 0; i < 100; i++) {
    v.push_back(i);
}
```