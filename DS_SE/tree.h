//
//  tree.h
//  DS_SE
//
//  Created by Miroslav Mironov on 7/5/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#ifndef __DS_SE__tree__
#define __DS_SE__tree__

#include <iostream>
using namespace std;

#endif /* defined(__DS_SE__tree__) */

template <typename T>
struct tree {
    T value;
    tree<T>* left;
    tree<T>* right;
};

template <typename T>
void insert(const T& value, tree<T>*& root)
{
    if (!root)
    {
        root = new tree<T>;
        root->value = value;
        root->left = 0;
        root->right = 0;
        return;
    }
    
    if (root->value == value)
    {
        return;
    }
    else if (value < root->value)
    {
        insert(value, root->left);
    }
    else
    {
        insert(value, root->right);
    }
}

template<typename T>
void print(tree<T>* root)
{
    if (root)
    {
        print(root->left);
        cout << root->value << " ";
        print(root->right);
    }
}