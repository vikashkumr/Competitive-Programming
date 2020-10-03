// Time: O(nlonn + mlogm) | O(1) space

pair<int,int> minPairDifference(int a[], int b[]) {
    int n = sizeof a / sizeof a[0];
    sort(a,a+n);
    sort(b,b+n);
    int idx1 = 0;
    int idx2 = 0;
    int smallest = INT_MAX;
    int current = INT_MAX;
    pair<int,int> p;
    while(idx1 < len(a) and idx2 < len(b)) {
        if(a[idx1] < b[idx2]) {
            current = b[idx2]-a[idx1];
            idx1++;
        } else if(a[idx1] > b[idx2]) {
            current = a[idx1]-b[idx2];
            idx2++;
        } else return {a[idx1], b[idx2]}

        smallest = min(smallest, current);
    }
    return smallest;
}