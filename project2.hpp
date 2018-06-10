//
//  project2.hpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 5. 15..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#ifndef project2_hpp
#define project2_hpp

#include <cstdio>
#include <stdio.h>
#include <string>
#include <iostream>

#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#define MAX_DEGREE 80 //다항식의 처리 가능한 최대 차수+1

class Polynomial
{
    int degree;
    float coef[MAX_DEGREE];
    
public:
    Polynomial();
    
    //다항식의 내용을 입력받는 멤버함수
    void read();
    
    // 다항식의 내용을 화면에 출력하는 함수
    void display(char *str); // 디폴트 매개변수 사용
    void add(Polynomial a, Polynomial b);
    void sub(Polynomial a, Polynomial b);
    void mul(Polynomial a, Polynomial b);
    
    float comp(float a, float b);
    
    void trim();
    bool isZero(); 
    void negate();
    
    
};

class p2
{
public:
    p2();
    void init();
};

#endif /* project2_hpp */
