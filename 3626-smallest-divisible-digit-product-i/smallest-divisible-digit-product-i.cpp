class Solution {
public:
    int prodOfDigit(int n){
        int prod = 1;
        while(n>0){
            prod *= (n%10);
            n = n / 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while(n){
            if(prodOfDigit(n) % t == 0){
                return n;
            }
            n++;
        }
        return n;
    }
};