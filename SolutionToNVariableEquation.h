#ifndef SOLUTIONTONVARIABLEEQUATION_H
#define SOLUTIONTONVARIABLEEQUATION_H
//http://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/
int numberOfSolution(int a[], int n, int rhs, int i, int dp[]){
    //rhs = rhs - a[0]*i till rhs>=0 starting from i=0
    //recur for the remaining array
    if(i>=n)return 0;
    if(dp[rhs]>=0)return dp[rhs];
    int sum = 0; int j=0;
    while(true){
        if(rhs-j*a[i]==0){sum++; break;}
        if(rhs-j*a[i]<0)break;
        sum+=numberOfSolution(a, n, rhs-j*a[i], i+1, dp);
        j++;
    }
    dp[rhs]=sum;
    return sum;
}

int numberOfSolution(int a[], int n, int rhs){
    int dp[rhs+1];
    for(int i=0; i<rhs+1; i++)dp[i]=-1;
    return numberOfSolution(a, n, rhs, 0, dp);
    
}


#endif /* SOLUTIONTONVARIABLEEQUATION_H */

