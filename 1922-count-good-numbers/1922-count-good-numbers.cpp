class Solution {
public:
    int MOD = 1e9+7;
    long long power(long long b, long long e){
        long long result = 1;
        while(e>0){
            if(e%2 ==1){
                result = (result * b)%MOD;
            }
            b = (b*b) % MOD;
            e = e/2;
        }
        return result % MOD;
    }    
    int countGoodNumbers(long long n) {

        long long evenPos = (n+1)/2;
        long long oddPos = (n/2);
        return (power(5, evenPos)*power(4, oddPos)) % MOD;
    }
};