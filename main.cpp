#include <iostream>
#include "CountDearrangement.h"
#include "KTurnPath.h"
#include "PathsWithFixedLength.h"
using namespace std;

int main(){
    int k = 12;
    int mat[3][3] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << pathWithKCoins(mat,2, 2, k);
    
    //Go (0,0) to (m,n) in k turns
    //cout<<kTurnPath(3,3,2);
    
    //Count total dearrangements of n numbers
    //cout<<countDearrangement(4);
    return 0;
}

