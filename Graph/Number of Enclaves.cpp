// 1020. Number of Enclaves
// Medium

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


// Example 1:
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
class Solution {
public:
int fill(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j]==0)
        return 0;
    return (g[i][j] = 0) + fill(g, i + 1, j) + fill(g, i, j + 1) 
        + fill(g, i - 1, j) + fill(g, i, j - 1);
}
    public:
int numEnclaves(vector<vector<int>>& g, int res = 0) {
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j)
            if (i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1)
                fill(g, i, j);
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j)
            // res += fill(g, i, j) > 0;
            // if(fill(g, i, j)>0)res++;
             if (g[i][j] == 1) {
                    res++;
                    // fill(g, i, j);
                }
    return res;
}

};
