vector 构造函数



- ```C++
  - vector():创建一个空vector
  
  - vector(int nSize):创建一个vector,元素个数为nSize****   //vector<int> a(n); 大小为a的容器
  
  - vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t  
  
    //vector<int>a(n,1);//大小为n，初始化为1；
  
  - vector(const vector&):复制构造函数
  
  - vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中
  
    //vector <int>a2(a1,a1+n);//将a中 [begin,end)区间元素复制
  ```

  