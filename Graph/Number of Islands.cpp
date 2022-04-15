// Tc O(n)
// Sc O(mxn)

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// dfs
class Solution {
    void mark_island(vector<vector<char>>& g,int x,int y,int r,int c){
        if(x<0 || x>=r ||y>=c ||y<0 || g[x][y] !='1')
            return;
        g[x][y] ='2';
         mark_island(g, x+1,y,r,c);
         mark_island(g, x,y+1,r,c);
          mark_island(g, x-1,y,r,c);
           mark_island(g, x,y-1,r,c);
                                                            
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if(row==0)return 0;
        int col=grid[0].size();
        
        int ans=0;
        for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              if(grid[i][j]=='1')
              {
                  mark_island(grid,i,j,row,col);
                  ans+=1;
              }
          }
               
        }
        return ans;
    }
};

//bfs

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
