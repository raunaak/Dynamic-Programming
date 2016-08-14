#include <iostream>
#include "CountDearrangement.h"
#include "KTurnPath.h"
#include "PathsWithFixedLength.h"
#include "RemoveElementsWithGivenCondition.h"
#include "SolutionToNVariableEquation.h"
#include "SubsetSum.h"
#include "LongestPath.h"
#include "DistanceSteps.h"
#include "SameHalfSum.h"
#include "LongestSubsequence.h"
#include "TotalNumberOfNDigits.h"
#include "SumOfDigits.h"
#include "ReachDestination.h"
#include "NonDecreasingSequence.h"
#include "LongestPathInMatrix.h"
using namespace std;

int main(){
    //Find length of the longest consecutive path from a given starting character
    char mat[3][3] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};
 
    cout << longestPath(mat, 'a') << endl;
    cout << longestPath(mat, 'e') << endl;
    cout << longestPath(mat, 'b') << endl;
    cout << longestPath(mat, 'f') << endl;
    
    //Count non decreasing sequence with maximum length n
    //cout<<countNonDecreasing(3);
    
    //Minimum positive points to reach destination
    /*int points[3][3] = { {-2,-3,3},
                      {-5,-10,1},
                      {10,30,-5}
                    };
    cout<<minInitialPoints(points);*/
    
    //Count of n digit numbers whose sum of digits equals to given sum
    //cout<<countDigits(2,18);
    
    //total number of digits of length n with even sum = odd sum+1
    //cout<<totalNumber(3);
    
    //Longest Repeating Subsequence
    //cout<<longestSubsequence("axxxaa",6);
    
    //Count even length binary sequences with same sum of first and second half bits
    //cout<<sameHalfSum(2);
    
    /* Count ways to travel using 1,2 and 3
    cout<<countWaysToTravelRecursion(3);
    cout<<countWaysToTravelIterative(1);
    */
    
    /*
    int mat[][3] = {{1, 2, 9},
                   {5, 3, 8},
                   {4, 6, 7}};
    longestPath(mat,3);
    */
    
    /* Count number of subsets with given sum
    int set[] = {3, 34, 4, 12, 5, 2}; int sum = 9;
    cout<<sumSubset(set, 6, sum);
    */
    
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
    //cout<<kTurnPath(3,3,3);
    
    //Count total dearrangements of n numbers
    //cout<<countDearrangement(4);
    return 0;
}

