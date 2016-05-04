//  https://github.com/zhiyu/chartee/
//
//  Created by zhiyu on 7/11/11.
//  Copyright 2011 zhiyu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Chart.h"
#import <QuartzCore/QuartzCore.h>
#import "YAxis.h"
#import "AutoCompleteDelegate.h"

@interface CandleViewController : UIViewController<UISearchBarDelegate>

@property (nonatomic, strong) Chart *candleChart;
@property (nonatomic, strong) UITableView *autoCompleteView;
@property (nonatomic, strong) UIView *toolBar;
@property (nonatomic, strong) UIView *candleChartFreqView;
@property (nonatomic, strong) AutoCompleteDelegate *autoCompleteDelegate;
@property (nonatomic, strong) NSTimer *timer;
@property (nonatomic, assign) int chartMode;
@property (nonatomic, assign) int tradeStatus;
@property (nonatomic, copy) NSString *lastTime;
@property (nonatomic, strong) UILabel *status;
@property (nonatomic, copy) NSString *req_freq;
@property (nonatomic, copy) NSString *req_type;
@property (nonatomic, copy) NSString *req_url;
@property (nonatomic, copy) NSString *req_security_id;

-(void)initChart;
-(void)getData;
-(void)generateData:(NSMutableDictionary *)dic From:(NSArray *)data;
-(void)setData:(NSDictionary *)dic;
-(void)setCategory:(NSArray *)category;
-(BOOL)isCodesExpired;
-(void)getAutoCompleteData;
-(void)setOptions:(NSDictionary *)options ForSerie:(NSMutableDictionary *)serie;

@end
