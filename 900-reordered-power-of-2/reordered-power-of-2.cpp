class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<multiset<int>> powers;
        int power = 1;
        int digit;
        for(int i= 1; i<=30; i++){
            multiset<int> digits;
            int temp = power;
            while(temp>0){
                digit = temp%10;
                digits.insert(digit);
                temp/=10;
            }
            powers.insert(digits);
            power = power*2;
        }
        multiset<int> number;
        while(n>0){
            digit = n%10;
            number.insert(digit);
            n/=10;
        }
        if(powers.count(number)) return true;
        else return false;
    }
};