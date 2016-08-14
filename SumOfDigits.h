#ifndef SUMOFDIGITS_H
#define SUMOFDIGITS_H
//http://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/
int count[10][81];

int countDigit(int n, int sum){
    //base case
    if(sum==0)return 1;
    if(n==0||sum<0)return 0;
    
    //dp part
    if(count[n][sum]!=-1)return count[n][sum];
    
    //recursion part
    int ans = 0;
    for(int i=0; i<10; i++)ans+=countDigit(n-1, sum-i);
    return count[n][sum]=ans;
}

int countDigits(int n, int sum){
    for(int i=0; i<=n; i++)for(int j=0; j<=sum; j++)count[i][j]=-1;
    int ans = 0;
    for(int i=1; i<10; i++)ans+=countDigit(n-1, sum-i);
    return ans;
}

#endif /* SUMOFDIGITS_H */

