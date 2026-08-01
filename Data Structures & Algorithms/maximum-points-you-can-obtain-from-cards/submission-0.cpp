class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()<=k) {
            int sum = 0;
            for(int i = 0; i < cardPoints.size(); i++) {
                sum += cardPoints[i];
            }
            return sum;
        }


        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += cardPoints[i];
        }

        
        int curr = ans;

        for(int i = 0; i < k; i++) {
            curr = curr-cardPoints[k-i-1]+cardPoints[cardPoints.size()-1-i];
            ans = max(ans, curr);
        }
        
        return ans;

    }
};