#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
int head,p[N],ne[N],id;
//p 结点值  ne下个结点编号  
void init(){
    head=-1;//头节点编号  之后变尾结点
    id=0;//结点起始编号
}

void add_to_head(int x){//插到头节点前
    p[id]=x,ne[id]=head,head=id++;
}

void add(int k,int x){//插到第k个结点后
    p[id]=x,ne[id]=ne[k],ne[k]=id++;
}
void remove(int k){// 将编号k后面的点删除
    ne[k]=ne[ne[k]];
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

int m;
cin>>m;
init();
while(m--){
    int k,x;
     char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k) head = ne[head];
            else remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
}
        for(int i=head;i!=-1;i=ne[i]){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    
    return 0;
}
