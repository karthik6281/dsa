class Solution {
public:
    void setRow(int i,int n ,vector<vector<int>>& matrix){
        for(int j = 0 ; j < n ;j++){
            matrix[i][j] = 0 ;
        }
        return ;
    }
    void setCol(int i,int n ,vector<vector<int>>& matrix){
        for(int j = 0 ; j < n ;j++){
            matrix[j][i] = 0 ;
        }
        return ;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int col = -1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0]=0 ;
                    if(j==0)col=0 ;
                    else{
                        matrix[0][j]=0 ;
                    }
                }
            }
        }
        for(int i =1 ; i < m ;i++){
            if(matrix[0][i]==0)setCol(i,n,matrix) ;
        }
        for(int j = 0 ; j < n ;j++){
            if(matrix[j][0]==0)setRow(j,m,matrix) ;
        }
        if(col==0)setCol(0,n,matrix) ;
        return ;
    }
};