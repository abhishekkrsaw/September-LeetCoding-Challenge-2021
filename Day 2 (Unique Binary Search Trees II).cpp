/*
Question Link -> https://leetcode.com/problems/unique-binary-search-trees-ii/

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order. 

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]] 

Constraints:
1 <= n <= 8
*/


//C++ Code:

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateBSTs(1,n);
    }
    
    vector<TreeNode*> generateBSTs(int start, int end)
    {
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> lst = generateBSTs(start,i-1);
            vector<TreeNode*> rst = generateBSTs(i+1,end);
            for(int j=0;j<lst.size();j++)
            {
                for(int k=0;k<rst.size();k++)
                {
                    TreeNode *root = new TreeNode(i,lst[j],rst[k]);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
