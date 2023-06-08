class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1)return nums[0] ;
        int s = 0 ;
        int e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            if(mid-1 >= 0 && nums[mid-1]==nums[mid]){
                if((n-mid-1)%2 == 0)e = mid-1 ;
                else s = mid+1 ;
            }
            else if(mid+1 <= n-1 && nums[mid+1]==nums[mid]){
                if((n-mid-1)%2 != 0)e = mid-1 ;
                else s = mid+1 ;
            }
            else{
                return nums[mid] ;
            }
        }
        return nums[s] ;
    }
};