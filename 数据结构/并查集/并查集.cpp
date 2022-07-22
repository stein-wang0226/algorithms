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
int find(int x) {//递归
	if (x != pre[x]) pre[x] = find_r(pre[x]);//
	return pre[x];
}
//循环
int _find(int x) {
	while(x != pre[x]) { //如果x元素的父亲指向的不是自己，说明x并不是集合中的根元素，还需要一直向上查找和路径压缩
		//在find查询中嵌入一个路径压缩操作	
		pre[x]=pre[pre[x]];//区别
		//x元素不再选择原来的父亲节点，而是直接选择父亲节点的父亲节点来做为自己新的一个父亲节点
		//这样的操作使得树的层数被压缩了		
		x=pre[x];//x压缩完毕后且x并不是根节点，x变成x新的父节点继续进行查找和压缩的同时操作
	}
	return x;//经过while循环后，x=pre[x],一定是一个根节点，且不能够再进行压缩了,我们返回即可
}
void merge(int x,int y) {	   //合并函数
	int rx=find_r(x);
	int ry=find_r(y);
	if(rx!=ry) pre[rx]=ry;
}
int main() {

	return 0;
}
