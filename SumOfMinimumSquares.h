#ifndef SUMOFMINIMUMSQUARES_H
#define SUMOFMINIMUMSQUARES_H
#include <algorithm>

int sumSq(int n, int dp[]){
    if(dp[n]!=-1)return dp[n];
    int maxi = 100;
    for(int i=1; i*i<=n; i++)maxi = std::min(maxi, sumSq(n-i*i, dp));
    return dp[n]=1+maxi;
}
int sumOfMinSquares(int n){
    int dp[n+1];
    for(int i=2; i<=n; i++)dp[i]=-1;
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=n; i++)sumSq(i, dp);
    return dp[n];
}


#endif /* SUMOFMINIMUMSQUARES_H */

