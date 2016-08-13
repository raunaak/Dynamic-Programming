#ifndef SAMEHALFSUM_H
#define SAMEHALFSUM_H
#include <algorithm>

//http://www.geeksforgeeks.org/count-even-length-binary-sequences-with-same-sum-of-first-and-second-half-bits/
const int x = 10;
int sameHalfSum(int n, int diff, int sum[x][x]){
    //T(n, diff) = 2*T(n-1, diff)+T(n-1, diff-1)+T(n-1,diff+1)
    if(abs(diff)>n)return 0;  //unnecessary case removed
    if(sum[n][abs(diff)]>-1)return sum[n][abs(diff)];  //dp case and base case covered
    sum[n][abs(diff)] = 2*sameHalfSum(n-1, diff, sum) + sameHalfSum(n-1, diff-1, sum) + sameHalfSum(n-1, diff+1, sum); //recursion step and dp array element visited
    return sum[n][abs(diff)];  
}

int sameHalfSum(int n){
    int sum[x][x];
    for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)sum[i][j]=-1;
    sum[1][0]=2; sum[1][1]=1;
    for(int j=2; j<=n; j++)sum[1][j]=0;
    return sameHalfSum(n, 0, sum);
}

#endif /* SAMEHALFSUM_H */

