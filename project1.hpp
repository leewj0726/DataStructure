//
//  practice1.hpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 4. 30..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#ifndef project1_hpp
#define project1_hpp

#include <stdio.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>

class p1
{
public:
    p1(int num);
    void init();
    
private:
    int n;
    int sum;
    
    int algoritm1(int n);
    int algoritm2(int n);
    int algoritm3(int n);
    
    void calc_time(boost::function<int (int)> func, int num);
};

#endif /* practice1_hpp */
