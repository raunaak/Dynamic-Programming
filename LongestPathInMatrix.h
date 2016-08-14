#ifndef LOTHREEGESTPATHITHREETHREEATRIX_H
#define LOTHREEGESTPATHITHREETHREEATRIX_H
#include <algorithm>
#include "Constants.h"
int dp[THREE][THREE];

bool checkBoundsLongestPath(int i, int j){
    return i>=0&&j>=0&&i<THREE&&j<THREE;
}

int longestPath(char mat[THREE][THREE], int i, int j){
    int maxi = 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(checkBoundsLongestPath(i-1,j-1)&&mat[i-1][j-1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i-1, j-1), maxi);
    if(checkBoundsLongestPath(i-1,j)&&mat[i-1][j]==mat[i][j]+1)maxi = std::max(longestPath(mat, i-1, j), maxi);
    if(checkBoundsLongestPath(i-1,j+1)&&mat[i-1][j+1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i-1, j+1), maxi);
    if(checkBoundsLongestPath(i,j+1)&&mat[i][j+1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i, j+1), maxi);
    if(checkBoundsLongestPath(i+1,j+1)&&mat[i+1][j+1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i+1, j+1), maxi);
    if(checkBoundsLongestPath(i+1,j)&&mat[i+1][j]==mat[i][j]+1)maxi = std::max(longestPath(mat, i+1, j), maxi);
    if(checkBoundsLongestPath(i+1,j-1)&&mat[i+1][j-1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i+1, j-1), maxi);
    if(checkBoundsLongestPath(i,j-1)&&mat[i][j-1]==mat[i][j]+1)maxi = std::max(longestPath(mat, i, j-1), maxi);
    return dp[i][j]=1+maxi;
}

int longestPath(char mat[THREE][THREE], char c){
    for(int i=0; i<THREE; i++)for(int j=0; j<THREE; j++)dp[i][j]=-1;
    int maxi = 0;
    for(int i=0; i<THREE; i++)for(int j=0; j<THREE; j++)if(mat[i][j]==c){int x = longestPath(mat, i, j); maxi = std::max(maxi, x);}
    return maxi;
}


#endif /* LOTHREEGESTPATHITHREETHREEATRIX_H */

