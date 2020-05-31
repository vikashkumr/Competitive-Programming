class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&] (vector<int>a , vector<int>b) -> bool {
            if(a[1]==b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        
        for(int i=1;i<people.size();i++) {
            int cnt = 0;
            for(int j=i-1;j>=0;j--) {
                if(people[j][0] >= people[i][0]) cnt++;
            }
            if(cnt>people[i][1]) {
                vector<int> v(people[i]);
                cnt = cnt-people[i][1];
                int t = i;
                while(cnt--) {
                    swap(people[t],people[t-1]);
                    t--;
                }
                people[t] = v;
            }
        }
        return people;
    }
};