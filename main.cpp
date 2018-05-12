//
//  main.cpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 4. 30..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#include <iostream>
#include "project1.hpp"
#include "practice2.hpp"

int main(int argc, const char * argv[])
{
    p1 *p1_inst = new p1(2000);
    p1_inst->init();
    
    p2_3 *p2_3_inst = new p2_3();
    p2_3_inst->init();
    return 0;
}
