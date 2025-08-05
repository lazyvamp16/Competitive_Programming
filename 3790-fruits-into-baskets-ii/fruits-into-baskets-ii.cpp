class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt =0;
        for(int i : fruits){
            bool flag = false;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=i){
                    flag =true;
                    baskets.erase(baskets.begin()+j);
                    break;
                }
            }
            for(int k:baskets) cout << k << " ";
            cout <<endl;
            if(!flag) cnt++;
        }
        return cnt;
    }
};