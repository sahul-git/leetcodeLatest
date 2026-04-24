class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r= 0;
        int blank = 0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i] == 'L'){
                l++;
            }else if(moves[i]== 'R'){
                r++;
            }else{
                blank++;
            }
        }
        if(l>=r) l+=blank;
        else if(r>l) r+=blank;
        return abs(l-r);

    }
};