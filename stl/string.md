# string



~~~C++
//倒置串
  reverse(str1.begin(), str1.end());

  //字符串转字符数组
  //不推荐的用法，但是需要了解
  string a = "abc123";
  const char *b;//这里必须为const char *，不能用char *,不然下一句会报错
  b = a.c_str();

//推荐用法
  string c = "abc123";
  char *d = new char[20];
  strcpy(d, c.c_str());//因为这里没有直接赋值，所以指针类型可以不用const char *

//查找串
  //find-从指定位置起向后查找，直到串尾
  string st1("babbabab");
substr(pos,len);//从pos开始取len长度

将 string 对象初始化为 s 指向的字符串

```
string str("hello");
```

string str("hello!");
int len1 = str.size();
int len2 = str.length();

string str("hello");
char ch = 'a';
str.push_back(ch);//加字符



string str("hello");
string str2 = str.substr(3,2)//*stringvar*.**substr(***start* **,** [*length* ]**)
~~~

