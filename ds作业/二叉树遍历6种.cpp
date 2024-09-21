// 二叉树三种遍历 递归 非递归
#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    Node* lchild;
    Node* rchild;
}node[1005];
typedef  Node*  Bitree;
void Create(Bitree &root){ // 递归构造二叉树(先序)  传引用
    int n;
    cin>>n;
    if(n==-1){
        root=NULL;
        return ;
    }
    root=new Node;
    root->data=n;
    Create(root->lchild);
    Create(root->rchild);
}
void visit(Node*u){
    if(u==NULL)return;
    cout<<u->data;
}
void PreTraverse(Node*root){ // 递归 先序
    if(root==NULL)return ;
    visit(root);
    PreTraverse(root->lchild);
    PreTraverse(root->rchild);
}
void InTraverse(Node*root){ // 递归 中序
    if(root==NULL)return ;
    InTraverse(root->lchild);
    visit(root);
    InTraverse(root->rchild);
}
void LaTraverse(Node*root){ // 递归 后序
    if(root==NULL)return ;
    LaTraverse(root->lchild);
    LaTraverse(root->rchild);
    visit(root);
}
//非递归
void Pre_Traverse(Node*root){//先序
    stack<Node*>stk;
    if(root==NULL)return;

    stk.push(root);//根入栈
    while(!stk.empty()){
        auto cur=stk.top();
        stk.pop();
        visit(cur); // 出栈访问  
        //入栈先又再左  出栈才先左再右
        if(cur)stk.push(cur->rchild);
        if(cur)stk.push(cur->lchild);
    }
}
void In_Traverse(Node*root){ // 中序  先序也可以按这个方式写；
    stack<Node*>stk;
    if(root==NULL)return;
    stk.push(root);
    while(!stk.empty()){
        while(stk.top()!=NULL){
            stk.push(stk.top()->lchild);// 向左到头  中->左
        }
        stk.pop(); //空指针弹出
        if (!stk.empty()){
            auto u =stk.top();visit(u);// 访问结点
            stk.pop();
            if(u)stk.push(u->rchild);// 向右一步
        }
    }
}
void La_Traverse(Node*root){//后序
    stack<Node*>stk1,stk2; // 先根后左后右入栈  出栈序的倒序 
    if(root==NULL)return;
    stk1.push(root);
    while(!stk1.empty()){
        auto u=stk1.top();
        stk2.push(u);//
        stk1.pop();
        if(u)stk1.push(u->lchild);
        if(u)stk1.push(u->rchild);
    }
    while(!stk2.empty()){
        visit(stk2.top());
        stk2.pop();
    }
}
int main(){
    Bitree root=nullptr;
    Create(root);
    PreTraverse(root);cout<<endl;
    Pre_Traverse(root);cout<<endl;
    In_Traverse(root);cout<<endl;
    InTraverse(root);cout<<endl;
    LaTraverse(root);cout<<endl;
    La_Traverse(root);cout<<endl;

}






