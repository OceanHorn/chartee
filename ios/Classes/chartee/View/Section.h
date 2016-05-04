//
//  Section.h
//  https://github.com/zhiyu/chartee/
//
//  Created by zhiyu on 7/11/11.
//  Copyright 2011 zhiyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YAxis.h"

@interface Section : NSObject 

@property (nonatomic, assign) bool   hidden;
@property (nonatomic, assign) bool   isInitialized;
@property (nonatomic, assign) bool   paging;
@property (nonatomic, assign) int    selectedIndex;
@property (nonatomic, assign) CGRect frame;
@property (nonatomic, assign) float  paddingLeft;
@property (nonatomic, assign) float  paddingRight;
@property (nonatomic, assign) float  paddingTop;
@property (nonatomic, assign) float  paddingBottom;
@property (nonatomic, strong) NSMutableArray *padding;
@property (nonatomic, strong) NSMutableArray *series;
@property (nonatomic, strong) NSMutableArray *yAxises;
@property (nonatomic, strong) NSMutableArray *xAxises;

-(void)addYAxis:(int)pos;
-(void)removeYAxis:(int)index;
-(void)addYAxises:(int)num at:(int)pos;
-(void)removeYAxises;
-(void)initYAxises;
-(void)nextPage;

@end
