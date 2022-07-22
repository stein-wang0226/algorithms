struct edge {
    int v,next;
}e[Mm];
int tot,head[Mn];
void addedge(int u,int v) {
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int mx[Mn],my[Mn],vis[Mn];
int dis;
int dx[Mn],dy[Mn];
int n,m;
bool searchp() {
    queue<int>q;
    dis=INF;
    CLR(dx,-1);
    CLR(dy,-1);
    for(int i=1;i<=n;i++) {
        if(mx[i]==-1) {
            q.push(i);
            dx[i]=0;
        }
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(dx[u]>dis) break;
        for(int i=head[u];~i;i=e[i].next) {
            int v=e[i].v;
            if(dy[v]==-1) {
                dy[v]=dx[u]+1;
                if(my[v]==-1) dis=dy[v];
                else {
                    dx[my[v]]=dy[v]+1;
                    q.push(my[v]);
                }
            }
        }
    }
    return dis!=INF;
}
bool dfs(int u) {
    for(int i=head[u];~i;i=e[i].next) {
        int v=e[i].v;
        if(vis[v]||(dy[v]!=dx[u]+1)) continue;
        vis[v]=1;
        if(my[v]!=-1&&dy[v]==dis) continue;
        if(my[v]==-1||dfs(my[v])) {
            my[v]=u;
            mx[u]=v;
            return true;
        }
    }
    return false;
}
int maxMatch() {
    int res = 0;
    CLR(mx,-1);
    CLR(my,-1);
    while(searchp()) {
        CLR(vis,0);
        for(int i=1;i<=n; i++)
            if(mx[i] == -1 && dfs(i))
                res++;
    }
    return res;
}
void init() {
    tot=0;
    CLR(head,-1);
}