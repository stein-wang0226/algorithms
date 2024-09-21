#include <bits/stdc++.h>
using namespace  std;
const int N=1005;
int pre[N];
int mid[N];
map<int,int>pos2; // 中序位置
void getlast(int len,int l1,int r1,int l2){ // 子树大小 中序区间l,r   先序序列起始位置l
	if(len<=0)return ;
	int root= pre[l2];
    int pos =pos2[root]; //中序根  左右分界
//后序 输出
    getlast(pos-l1,l1,pos-1,l2+1); // 左
    getlast(len+l1-1-pos,pos+1,r1,l2+pos-l1+1); // 右
    cout<<root<<" " ;

}



int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>pre[i];}
		for(int i=1;i<=n;i++)cin>>mid[i],pos2[mid[i]]=i;

			getlast(n,1,n,1);



	}