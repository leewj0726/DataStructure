//
//  practice2-3.cpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 4. 30..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#include "practice2.hpp"

void p2_3::init()
{
    set_value();
    print_value();
}

void p2_3::print_value()
{
    for(int i = 0; i < MAX_INDEX; i++)
    {
        std::cout<< i <<"요소의 값: "<< two[i] << std::endl;
    }
}

void p2_3::set_value()
{
    two[0] = 1;
    for(int i = 1; i < MAX_INDEX; i++)
    {
        int tmp_val = 1;
        for(int j = 0; j < i; j++)
        {
            tmp_val *= 2;
        }
        two[i] = tmp_val;
    }
}

int Rectangle::perimeter()
{
    return h*w;
}

int Rectangle::area()
{
    return (h*2) + (w*2);
}


void p2_5::init()
{
    
}

