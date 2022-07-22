#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//给定字符串s  求最小长度len使得任意长度为len的子串不相同
//二分+哈希 set
using namespace std;
int n;
string s;
unordered_set<string>hash_st;
bool check(int mid){//对每个长度为mid的子串插入查询即可     边插入边查重
  for(int i=0;i+mid-1<s.size();i++){//枚举起始位置
      string ss=s.substr(i,mid);//枚举所有子串
      if(hash_st.count(ss))return 0;//有重复
      hash_st.insert(ss);//插入
  }
  return 1; 
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
cin>>s;
int l=1,r=n;
while(l<r){//最小值
int mid =l+r>>1;
if(check(mid))r=mid;
else l=mid+1;
}
cout<<l<<endl;

return 0;
}
