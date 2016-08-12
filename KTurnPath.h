#ifndef KTURNPATH_H
#define KTURNPATH_H

//Question Link: http://www.geeksforgeeks.org/count-number-of-paths-with-k-turns/
int a[10][10][10][2]; //cache array

int kTurnPath(int m, int n, int k, int d){
    //BASE CASE
    if(k<0)return 0;
    if(m==1&&d==1)return 1; //reach from column
    if(n==1&&d==0)return 1; //reach from row
    if(m==1&&d==0)return 0; //could only reach by column but d says to reach from row
    if(n==1&&d==1)return 0; //could only reach by row but d says to reach from column    
    if(a[m][n][k][d]>=0)return a[m][n][k][d];
    
    if(d==1){ //d='1' means reach from column
    int c1 = kTurnPath(m, n-1, k-1, 0);//reach from column just above n 
    int c2 = kTurnPath(m, n-1, k, 1);//reach from some other column
    a[m][n][k][d]=c1+c2;
    }else{ //d='0' means reach from row
    int r1 = kTurnPath(m-1, n, k-1, 1);//reach from row just before m
    int r2 = kTurnPath(m-1, n, k, 0);//reach from some other row
    a[m][n][k][d]=r1+r2;
    }    
    return a[m][n][k][d];
}

int kTurnPath(int m, int n, int k){
    /*
     * One can only travel from (i,j) to (i+1, j) and (i,j) to (i,j+1)
     * To reach (m,n)
     * i) reach from column
     *     reach from column just above n
     *     reach from some other column
     * ii) reach from row
     *     reach from row just before m
     *     reach from some other row
     */
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            for(int k=0; k<10; k++)
                for(int d=0; d<2; d++)a[i][j][k][d]=-1; 
            
    if(k==0)return m==1||n==1;
    if(m==1||n==1)return 0;
            
            
    return kTurnPath(m,n,k,0)+kTurnPath(m,n,k,1);
}


#endif /* KTURNPATH_H */

