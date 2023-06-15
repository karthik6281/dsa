class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>>ans ;
        int n = nums.size() ;
        int i = 0 ;
        while(i<=n-3){
            int j = i+1 ;
            int k = n-1 ;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp = {nums[i],nums[j],nums[k]} ;
                    ans.push_back(temp) ;
                    int a = nums[j] ;
                    int b = nums[k] ;
                    while(j<n-1 && nums[j]==a){
                        {if(j>k)break ;}j++ ;
                    }
                    while(k>j && nums[k]==b){
                        {if(k<j)break ;}k-- ;
                    }
                }
                else if (nums[i]+nums[j]+nums[k]<0)j++ ;
                else k-- ;
            }
            int c = nums[i] ;
            while(i<=n-3 && nums[i]==c){i++ ;}
        }
        return ans ;
    }

};