## public继承的赋值兼容规则

这是一个很重要的规则，没有该规则，就不存在多态。

```c++
class Base {};
class Derived: public Base {};

int main () {
    Base base;
    Derived derived;

    // 第一 派生类的对象可以赋值给基类对象
    base = derived; // OK

    // 第二 派生类对象可以初始化基类引用
    Base & base1 = derived; // OK

    // 第三 派生类的地址可以赋值给基类对象指针
    Base * basep = & derived; // OK
    return 0;
}
```

### 再码一遍字，因为这个基本概念太重要了:

1. 派生类对象可以赋值给基类对象
2. 派生类对象可以初始化基类的引用
3. 派生类对象的地址可以赋值给基类的指针

如果非 public 继承(private, protected)，则以上三条规则不适用