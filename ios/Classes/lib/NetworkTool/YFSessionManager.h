//
//  YFSessionManager.h
//  chartee
//
//  Created by 郭玉富 on 16/5/4.
//  Copyright © 2016年 zhengzhiyu. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>


typedef void(^SuccessHandle)(NSURLSessionDataTask *task, id responseObject);
typedef void(^FailureHandle)(NSError *error);


typedef NS_ENUM(NSUInteger, YFRequestDataType) {
    YFRequestDataTypeDay = 0,
    YFRequestDataTypeWeek,
    YFRequestDataTypeMonth,
};

@interface YFSessionManager : AFHTTPSessionManager

+ (instancetype)sharedSessionManager;

- (void)get:(NSString *)stockCode dataType:(YFRequestDataType)dataType success:(SuccessHandle)successHandle failure:(FailureHandle)failureHandle;

@end
