//
//  YFURLSessionManager.h
//  chartee
//
//  Created by 郭玉富 on 16/5/4.
//  Copyright © 2016年 zhengzhiyu. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>

typedef NS_ENUM(NSUInteger, YFURLRequestDataType) {
    YFURLRequestDataTypeDay = 0,
    YFURLRequestDataTypeWeek,
    YFURLRequestDataTypeMonth,
};

typedef void(^SuccessHandler)(id data);
typedef void(^FailureHandler)(NSError *error);

@interface YFURLSessionManager : AFURLSessionManager
+ (instancetype)sharedURLSessionManager;
- (void)fetch:(NSString *)stockCode dataType:(YFURLRequestDataType)dataType success:(SuccessHandler)success failure:(FailureHandler)failure;
@end
