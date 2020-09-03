//similar to edit distance

string abbreviation(string a, string b) {
    int la = a.length();
    int lb = b.length();

    bool dp[1001][1001];

    //filling first row
    dp[0][0] = true;
    for(int i = 1; i <= lb; i++) {
        dp[0][i] = false;
    }

    //filling first col

    for(int i = 1; i<=la; i++) {
        if(a[i-1]>='a' and a[i-1]<='z' && dp[i-1][0]) dp[i][0] = true;
        else dp[i][0] = false;
    }

    //common algo
    for(int i=1;i<=la;i++) {
        for(int j=1;j<=lb;j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(a[i-1]>='a' and a[i-1]<='z') {
                if(dp[i-1][j]) dp[i][j] = true;
                else if(toupper(a[i-1]) == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else dp[i][j] = false;
            } else dp[i][j] = false;
        }
    }

    if(dp[la][lb]) return "YES";
    return "NO";

}