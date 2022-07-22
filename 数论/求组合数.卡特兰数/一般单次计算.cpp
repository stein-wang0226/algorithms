// 一般方法单次计算
int a,b,p;
int qpow(int a,int k){
    int res=1;
    while(k){
        if(k&1)res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}

int C(int a,int b){
    if(b>a)return 0;
    int  res=1;
    int temp=1;
    for(int i=a,j=1;j<=b;i--,j++)
    {
        res=res*i%p;     //计算a*...*b
        temp=temp*j%p;    //  计算b!
    }
    return res*qpow(temp,p-2)%p;//      逆元 费马  除变乘  算/b!
}