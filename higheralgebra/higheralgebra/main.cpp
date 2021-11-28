//
//  main.cpp
//  higheralgebra
//
//  Created by Рамиль Алиев on 16.04.2020.
//  Copyright © 2020 Рамиль Алиев. All rights reserved.
//

#include <iostream>
#include "permutation.hpp"
#define N sizeof(unsigned long)

using namespace std;

int main(int argc, const char * argv[]) {
    unsigned long s[7],t[5];
    s[0]=2; //1 S                  T
    s[1]=1; //2   1 2 3 4 5 6 7    1 2 3 4 5 6 7
    s[2]=5; //3   2 1 5 3 4 7 6    1 2 3 5 4 6 7
    s[3]=3; //4
    s[4]=4; //5
    s[5]=7; //6
    s[6]=6; //7
    t[0]=1; //1 T 1 2 3 5 4 6 7
    t[1]=2; //2
    t[2]=3; //3
    t[3]=5; //4
    t[4]=4; //5
    permutation S(7, s);
    permutation T(5, t);
    S.print();
    cout<<endl;
    T.print();
    cout<<endl;
    permutation K=T*S;
    K.print();
    return 0;
}
