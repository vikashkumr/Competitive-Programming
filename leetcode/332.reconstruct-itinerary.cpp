/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

@lc code=start
/*
ds => multiset + stack
https://www.youtube.com/watch?v=WYqsg5dziaQ
O(Edges)

key: * need to visit every edge ones
     * testcase will always be valid
Algo:
* put src to stack 
* while !stk.empty take last element as key and push first element from graph to stack if empty pop stack and push to answer
*finally reverse ans vector and return 
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //reason for taking multiset it always keep element sorted
        unordered_map<string, multiset<string>> gr;
        for(int i=0;i<tickets.size();i++) {
            gr[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> ans;
        stack<string> stk;
        stk.push("JFK");
        while(!stk.empty()) {
            string src = stk.top();
            if(gr[src].size() == 0) {
                ans.push_back(src);
                stk.pop();
            } else {
                auto dest = gr[src].begin();
                stk.push(*dest);
                gr[src].erase(dest);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

