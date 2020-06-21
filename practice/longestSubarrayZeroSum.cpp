#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}


//if we get prefix sum 0 at ith iteration it means sum of all element till i is ZERO

/*You are required to complete this function*/
int maxLen(int A[], int n) {
    int pre = 0;
    int ans = 0;
    unordered_map<int,int> hm;
    
    for(int i=0;i<n;i++) {
        pre += A[i];
        if(pre == 0) ans = max(ans, i+1);
        if(hm.count(pre) > 0) {
            ans = max(ans, i - hm[pre]);
        } else
        hm[pre] = i;
    }
    return ans;
}