/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
/* 
Approach 1: sort array and check for consecuency time = O(nlogn) space = O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue;
            if(nums[i]-nums[i-1] == 1) cnt++;
            else {
                ans = max(cnt, ans);
                cnt = 1;
            }
        }
        return max(cnt, ans);
    }
};
// @lc code=end


Approach 2: This problem can be solved in O(n) time using an Efficient Solution. 
            The idea is to use Hashing. We first insert all elements in a Set.
            Then check all the possible starts of consecutive subsequences.

Algorithm:

Create an empty hash.
Insert all array elements to hash.
Do following for every element arr[i]
Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.

*/

// O(n) solution
    main() {
        int n;
        cin>>n;
        int a[n];
        unordered_set<int> st;
        for(int i=0;i<n;i++) {
           cin>>a[i];
           st.insert(a[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(st.find(a[i]-1) == st.end()) {
                int j = a[i];
                while(st.find(j) != st.end()) j++;
                ans = max(ans, j-a[i]);
            }
        }
        cout<<ans<<endl;
    }

