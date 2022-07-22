#include <bits/stdc++.h>
using namespace std;
#define LOCAL
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
void addhead_(int a, List *plist) {  //茶在头结点后
  Node *temp = (Node *)malloc(sizeof(struct Node));
  temp->data = a;
  temp->next = plist->phead->next;
  plist->phead->next = temp;
}  // 将插到第k结点后
void add_to_pos(int data, Node *k, List *plist) {
  Node *temp = (Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = k->next;
  k->next = temp;
  if (temp->next == NULL) plist->ptail = temp;
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
void Destory(List *plist) {
  Clear(plist);                        //  清空单链表
  free(plist->phead);                  //释放剩余的头结点
  plist->phead = plist->ptail = NULL;  // 将列联表中指针变量清空
}

vector<int> scan(List*list){//遍历存储
    vector<int>ans;
    Node *temp = list->phead->next;  
do {
    ans.push_back(temp->data);
    temp = temp->next;
  } while (temp != NULL);
  return ans;
}
void output(List *plist) {
  Node *temp = plist->phead->next;  //头结点无值
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != NULL);
}
void insert(int t,List *list){   // 插入操作 将t按序插入
 if (list->phead->next == NULL) {  //空
        addtail(t, list);
        return;
      }
      Node *temp = list->phead->next;
      Node *pos = list->phead;
      while (temp->data < t) {  //找最后一个比t小的
        pos = temp;
        temp = temp->next;
        if (temp == NULL) break;
      }
      if (pos == list->phead)
        addhead_(t, list);  //插在头上
      else if (pos->next != NULL)
        add_to_pos(t, pos, list);  // 插在中间
      else
        addtail(t, list);  //插在末尾
}
void merge(List *list1,List*list2){//将list2 合入list1中
  Node *temp=list2->phead->next;
  while(temp!=NULL){
    insert(temp->data,list1);
    temp=temp->next;
  }
}
void reverse (List *list){//翻转
  vector<int>v=scan(list);//储存
  Clear(list);  // 情空
  for(int i=v.size()-1;i>=0;i--){
  addtail(v[i],list);
  }//
}
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n;
  List list1 = create();
  List list2 = create();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t > 0) {
      insert(t,&list1);
    } else if (t < 0) {
      insert(t,&list2);
    }
  }
  output(&list1);
  cout << endl;
  output(&list2);
  merge(&list1,&list2);
  cout<<endl;
  output(&list1);
  //   cout<<endl;
  //   reverse(&list1);
  //   output(&list1);
  //   cout<<endl;
  //    reverse(&list2);
  //   output(&list2);
  //   cout<<endl;
  // Destory(&list1);
  // Destory(&list2);

  return 0;
}
