class Solution {
public:
    map<int,int>arr;
    int findLHS(vector<int>& nums) {
        arr.clear();
        for(int it : nums) {
            arr[it]++;
        }
        bool flag = 0;
        int tmp = 0;
        if(arr.size()==1) return tmp;

        //to handle 0 case bcz by default every element has 0 occurance
        if(arr[0]==0) flag = 1;
        for(auto it : arr) {
            if(flag==1) {
                //to handle map<0,x> case
                if(it.first==1 or it.first==-1) continue;
            }
                if(arr[it.first-1]!=0)
                tmp = max(tmp,arr[it.first]+arr[it.first-1]);
        }
        return tmp;
    }
};