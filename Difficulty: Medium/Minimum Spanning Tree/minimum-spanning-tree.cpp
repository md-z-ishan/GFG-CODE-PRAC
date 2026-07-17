class Disjoint{
    public:
    vector<int>parent,size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,0);
        iota(begin(parent),end(parent),0);
    }
    int ult_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=ult_parent(parent[node]);
    }
    void Union_By_Size(int u,int v){
        int pu=ult_parent(u);
        int pv=ult_parent(v);
        if(pu==pv)return ;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pu]+=size[pv];
        }else{
            parent[pv]=pu;
            size[pv]+=size[pu];
        }
    }
    
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        Disjoint ds(V);
        int cost =0;
        sort(begin(edges),end(edges),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            if(ds.ult_parent(u)!=ds.ult_parent(v)){
                cost+=wt;
                ds.Union_By_Size(u,v);
            }
        }
        return cost;
    }
};