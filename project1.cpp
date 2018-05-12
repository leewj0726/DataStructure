//
//  practice1.cpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 4. 30..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#include "project1.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

p1::p1(int num) : n(num){}

int p1::algoritm1(int n)
{
    int num = (n * (n+1))/2;
    return num;
}

int p1::algoritm2(int n)
{
    int num = 0;
    for(int i = 1; i <= n; i++)
    {
        num += i;
    }
    return num;
}

int p1::algoritm3(int n)
{
    int i;
    int j;
    int num = 0;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j < i; j++)
        {
            num += 1;
        }
    }
    return num;
}

void p1::calc_time(boost::function<int (int)> func, int num)
{
    clock_t start, finish;
    double duration;
    start = clock();
    
    std::cout << "결과: " <<func(num) << std::endl;
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout.precision(7);
    std::cout << "시간: " << std::fixed << duration << std::endl;
}

void p1::init()
{
    calc_time(boost::bind(&p1::algoritm1,this, _1),n);
    calc_time(boost::bind(&p1::algoritm2,this, _1),n);
    calc_time(boost::bind(&p1::algoritm3,this, _1),n);
}
