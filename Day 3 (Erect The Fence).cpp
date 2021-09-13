/*
Question Link -> https://leetcode.com/problems/erect-the-fence/

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.
Return the coordinates of trees that are exactly located on the fence perimeter. 

Example 1:
Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]

Example 2:
Input: points = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]] 

Constraints:
1 <= points.length <= 3000
points[i].length == 2
0 <= xi, yi <= 100
All the given points are unique.
*/


//C++ Code:

class Solution {
public:
    
    static bool compr(const vector<int> &a, const vector<int> &b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    static bool compr2(const vector<int> &a, const vector<int> &b){
        return a[0]==b[0] && a[1]==b[1];
    }   
    
    bool slope(const vector<int> &o, const vector<int> &a, const vector<int> &b){
        int c = (b[1]-o[1])*(a[0]-o[0]) - (a[1]-o[1])*(b[0]-o[0]);
        if(c<0)
            return true;
        return false;
    }    
    
    // Used the concept of Convex Hull
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end(),compr);
        vector<vector<int>> lower,upper,ans;     // lower hull, upper hull, final hull
        int p=-1;
        for(int i=0;i<trees.size();i++)
        {
            while(p>0 && slope(lower[p-1],lower[p],trees[i])){
                lower.pop_back();
                p--;
            }
            lower.push_back(trees[i]);
            p++;
        }
        p=-1;
        for(int i=trees.size()-1;i>=0;i--)
        {
            while(p>0 && slope(upper[p-1],upper[p],trees[i])){
                upper.pop_back();
                p--;
            }
            upper.push_back(trees[i]);
            p++;
        }
        
        for(int i=0;i<lower.size();i++)
            ans.push_back(lower[i]);
        for(int i=0;i<upper.size();i++)
            ans.push_back(upper[i]);
        
        sort(ans.begin(),ans.end(),compr);
        ans.erase(unique(ans.begin(),ans.end(),compr2),ans.end());    //erasing the duplicate elements
        return ans;
    }
};
