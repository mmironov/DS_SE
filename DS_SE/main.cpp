//
//  main.cpp
//  DS_SE
//
//  Created by Miroslav Mironov on 7/5/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "clist.h"
#include "tree.h"
#include "list.h"
using namespace std;

void makeCircular(tree<int>* root)
{
    root->right = root;
    root->left = root;
}

void join(tree<int>* a, tree<int>* b)
{
    a->right = b;
    b->left = a;
}

tree<int>* append(tree<int>* l1, tree<int>* l2)
{
    if (!l1)
    {
        return l2;
    }
    
    if (!l2)
    {
        return l1;
    }
    
    tree<int>* last1 = l1->left;
    tree<int>* last2 = l2->left;
    
    join(last1, l2);
    join(last2, l1);
    
    return l1;
}

tree<int>* treeToList(tree<int>* root)
{
    if (!root)
    {
        return 0;
    }
    
    tree<int>* left = treeToList(root->left);
    tree<int>* right = treeToList(root->right);
    
    makeCircular(root);
    
    tree<int>* firstPart = append(left, root);
    tree<int>* fullList = append(firstPart, right);
    
    return fullList;
}

void printAsList(tree<int>* root)
{
    if (!root)
    {
        return;
    }
    
    tree<int>* p = root;
    
    do
    {
        cout << p->value << " ";
        p = p->right;
    }
    while (p != root);
}

int solve(Buffer<int> circle, int k)
{
    while (circle.size() > 1)
    {
        for(int i=1; i < k; ++i)
        {
            int front = circle.front();
            circle.dequeue();
            circle.enqueue(front);
        }
        
        circle.dequeue();
    }
    
    return circle.front();
}

void testTreeListRecursionAndOrdering()
{
    tree<int>* root = 0;
    
    insert(5, root);
    insert(10, root);
    insert(4, root);
    insert(0, root);
    
    print(root);
    
    cout << endl;
    
    cout << "Is the tree ordered: " << isOrdered(root) << endl;
    
    tree<int>* list = treeToList(root);
    
    printAsList(list);
    
    cout << endl;
}

void testJosephus()
{
    Buffer<int> circle;
    for(int i=1; i <= 9; ++i)
    {
        circle.enqueue(i);
    }
    
    int k = 4;
    
    cout << "Solved: " << solve(circle, k) << endl;
}

void testChain()
{
    list<int>* start = 0;
    list<int>* end = 0;
    
    for(int i=1; i <= 5; ++i) {
        add(i, start, end);
    }
    
    list<int>* start2 = 0;
    list<int>* end2 = 0;
    
    for(int i=1; i <= 5; ++i) {
        
        if (i==3)
        {
            add(i, start2, end2);
        }
        else
        {
            add(i*10, start2, end2);
        }
    }
    
    join(start, end, start2, end2);
    
    print(start);
    cout << endl;
    cout << "Is a chain?: " << isJoined(start, end2) << endl;
    cout << "Sum chain: " << sumChain(start, end2) << endl;
}

void testSymmetric()
{
    tree<int>* root = 0;
    
    insert(5, root);
    insert(10, root);
    insert(4, root);
    insert(0, root);
    insert(20, root);
    
    cout <<"Is symmetric: " << isSymmetric(root);
}

int main(int argc, const char * argv[]) {
    
    //testTreeListRecursionAndOrdering();
    
    //testJosephus();
    
    //testChain();
    
    testSymmetric();
    
    return 0;
}
