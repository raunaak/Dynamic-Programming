#ifndef SUBSETSUM_H
#define SUBSETSUM_H
// Question Link : http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
// I have modified code to obtain number of sequences with the required sum
int subsetSum(int a[], int n, int sum, int low, int high){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(low>high)return 0;
    return subsetSum(a, n, sum-a[low], low+1, high)+subsetSum(a, n, sum, low+1, high);
}

int subsetSum(int a[], int n, int sum){
    return subsetSum(a, n, sum, 0, n-1);
}


#endif /* SUBSETSUM_H */

