class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length() ;
        vector<vector<bool>>dp(n,vector<bool>(n,false)) ;
        pair<int,int>p ;
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = true;
        }
        for(int g = 1 ; g <n ;g++){
            for(int i = 0,j = g ; j < n ;i++,j++){
                if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j] = true ;
                        p = {i,j} ;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = true ;
                        p = {i,j} ;
                    }
                }
            }
        }
        string ans = "" ;
        for(int i = p.first ; i <= p .second ;i++){
            ans += s[i] ;
        }
        return ans ;
    }
    
};