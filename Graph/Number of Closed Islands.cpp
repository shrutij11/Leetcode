// 1254. Number of Closed Islands
// Medium

// Given a 2D grid consists of 0s (land) and 1s (water).  
//   An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands.

// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
class Solution {
int fill(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j])
        return 0;
    return (g[i][j] = 1) + fill(g, i + 1, j) + fill(g, i, j + 1) 
        + fill(g, i - 1, j) + fill(g, i, j - 1);
}
    public:
int closedIsland(vector<vector<int>>& g, int res = 0) {
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j)
            if (i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1)
                fill(g, i, j);
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j)
            // res += fill(g, i, j) > 0;
            // if(fill(g, i, j)>0)res++;
             if (g[i][j] == 0) {
                    res++;
                    fill(g, i, j);
                }
    return res;
}
};
