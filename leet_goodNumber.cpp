// count goodnumber 
// striver, Leet Code

long long m=1000000007;     
long long pow(int x, long long n){
    long long m=1000000007;
    if (n==1) return x;
    return (x*pow(x,n-1))%m;
}

/*
long long pow(int x, long long n){
    long long m=1000000007;
    if (n==1) return x;
    return (x*pow(x,n-1)) % m;
}
*/

int countGoodNumbers(long long n) {
    //long long m=1000000007;
    return int((pow(4,n/2)*pow(5,n-(n/2)))%m);
}
int main(){
cout << countGoodNumbers(50);
long long m=1000000007;
}


/*
int main()
{
    long long p =1;
    long long m = 1000000007;
    for(long long i=1; i<=50; i++)
    {
        if (i%2 != 0)
        {
            p = (p*5) %m;
        }
        else p = (p*4) ;
    }
    cout << p;
    return(0);
}
*/
