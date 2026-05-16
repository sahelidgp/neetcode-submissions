class Solution {
public:
    int dr[4] = {0,-1,0,1};
    int dc[4] = {1,0,-1,0};
    void dfs(vector<vector<int>>& image,int row,int col, int color,vector<vector<bool>>& vis,int stColor){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;
        vis[row][col] = true;

        for(int i=0;i<4;i++){
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == stColor && !vis[nRow][nCol]){
                dfs(image,nRow,nCol,color,vis,stColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int stColor = image[sr][sc];
        dfs(image,sr,sc,color,vis,stColor);

        return image;
    }
};