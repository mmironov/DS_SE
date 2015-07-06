//
//  list.h
//  DS_SE
//
//  Created by Miroslav Mironov on 7/5/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#ifndef __DS_SE__list__
#define __DS_SE__list__

#include <iostream>
using namespace std;

template <typename T>
struct list {
    T value;
    list* prev;
    list* next;
};

template <typename T>
void print(list<T>* start)
{
    while (start)
    {
        cout << start->value << " ";
        start = start->next;
    }
}

template <typename T>
void add(const T& value, list<T>*& start, list<T>*& end)
{
    list<T>* elem = new list<T>;
    elem->value = value;
    elem->prev = 0;
    elem->next = 0;
    
    if (!start)
    {
        start = elem;
        end = elem;
        return;
    }
    
    end->next = elem;
    elem->prev = end;
    end = elem;
}

//Result is in start1 and end2
bool join(list<int>* start1, list<int>* end1,
          list<int>* start2, list<int>* end2)
{
    list<int>* toLeft = end1;
    list<int>* toRight = start2;
    
    while (toLeft && toRight)
    {
        if (toLeft->value == toRight->value)
        {
            start2->prev = toLeft;
            end1->next = toRight;
            return true;
        }
        
        toLeft = toLeft->prev;
        toRight = toRight->next;
    }
    
    return false;
}

bool isJoined(list<int>* start, list<int>* end)
{
    while (start && end)
    {
        if (start->next && start->next->prev != start)
        {
            return true;
        }
        
        if (end->prev && end->prev->next != end)
        {
            return true;
        }
        
        start = start->next;
        end = end->prev;
    }
    
    return false;
}

int sumChain(list<int>* start, list<int>* end)
{
    int sum = 0;
    
    while (start)
    {
        sum += start->value;
        
        if (start->next && start->next->prev != start)
        {
            break;
        }
        
        start = start->next;
    }
    
    while (end)
    {
        sum += end->value;
        
        if (end->prev && end->prev->next != end)
        {
            break;
        }
        
        end = end->prev;
    }
    
    return sum;
}

#endif /* defined(__DS_SE__list__) */