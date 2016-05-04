//
//  YAxis.h
//  https://github.com/zhiyu/chartee/
//
//  Created by zhiyu on 7/11/11.
//  Copyright 2011 zhiyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YAxis : NSObject

@property(nonatomic, assign) bool isUsed;

@property(nonatomic, assign) CGRect frame;
@property(nonatomic, assign) float max;
@property(nonatomic, assign) float min;
@property(nonatomic, assign) float ext;
@property(nonatomic, assign) float baseValue;
@property(nonatomic, assign) bool  symmetrical;
@property(nonatomic, assign) bool  baseValueSticky;
@property(nonatomic, assign) float paddingTop;
@property(nonatomic, assign) int tickInterval;
@property(nonatomic, assign) int pos;
@property(nonatomic, assign) int decimal;

-(void)reset;

@end
