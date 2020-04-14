class Solution
{
public:
    string reverseWords(string s) {
        int l = s.length();
        int st = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + st, s.begin() + i);
                st = i + 1;
            }
            else if (i == l - 1) {
                reverse(s.begin() + st, s.begin() + i + 1);
            }
        }
        return s;
    }
};