class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans ;
        for(int i = 0 ; i < numRows ; i++){
            vector<int>temp ;
            temp.push_back(1) ;
            int res = 1 ;
            for(int j = 1 ; j <= i ; j++){
                res = res*(i-j+1)/j ;
                temp.push_back(res) ;
            }
            ans.push_back(temp) ;
        }
        return ans ;
    }
};