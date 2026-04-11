class Solution {
public:
    double myPow(double x, int n) {
        // if(x == 0 || x == 1) return x;
        
        // int p = abs(n);
        // double ans = 1;
        // while(p--){
        //     ans *= x;
        // }
        // if(n>0){
        //     return ans;
        // }else{
        //     double ans1 = 1/ans;
        //     return ans1;
        // }
        // return 1;

        long long N = n; // handle INT_MIN
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        double ans = 1;
        while(N > 0){
            if(N%2 == 1){
                ans*= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;  //time complexity = O{long n}
    }
};