class Solution {
public:
    int check(int i , vector<int>nums){
        int n = nums.size() ;
        int mini = INT_MAX ;
        int ind = i+1 ;
        for(int j = i+1 ; j < n ;j++){
            if(nums[j] > nums[i]){
                if(min(mini,nums[j]) == nums[j]){
                    mini = nums[j] ;
                    ind = j ;
                }
            }
        }
        return ind ;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int ind = n-1 ;
        while(ind>0){
            if(nums[ind-1] < nums[ind]){
                int pos = check(ind-1,nums) ;
                swap(nums[ind-1],nums[pos]) ;
                break ;
            }
            else ind-- ;
        }
        reverse(nums.begin()+ind , nums.end()) ;  //sort also works
    }
};

// one-line solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end()) ;
        // return nums ;
    }
};