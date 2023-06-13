class Solution {
public:
    int rem(int i,int n){
        return i%n ;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        int s = 0 ; 
        int e = (m*n)-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            int i = mid/n ;
            int j = rem(mid,n) ;
            if(matrix[i][j] == target)return true ;
            else if(matrix[i][j] < target)s =mid+1 ;
            else e= mid-1 ;
        }
        return false ;
    }
};