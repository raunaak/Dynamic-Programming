#ifndef PATHSWITHFIXEDLENGTH_H
#define PATHSWITHFIXEDLENGTH_H

int pathWithKCoins(int mat[][3], int i, int j, int coin){
    if(i==0&&j==0)return (coin==mat[0][0]?1:0);
    if(i<0||j<0||coin<0)return 0;
    return pathWithKCoins(mat, i-1, j, coin-mat[i][j]) + pathWithKCoins(mat, i, j-1, coin-mat[i][j]);
}


#endif /* PATHSWITHFIXEDLENGTH_H */

