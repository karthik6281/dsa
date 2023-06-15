class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0] ; 
        int count = 1 ;
        int n = nums.size() ;
        for(int i = 1 ; i < n ;i++){
            if(count==0){el = nums[i] ;count++ ;}
            else if(nums[i]!=el)count-- ;
            else count++ ;
        }
        return el ;
    }
};