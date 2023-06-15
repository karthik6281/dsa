class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<vector<int>>ans ;
        if(n<4)return ans ;
        sort(nums.begin(),nums.end()) ;
        int p = 0 ;
        while(p<=n-4){
            int i = p+1 ;
            while(i<=n-3){
                int j = i+1 ;
                int k = n-1 ;
                while(j<k){
                    long long sum = nums[p] ;
                    sum += nums[i] ;
                    sum += nums[j] ;
                    sum += nums[k] ;
                    if(sum==target){
                        vector<int>temp = {nums[p],nums[i],nums[j],nums[k]} ;
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
                    else if (sum<target)j++ ;
                    else k-- ;
                }
                int c = nums[i] ;
                while(i<=n-3 && nums[i]==c){i++ ;}
            }
            int d = nums[p] ;
            while(p<=n-4 && nums[p]==d){p++ ;}
        }
        return ans ;
    }
};