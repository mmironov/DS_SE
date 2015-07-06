//
//  clist.h
//  DS_SE
//
//  Created by Miroslav Mironov on 7/6/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#ifndef __DS_SE__clist__
#define __DS_SE__clist__

#include <stdio.h>

template <typename T>
struct clist {
    T value;
    clist<T>* prev;
    clist<T>* next;
};

#endif /* defined(__DS_SE__clist__) */
