class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int drunk = 0;
        while(full > 0){
            empty += full;
            drunk += full;
            full = 0;

            while(empty >=  numExchange){
                full = full + 1;
                empty -= numExchange;
                numExchange++;
            }
           
            
        }
        return drunk;
    }
};