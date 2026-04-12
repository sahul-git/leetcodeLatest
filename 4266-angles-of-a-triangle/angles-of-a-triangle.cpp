class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        if (a + b <= c || a + c <= b || b + c <= a)
            return {};
        double angleA = acos((b * b + c * c - a * a) / (2 * b * c));
        double angleB = acos((a * a + c * c - b * b) / (2 * a * c));
        double angleC = acos((a * a + b * b - c * c) / (2 * b * a));
        double pi = acos(-1.0);
        angleA = angleA * 180.0 / pi;
        angleB = angleB * 180.0 / pi;
        angleC = angleC * 180.0 / pi;
        vector<double> ans = {angleA, angleB, angleC};
        sort(ans.begin(), ans.end());
        return ans;


    }
};