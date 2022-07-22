#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 1e5 + 5;
//链表操作
//结点
struct Node {
  int data;
  struct Node *next;
};

struct List {
  struct Node *phead;
  struct Node *ptail;
};
typedef struct Node *Position;  //
// 1.创建链表
List create() {
  List list;
  //  申请一个结点
  list.phead = list.ptail = (Node *)malloc(sizeof(struct Node));
  if (list.phead != NULL) list.phead->next = NULL;  //后续为空
  return list;
}  //返回
//在尾部添加结点
void addtail(int a, List *plist) {
  Node *temp = (Node *)malloc(sizeof(struct Node));
  temp->data = a;
  temp->next = NULL;
  if (NULL == plist->phead) {
    plist->phead = temp;  //
  } else {
    plist->ptail->next = temp;
  }
  plist->ptail = temp;  //尾结点应该始终指向最后一个
}
// 插到头结点前
void addhead(int a, List *plist) {
  Node *temp = (Node *)malloc(sizeof(struct Node));
  temp->data = a;
  temp->next = plist->phead;  // 插到头结点前
  plist->phead = temp;        //更新头结点
}
// 2.链表清空
//释放链表中除头节点外所有结点
void Clear(List *plist) {
  Node *p = plist->phead->next;  //从链表头结点的后继结点开始清空
  while (p != NULL) {            //直到最后
    Node *q = p;                 //  记录该节点用于释放
    p = p->next;                 // 移动到下一个
    free(q);
  }
  plist->phead->next = NULL;    //头结点后已无结点
  plist->ptail = plist->phead;  //初始化头尾结点
}
//销毁线性表
void Destory(struct List *plist) {
  Clear(plist);                        //  清空单链表
  free(plist->phead);                  //释放剩余的头结点
  plist->phead = plist->ptail = NULL;  // 将列联表中指针变量清空
}

void output(List *plist) {
  Node *temp = plist->phead->next;  //头结点无值
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != NULL);
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n, m, k;
  List plist = create();
  cin >> m >> n >> k;
  vector<int> res1;
  for (int i = 1; i <= m; i++) {
    addtail(i, &plist);
  }

  plist.ptail->next = plist.phead->next;  //环形
  Node *temp = plist.phead->next;         //从第1个开始
  int mm = m;
  while (m--) {                         //还有人
    for (int i = 1; i <= n - 2; i++) {  //后移n-2人
      temp = temp->next;
    }
    //删第n-1个
    Node *p = (temp->next);
    cout << p->data << " ";
    res1.push_back(p->data);
    if (m)
      temp->next = temp->next->next;
    else {
      plist.phead->next = NULL;
      break;
    }                   //最后一个
    free(p);            //清楚p
    temp = temp->next;  // 从下一个开始
  }
  Destory(&plist);
  List plist2 = create();
  for (auto i : res1) {
    addtail(i, &plist2);
  }
  plist2.ptail->next = plist2.phead->next;  //环形
  Node *temp2 = plist2.phead->next;          //从第1个开始
  while (mm--) {
    for (int i = 1; i <= n - 2; i++) {  //后移n-2人
      temp2 = temp2->next;
    }
    //删第n-1个
    Node *p = (temp2->next);
    cout << p->data << " ";
    if (mm)
      temp2->next = temp2->next->next;
    else {
      plist2.phead->next = NULL;
      break;
    }                   //最后一个
    free(p);            //清楚p
    temp2 = temp2->next;  // 从下一个开始
  }
  return 0;
}