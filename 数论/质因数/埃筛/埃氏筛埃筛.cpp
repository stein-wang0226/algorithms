#include <iostream>
#include <algorithm>

using namespace std;
//埃氏筛  通过n之前所有质数标记合数
//   时间复杂度   调和级数    nlog(logn)
const int N= 1000010;

int prime[N], cnt=0;
bool vis[N];//  标记合数

void get_primes(int n)
{
   for(int i=2;i<=n;i++){
       if(!vis[i]){//未被标记  prime 
           prime[++cnt]=i;  
           for(int j=i+i;j<=n;j+=i)vis[j]=1;//通过 质数j标记之后合数
       }//这里可从i*i开始 
   }
}
int main()
{
    int n;
    cin >> n;
    get_primes(n);

    cout << cnt << endl;
    //for(int i=1;i<=cnt;i++)cout<<prime[i]<<" ";

    return 0;
}
