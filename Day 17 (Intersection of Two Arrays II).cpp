/*
Question Link -> https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both 
arrays and you may return the result in any order. 

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted. 

Constraints:
  1 <= nums1.length, nums2.length <= 1000
  0 <= nums1[i], nums2[i] <= 1000
*/

//C++ Code

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size()-1, m=nums2.size()-1;
        while(n>=0 && m>=0){
            if(nums1[n]==nums2[m]){
                ans.push_back(nums1[n]);
                m--;
                n--;
            }
            else if(nums1[n]>nums2[m])
                n--;
            else
                m--;
        }
        return ans;
    }
};
