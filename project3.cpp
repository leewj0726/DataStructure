//
//  project3.cpp
//  DataStructure
//
//  Created by WooJin Lee on 2018. 6. 17..
//  Copyright © 2018년 WooJin Lee. All rights reserved.
//

#include "project3.hpp"



ArrayStack::ArrayStack()
{
    top = -1;
}

ArrayStack::~ArrayStack()
{
    
}

bool ArrayStack::isEmpty()
{
    return top == -1;
}

bool ArrayStack::isFull()
{
    return top == MAX_STACK_SIZE - 1;
}

void ArrayStack::push(int e)
{
    if(isFull())
    {
        error("스택 오버플로우 에러");
    }
    
    data[++top] = e;
}

int ArrayStack::pop()
{
    if(isEmpty())
    {
        error("스택 공백 에러");
    }
    
    return data[top--];
}

int ArrayStack::peek()
{
    if(isEmpty())
    {
        error("스택 공백 에러");
    }
    return data[top];
}

void ArrayStack::display()
{
    std::string msg;
    msg = (boost::format("[스택 항목의 수 = %2d] ==> ") % (top+1)).str();
    std::cout<<msg<<std::endl;
    
    for(int i = 0; i <= top; i++)
    {
        msg = (boost::format("<%2d>") % data[i]).str();
        std::cout<<msg;
    }
    std::cout<<std::endl;
}

bool ArrayStack::checkMatching(char * filename)
{
    FILE *fp = fopen(filename, "r");
    char prior_ch = ' ';
    int count_quote = 0;
    
    if(fp == NULL)
    {
        error("ERROR: 파일이 존재하지 않습니다.\n");
    }
    
    int nLine = 1; // 읽은 라인 개수
    int nChar = 0; // 읽은 문자 개수
    
    ArrayStack stack;   //스택 객체
    char ch;
    
    while ((ch = getc(fp)) != EOF)
    {
        if(ch == '/n')
        {
            nLine++;
        }
        nChar++;
        
        if(prior_ch == '\'')
        {
            if(ch != '\'')
            {
                count_quote++;
            }
        }
        
        if(count_quote == 0 || count_quote == 2) //바로 이전 케릭터가 쿼테이션이 아니면서 쿼테이션 카운터도 2가 아직 아닌 경우
        {
            if(ch == '[' || ch == '(' || ch == '{')
            {
                stack.push(ch);
            }
            
            else if (ch == ']' || ch ==')' || ch == '}')
            {
                int prev = stack.pop();
                if ((ch == ']' && prev != '[') ||
                    (ch == ')' && prev != '(') ||
                    (ch =='}' && prev != '{') )
                {
                    break;
                }
            }
            
            if(count_quote == 2)
            {
                count_quote = 0;
            }
        }
        
        
        prior_ch = ch;
    }
    
    fclose(fp);
    
    std::string msg;
    msg = (boost::format("%s 파일 검사결과:\n") % filename).str();
    std::cout<<msg<<std::endl;
    
    if(!stack.isEmpty())
    {
        msg = (boost::format("Error: 문제 발견!(라인수 = %d, 문자수 = %d)\n\n") % nLine % nChar).str();
        std::cout<<msg<<std::endl;
    }
    else
    {
        msg = (boost::format("Ok: 괄호닫기정상(라인수 = %d, 문자수 = %d)\n\n") % nLine % nChar).str();
        std::cout<<msg<<std::endl;
    }
    return stack.isEmpty();
    
}


p3::p3()
{
    
}

void p3::init()
{
    ArrayStack* checkmatch = new ArrayStack();
    checkmatch->checkMatching("/Users/woojinlee/Documents/GitRepository/DataStructure/project3.hpp");
    checkmatch->checkMatching("/Users/woojinlee/Documents/GitRepository/DataStructure/project3.cpp");
}
