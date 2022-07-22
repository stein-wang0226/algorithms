# bit set

```C++
bitset<n>s;  //长度为n
```

相当于一个二进制的数组，并且可以直接用01串赋值

能直接位运算，下标访问

```C++
bitset<8>foo(string("10011011"));

cout<<foo.count()<<endl;//5　　（count函数用来求bitset中1的位数，foo中共有５个１
cout<<foo.size()<<endl;//8　　（size函数用来求bitset的大小，一共有８位

cout<<foo.test(0)<< endl;//true　　（test函数用来查下标处的元素是０还是１，并返回false或true，此处foo[0]为１，返回true
cout<<foo.test(2)<<endl;//false　　（同理，foo[2]为０，返回false

cout<<foo.any()<<endl;//true　　（any函数检查bitset中是否有１
cout<<foo.none()<<endl;//false　　（none函数检查bitset中是否没有１
cout<<foo.all()<<endl;//false　　（all函数检查bitset中是全部为１
```

```C++
如果超出了bitset定义的范围：
bitset<2>bitset1(12);//12的二进制为1100（长度为４），但bitset1的size=2，只取后面部分，即00

string s="100101";
bitset<4> bitset2(s);//s的size=6，而bitset的size=4，只取前面部分，即1001
```

