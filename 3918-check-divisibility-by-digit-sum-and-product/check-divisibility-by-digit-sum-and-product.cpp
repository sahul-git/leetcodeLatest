class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digPrd = 1;

        int temp = n;
        while(temp>0){
            int dig = temp % 10;
            temp = temp / 10;
            digSum += dig;
            digPrd *= dig;
        }
        
        int sum = digSum + digPrd;

        if(n%sum == 0) return true;
        return false;
    }
};