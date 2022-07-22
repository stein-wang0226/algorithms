```C++
//pair 重载
typedef pair<int,int> PII  ;
//.....

struct cmp{
	bool operator(){const PII &a,const PII &b}{
	return a.first<b.first;
    }
}
```

