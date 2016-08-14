#ifndef NONDECREASINGSEQUENCE_H
#define NONDECREASINGSEQUENCE_H

int countNonDecreasing(int n){
    int dp[n+1][10];
    for(int i=0; i<10; i++)dp[1][i]=1;
    for(int i=2; i<=n; i++){
        for(int j=9; j>=0; j--){
            if(j==9)dp[i][9]=dp[i-1][9];
            else dp[i][j]=dp[i-1][j]+dp[i][j+1];
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++)ans+=dp[n][i];
    return ans;
}

#endif /* NONDECREASINGSEQUENCE_H */

