//
//  project2.cpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 5. 15..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#include "project2.hpp"

p2::p2(){}

void p2::init()
{
    Polynomial a,b,c;
    a.read();
    b.read();
    c.sub(a, b);
    
    a.display("A = ");
    b.display("B = ");
    c.display("A+B=");
}

Polynomial::Polynomial()
{
    degree = 0;
}

void Polynomial::read()
{
    printf("다항식의 최고 차수를 입력하십시오");
    scanf("%d", &degree);
    printf("각 항의 계수를 입력하시오");
    
    for(int i=0 ; i<=degree ; i++)
    {
        scanf("%f", coef+i);
    }
}

void Polynomial::display(char *str)
{
    printf("\t%s", str);
    for(int i = 0; i < degree ; i++)
    {
        printf("%5.1f x^%d + ", coef[i], degree-i);
    }
    printf("%4.1f\n", coef[degree]);
}

void Polynomial::add(Polynomial a, Polynomial b)
{
    if(a.degree > b.degree)
    {
        *this = a;
        for (int i = 0; i<=b.degree; i++)
        {
            coef[i+(degree-b.degree)] += b.coef[i];
        }
    }
    else
    {
        *this = b;
        for (int i = 0; i<=a.degree; i++)
        {
            coef[i+(degree-a.degree)] += a.coef[i];
        }
    }
}

void Polynomial::sub(Polynomial a, Polynomial b)
{
    if(a.degree > b.degree)
    {
        *this = a;
        for (int i = 0; i<=b.degree; i++)
        {
            coef[i+(degree-b.degree)] -= b.coef[i];
        }
    }
    else
    {
        *this = b;
        for (int i = 0; i<=a.degree; i++)
        {
            coef[i+(degree-a.degree)] -= a.coef[i];
        }
    }
}

bool Polynomial::isZero()
{
    return degree == 0;
}

void Polynomial::negate()
{
    for (int i = 0; i < degree; i++)
    {
        coef[i] = -coef[i];
    }
}
