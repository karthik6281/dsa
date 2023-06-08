class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        if(n==1)return nums[0] == target ? 0 : -1 ;
        int s = 0 ; 
        int e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            if(nums[mid]==target)return mid ;
            if(nums[mid] >= nums[0]){
                if(nums[mid] > target){
                    if(target >= nums[0])e = mid-1 ;
                    else s = mid+1 ;
                }
                else s = mid+1 ;
            }
            else{
                if(nums[mid] > target){
                    if(target < nums[n-1])e = mid-1 ;
                    else s = mid+1 ;
                }
                else{
                    if(target <= nums[n-1])s = mid+1 ;
                    else e = mid-1 ;
                }
            }
        }
        if(s>=0 && s<=n-1 && nums[s]==target)return s ;
        if(e>=0 && e<=n-1 && nums[e]==target)return e ;
        return -1 ;
    }
};