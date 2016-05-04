//
//  YFSessionManager.m
//  chartee
//
//  Created by 郭玉富 on 16/5/4.
//  Copyright © 2016年 zhengzhiyu. All rights reserved.
//

#import "YFSessionManager.h"

@implementation YFSessionManager

+ (instancetype)sharedSessionManager {
    
    static YFSessionManager *instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSURL *baseURL = [NSURL URLWithString:@"http://ichart.yahoo.com/"];
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        instance = [[self alloc] initWithBaseURL:baseURL sessionConfiguration:configuration];
        instance.responseSerializer.acceptableContentTypes = [[NSSet alloc] initWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/plain", @"text/html", @"text/csv", nil];
    });
    return instance;
}

- (void)get:(NSString *)stockCode dataType:(YFRequestDataType)dataType success:(SuccessHandle)successHandle failure:(FailureHandle)failureHandle {
    
    NSString *dataTypeString;
    switch (dataType) {
        case YFRequestDataTypeDay:
            dataTypeString = @"d";
            break;
        case YFRequestDataTypeWeek:
            dataTypeString = @"w";
            break;
        case YFRequestDataTypeMonth:
            dataTypeString = @"m";
            break;
            
        default:
            break;
    }
    
    void(^success)(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) = ^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if (responseObject && successHandle) {
            successHandle(task, responseObject);
        } else if (failureHandle){
            NSError *error = [NSError errorWithDomain:@"" code:-1 userInfo:@{@"name":@"nil", @"info":@"No data"}];
            failureHandle(error);
        };
    };
    void(^failure)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) = ^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        if (failureHandle) {
            failureHandle(error);
        }
    };
    
    NSString *requestString = [NSString stringWithFormat:@"table.csv?s=%@&g=%@", stockCode, dataTypeString];
    
    [self GET:requestString parameters:nil progress:nil success:success failure:failure];
}

@end
