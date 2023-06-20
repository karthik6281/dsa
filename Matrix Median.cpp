class Solution{   
public:
    int func(int num , vector<vector<int>> &matrix ,int n ,int m){
        int count = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            count += upper_bound(matrix[i].begin(),matrix[i].end(),num) - matrix[i].begin() ;
        }
        return count ;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int size = n*m/2 ;
        int s = 1 ; 
        int e = 2000 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            int left = func(mid,matrix,n,m) ;
            if(left > size){
                e = mid-1 ;
            }
            else{
                s = mid+1 ;
            }
        }
        return s;
    }
};