class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        vector<int> arr;
        for(int i=0; i<v.size()-1; i++){
            if(arr.size()==3){
                if((arr[2]-arr[0])>k) return {};
                ans.push_back(arr);
                arr.clear();
            }
            arr.push_back(v[i]);
        }
        arr.push_back(v.back());
        if((arr[2]-arr[0])>k) return {};
        ans.push_back(arr);
        return ans;
    }
};