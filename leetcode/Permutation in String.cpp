class Solution {
public:
    int A[27]={0};
    int B[27]={0};

    bool check(string &s1, string &s2, int idx) {
        for(int i=idx;i<s1.length()+idx;i++) {
            B[s2[i]-'a'+1]++;
        }
        for(int i=1;i<=26;i++) {
            if(A[i]!=B[i]) return false; 
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1>l2) return false;
        for(int i=0;i<s1.length();i++) {
            A[s1[i]-'a'+1]++;
        }

        for(int i=0;i<=l2-l1;i++) {
            memset(B,0,sizeof B);
           if(check(s1,s2,i)) return true;
        }
        return false;
    }
};