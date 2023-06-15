class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2 ;
        double res = 1 ;
        int r = min(m-1,n-1) ;
        for(int i = 1 ; i <=r ;i++){
            res = res*(N-i+1)/i ;
        }
        return (int)res ;
    }
};