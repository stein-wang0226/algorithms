#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define  LOCAL
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n;
struct  Node{
    int data;
    int depth;
    int fa;
}node[N];
map <int,int>id;
int idx=0;
void solve(){
    int num ,fa;
    fa=0;
    cin>>node[fa].data;
    node[fa].fa=-1;
    node[fa].depth=1;
    while(cin>>num) {
        if (num) {
            node[++idx].fa = fa;
            node[idx].data = num;
            node[idx].depth = node[fa].depth + 1;
            id[num] = idx;
            fa = idx; // 更新父节点
        }
        else fa = node[fa].fa;//否则回退
        if(fa==-1) { cin>>num; break; }//

    }
        int a,b;
        cin>>a>>b;
        int x=id[a];
        int y=id[b];
        while(node[x].data!=node[y].data){
            if(node[x].depth>=node[y].depth) x=node[x].fa;
            else y=node[y].fa; //
        }
        cout<<node[x].data<<endl;

}
signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
