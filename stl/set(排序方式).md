```C++

内部有序   增删改查logn
    
可以通过定义结构体(或类)，并在其中重载()运算符，来自定义排序函数。然后，在定义set的时候，将结构体加入其中例如如下代码中的set<int, intComp>和set<string, strComp >。

#include <iostream>
#include <string>
#include <set>
using namespace std;

struct intComp {
	bool operator() (const int& lhs, const int& rhs) const{
		return lhs > rhs;
	}
};

struct strComp
{
	bool operator() (const string& str1, const string& str2) const {
		return str1.length() < str2.length();
	}
}；
    
    
    erase(x);//清除   log
```

