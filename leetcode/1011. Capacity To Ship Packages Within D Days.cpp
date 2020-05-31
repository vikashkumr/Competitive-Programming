class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = accumulate(weights.begin(),weights.end(),0);
        int l = 0, r = sum;
        int ans = 0;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            int tmp_d = 1;
            int l_sum = 0;
            int i = 0;
            bool ok = 1;
            
            for(int weight: weights) {
                if(mid < weight) {
                    l = mid+1;
                    ok = 0;
                    break;
                }
                if(l_sum + weight <= mid)
                    l_sum += weight;
                else {
                    tmp_d++;
                    l_sum = weight;
                }
                i++;
            }

            if(ok) {
                if(tmp_d <= D ) {
                ans = mid;
                r = mid - 1;
                } else {
                    l = mid + 1;
                }   
            }
        }

        return ans;
    }
};