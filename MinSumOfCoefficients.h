#ifndef MIINT_MAXSUMOFCOEFFICIEINT_MAXTS_H
#define MIINT_MAXSUMOFCOEFFICIEINT_MAXTS_H
#include <algorithm>
#include "Constants.h"

int coefficient(int n, int a[], int m, int dp[]){
    if(n<0)return INT_MAX;
    if(dp[n]!=-1)return dp[n];
    int min = INT_MAX;
    for(int i=0; i<m; i++)min = std::min(min, coefficient(n-a[i], a, m, dp));
    return dp[n]=1+min;
}
int minSumOfCoefficients(int n, int a[], int m){
    int dp[n+1];
    for(int i=0; i<=n; i++)dp[i]=-1;
    dp[0]=0;
    int min = INT_MAX;
    for(int i=0; i<m; i++)min = std::min(min, coefficient(n-a[i], a, m, dp));
    return dp[n]=1+min;
}

#endif /* MIINT_MAXSUMOFCOEFFICIEINT_MAXTS_H */

