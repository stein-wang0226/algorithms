#include <bits/stdc++.h>//jump  ��������������к� 
using namespace std;
int a[1005],ans[10005],n,t,x;
int main() {
	while(~scanf("%d",&n)&&n) {//���뷽ʽ
		memset(a,0,sizeof a);
		memset(a,0,sizeof a);
		for(int i=1; i<=n; i++) { //���������a[0]
			scanf("%d",&a[i]);//input
			ans[i]=a[i];//��ֵ��ans�У�����ǰi�������
		}
		int Max=0;
		for(int i=0; i<=n; i++) {

			int k=ans[0];//����ǰi���ans���ֵ
			for(int j=0; j<i; j++) {
				if(ans[j]>k&&a[j]<a[i])k=ans[j];//�ҵ����� �����ans
			}
			ans[i]+=k;
			if(ans[i]>Max)Max=ans[i];
		}

		cout<<Max<<"\n";
	}
	return 0;
}
