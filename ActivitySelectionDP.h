#ifndef ACTIVITYSELECTIONDP_H
#define ACTIVITYSELECTIONDP_H
#include "Constants.h"
/*16.1-1
Page 422 Chapter 16 Greedy Algorithms Cormen
Give a dynamic-programming algorithm for the activity-selection problem, based
on recurrence (16.2). Have your algorithm compute the sizes cŒi; j  as defined
above and also produce the maximum-size subset of mutually compatible activities.
Assume that the inputs have been sorted as in equation (16.1). Compare the running
time of your solution to the running time of GREEDY-ACTIVITY-SELECTOR.*/

int realActivity(int s[], int f[], int i, int j, int *dp, int n, int start, int end){
    if(dp[i*n+j]!=-1)return dp[i*n+j]; //dp
    
    if(i>=j)return dp[i*n+j]=0;//null set returns 0 tasks
    
    //BASE CASE
    if(i+1==j){ //if element is within time bounds, return 1 else 0
        dp[i*n+j]=s[i]>=start&&f[i]<=end;
        return dp[i*n+j];
    }

    //recursion
    int max = 0; //add element to set if it is within time bounds
    for(int k=i; k<j; k++)if(s[k]>=start&&f[k]<=end)max = std::max(max, 1+realActivity(s, f, i, k, dp, n, start, s[k])+realActivity(s, f, k+1, j, dp, n, f[k], end));
    return dp[i*n+j]=max;
}

int activitySelection(int s[], int f[], int i, int j){
    int dp[j+1][j+1];
    for(int x=0; x<=j; x++)for(int y=0; y<=j; y++)dp[x][y]=-1;
    return realActivity(s, f, i, j, &dp[0][0], j+1, 0, f[j-1]);
}
#endif /* ACTIVITYSELECTIONDP_H */

