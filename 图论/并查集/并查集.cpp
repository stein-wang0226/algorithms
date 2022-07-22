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
int find_r(int x) {//�ݹ�

	if (x != pre[x]) pre[x] = find_r(pre[x]);

	return pre[x];

}
//ѭ��
int find_r(int x) {
	while(x != pre[x]) { //���xԪ�صĸ���ָ��ָ��Ĳ����Լ���˵��x�����Ǽ����еĸ�Ԫ�أ�����Ҫһֱ���ϲ��Һ�·��ѹ��
		//��find��ѯ��Ƕ��һ��·��ѹ������
		pre[x]=pre[pre[x]];
		//xԪ�ز���ѡ��ԭ���ĸ��׽ڵ㣬����ֱ��ѡ���׽ڵ�ĸ��׽ڵ�����Ϊ�Լ��µ�һ�����׽ڵ�
		//�����Ĳ���ʹ�����Ĳ�����ѹ����
		x=pre[x];//xѹ����Ϻ���x�����Ǹ��ڵ㣬x���x�µĸ��ڵ�������в��Һ�ѹ����ͬʱ����
	}
	return x;//����whileѭ����x=pre[x],һ����һ�����ڵ㣬�Ҳ��ܹ��ٽ���ѹ����,���Ƿ��ؼ���
}



void merge(int x,int y) {	   //�ϲ�����
	int rootx=find_pre(x);
	int rooty=find_pre(y);
	if(rootx!=rooty) pre[rootx]=rooty;
}

int main() {
	int n,k;//��������������
	int m,x,y;//mΪ������
	cin>>n>>k;
	init(n);
	for(int i=0; i<k; i++) {
		cin>>m;
		if(m==1) {
			cin>>x>>y;
			merge(x,y);
		} else if(m==2) {
			divide(x,y);//ȡ����һ��
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


