## string

string 类是一个模板类，使用时要包含头文件 `<string>`，其定义如下:

```c++
typedef basic_string<char> string;
```

### string 对象的初始化

```c++
string s1("hello"); // 一个参数的构造函数
string s2(8, 'x'); // 使用 8 个字符 x 初始化 string 对象
string month = "March";
```

需要注意的是，string 对象不提供以字符和整数为参数的构造函数，如以下初始化是错误的:

```c++
string error1 = 'c';
string error2 = 123;
string error3('u');
string error4(8);
```

但可以将字符复制给 string 对象:

```c++
string c;
c = 'u'; // ok
```

### 示例

```c++
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1("Hello");
    cout << s1 << endl; // Hello

    string s2(8, 'x');
    cout << s2 << endl; // xxxxxxxx

    string s3 = "March";
    cout << s3 << endl; // March

    string s4;
    s4 = 'u';
    cout << s4 << endl; // u

    return 0;
}
```

### 获取 string 对象的长度

```c++
string s = "Hello";
cout << s.length(); // 5
```

### 缓冲区读入

string 对象支持流提取运算符(cin)

```c++
string s;
cin >> s;
```

同时 string 对象也支持 getline 函数

```c++
string s;
getline(cin, s);
```

### string 对象的赋值和连接

用 = 赋值，将源字符串复制一份给目标对象

```c++
string s1("Hello"), s2;
s2 = s1;
```

也可以使用 assign 函数赋值，可以复制出字符串中的一个范围

```c++
string s3("cat"), s4, s5;
s4.assign(s3); // cat
s5.assign(s3, 0, 2); // ca
```

可以通过下标或 at 成员函数访问 string 对象中指定位置的字符

```c++
string s("Hello");
for (int i = 0; i < s.length(); i++) {
    cout << s.at(i) << endl;
}
```

**at 与下标方式的区别**： at 会做范围检查，如果超出字符串长度，at 会抛出异常，而下标访问则不会。

使用 + 或 append 成员函数连接 string 对象

```c++
string s1("Good "), s2("morning!");
s1.append(s2);
cout << s1 << endl; // Good morning!
cout << s2 << endl; // morning!

s2.append(s1, 3, s1.size()); // 从 s1 下标为 3 的位置开始复制 s1.size() 个字符
cout << s1 << endl; // Good morning!
cout << s2 << endl; // morning!d morning!
```

### 字符串比较

使用关系运算符比较 string 对象的大小，或比较是否相等

```
==, >=, >, <, <=, !=
```

还可以使用 string 对象的成员函数 compare 比较

```c++
string s1("hello"), s2("hello"), s3("hell");
int f1 = s1.compare(s2);
int f2 = s1.compare(s3);
int f3 = s3.compare(s1);
int f4 = s1.compare(1, 2, s3, 0, 3); //s1 1-2; s3 0-3
int f5 = s1.compare(0, s1.size(), s3); //s1 0-end
cout << f1 << endl << f2 << endl << f3 << endl;
cout << f4 << endl << f5 << endl;
```

上例将输出

```c++
0
1
-1
-1
1
```

### 取字符串的子串

```c++
string s1 = "Hello world", s2;
s2 = s1.substr(4, 5); // o wor
```

### 字符串交换

```c++
string s1 = "Hello world", s2("xianlihua");
s1.swap(s2);
cout << s1 << endl; // xianlihua
cout << s2 << endl; // Hello world
```

### string 对象的特性

- capacity() 返回无需增加内存便可存储的字符数
- maximum_size() 返回 string 对象可存放的最大字符数
- length(), size() 返回字符串的大小/长度
- empty() 返回 string 对象是否为空
- resize() 改变字符串对象的长度

示例

```c++
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1("hello world");
    cout << s1.capacity() << endl;
    cout << s1.max_size() << endl;
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.empty() << endl;
    cout << s1 << "aaa" << endl;
    s1.resize(s1.length()+10);
    cout << s1.capacity() << endl;
    cout << s1.max_size() << endl;
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1 << "aaa" << endl;
    s1.resize(0);
    cout << s1.empty() << endl;
    return 0;
}
```

上例在 g++ 4.8.1 (win) 将输出

```c++
// 11
// 1073741820
// 11
// 11
// 0
// hello worldaaa
// 22
// 1073741820
// 21
// 21
// hello world
```

不同的编译器输出结果可能会不一样

### 字符串查找

find 查找目标字符串中首次出现指定字符串的位置

```c++
string s("Hello World");
cout << s.find("lo"); // 3
```

rfind 与 find 相同，只是查找顺序由后向前

find_first_of() 则查找目标字符串中指定字符串中的字符首次出现的位置

```c++
string s1("hello worlld");
cout << s1.find("ll") << endl;
cout << s1.find("abc") << endl;
cout << s1.rfind("ll") << endl;
cout << s1.rfind("abc") << endl;
cout << s1.find_first_of("abcde") << endl;
cout << s1.find_first_of("abc") << endl;
cout << s1.find_last_of("abcde") << endl;
cout << s1.find_last_of("abc") << endl;
cout << s1.find_first_not_of("abcde") << endl;
cout << s1.find_first_not_of("hello world") << endl;
cout << s1.find_last_not_of("abcde") << endl;
cout << s1.find_last_not_of("hello world") << endl;
// 2
// 4294967295
// 9
// 4294967295
// 1
// 4294967295
// 11
// 4294967295
// 0
// 4294967295
// 10
// 4294967295
```

### 删除与替换

erase() 删除字符串中指定下标及之后的字符

```c++
string s1("hello worlld");
s1.erase(5);
cout << s1; // hello
cout << s1.length(); // 5
cout << s1.size(); // 5
```

replace(int index, int len, string s) 将字符串中index下标开始len长度的字符串替换为s

```c++
string s1("hello world");
s1.replace(2,3, “haha");
cout << s1; // hehaha world
```

### 插入字符

insert() 在指定下标处插入字符串

```c++
string s1("hello world");
string s2("show insert");
s1.insert(5, s2);
cout << s1; // helloshow insert world
s1.insert(2, s2, 5, 3);
cout << s1; // heinslloshow insert world
```

### 转换为C 语言式的 char * 字符串

```c++
string s1 = "hello world";
printf("%s\n", s1.c_str()); // hello world
```

也可以使用成员函数 data()

```c++
string s1("hello world");
const char * p = s1.data(); // s1.data() 返回 char * 类型的字符串
for (int i = 0; i < s1.length(); i++) {
    printf("%c", *(p + i)); // hello world
}
```

成员函数 copy()

```c++
string s1("hello world");
int len = s1.length();
char * p2 = new char[len+1];
s1.copy(p2, 5, 0);
p2[5]=0;
cout << p2 << endl; // hello
```

