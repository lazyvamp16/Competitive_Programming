// Climbing stairs
// dynamic programming

    int climbStairs(int n) {
        if(n==1) return(1);
        if(n==2) return(2);
        if(n==3) return(3);
        int f3= 3;
        int f2 = 2;
        int f4;
        for (int i=4;i<=n;i++){
            f4 = f3+f2;
            f2=f3;
            f3=f4;
        }
        return(f4);
    }
};
