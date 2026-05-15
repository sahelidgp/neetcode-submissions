class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int e = trust.size();
        vector<int>indegree(n+1);
        vector<int>outdegree(n+1);
        for(int i=0;i<e;i++){
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(indegree[i] == n-1 && outdegree[i] == 0)return i;
        }
        return -1;
    }
};