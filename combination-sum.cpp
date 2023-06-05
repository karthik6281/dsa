class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int>dp ;
        func(0,target,candidates,dp,ans) ;
        return ans ;
    }
    void func(int i ,int target , vector<int>nums , vector<int>&dp , vector<vector<int>>&ans){
        if(i==nums.size())return ;
        if(target==0){
            ans.push_back(dp) ;
            return ;
        }
        if(nums[i] <= target){
            dp.push_back(nums[i]) ;
            func(i,target-nums[i],nums,dp,ans) ;
            dp.pop_back() ;
        }
        func(i+1,target,nums,dp,ans) ;
    }
};