
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;
int n, m;
map<string, int> mp;
struct Data {
    string id;
    int timeIn=0;
    int push_time=0;
};
struct elem {
    Data data;
    elem *next;
};

struct LinkQueue {
    elem *front; // 空
    elem *rear;
    int size = 0;

    void init() {
        size = 0;
        front = rear = new (elem);
        if (!front) cerr << "error-1";
        front->next = NULL;
    }

    void push(Data u) {
        elem *p = new(elem);
        p->data = u;
        p->next = NULL;
        rear->next = p;
        rear = p;
        size++;
    }

    Data pop() {
        if (front == rear) {
            cerr << "error0";
        }
        elem *p = front->next;
        Data tmp = p->data;
        front->next = p->next;
        if (rear == p)rear = front; // 空
        delete (p);
        size--;
        return tmp;
    }

    Data pop(string id) {
        if (front == rear || size == 0) {
            cerr << "error1";//
        }
        elem *p = front;
        Data tmp;
        while (p->next) { // 遍历
            if (p->next->data.id == id) {//删除
                if (p->next == rear)rear = p; // 更新尾指针
                tmp = p->next->data;
                p->next = p->next->next;
                size--;
                break;
            }
            p = p->next;
        }
        if (size == 0)rear = front; // 空
        delete (p);
        return tmp;
    }

} Q;

vector<Data> stk1, stk2;

void solve() {
    Q.init();
    cin >> n; //栈容量
    int tot = 0;
    string op, id;
    int time;
    while (1) {
        cin >> op ;
        if (op == "end")break;
        cin>> id >> time;
        if (op == "arrive") {
            Data tmp{id, time};
            if (stk1.size() < n) {//未满
                tmp.push_time=time;
                stk1.emplace_back(tmp);
                mp[id] = 1;
                cout << stk1.size() << endl;
            } else {
                tmp.push_time=-1;
                Q.push(tmp);
                mp[id] = 2;
                cout << Q.size << endl;
            }
        } else {
            if (mp[id] == 1) {//在stk
                while (!stk1.empty() && stk1.back().id != id) {
                    stk2.emplace_back(stk1.back());  // 意义不明的操作
                    stk1.pop_back();
                }
                if (stk1.empty())cerr << "error";
                Data top = stk1.back();
                if(~top.push_time)cout << "时间:" << time - top.timeIn << "费用" << time - top.push_time << endl;
                else cerr<<"fail";
                while (!stk2.empty()) { // 放回
                    stk1.emplace_back(stk2.back());
                    stk2.pop_back();
                }
                if (Q.size) {// 进栈
                    Data tmp = Q.pop();
                    tmp.push_time = time;      //进栈时间
                    stk1.emplace_back(tmp);
                    mp[tmp.id] = 1;
                }

            } else {//   一直在que中
                Data tmp = Q.pop();
                cout << "时间:" << time - tmp.timeIn << "费用" << 0 << endl;
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    solve();


    return 0;
}
