#include<iostream>
using namespace std;
const int MAX=100005;			//�������󳤶ȣ���ͼ�е���������ֵ��
int m,n;						//��ǰͼ�ĳ�����
int pre[MAX];					//���ڴ��ÿ����ĸ��ڵ�
void init(int n) {			//��ʼ������
	for(int i=1; i<=n; i++)
		pre[i]=i;
}
int find_r(int key) {	   //Ѱ�Ҹ��ڵ㺯��
	int r=key;
	while(r!=pre[r])
		r=pre[r];

	return r;
}
//**������·��ѹ����find����
int find(int x) {//�ݹ�
	if (x != pre[x]) pre[x] = find_r(pre[x]);//
	return pre[x];
}
//ѭ��
int _find(int x) {
	while(x != pre[x]) { //���xԪ�صĸ���ָ��Ĳ����Լ���˵��x�����Ǽ����еĸ�Ԫ�أ�����Ҫһֱ���ϲ��Һ�·��ѹ��
		//��find��ѯ��Ƕ��һ��·��ѹ������	
		pre[x]=pre[pre[x]];//����
		//xԪ�ز���ѡ��ԭ���ĸ��׽ڵ㣬����ֱ��ѡ���׽ڵ�ĸ��׽ڵ�����Ϊ�Լ��µ�һ�����׽ڵ�
		//�����Ĳ���ʹ�����Ĳ�����ѹ����		
		x=pre[x];//xѹ����Ϻ���x�����Ǹ��ڵ㣬x���x�µĸ��ڵ�������в��Һ�ѹ����ͬʱ����
	}
	return x;//����whileѭ����x=pre[x],һ����һ�����ڵ㣬�Ҳ��ܹ��ٽ���ѹ����,���Ƿ��ؼ���
}
void merge(int x,int y) {	   //�ϲ�����
	int rx=find_r(x);
	int ry=find_r(y);
	if(rx!=ry) pre[rx]=ry;
}
int main() {

	return 0;
}
