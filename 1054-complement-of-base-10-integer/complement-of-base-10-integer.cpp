class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int temp = 1;
        int power = 0;

        while(temp <= n){
            temp = temp * 2;
            power++;
        }

        return (1 << power) - 1 - n;
    }
};