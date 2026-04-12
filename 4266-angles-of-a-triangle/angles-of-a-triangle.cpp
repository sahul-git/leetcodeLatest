class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if(a + b <= c || b+c <= a || c+a <= b) return ans;
        auto clamp = [](double x) {
            if(x > 1) return 1.0;
            if(x < -1) return -1.0;
            return x;
        };

        double angleA = acos(clamp((double)(b*b + c*c - a*a) / (2.0 * b * c))) * 180.0 / M_PI;
        double angleB = acos(clamp((double)(a*a + c*c - b*b) / (2.0 * a * c))) * 180.0 / M_PI;
        double angleC = acos(clamp((double)(a*a + b*b - c*c) / (2.0 * a * b))) * 180.0 / M_PI;

        ans = {angleA, angleB, angleC};
        sort(ans.begin(), ans.end());
        return ans;


    }
};