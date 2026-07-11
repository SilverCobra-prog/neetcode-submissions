class Solution {
public:

    int binSearch(vector<int> v, int hi, int lo, int hours) {
        int ans = hi;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            int h = 0;
            for(int i = 0; i < v.size(); i++) {
                h += v[i]/mid;
                if(v[i] % mid != 0) h++;
                cout << h << " ";
            }
            cout << endl;
            cout << mid << " " << h << " " << hours << endl;
            if(h <= hours && mid < ans) {
                ans = mid;
                hi = mid-1;
            }  else {
                lo = mid+1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int most = 0;
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > most) most = piles[i];
        }
        return binSearch(piles, most, 1, h);
    }
};
