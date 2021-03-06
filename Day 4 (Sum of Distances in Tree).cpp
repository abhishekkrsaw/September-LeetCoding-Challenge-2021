/*
Question Link -> https://leetcode.com/problems/sum-of-distances-in-tree/

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes. 

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Example 2:
Input: n = 1, edges = []
Output: [0]

Example 3:
Input: n = 2, edges = [[1,0]]
Output: [1,1] 

Constraints:
  1 <= n <= 3 * 104
  edges.length == n - 1
  edges[i].length == 2
  0 <= ai, bi < n
  ai != bi
  The given input represents a valid tree
  */


//C++ Code: 

class Solution {    
public:
    
    void check(vector<vector<int>>& adj, int i, int parent, vector<int> &ans, vector<int> &total){
        for(int temp:adj[i]){
            if(temp==parent)
                continue;
            check(adj, temp, i, ans, total);
            total[i]+=total[temp];
            ans[i]+=ans[temp]+total[temp];
        }
    }
    
    void find(vector<vector<int>>& adj, int i, int parent, vector<int> &ans, vector<int> &total){
        for(int temp:adj[i]){
            if(temp==parent)
                continue;
            ans[temp] = ans[i]-total[temp]+(total.size()-total[temp]);
            find(adj, temp, i, ans, total);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {        
        vector<vector<int>>adj(n);        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> ans(n,0), total(n,1);                
        check(adj, 0, -1, ans, total);
        find(adj, 0, -1, ans, total);
        return ans;
    }   
};
