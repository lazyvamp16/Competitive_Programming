class Solution {
public:
    bool check(string s, string g, int i1, int i2, int n){
        for(int i=0 ; i<n; i++){
            //cout << s[i1%n] << g[i2%n] << endl;
            if(s[i1++%n]!=g[i2++%n]) return false;
        }        
        return true;
    }

    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n!=goal.size()) return false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i]==goal[j]){
                    //cout << "enter"<< i << j<< endl;
                    int index1 = i;
                    int index2 = j;
                    if(check(s,goal,index1,index2,n)) return true;
                }
            }
        }  
        return false;      
    }
};