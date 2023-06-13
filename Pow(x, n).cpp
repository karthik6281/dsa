class Solution {
public:
    double myPow(double x, int n) {
        long long m = n ;
        if(m<0)m=-1*m ;
        double ans = 1.0 ;
        while(m){
            if(m%2==1){
                ans = ans*x ;
                m = m-1 ;
            }
            else{
                x = x*x ;
                m = m/2 ;
            }
        }
        if(n<0)return 1/ans ;
        return ans ;
    }
};

class Solution {
public:
    double func(double x ,long long n){
        if(n==0)return 1 ;
        double res = func(x,n/2) ;
        if(n%2==0){
            return res*res ;
        }
        return x*res*res ;
    }
    double myPow(double x, int n) {
        if(n==0)return 1 ;
        if(x==0)return 0 ;
        long long m = n ;
        if(m<0)return func(1/x,-m) ;
        return func(x,m) ;
    }
};