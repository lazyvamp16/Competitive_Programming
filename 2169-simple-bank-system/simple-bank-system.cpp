class Bank {
public:
    vector<long long> &balance;
    int n;
    Bank(vector<long long>& b): balance(b), n(b.size()) {
        //balance = b;
        //n = balance.size();
    }
    
    bool transfer(int a1, int a2, long long money) {
        bool flag = false;
        if(a1<=n && a1>=1 && a2<=n && a2>=1){
            if(balance[a1-1]>=money){
                flag = true;
                balance[a1-1]-=money;
                balance[a2-1]+=money;
            }
        }
        return flag;
    }
    
    bool deposit(int a, long long money) {
        bool flag = false;
        if(a<=n && a>=1){
            flag = true;
            balance[a-1]+=money;
        }
        return flag;
    }
    
    bool withdraw(int a, long long money) {
        bool flag = false;
        if(a<=n && a>=1){
            if(balance[a-1]>=money){
                flag = true;
                balance[a-1]-=money;
            }
        }
        return flag;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */