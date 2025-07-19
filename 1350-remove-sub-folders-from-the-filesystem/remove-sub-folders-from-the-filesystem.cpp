class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        string prev = folder[0];
        ans.push_back(prev);
        int n = prev.length();
        for(string i : folder){
            if (i==prev) continue;
            if(i.length()==n || (i.length()>n && i[n]!='/')) {
                ans.push_back(i);
                prev = i;
                n = prev.length();
            }
            else{
                for(int x= 1; x<n; x++){
                    //cout << prev << i << endl;
                    if(prev[x]!=i[x]) {
                        //cout << prev[x] << " " << i[x] <<endl;
                        ans.push_back(i);
                        prev = i;
                        n=prev.length();
                        break;
                    }
                }
            }
        }
        return ans;
    }
};