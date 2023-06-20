class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>m ;
        int left = 0 ;
        int right = 0 ;
        int maxi = 1 ;
        int n = s.length() ;
        if (n == 0)return 0 ;
        m.insert(s[0]) ;
        right = 1 ;
        while(right<n){
            if(m.find(s[right])!=m.end()){
                while(s[left]!=s[right]){
                    m.erase(s[left]) ;left++ ;
                }
                left++ ;
            }
            else{
                m.insert(s[right]) ;
                maxi = max(maxi,right-left+1) ;
            }
            right++ ;
        }
        return maxi ;
    }
};