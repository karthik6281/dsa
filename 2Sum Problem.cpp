// ----hashing------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        unordered_map<int,vector<int>> m ;
        for(int i = 0 ; i < n ;i++){
            m[nums[i]].push_back(i) ;
        }
        vector<int>ans ;
        for(int i = 0 ; i < n ; i++){
            if((target/2 == nums[i])){
                if(m[nums[i]].size() >=2)return m[nums[i]] ;
            }
            else if(m[target-nums[i]].size()!=0){
                ans.push_back(i) ;
                ans.push_back(m[target-nums[i]][0]) ;
                break ;
            }
        }
        return ans ;
    }
};

// ----sort + 2 pointer -> beats 95 percent -----
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp = nums ;
        sort(nums.begin(),nums.end()) ;
        int n = nums.size() ;
        int s = 0 ;
        int e  = n-1 ;
        vector<int>ans ;
        while(s<=e){
            if(nums[s]+nums[e] == target){
                ans.push_back(nums[s]) ;
                ans.push_back(nums[e]) ;
                break ;
            }
            else if(nums[s]+nums[e] < target)s++ ;
            else e-- ;
        }
        int a = find(temp.begin(),temp.end(),ans[0])-temp.begin() ;
        reverse(temp.begin(),temp.end()) ;
        int b = find(temp.begin(),temp.end(),ans[1])-temp.begin() ;
        int c = n-b-1 ;
        ans[0] = a ;
        ans[1] = c ;
        return ans ;
    }
};