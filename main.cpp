#include <iostream>
#include "CountDearrangement.h"
#include "KTurnPath.h"
#include "PathsWithFixedLength.h"
#include "RemoveElementsWithGivenCondition.h"
#include "SolutionToNVariableEquation.h"
#include "SubsetSum.h"
using namespace std;

int main(){
    int set[] = {3, 34, 4, 12, 5, 2}; int sum = 9;
    cout<<subsetSum(set, 6, sum);
    
    /* Find number of solution to n variable equation
    int coeff[] = {2, 2, 3}; int rhs = 4;
    cout<<numberOfSolution(coeff, 3, rhs);
    */
    
    /* Remove elements with given condition
    int arr[] = {2, 3, 4, 5, 6, 4};
    cout<<function(arr, 6, 1);
    */
    
    /* Find paths with k coins
    int k = 12;
    int mat[3][3] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << pathWithKCoins(mat,2, 2, k);
    */
    
    //Go (0,0) to (m,n) in k turns
    //cout<<kTurnPath(3,3,2);
    
    //Count total dearrangements of n numbers
    //cout<<countDearrangement(4);
    return 0;
}

