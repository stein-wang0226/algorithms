#include<iostream>
using namespace std;

const int MAX=100005;			//数组的最大长度（即图中点个数的最大值）
int m,n;						//当前图的长宽规格
int pre[MAX];					//用于存放每个点的根节点

void init(int n) {			//初始化函数
	for(int i=1; i<=n; i++)
		pre[i]=i;
}
int find_r(int key) {	   //寻找根节点函数
	int r=key;
	while(r!=pre[r])
		r=pre[r];

	return r;
}
//**下面是路径压缩的find函数
int find_r(int x) {//递归

	if (x != pre[x]) pre[x] = find_r(pre[x]);

	return pre[x];

}
//循环
int find_r(int x) {
	while(x != pre[x]) { //如果x元素的父亲指针指向的不是自己，说明x并不是集合中的根元素，还需要一直向上查找和路径压缩
		//在find查询中嵌入一个路径压缩操作
		pre[x]=pre[pre[x]];
		//x元素不再选择原来的父亲节点，而是直接选择父亲节点的父亲节点来做为自己新的一个父亲节点
		//这样的操作使得树的层数被压缩了
		x=pre[x];//x压缩完毕后且x并不是根节点，x变成x新的父节点继续进行查找和压缩的同时操作
	}
	return x;//经过while循环后，x=pre[x],一定是一个根节点，且不能够再进行压缩了,我们返回即可
}



void merge(int x,int y) {	   //合并函数
	int rootx=find_pre(x);
	int rooty=find_pre(y);
	if(rootx!=rooty) pre[rootx]=rooty;
}

int main() {
	int n,k;//城市数，操作数
	int m,x,y;//m为操作数
	cin>>n>>k;
	init(n);
	for(int i=0; i<k; i++) {
		cin>>m;
		if(m==1) {
			cin>>x>>y;
			merge(x,y);
		} else if(m==2) {
			divide(x,y);//取消上一次
		}


		int ans=0;
		for(int i=1; i<=n; i++)
			if(find_pre(i)==i)ans++;
		if(m==1) {

			if(ans==1)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			cout<<ans<<endl;
		}

	}
	return 0;
}


