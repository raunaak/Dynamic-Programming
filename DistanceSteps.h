#ifndef DISTANCESTEPS_H
#define DISTANCESTEPS_H
//http://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
int countWaysRecursion(int distance, int a[]){
    if(distance<0)return 0;
    if(a[distance]>=0)return a[distance];
    a[distance] = countWaysRecursion(distance-1, a)+countWaysRecursion(distance-2, a)+countWaysRecursion(distance-3, a);
    return a[distance];
}

int countWaysToTravelRecursion(int distance){
    int a[distance+1];
    a[0]=1;
    for(int i=1; i<=distance; i++)a[i]=-1;
    return countWaysRecursion(distance, a);
}

int countWaysToTravelIterative(int distance){
    int a[distance+1];
    a[0]=1; a[1]=1; a[2]=2;
    for(int i=3; i<=distance; i++)a[i]=a[i-1]+a[i-2]+a[i-3];
    return a[distance];
}

#endif /* DISTANCESTEPS_H */

