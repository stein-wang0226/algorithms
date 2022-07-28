//合并两组区间：每次关心末端点最小的


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i=0,j=0;
        vector<vector<int>>res ;
       while(i<firstList.size()&&j<secondList.size()){
                int maxx=min(firstList[i][1],secondList[j][1]);
                int minn=max(firstList[i][0],secondList[j][0]);
                
            if(firstList[i][1]<=secondList[j][1]){
                    i++;
            }
            else j++;
            vector<int>tmp;
            if(maxx>=minn){
                    tmp.push_back(minn);
                    tmp.push_back(maxx);
                    res.push_back(tmp);
            }


        }
        return res;
    }
};