/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
/*

The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. 
When we traverse the string, to know the length of current window we need to indexes.
1) Ending index ( j ) : We consider current index as ending index.
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window.
    To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[].
    If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> last_index(256,-1);
       int i = 0;
        int ans = 0;
        for(int j=0;j<s.length();j++) {
            i = max(i, last_index[s[j]] + 1);
            ans = max(ans, j-i+1);
            last_index[s[j]] = j;
        }
        return ans;
    }
};
// @lc code=end

