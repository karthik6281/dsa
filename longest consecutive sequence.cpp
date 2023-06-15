
class DisjointSet
{   public:
    vector<int>rank ,parent,size,island ;
    DisjointSet(int n){
        rank.resize(n+1,0) ;
        island.resize(n+1,0) ;
        parent.resize(n+1,0) ;
        size.resize(n+1,1) ;
        for(int i = 0 ; i<=n ; i++){
            parent[i] = i ;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node ;
        }
        return parent[node] = findUPar(parent[node]) ;
    }
    void unionByRank(int u , int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        if(ulp_u == ulp_v) return ;
        else if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else if(rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++ ;
        }
    }
    void unionBySize(int u , int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        if(ulp_u == ulp_v) return ;
        else if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
        }
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        if(n==0)return 0 ;
        unordered_map<int,int> m;
        for(int i= 0 ; i < n;i++){
            m[nums[i]]=i ;
        }
        vector<int>arr ;
        for(auto it :m){
            arr.push_back(it.first) ;
        }
        int k = arr.size() ;
        for(int i= 0 ; i < k;i++){
            m[arr[i]]=2*i+1 ;
        }
        DisjointSet ds(k) ;
        for(int i= 0 ; i < k ; i++){
            if(m[arr[i]-1]!=0){
                ds.unionBySize(i,(m[arr[i]-1]-1)/2) ;
            }
        }
        return *max_element(ds.size.begin(),ds.size.end()) ;
    }
};