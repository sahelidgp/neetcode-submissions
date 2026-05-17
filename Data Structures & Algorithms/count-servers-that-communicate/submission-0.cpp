class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int,int>row_map;
        unordered_map<int,int>col_map;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                {
                    row_map[i]++;
                    col_map[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && (row_map[i]>1 || col_map[j]>1)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};