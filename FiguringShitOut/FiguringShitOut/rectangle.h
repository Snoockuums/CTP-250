//
//  rectangle.h
//  FiguringShitOut
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#ifndef __FiguringShitOut__rectangle__
#define __FiguringShitOut__rectangle__

#include <stdio.h>

class rectangle {
private:
    int width;
    int height;
    
public:
    rectangle();
    rectangle(int, int);
    int area();
};
#endif /* defined(__FiguringShitOut__rectangle__) */
