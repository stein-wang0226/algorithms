


class Solution {
public:
	map<int,int>vis;
	vector<int>tmp;
	void dfs(int u,vector<vector<int>>& graph,int n,vector<vector<int>>& ans){
		vis[u]=1;
		tmp.push_back(u);
        if(u==n-1){//output
        	ans.push_back(tmp);
        }
        for(auto v:graph[u]){
        	if(!vis[v])dfs(v,graph,n,ans);
        }
		//回溯
        vis[u]=0;tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    	vector<vector<int>> ans;
    	int n=graph.size();
    	vis.clear();
    	dfs(0,graph,n,ans);
    	return ans;
    }
};