 class Disjoint{
     public:
     vector<int>rank,parent;
     Disjoint(int n){
         rank.resize(n+1,0);
         parent.resize(n+1);
         iota(begin(parent),end(parent),0);
     }
     int ult_parent(int node){
         if(node==parent[node])return node;
         return parent[node]=ult_parent(parent[node]);
     }
     bool union_By_Rank(int u,int v){
         int pu=ult_parent(u);
         int pv=ult_parent(v);
         if(pu==pv)return false;
         if(rank[pu]<rank[pv]){
             parent[pu]=pv;
         }
         else if(rank[pv]<rank[pu]){
             parent[pv]=pu;
         }else{
             parent[pv]=pu;
             rank[pu]++;
         }
         return true;
     }
 };

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        Disjoint ds(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            if(!ds.union_By_Rank(u,v)){
                return true;
            }
        }
        return false;
        
    }
};