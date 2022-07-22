#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
//从后往前判断对应字母是否连续z最后一次出现
int T, n, a[N];
vector<int >pos[30]; //每个字母位置
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
  for(int i=0;i<=26;i++)pos[i].clear();
    string a, b;
    cin >> a >> b;
    int len = a.size();
    int len2=b.size();
    for (int i=0;i<len;i++ ) {//从后往前最后一个出现位置
      pos[a[i]-'A'].push_back(i);
    }
    int p1=len-1,p2=len2-1;
    int flag=1;
    while(p1>=0&&p2>=0){
        if(a[p1]==b[p2]){
           if(p1==pos[a[p1]-'A'].back()&&pos[a[p1]-'A'].size()){
              pos[a[p1]-'A'].pop_back();
               p1--,p2--; //是从后往前最后一个
            //同时更改位置
            
           }
            else{flag=0;break;} 
        }
        else {// 向前找
            p1--;
        }
    }
    if(p2>=0)flag=0;
    if(!flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

  }
  return 0;
}
