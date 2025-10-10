class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        long long a = LLONG_MIN;
        /*
        for(int i=0; i<n; i++){
            int ans = 0;
            for(int j=i; j<n; j+=k){
                ans+=energy[j];
            }
            a = max(a,ans); 
        }
        */
        for(int i=n-1; i>=n-k; i--){
            long long sum = 0;
            for(int j=i; j>=0; j-=k){
                sum += energy[j];
                a = max(a,sum);
            }
        }
        return a;
    }
};