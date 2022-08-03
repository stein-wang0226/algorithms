    class Solution {
    public:
    	int longestCycle(vector<int>& edges) {
    		int n=edges.size();
    		map<int,int>cnt1;
    		map<int,int>vis;
    		vis.clear();
    		int ans=-1;
    		for(int i=0;i<n;i++){
    			if(vis[i]||edges[i]==-1)continue;
    			cnt1.clear();
    			vis[i]=1;
    			int cnt=1;
    			int tmp=i;
    			cnt1[tmp]=1;
    			while(~edges[tmp]){
    				tmp=edges[tmp];
    				if(cnt1[tmp]){
    					ans=max(ans,cnt+1-cnt1[tmp]);
    					break;
    				}
    				if(vis[tmp])break;
    				vis[tmp]=1;
    				cnt1[tmp]=++cnt;
    			}
    		}
    		return ans;
    	}
    }s;