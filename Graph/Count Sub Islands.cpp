// 1905. Count Sub Islands
// Medium

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical).
//  Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.
// Example 1:

// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.



class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          int count=0;
        int m=grid2.size();
        int n=grid2[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int flag=1;
              
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,flag);
                    if(flag==1)count++;
                }
            }
        }
        return count;
    }  
        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j, int &flag){
            if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size()|| grid2[i][j]==0)return ;
           
            if( grid2[i][j]==1){
                  if(grid1[i][j]==0){
                      flag=0;
                      return;
                  }
                  grid2[i][j]=0;
            }
            dfs(grid1,grid2,i-1,j,flag);
             dfs(grid1,grid2,i,j-1,flag);
             dfs(grid1,grid2,i+1,j,flag);
             dfs(grid1,grid2,i,j+1,flag);
        }
    
};
