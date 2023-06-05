class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int>dp ;
        sort(candidates.begin(),candidates.end()) ;
        func(0,target,candidates,dp,ans) ;
        return ans ;
    }
    void func(int a ,int target , vector<int>nums , vector<int>&dp , vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(dp) ;
            return ;
        }
        if(a==nums.size())return ;
        for(int i = a ; i < nums.size() ; i++){
            if(i>a && nums[i] == nums[i-1])continue ;
            if(nums[i] <= target){
                dp.push_back(nums[i]) ;
                func(i+1,target-nums[i] , nums,dp,ans) ;
                dp.pop_back() ;
            }
        }
        return ;
    }
};