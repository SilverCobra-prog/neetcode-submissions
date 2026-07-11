class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mostWater = 0;
        int left = 0; 
        int right = heights.size()-1;
        while(left < right) {
            int height = min(heights[left], heights[right]);
            int dist = right-left;
            mostWater = max(dist*height,mostWater);
            if(heights[right] < heights[left]) right--;
            else left++;
        }
        return mostWater;
    }
};
