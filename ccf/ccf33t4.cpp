// 关键:只存 m 个 有水滴的，因为只有初始有水的格子参与操作，最多删m次

// 用链表存有水的格子下标   模拟爆开   O(1) 增删
// 优先队列   最左
#include "bits/stdc++.h"
const int N = 3e5+5;
using namespace std;
struct node{ // 存有水的  链表  过程中可能有0
    int x,w,pre,nex;//pre nex 为前后a的下标
    bool operator<(const node &b)const{
        return x<b.x;
    }
}a[N];
map<int,int>Id; // 格子号 --> a下标
priority_queue<int,vector<int>,greater<>>Q; // 存将爆开的格子的a[]下标  堆顶 最左
int c,n,m;


int main(){
    cin>>c>>m>>n;
    int x,w;
    for(int i=1;i<=m;i++){
        cin>>x>>w;
        a[i].x =x; a[i].w =w;
    }
    sort(a+1,a+1+m); // 按x排序 生成链表
    for(int i=1;i<=m;i++){
        Id[a[i].x] = i;
        a[i].pre = i-1; //  有一个0是不合法的
        a[i].nex = i+1;
    }
    int p;
    int ans = m;
    while(n--){
        cin>>p;
        int i = Id[p]; // p格子的a下标
        a[i].w++;
        if(a[i].w>=5)Q.push(i); //


        while(!Q.empty()){
            int tt = Q.top();
            Q.pop();
            if(0==a[tt].w)continue; // 已爆开过=0; 相当于标记
            a[tt].w = 0;ans--; // 爆开
            int l = a[tt].pre; // 左
            int r = a[tt].nex;// 右
            a[l].w++;a[r].w++;
            if(l>0&&a[l].w>=5)Q.push(l);
            if(r<=m&&a[r].w>=5)Q.push(r);
            // 关键: 从链表中删除已爆开的格子
            a[l].nex = r ;
            a[r].pre = l;
        }
        cout<<ans<<endl;
    }




    return 0;
}




