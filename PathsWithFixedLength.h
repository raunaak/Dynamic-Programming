#ifndef PATHSWITHFIXEDLENGTH_H
#define PATHSWITHFIXEDLENGTH_H
//dp used
int b[4][4][13];

int pathWithKCoin(int mat[][3], int i, int j, int coin);

int pathWithKCoins(int mat[][3], int i, int j, int coin){
    for(int x=0; x<=i; x++)for(int y=0; y<=j; y++)for(int z=0; z<=coin; z++)b[x][y][z]=-1;
    b[0][0][0]=1;
    for(int z=1; z<=coin; z++)b[0][0][z]=(z==mat[0][0]?1:0);
    return pathWithKCoin(mat, i, j, coin);    
}

int pathWithKCoin(int mat[][3], int i, int j, int coin){
    if(i==0&&j==0)return b[0][0][coin];
    if(i<0||j<0||coin<0)return 0;
    int ans = 0;
    if(i-1>=0&&j>=0&&coin-mat[i][j]>=0){
        if(b[i-1][j][coin-mat[i][j]]==-1)b[i-1][j][coin-mat[i][j]]=pathWithKCoin(mat, i-1, j, coin-mat[i][j]);
        ans+=b[i-1][j][coin-mat[i][j]];
    }
    if(i>=0&&j-1>=0&&coin-mat[i][j]>=0){
        if(b[i][j-1][coin-mat[i][j]]==-1)b[i][j-1][coin-mat[i][j]]=pathWithKCoin(mat, i, j-1, coin-mat[i][j]);
        ans+=b[i][j-1][coin-mat[i][j]];
    }
    return ans;
}


#endif /* PATHSWITHFIXEDLENGTH_H */

