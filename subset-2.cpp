class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans ;
        sort(nums.begin(),nums.end()) ;
        vector<int>dp ;
        func(0,nums,dp,ans) ;
        return ans ;
    }
    void func(int a , vector<int>nums,vector<int>&dp,vector<vector<int>>&ans){
        ans.push_back(dp) ;
        for(int i = a ; i < nums.size() ;i++){
            if(i>a && nums[i]==nums[i-1])continue ;
            dp.push_back(nums[i]) ;
            func(i+1,nums,dp,ans) ;
            dp.pop_back() ;
        }
        return ;
    }
};