// can complete circuit
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,g,c;
        int max=-1;
        int ans=-1;
        for(int j=0; j<gas.size(); j++){
            i=(j==gas.size()-1)? 0 : j+1;
            c=0;
            g=gas[j];
            while(c<gas.size()-1){
                if(i==0) g = g-cost[gas.size()-1];
                else g= g-cost[i-1];
                if(g<=0) 
                {
                    g=-1;
                    break;
                }
                if(i==0) g = g+gas[i];
                else g= g+gas[i];
                i++;
                c++;
                if(i==gas.size()) i=0;
            }
            if (j!=0) g = g-cost[j-1];
            else g = g-cost[gas.size()-1];
            cout << g<<endl;
            if (g>max){
                max = g;
                ans = j;
            }
        }
        return(ans);
    }
};
