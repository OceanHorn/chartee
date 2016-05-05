//
//  Chart.h
//  https://github.com/zhiyu/chartee/
//
//  Created by zhiyu on 7/11/11.
//  Copyright 2011 zhiyu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YAxis.h"
#import "Section.h"
#import "ChartModel.h"
#import "LineChartModel.h"
#import "AreaChartModel.h"
#import "ColumnChartModel.h"
#import "CandleChartModel.h"

@class ChartModel;

@interface Chart : UIView

@property (nonatomic, assign) bool enableSelection;
@property (nonatomic, assign) bool isInitialized;
@property (nonatomic, assign) bool isSectionInitialized;
@property (nonatomic, assign) float borderWidth;
@property (nonatomic, assign) float plotWidth;
@property (nonatomic, assign) float plotPadding;
@property (nonatomic, assign) float plotCount;
@property (nonatomic, assign) float paddingLeft;
@property (nonatomic, assign) float paddingRight;
@property (nonatomic, assign) float paddingTop;
@property (nonatomic, assign) float paddingBottom;
@property (nonatomic, assign) int rangeFrom;
@property (nonatomic, assign) int rangeTo;
@property (nonatomic, assign) int range;
@property (nonatomic, assign) int selectedIndex;
@property (nonatomic, assign) float touchFlag;
@property (nonatomic, assign) float touchFlagTwo;
@property (nonatomic,retain) NSMutableArray *padding;
@property (nonatomic,retain) NSMutableArray *series;
@property (nonatomic,retain) NSMutableArray *sections;
@property (nonatomic,retain) NSMutableArray *ratios;
@property (nonatomic,retain) NSMutableDictionary *models;
@property (nonatomic,retain) UIColor *borderColor;
@property (nonatomic,retain) NSString *title;


-(float)getLocalY:(float)val withSection:(int)sectionIndex withAxis:(int)yAxisIndex;
-(void)setSelectedIndexByPoint:(CGPoint) point;
-(void)reset;

/* init */
-(void)initChart;
-(void)initXAxis;
-(void)initYAxis;
-(void)initModels;
-(void)addModel:(ChartModel *)model withName:(NSString *)name;
-(ChartModel *)getModel:(NSString *)name;

/* draw */
-(void)drawChart;
-(void)drawXAxis;
-(void)drawYAxis;
-(void)drawSerie:(NSMutableDictionary *)serie;
-(void)drawLabels;
-(void)setLabel:(NSMutableArray *)label forSerie:(NSMutableDictionary *) serie;

/* data */
-(void)appendToData:(NSArray *)data forName:(NSString *)name;
-(void)clearDataforName:(NSString *)name;
-(void)clearData;
-(void)setData:(NSMutableArray *)data forName:(NSString *)name;

/* category */
-(void)appendToCategory:(NSArray *)category forName:(NSString *)name;
-(void)clearCategoryforName:(NSString *)name;
-(void)clearCategory;
-(void)setCategory:(NSMutableArray *)category forName:(NSString *)name;

/* series */
-(NSMutableDictionary *)getSerie:(NSString *)name;
-(void)addSerie:(NSObject *)serie;

/* section */
-(Section *)getSection:(int) index;
-(int) getIndexOfSection:(CGPoint) point;
-(void)addSection:(NSString *)ratio;
-(void)removeSection:(int)index;
-(void)addSections:(int)num withRatios:(NSArray *)rats;
-(void)removeSections;
-(void)initSections;

/* YAxis */
-(YAxis *)getYAxis:(int) section withIndex:(int) index;
-(void)setValuesForYAxis:(NSDictionary *)serie;

@end
