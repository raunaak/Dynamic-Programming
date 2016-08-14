#ifndef REACHDESTITHREEATIOTHREE_H
#define REACHDESTITHREEATIOTHREE_H
#include <algorithm>
#include "Constants.h"
//Question http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/
int points[THREE][THREE];

//utility function  
bool checkBounds(int i, int j){
    return i>=0&&j>=0&&i<THREE&&j<THREE;
}

int minInitialPoints(int mat[THREE][THREE]){
    for(int i=THREE-1; i>=0; i--){
        for(int j=THREE-1; j>=0; j--){
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

#endif /* REACHDESTITHREEATIOTHREE_H */

