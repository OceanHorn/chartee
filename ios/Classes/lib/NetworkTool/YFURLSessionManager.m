//
//  YFURLSessionManager.m
//  chartee
//
//  Created by 郭玉富 on 16/5/4.
//  Copyright © 2016年 zhengzhiyu. All rights reserved.
//

#import "YFURLSessionManager.h"

@implementation YFURLSessionManager

+ (instancetype)sharedURLSessionManager {
    
    static YFURLSessionManager *instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        instance = [[self alloc] initWithSessionConfiguration:configuration];
        AFHTTPResponseSerializer *responseSerializer = [AFHTTPResponseSerializer serializer];
        responseSerializer.acceptableContentTypes = [[NSSet alloc] initWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/plain", @"text/html", @"text/csv", nil];
        instance.responseSerializer = responseSerializer;

    });
    return instance;
}
- (void)fetch:(NSString *)stockCode dataType:(YFURLRequestDataType)dataType success:(SuccessHandler)success failure:(FailureHandler)failure {
    
    NSString *dataTypeString;
    switch (dataType) {
        case YFURLRequestDataTypeDay:
            dataTypeString = @"d";
            break;
        case YFURLRequestDataTypeWeek:
            dataTypeString = @"w";
            break;
        case YFURLRequestDataTypeMonth:
            dataTypeString = @"m";
            break;
            
        default:
            break;
    }
    NSString *requestString = [NSString stringWithFormat:@"http://ichart.yahoo.com/table.csv?s=%@&g=%@", stockCode, dataTypeString];
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:requestString]];
    
    [[self dataTaskWithRequest:request completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
        NSHTTPURLResponse *responseHTTP = (NSHTTPURLResponse *)response;
        if (responseHTTP.statusCode == 200) {
            if (responseObject && success) {
                NSString *str = [[NSString alloc] initWithData:responseObject encoding:NSUTF8StringEncoding];
//                NSLog(@"str:%@", str);
//                success(responseObject);
                success(str);
            } else if (failure) {
                failure(error);
            }
        } else if (failure) {
            failure(error);
        }
    }] resume];
}
@end
