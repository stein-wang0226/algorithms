#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a,b;
const int mod = 1e9+7;
int val; // 位权

signed main()
{
  int n;
  int ma,mb,lena,lenb;
  cin>>n;
  cin>>lena;
  for(int i=1;i<=lena;i++){
    cin>>ma;
    a.push_back(ma);
  }
  cin>>lenb;
  for(int i=1;i<=lenb;i++){
    cin>>mb;
    b.push_back(mb);
  }

  int len=lena;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int ans=0;
  int last = lena-lenb;
        while(last--)b.push_back(0); // 高位补0
        val=1;
        ans+=a[0]-b[0];
        for(int i=1;i<len;i++){
          val*=max({a[i - 1] + 1, b[i - 1] + 1,2ll});
          val%=mod;
          ans+=((a[i]-b[i])*val)%mod;
          ans%=mod;
        }
//不反转可用秦九~算法从高到低先乘后加


        cout<<(ans+mod)%mod<<endl;
        return 0;
      }