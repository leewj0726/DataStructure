//
//  practice2-3.hpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 4. 30..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#ifndef practice2_3_hpp
#define practice2_3_hpp

#define MAX_INDEX 10

#include <stdio.h>
#include <iostream>

class p2_3
{
public:
    void init();
    void set_value();
    void print_value();
    
private:
    int two[MAX_INDEX];
};

class p2_4
{

};

class Rectangle
{
public:
    int area();
    int perimeter();
    
private:
    int w;
    int h;
};

class p2_5
{
public:
    Rectangle rec;
    p2_5();
    void init();
};



#endif /* practice2_3_hpp */
