class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>ans ;
        if(n==1){
            ans.push_back(nums[0]) ;
            return ans ;
        }
        int count1 = 0 ;
        int count2 = 0 ;
        int el1 = INT_MIN ; 
        int el2 = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(count1==0 && nums[i]!=el2){
                el1 = nums[i] ;
                count1++ ;
            }
            else if(count2==0 && nums[i]!=el1){
                el2= nums[i] ;
                count2++ ;
            }
            else if(nums[i]==el1)count1++ ;
            else if(nums[i]==el2)count2++ ;
            else{
                count1-- ;count2-- ;
            }
        }
        int mini =( int)(n/3)+ 1 ;
        int a = 0 ;  int b = 0 ;
        for(int i = 0 ; i < n ;i++){
            if(nums[i]==el1)a++ ;
            else if(nums[i]==el2)b++ ;
        }
        if(a>=mini)ans.push_back(el1) ;
        if(b>=mini)ans.push_back(el2) ;
        return ans ;
    }
};