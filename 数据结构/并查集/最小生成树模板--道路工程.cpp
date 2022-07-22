#include <bits/stdc++.h>
using namespace std;
//��С������
int pre[105], m, n, t;
void init(int n) {  //��ʼ��Ϊ����
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
	}
}
int find_r(int x) {   //Ѱ�Ҹ��ڵ㺯��
	while (pre[x] != x) {  //��Ϊ��
		x = pre[x];       //һֱ������
	}
	return x;
}
void merge(int x, int y) {
	int root_x = find_r(x);
	int root_y = find_r(y);
	if (root_x != root_y) {  //������ͬһ����
		pre[root_x] = root_y;  //�ϲ�
	}
}
struct edge {
	int from, to, dis;
	bool operator<(const edge &b) const {
		return dis < b.dis;  //����
	}
} a[6000];
int main() {
	while (~scanf("%d",&n),n) {
		int ans=0;
		init(n);
		memset(a,0,sizeof a);
		for (int i = 1; i <= n * (n - 1) / 2; i++) {
			scanf("%d %d %d",&a[i].from,&a[i].to,&a[i].dis);
		}
		sort(a + 1, a + n * (n - 1) / 2+1);  //��������
		for (int i = 1; i <= n * (n - 1) / 2; i++) {
			int x=a[i].to;
			int y=a[i].from;
			if(find_r(x)!=find_r(y)) { //������ͬһ���Ϻϲ� ����ֹ�ɻ�
				merge(x,y);
				ans+=a[i].dis;
			}
		}
		printf("%d\n",ans);
	}
}

