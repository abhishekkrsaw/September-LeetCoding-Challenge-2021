/*
Question Link -> https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

Example 1:
Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:
Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/

//C++ Code:

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> check(m,vector<int>(n,INT_MAX));
        using temp = tuple<int,int,int>;
        
        queue<temp> q ;
        q.push({0,0,0});
        int dis = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y,p] = q.front(); 
                q.pop();
                if(x==m-1 && y==n-1)
                    return dis;
                
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n){                        
                        if(p+grid[nx][ny]>k || check[nx][ny]<=p+grid[nx][ny])
                            continue;
                        q.push({nx,ny, p+grid[nx][ny]});
                        check[nx][ny] = p+grid[nx][ny];                        
                    }
                }                
            }
            dis++;
        }        
        return -1;
    }
};
