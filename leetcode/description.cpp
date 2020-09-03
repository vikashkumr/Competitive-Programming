
// https://www.lintcode.com/problem/find-the-celebrity/description
//two pointer approach

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        // Write your code here
        int p1 = 0;
        int p2 = n-1;
        while(p1<p2) {
            if(knows(p1,p2)) {
                p1++;
            } else {
                // this person can never be a celebrity bcz p1 doesn't know him 
                // where a celebrity should be known by every one and there could be a single celebrity
                p2--;
            }
        }
        for(int i=0;i<n;i++) {
            if(i!=p1 and (knows(p1,i) || !knows(i,p1))) return -1;
        }
        return p1;
    }
};