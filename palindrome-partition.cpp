class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string>dp ;
        func(0,s,dp,ans) ;
        return ans ;
    }
    bool isPalindrome(string r){
        int n = r.length() ;
        int p = 0 ;
        int q = n-1 ;
        while(p<=q){
            if(r[p++] != r[q--])return false ;
        }
        return true ;
    }
    void func(int a , string s ,vector<string>&dp , vector<vector<string>>&ans){
        if(a==s.length()){
            ans.push_back(dp) ;
        }
        for(int i = a ; i < s.length(); i++){
            string r = s.substr(a,i-a+1) ;
            if(isPalindrome(r)){
                dp.push_back(r) ;
                func(i+1,s,dp,ans) ;
                dp.pop_back() ;
            }
        }
        return ;
    }
};