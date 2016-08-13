#ifndef TOTALNUMBEROFNDIGITS_H
#define TOTALNUMBEROFNDIGITS_H

int arr1[10][81];
int arr2[10][81];
int totalNumber(int n, int i, int diff){
    if(i>=n)return diff==1;
    if(diff>=0&&arr1[i][diff]!=-1)return arr1[i][diff];
    if(diff<0&&arr2[i][-diff]!=-1)return arr2[i][-diff];
    int ans = 0;
    if(i%2==0){
        for(int j=0; j<10; j++)
            ans+=totalNumber(n, i+1, diff+j);        
    }else{
        for(int j=0; j<10; j++)
            ans+=totalNumber(n, i+1, diff-j);
    }
    if(diff>=0)return arr1[i][diff]=ans;
    else return arr2[i][-diff]=ans;
}

int totalNumber(int n){
    for(int i=0; i<10; i++)for(int j=0; j<81; j++){arr1[i][j]=-1; arr2[i][j]=-1;}
    int ans = 0;
    for(int i=1; i<10; i++)ans+=totalNumber(n, 1, i);
    return ans;
}


#endif /* TOTALNUMBEROFNDIGITS_H */

