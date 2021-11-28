//
//  permutation.hpp
//  higheralgebra
//
//  Created by Рамиль Алиев on 07.07.2020.
//  Copyright © 2020 Рамиль Алиев. All rights reserved.
//

#ifndef permutation_hpp
#define permutation_hpp

#include <iostream>
#include <vector>
using namespace std;


class permutationcycle{
    unsigned long n;
    unsigned long *Im;
public:
    permutationcycle();
    
};

class permutation{
    unsigned long n;
    unsigned long *Im;
public:
    permutation();
    permutation(const unsigned long &m);
    permutation(const unsigned long &m, unsigned long *A);
    permutation(permutation const &a);
    permutation(permutation const &a, const unsigned long &k);
    ~permutation();
    unsigned long operator[](const unsigned long &k);
    permutation inverse();
    permutation operator=(const permutation& a);
    bool operator==(const permutation& a);
    bool operator!=(const permutation& a);
    permutation operator*(const permutation& a);
    permutation operator*=(const permutation& a);
   // permutation embed(const permutation& a, const unsigned long &m);
    void print();
    permutation pow(const unsigned long &h);
    unsigned long ord();
   // vector <permutation> incycles();
};

#endif /* permutation_hpp */
