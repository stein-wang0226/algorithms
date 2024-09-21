#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, top = 0, tmp_top = 0;
struct Node {
	string car;
	int time;
};
Node stk[N], tmp_stk[N];
typedef struct DoubleLinkList {
	Node data;	
	DoubleLinkList* next;	
	DoubleLinkList* prev;	
}DoubleLinkList, DoubleLinkNode;
bool DoubleLinkListInit(DoubleLinkList* &L) {
	L = new DoubleLinkNode;	
	if (!L)return true;	
	L->next = NULL;	
	L->prev = NULL;	
	return true;
}
bool DoubleLinkListInsertBack(DoubleLinkList*& L, DoubleLinkNode* node) {
	DoubleLinkNode* last = NULL;
	if (!L || !node) return false;
	last = L;
	while (last->next) last = last->next;
	node->next = NULL;
	node->prev = last;
	last->next = node;
	return true;
}
Node DoubleLinkListTop(DoubleLinkList*& L) {
	DoubleLinkList* p;
	if (!L || !L->next) {
		cout << "top_双向链表为空！" << endl;
		return (Node){"", 0};
	}
	if(L->next->next == NULL) {
		p = L->next;
		Node res = p -> data;
		delete p;
		L->next = NULL;
		return res;
	}
	p = L;
	p = p->next; 
	p->prev->next = p->next;  
	p->next->prev = p->prev;
	Node res = p -> data;
	delete p;
	return res;
}
Node DoubleLinkListFind(DoubleLinkList* &L, Node n0) {
	DoubleLinkList* p;
	int index = 0;
	if (!L || !L->next) {
		cout << "find_双向链表为空！" << endl;
		return (Node){"", 0};
	}
	p = L;
	while (p && p -> data.car != n0.car) {
		p = p->next;
		index++;
	}
	if (!p)return (Node){"", 0}; //当结点不存在时，返回失败
	p->prev->next = p->next;
	p->next->prev = p->prev;
	Node res = p -> data;
	delete p;
	return res;
}
void DoubleLinkListDestroy(DoubleLinkList*  &L) {
	DoubleLinkList* p = L;
	while (p) {
		L = L->next; //L指向下一个结点
		delete p;   //删除当前结点
		p = L;     //p移向下一个结点
	}
}
bool DoubleLinkListEmpty(DoubleLinkList*  &L) {
	if(!L || !L -> next) {
		return 1;
	}
	return 0;
}
DoubleLinkList* L, s; 
void in_car(Node n0) {
	if(top < 5) {
		stk[++top] = n0;
		return;
	}
	else {
		auto tmp = new DoubleLinkNode;
		tmp -> data = n0;
		DoubleLinkListInsertBack(L, tmp);
	}
}
Node out_car(Node n0) {
	int flag = 0;
	while(top != 0) {
		//cout << stk[top].car << " " << n0.car << endl;
		if(stk[top].car == n0.car) {
			flag = 1;
			break;
		}
		tmp_stk[++tmp_top] = stk[top];
		top--;
	}
	//cout << flag << endl;
	if(flag) {
		auto res = stk[top];
		top--;
		//cout << top << "\n";
		while(tmp_top != 0) {
			stk[++top] = tmp_stk[tmp_top--];
		}
		if(!DoubleLinkListEmpty(L)) stk[++top] = DoubleLinkListTop(L);
		return res;
	}
	auto n1 = DoubleLinkListFind(L, n0);
	return n1;
}
void solve() {
	int opt, time, n;
	string car_name;
	cin >> n;
	while(n--) {
		cin >> opt >> car_name >> time;
		if(opt == 1) {
			Node n0 = {car_name, time};
			in_car(n0);
		}
		else {
			Node n1 = {car_name, time};
			Node n0 = out_car(n1);
			cout << (n1.time - n0.time) * 50 << endl;
		}
		//for(int i = 1; i <= top; i++) cout << stk[i].car << " " << stk[i].time << endl;
	}
}
int main() {
	DoubleLinkListInit(L);
	solve();
	DoubleLinkListDestroy(L);
}
