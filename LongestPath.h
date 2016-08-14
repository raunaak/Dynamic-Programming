#ifndef LONGESTPATH_H
#define LONGESTPATH_H
//Dynamic Programming used
//Question Link: http://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
bool checkBounds(int i, int j, int n, int m){
    return i>=0&&j>=0&&i<n&&j<m;
}

int longestPath(int a[][3], int n, int mat[][3], int i, int j){
    if(!checkBounds(i,j, n, 3))return -1;
    if(mat[i][j]>=0)return mat[i][j];
    int max = 1;
    if(checkBounds(i+1, j, n, 3)&&a[i+1][j]==a[i][j]+1){int e = longestPath(a,n,mat,i+1,j)+1; if(max<e)max=e;}
    if(checkBounds(i-1, j, n, 3)&&a[i-1][j]==a[i][j]+1){int e = longestPath(a,n,mat,i-1,j)+1; if(max<e)max=e;}
    if(checkBounds(i, j+1, n, 3)&&a[i][j+1]==a[i][j]+1){int e = longestPath(a,n,mat,i,j+1)+1; if(max<e)max=e;}
    if(checkBounds(i, j-1, n, 3)&&a[i][j-1]==a[i][j]+1){int e = longestPath(a,n,mat,i,j-1)+1; if(max<e)max=e;}
    mat[i][j]=max;
    return max;
}

void longestPath(int a[][3], int n){
    int mat[n][3];
    for(int i=0; i<n; i++)for(int j=0; j<3; j++)mat[i][j]=-1;
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            longestPath(a, n, mat, i, j);
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

#endif /* LONGESTPATH_H */

