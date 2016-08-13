#ifndef SUBSETSUM_H
#define SUBSETSUM_H
// Question Link : http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
// I have modified code to obtain number of sequences with the required sum
int subsetSum(int a[], int n, int sum, int low, int high){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(low>high)return 0;
    return subsetSum(a, n, sum-a[low], low+1, high)+subsetSum(a, n, sum, low+1, high);
}

int subsetSum(int a[], int n, int sum){
    return subsetSum(a, n, sum, 0, n-1);
}

int sumSubset(int a[], int n, int sum){
    int dp[sum+1][n+1];
    int x=1;
    for(int j=0; j<=n; j++){if(a[j]==0)x++; dp[0][j]=x;}
    for(int i=1; i<=sum; i++)dp[i][0]=0;
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=dp[i][j-1]+(i-a[j-1]>=0?dp[i-a[j-1]][j-1]:0);
        }
    }
    return dp[sum][n];
}
#endif /* SUBSETSUM_H */

