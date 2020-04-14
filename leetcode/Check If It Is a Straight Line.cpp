class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        if (n == 1)
            return true;
        int x_diff = coordinates[1][0] - coordinates[0][0];
        int y_diff = coordinates[1][1] - coordinates[0][1];
        float slope = (float)y_diff / x_diff;
        for (int i = 1; i < n; i++)
        {
            int x = coordinates[i][0] - coordinates[i - 1][0];
            int y = coordinates[i][1] - coordinates[i - 1][1];
            float curr_ans = (float)y / x;
            if (curr_ans != slope)
                return false;
        }
        return true;
    }
};