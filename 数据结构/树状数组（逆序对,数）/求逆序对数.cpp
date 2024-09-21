#include <iostream>
#include <cstring>
using namespace std;
#define N 1010
int c[N],a[N];
int n;
int lowbit(int x){
    return x& -x;
}
void update(int i,int val){//单点更新:每次加自身lowbit的元素改变
    while(i<=n){
        c[i]+=val;
        i+=lowbit(i);
    }
}//更新(从小到大)时查询(从大到小)的逆过程
int sum(int i){//求前缀和
    int ret =0;
    while(i>0){
        ret+=c[i];
        i-=lowbit(i);
    }
    return ret;
}
 
int main()
{
    while(cin>>n){
        int ans=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            cin>>a[i];
           update(a[i],1);//每次更新
           ans+=i-sum(a[i]);//统计当前序列中（左边）大于a的元素的个数			
	    }
//	    for(int i=n;i>0;i--){//正序对 
//		           update(a[i],1);//每次更新
//		           ans+=i-sum(a[i]);//统计当前序列中（左边）大于a的元素的个数			
//	    }

 

        cout<<ans<<endl;
    }
    return 0;
}


