#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
int T;
unordered_map<int,int>pre; // 范围太大用map
int find(int x){  // 并查集找根节点即之后未用过的最小值
  if(!pre.count(x))return pre[x]=x;  // 未访问过 直接使用 建立pre
  if(x!=pre[x])pre[x]=find(pre[x]);// 否则向后递归寻找
  return pre[x];
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
int m;
cin>>m;
int root=find(m);
cout<<root<<" ";
pre[root]=find(root+1); // 将m的根连向下一个
// 此时 pre[m]已经使用  所以将根结点pre连向 find m+1  (下一个点的根节点)  相当于向后快速(指数)寻找第一个未访问(!pre.count)
// 举例  1.2.3....100  1   前面1~100为路径压缩的树 最后根结点100又指向101  所以find（1）能快速 find101
}
    return 0;
}

// set +二分
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t;
set<pair<ll,ll>>s;//为了按结尾排序，反着来
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    s.insert(make_pair(2e9,1));
    function<void(ll,ll)>add=[&](ll l,ll r)
    {
        if(l>r)return ;
        s.insert(make_pair(r,l));
    };
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        set<pair<ll,ll>>::iterator it=s.lower_bound(make_pair(x,0));
        if(it->second<=x)
        {
            cout<<x<<" ";
            add(it->second,(ll)x-1);
            add((ll)x+1,it->first);
            s.erase(it);
        }
        else {
            cout<<it->second<<" ";
            add(it->second+1,it->first);//如果可行区间的起点大于x，那就直接在当前可行的第一个位置插入
            s.erase(it);
        }
    }
}