#ifndef COUNTDEARRANGEMENT_H
#define COUNTDEARRANGEMENT_H
//Question Link : http://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
//Formula : D(n) = (n-1)*(D(n-1)+D(n-2))
//dp used
int countDearrangement(int n){
    int count[n+1];
    count[0] = 0;
    count[1] = 0;
    count[2] = 1;
    for(int i=3; i<=n; i++)count[i]=(i-1)*(count[i-1]+count[i-2]);
    return count[n];
}


#endif /* COUNTDEARRANGEMENT_H */

