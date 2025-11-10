class DSU{
    vector<int> size;
    vector<int> parent;
public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]= find(parent[x]);
    }

    bool UnionbySize(int i, int j){
        int ref_i = find(i);
        int ref_j = find(j);
        if(ref_i==ref_j) return true;
        else{
            if(size[ref_i]>size[ref_j]) {
                parent[ref_j] = ref_i;
                size[ref_j] +=size[ref_i];
            }
            else {
                parent[ref_i] = ref_j;
                size[ref_i]+=size[ref_j];
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n);
        for(auto x : edges){
            int i =x[0];
            int j=x[1];
            if(dsu->UnionbySize(i,j)) return{i,j};
        }
        return {};
    }
};