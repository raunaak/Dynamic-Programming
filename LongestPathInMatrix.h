#ifndef LONGESTPATHINMATRIX_H
#define LONGESTPATHINMATRIX_H
#include <algorithm>
#define N 3
#define M 3
int dp[N][M];

bool checkBoundsLongestPath(int i, int j){
    return i>=0&&j>=0&&i<N&&j<M;
}

int longestPath(char mat[N][M], int i, int j){
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

int longestPath(char mat[N][M], char c){
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)dp[i][j]=-1;
    int maxi = 0;
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(mat[i][j]==c){int x = longestPath(mat, i, j); maxi = std::max(maxi, x);}
    return maxi;
}


#endif /* LONGESTPATHINMATRIX_H */

