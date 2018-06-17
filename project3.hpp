//
//  project3.hpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 6. 17..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#ifndef project3_hpp
#define project3_hpp

#include <cstdio>
#include <cstdlib>
#include <boost/format.hpp>
#include <iostream>

#endif /* project3_hpp */

const int MAX_STACK_SIZE = 20;

class p3
{
public:
    p3();
    void init();
};

inline void error(char* message)
{
    std::string msg;
    msg = (boost::format("%s\n") % message).str();
    std::cout<<msg<<std::endl;
}

class ArrayStack
{
public:
    ArrayStack();
    virtual ~ArrayStack();

    bool checkMatching(char* filename);
    
private:
    int top;
    int data[MAX_STACK_SIZE];
    
    bool isEmpty();
    bool isFull();
    
    void push(int e);
    int pop();
    int peek();
    void display();
    void ignore_quatation(char* ch);
};
