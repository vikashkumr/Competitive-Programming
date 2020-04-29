//https://leetcode.com/problems/baseball-game/

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int ans = 0;
        stack<int> record;
        for (string s : ops)
        {
            if (s == "D")
            {
                ans += 2 * record.top();
                record.push(2 * record.top());
            }
            else if (s == "+")
            {
                int t1 = record.top();
                record.pop();
                ans += record.top() + t1;
                int sum = t1 + record.top();
                record.push(t1);
                record.push(sum);
            }
            else if (s == "C")
            {
                ans -= record.top();
                record.pop();
            }
            else
            {
                record.push(stoi(s));
                ans += stoi(s);
            }
        }
        return ans;
    }
};