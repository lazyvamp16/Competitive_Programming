class Solution {
public:
    int minSensors(int n, int m, int k) {
        int hor = n/(1+2*k);
        if((n%(1+2*k))!=0) hor+=1;

        int ver = m/(1+2*k);
        if((m%(1+2*k))!=0) ver+=1;

        return hor*ver;

        
    }
};