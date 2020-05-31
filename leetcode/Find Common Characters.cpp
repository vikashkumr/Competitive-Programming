class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        unordered_map<char,int> freq, local;
        for(char ch: A[0]) freq[ch]++;
        for(int i = 1; i < A.size(); i++) {
            local.clear();
            //update the original freq map
            for(char ch: A[i]) local[ch]++;
            for(auto it: freq) {
                freq[it.first] = min(local[it.first],freq[it.first]);
            }
        }
        string s = "";
        for(auto it: freq) {
            for(int i=0;i<it.second;i++) {
                s=it.first;
                ans.push_back(s);
            }
        }
        return ans;
    }
};