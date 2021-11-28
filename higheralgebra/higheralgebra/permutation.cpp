//
//  permutation.cpp
//  higheralgebra
//
//  Created by Рамиль Алиев on 07.07.2020.
//  Copyright © 2020 Рамиль Алиев. All rights reserved.
//

#include "permutation.hpp"

permutation:: permutation(){
        n=2;
        Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        Im[0]=1;
        Im[1]=2;
    }
permutation:: permutation(const unsigned long &m){
        n=m;
        Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<n;++i)
            Im[i]=i+1;
    }
permutation:: permutation(const unsigned long &m, unsigned long *A){
        n=m;
        Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<n;++i)
            Im[i]=A[i];
    }
permutation:: permutation(permutation const &a){
        n=a.n;
        Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<n;++i)
            Im[i]=a.Im[i];
    }
permutation:: permutation(permutation const &a, const unsigned long &k){
        n=k;
        Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<a.n;++i)
            Im[i]=a.Im[i];
        for(unsigned long i=a.n;i<n;++i)
            Im[i]=i+1;
}
    unsigned long permutation::operator[](const unsigned long &k){
        return Im[k-1];
    }
permutation permutation::inverse(){
        unsigned long *IM;
        IM=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=1;i<=n;++i){
            IM[Im[i-1]-1]=i;
        }
        permutation inv(n,IM);
        return inv;
}
permutation permutation::operator=(const permutation& a){
        n=a.n;
        free(Im);
        Im=Im=(unsigned long*)malloc(n*sizeof(unsigned long));
        for(unsigned long i=0;i<n;++i){
            Im[i]=a.Im[i];
        }
        return *this;
    }
bool permutation::operator==(const permutation& a){
        if(n==a.n){
            for(unsigned long i=0;i<n;++i){
                if(Im[i]!=a.Im[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    bool permutation::operator!=(const permutation& a){
        return !(*this==a);
    }
    permutation permutation::operator*(const permutation& a){
        if(n>a.n){
            permutation res(*this);
            for(unsigned long i=0;i<a.n;++i){
                unsigned long k=a.Im[i];
                res.Im[i]=Im[k-1];
            }
            return res;
        }else if(n<a.n){
            permutation res(a);
            for(unsigned long i=0;i<n;++i){
                unsigned long k=a.Im[i];
                res.Im[i]=Im[k-1];
            }
            return res;
        }
        permutation res(n);
        for(unsigned long i=0;i<n;++i){
            unsigned long k=a.Im[i];
            res.Im[i]=Im[k-1];
        }
        return res;
    }
    permutation permutation::operator*=(const permutation& a){
        if(n>a.n){
            permutation res(*this);
            for(unsigned long i=0;i<a.n;++i){
                unsigned long k=a.Im[i];
                res.Im[i]=Im[k-1];
            }
            *this=res;
            return *this;
        }else if(n<a.n){
            permutation res(a);
            for(unsigned long i=0;i<n;++i){
                unsigned long k=a.Im[i];
                res.Im[i]=Im[k-1];
            }
            *this=res;
            return *this;
        }
        permutation res(n);
        for(unsigned long i=0;i<n;++i){
            unsigned long k=a.Im[i];
            res.Im[i]=Im[k-1];
        }
        *this=res;
        return *this;
    }
/*
    permutation permutation::embed(const permutation& a, const unsigned long &m){
        
        return;
    }*/
    void permutation::print(){
        for(unsigned long i=0;i<n;++i)
            std::cout<<Im[i]<<" ";
    }
    permutation permutation::pow(const unsigned long &h){
        permutation A(n);
        for(unsigned long i=0;i<h;++i)
            A=A*(*this);
        return A;
    }
    unsigned long permutation::ord(){
        permutation id(n);
        permutation A(*this);
        unsigned long o=1;
        while(A != id){
            A*=(*this);
            ++o;
        }
        return o;
    }
/*
vector <permutation> permutation :: incycles(){
    vector <permutation> c;
    vector <bool> v(n);
    for(unsigned long i=0;i<n;++i)
        v[i]=true;
    unsigned long k=0,max=0;
    while(v[k]){
        if(Im[k]>k)
            max=c[k-1];
        v[k]=false;
        if(v[k]==k)
            ++k;
        else
            k=c[k-1];
    }
    double *im;
    im=(unsigned long*)malloc((max+1)*sizeof(unsigned long));
    permutation p(max+1,im);
    c.push_back(p);
    max=1;
    for(k=1;k<n && v[k];++k){
        max=k;
        while(v[k]){
            if(c[k-1]>k)
                max=c[k-1];
            v[k]=false;
            if(v[k]==k)
                ++k;
            else
                k=c[k-1];
        }
    }
    return c;
}
*/
