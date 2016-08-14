#ifndef REACHDESTINATION_H
#define REACHDESTINATION_H
#include <algorithm>
//Question http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/
#define N 3
#define M 3
int points[M][N];

//utility function  
bool checkBounds(int i, int j){
    return i>=0&&j>=0&&i<N&&j<M;
}

int minInitialPoints(int mat[N][M]){
    for(int i=N-1; i>=0; i--){
        for(int j=M-1; j>=0; j--){
            bool b1 = checkBounds(i+1,j);
            bool b2 = checkBounds(i,j+1);
            if(b1&&b2) points[i][j]=std::max(points[i+1][j], points[i][j+1])+mat[i][j];
            else if(b1) points[i][j]=points[i+1][j]+mat[i][j];
            else if(b2) points[i][j]=points[i][j+1]+mat[i][j]; 
            else points[i][j]=mat[i][j]-1;
            if(points[i][j]>0)points[i][j]=0;
        }
    }
    return -points[0][0];
}

#endif /* REACHDESTINATION_H */

