//
//  rectangle.cpp
//  FiguringShitOut
//
//  Created by Kylie Nicholson on 10/20/15.
//  Copyright (c) 2015 Kylie Nicholson. All rights reserved.
//

#include "rectangle.h"

rectangle::rectangle(){
    width =0;
    height = 0;
}

rectangle::rectangle(int w, int h){
    width = w;
    height = h;
}

int rectangle::area(){
    int area = width * height;
    return area;
}