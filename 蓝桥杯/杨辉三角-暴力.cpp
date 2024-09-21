#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6+5;
int pre[N];int cnt[N]; //存的上一行和当前行
signed main()
{
// 估计大小 暴力枚举每行的一半
  int n;
  cin>>n;
  pre[1]=pre[2]=1;
  if(n==1){cout<<1<<endl;return 0;}
  for(int i=3;i<=44723;i++){
        int len = i/2+1; // 枚举前一半
        for(int j=1;j<=len;j++){
          if(i%2&&j==len)cnt[len]=2*pre[len-1];
          else cnt[j]= pre[j-1]+pre[j];
          if(cnt[j]==n){
            cout<<i*(i-1)/2+j;
            return 0;
          }

        }
        for(int j=1;j<=len+1;j++){
            pre[j]=cnt[j]; // 更新
          }


        }


    cout << n * (n + 1) / 2 + 2;//如果枚举这么多还找不到则肯定为n行第二个是数


    return 0;
  }