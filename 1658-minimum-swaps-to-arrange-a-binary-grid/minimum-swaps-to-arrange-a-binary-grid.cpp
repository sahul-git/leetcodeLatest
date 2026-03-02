class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> rightZeros(grid.size(), -1);

        for(int i=0; i<grid.size(); i++){
            int count = 0;
            for(int j=grid.size()-1; j>=0; j--){
                if(grid[i][j] == 0 && count<grid.size()){
                    count++;
                }else{
                    break;
                }
            }
            rightZeros[i] = count;
        }
        for(int i=0; i<rightZeros.size(); i++){
            if(rightZeros[i] == -1) return -1;
        }
        int n = rightZeros.size();
        int swapcount = 0;
        for(int i=0; i<rightZeros.size(); i++){
            if(rightZeros[i] < n-i-1){
                int k = i;
                while(k<n && rightZeros[k] < n-i-1){
                    k++;
                    
                }
                if(k == n) return -1;  

                
                while(k > i){
                    swap(rightZeros[k], rightZeros[k-1]);
                    swapcount++;
                    k--;
                }
            }
        }

        return swapcount;
        

    }
};