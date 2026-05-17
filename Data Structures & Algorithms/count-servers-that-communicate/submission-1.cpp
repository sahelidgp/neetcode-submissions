class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>rowAloneCount(n+1);
        vector<int>colCount(m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)colCount[j]++;
            }
        }
        int result = 0;
        for(int i=0;i<n;i++){
            int rowcnt = accumulate(grid[i].begin(),grid[i].end(),0);
            if(rowcnt > 1){
                result += rowcnt;
            }else if(rowcnt == 1){
                int index = find(grid[i].begin(), grid[i].end(), 1)-grid[i].begin();
                if(colCount[index] >1)result++;
            }
        }
        return result;
    }
};