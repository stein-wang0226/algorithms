#include <bits/stdc++.h>//jump  ��������������к� 
#define ll long long
using namespace std;//stl��
const int  m[4]= {2,3,5,7};
int main () {
	set<ll>Set;//
	int n;
	while(~scanf("%d",&n)&&n) {//���뷽ʽ
		Set.clear();
		priority_queue<ll ,vector<ll> ,greater<ll > >que;//�������ȶ��� ȡ��������Ͷ�
		que.push(1);
		Set.insert(1);
		for(int i=1;; i++) { //ȡ����i�����ж�
			ll x=que.top(); //miȡ��
			que.pop();
			if(i==n) {//output
				if(i%10==1&&i % 100!=11)printf("The %dst humble number is %d.\n",i,x);
				else if(n%10==2&&n % 100!=12)printf("The %dnd humble number is %d.\n",i,x);
				else if(n%10==3&&n % 100!=13)printf("The %drd humble number is %d.\n",i,x);
				else
					printf("The %dth humble number is %d.\n",i,x);
					break;
			}
			for(int j=0; j<4; j++) { //�ֱ���С���2 3 5 7������
				ll x2=x*m[j];
				if(!Set.count(x2)) {
					Set.insert(x2);
					que.push(x2);
				}
			}
		}
	}
	return 0;
}
