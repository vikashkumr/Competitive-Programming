class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0,twenty = 0;
        bool flag = 1;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10) {
                if(five>0) {
                    ten++;
                    five--;
                } else {
                    flag = 0;
                    break;
                }
            } else {
                if(ten>0 and five>0) {
                    twenty++;
                    ten--;
                    five--;
                } else if(five>=3) {
                    twenty++;
                    five-=3;
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) return true;
        return false;
    }
};