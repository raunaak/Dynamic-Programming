#ifndef REMOVEELEMENTSWITHGIVENCONDITION_H
#define REMOVEELEMENTSWITHGIVENCONDITION_H
http://www.geeksforgeeks.org/find-minimum-possible-size-of-array-with-given-rules-for-removal/

//utility function to get to next 3 elements satisfying the given condition
void goToNextFalse(bool b[], int n, int i, int &x, int& y, int& z){
    x = -1; y = -1; z = -1;
    for(int j = i+1; j<n; j++){
        if(b[j]==false){
            if(x==-1)x=j;
            else if(y==-1)y=j;
            else if(z==-1)z=j;
        }
        if(z!=-1)return;
    }
    if(z==-1)z=n;
}

//utility function to count number of elements which are not removed
int countFalse(bool b[], int n){
    int count = 0;
    for(int i=0; i<n; i++)if(!b[i])count++;
    return count;
}

//main function to return minimum size
int function(int a[], int n, bool b[], int d){
    int x = -1; int y = -1; int z = -1; //x = index of first element, y = index of second element, z = index of third element
    int min = countFalse(b, n); //count elements left
    goToNextFalse(b, n, -1, x, y, z); //go to the next required sequence satisfying condition
    while(x<n&&y<n&&z<n){
        if(a[z]==a[y]+d&&a[x]+d==a[y]){ 
            b[x]=true; b[y]=true; b[z]=true; //elements are removed 
            int f = function(a, n, b, d); //minimum size for this child with above 3 elements removed
            if(f<min)min=f; //find minimum size among all sequence when one 3 element sequence has been further removed
            b[x]=false; b[y]=false; b[z]=false; //retrieve initial configuration
        }
        goToNextFalse(b, n, x, x, y, z); //move to next element
    }
    return min;
}

// user interface function
int function(int array[], int n, int d){
    bool b[n]; //boolean array to determine whether an element has been deleted or not, 'false' = not deleted, 'true' = deleted
    for(int i=0; i<n; i++)b[i]=false; // no element is deleted yet
    return function(array, n, b, d);
}


#endif /* REMOVEELEMENTSWITHGIVENCONDITION_H */

