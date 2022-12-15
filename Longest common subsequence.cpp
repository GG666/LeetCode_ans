int longestCommonSubsequence(string &s1, string &s2) {
    int size1 = s1.size(), size2 = s2.size();
    int i , j;
    vector<int> dp(size2);

    for(i = 0; i != size1; ++i){
        vector<int> next(size2);
        if(s1[i] == s2[0])
            next[0] = max(1, dp[0]);
        else
            next[0] = dp[0];

        for(j = 1; j != size2; ++j){
            if(s1[i] == s2[j])
                next[j] = max(dp[j - 1] + 1, dp[j]);
            else
                next[j] = max(next[j - 1], dp[j]);
        }
        dp = move(next);
    }

    int ans = 0;
    for(auto &i : dp)
        ans = i > ans ? move(i) : move(ans);
    return ans;
}
