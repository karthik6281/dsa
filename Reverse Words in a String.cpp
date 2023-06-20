class Solution {
public:
    string reverseWords(string s) {
        int left = 0 ;
        int right = 0 ;
        int n = s.length() ;
        vector<string>v ;
        string word = "" ;
        while(right<n){
            // cout << left << " " << right << endl ;
            if(s[right]==' '){
                right++ ;left=right ;
            }
            else if(s[right+1]==' ' || right==n-1){
                v.push_back(s.substr(left,right-left+1)) ;
                right++ ;
            }
            else right++ ;
        }
        string ans ;
        reverse(v.begin(),v.end()) ;
        int len = v.size() ;
        for(int i = 0 ; i < len ; i++){
            if(i==len-1)ans+=v[i] ;
            else ans += v[i] + ' ' ;
        }
        return ans ;
    }
};

// 

class Solution {
public:
    string reverseWords(string s) {
        int left = 0 ;
        int right = 0 ;
        int n = s.length() ;
        string word = "" ;
        string ans = "" ;
        while(right<n){
            // cout << left << " " << right << endl ;
            if(s[right]==' '){
                right++ ;left=right ;
            }
            else if(s[right+1]==' ' || right==n-1){
                ans= " " + s.substr(left,right-left+1) + ans ;
                right++ ;
            }
            else right++ ;
        }
        int len = ans.length() ;
        return ans.substr(1,len-1) ;
    }
};

// 

class Solution {
public:
    string reverseWords(string s) {
        int left = 0 ;
        int right = 0 ;
        int n = s.length() ;
        string word = "" ;
        string ans = "" ;
        string str = "" ;
        while(right<n){
            if(s[right]==' '){
                right++ ;left=right ;
            }
            else if(s[right+1]==' ' || right==n-1){
                str += s[right] ;
                ans= " "+str + ans ; str = "" ;
                right++ ;
            }
            else{
                str += s[right] ;
                right++ ;
            }
        }
        int len = ans.length() ;
        return ans.substr(1,len-1) ;
    }
};