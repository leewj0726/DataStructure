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
    Polynomial a,b,c,d,e;
    a.read();
    b.read();
    c.add(a, b);
    d.sub(a, b);
    e.mul(a, b);
    
    a.display("A = ");
    b.display("B = ");
    c.display("A+B=");
    d.display("A-B=");
    e.display("A*B=");
}

Polynomial::Polynomial()
{
    degree = 0;
}

void Polynomial::read()
{
    std::string mesg;
    
    mesg = (boost::format("%s") % "다항식 최고 차수를 입력하십시오.").str();
    std::cout << mesg;
    scanf("%d", &degree);
    
    mesg = (boost::format("%s") % "각 항의 계수를 입력하시오").str();
    std::cout << mesg;
    
    for(int i=0 ; i<=degree ; i++)
    {
        scanf("%f", coef+i);
    }
}

void Polynomial::display(char *str)
{
    std::string mesg;
    
    mesg = (boost::format("\t%s") % str).str();
    std::cout << mesg;
    
    for(int i = 0; i < degree ; i++)
    {
        mesg = (boost::format("%5.1f x^%d + ") % coef[i] % (degree-i)).str();
        std::cout << mesg;
    }
    mesg = (boost::format("%4.1f\n") % coef[degree]).str();
    std::cout << mesg;
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

float Polynomial::comp(float a, float b) // sub 기능을 위한 값 크기 비교 함수
{
    float tmp_result;
    if (a >= b)
    {
        tmp_result = (a - b);
        return tmp_result;
    }
    else
    {
        tmp_result = (b - a);
        return tmp_result;
    }
}

void Polynomial::sub(Polynomial a, Polynomial b)
{
    if(a.degree > b.degree)
    {
        *this = a;
        for (int i = 0; i<=b.degree; i++)
        {
            coef[i+(degree-b.degree)] = comp(coef[i+(degree-b.degree)], b.coef[i]);
            //coef[i+(degree-b.degree)] -= b.coef[i];
        }
    }
    else
    {
        *this = b;
        for (int i = 0; i<=a.degree; i++)
        {
            coef[i+(degree-a.degree)] = comp(coef[i+(degree-a.degree)], a.coef[i]);
            //coef[i+(degree-a.degree)] -= a.coef[i];
        }
    }
    
    trim();
}

void Polynomial::mul(Polynomial a, Polynomial b)
{
    if(a.degree > b.degree)
    {
        *this = a;
        for (int i = 0; i<=b.degree; i++)
        {
            coef[i+(degree-b.degree)] *= b.coef[i];
        }
    }
    else
    {
        *this = b;
        for (int i = 0; i<=a.degree; i++)
        {
            coef[i+(degree-a.degree)] *= a.coef[i];
        }
    }
}

void Polynomial::trim()
{
    int not_zero_pos = 0; // 높은 차수부터 루프를 돌며 A와 B의 차수가 0이 아닌 값이 나오는 차수를 저장하기 위한 공간
    for(int i = degree; i >= 0; i-- )
    {
        if(coef[i] != 0)
        {
            not_zero_pos = (degree - i); //차수가 0이 아니면 해당 차수를 저장 하고 루프를 끝냄
            break;
        }
    }
    
    float tmp_coef[not_zero_pos+1]; // A와 B의 차가 0이 아닌 차수만큼의 메모리 공간을 만듦
    
    int j = 0;
    degree = not_zero_pos; // 현재의 객체의 차수 값에 0이 아닌 차수를 덮어씌워 저장해둠
    for (int i = degree; i >= 0; i--) //
    {
        tmp_coef[j] = coef[i];
        j++;
    }
    
    memcpy(coef,tmp_coef,sizeof(tmp_coef));
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
