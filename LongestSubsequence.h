#ifndef LONGESTSUBSEQUENCE_H
#define LONGESTSUBSEQUENCE_H
#include <algorithm>
//Question Link: http://www.geeksforgeeks.org/longest-repeating-subsequence/

//utility function
int findNextChar(std::string str, int n, int i){
    int j=i+1;
    for( ;j<n; j++)if(str[j]==str[i])break;
    return j;
}

int longestSubsequence(std::string str, int n, int i, int j, int dp[]){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    int k = findNextChar(str, n, i); 
    int res1 = 0; int res2 = 0;
    if(k<n)res1 = 1+longestSubsequence(str, n, i+1, k+1, dp);
    res2 = longestSubsequence(str, n, i+1, i+1, dp);
    dp[i] = std::max(res1, res2);
    return dp[i];
}

int longestSubsequence(std::string str, int n){
    int dp[n]; //dp[i] longest subsequence starting from index>=i
    for(int i=0; i<n; i++)dp[i]=-1;
    return longestSubsequence(str, n, 0, 0, dp);
}


#endif /* LONGESTSUBSEQUENCE_H */

