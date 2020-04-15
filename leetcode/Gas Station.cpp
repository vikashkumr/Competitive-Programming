class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        map<int,bool>mp;
        for(int i=0;i<n;i++) {
            if(gas[i]>=cost[i]) {
                mp[i] = true;
            } 
        }
        int cnt_station=-1;
        int gas_avail;
        for(int i=0;i<n;i++) {
            if(mp[i]==true) {
                gas_avail = gas[i];
                gas_avail = gas_avail-cost[i];
                cnt_station = (i+1)%n;
                while(cnt_station!=i) {
                    gas_avail += gas[cnt_station];
                    if(gas_avail>=cost[cnt_station]) {
                        gas_avail -=cost[cnt_station];
                        cnt_station = (cnt_station+1)%n;
                    } else {
                        break;
                    }
                }
            }
            if(cnt_station==i) {
                return i;
            }
            cnt_station = -1;
        }
        return -1;
        
    }
};