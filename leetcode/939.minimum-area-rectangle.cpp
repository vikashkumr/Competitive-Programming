/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// @lc code=start
/*

Approach:
Idea is to find diagonal cordinates and then we can easily find other two points.
For each two points (A and B), we first determine if they are diagonal. If they are diagonal, we know these two points have different x and different y.
Then we can use the map to check:

1. there exists a point which has A's x and B's y
2. there exists a point which has B's x and A's y
3. check size

*/



class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
	//store y-value for each x-val O(n)
        unordered_map<int,unordered_set<int>> hmx;
        for(auto &point: points) {
            hmx[point[0]].insert(point[1]);
        }
        int ans = INT_MAX;
		//for each point check every other points O(n^2)
        for(auto &pointA: points) {
            for(auto &pointB: points) {
			//if both pointA and pointB lies on same column or row then continue
                if(pointA[0]==pointB[0] or pointA[1] == pointB[1]) continue
				
				//if point corresponding to pointA and pointB not found continue
                if(hmx[pointA[0]].count(pointB[1])<1 or hmx[pointB[0]].count(pointA[1])<1) continue;
				
				//here we found poinds corresponding to pointA and pointB so update area.(diagonal points)
                ans = min(ans, abs(pointA[0] - pointB[0]) * abs(pointA[1]-pointB[1]));
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
// @lc code=end

