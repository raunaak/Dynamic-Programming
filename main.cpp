#include <iostream>
#include "CountDearrangement.h"
#include "KTurnPath.h"
using namespace std;

int main(){
    //Go (0,0) to (m,n) in k turns
    cout<<kTurnPath(3,3,2);
    
    //Count total dearrangements of n numbers
    //cout<<countDearrangement(4);
    return 0;
}

