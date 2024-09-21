#include "bits/stdc++.h"

using namespace std;

//lc23
// 合并k个升序列表 -- 分治法
struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    return  merge(lists, 0, n - 1);
  }

    //递归分治 返回头节点
  ListNode *merge(vector<ListNode *> &lists, int l, int r) {
    if (l == r)return lists[l];
    if (l > r)return nullptr;
        //分治
    int mid = (l + r) >> 1;
    auto p1 = merge(lists, l, mid);
    auto p2 = merge(lists, mid + 1, r);
    if (!p1)return p2;
    if (!p2)return p1;
    ListNode *head = new(ListNode), *cur1 = p1, *cur2 = p2, *last = head;
    while (cur1 && cur2) {
      if (cur1->val < cur2->val) {
        last->next = cur1;
        cur1 = cur1->next;
      } else {
        last->next = cur2;
        cur2 = cur2->next;
      }
      last = last->next;
    }
        // 剩余的p1 或p2 直接连上
    if(cur1)last->next = cur1;
    if(cur2) last->next = cur2;
    return head->next;
  }
};
