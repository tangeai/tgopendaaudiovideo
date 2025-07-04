//
//  DACustomQueue.h
//  DAAudioVideo
//
//  Created by Darren on 2020/6/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

#define DA_CustomCacheQueueStart @"DACustomCacheQueueStart"
#define DA_CustomCacheQueueEnd @"DA_CustomCacheQueueEnd"

@interface DACustomCacheQueue <__covariant ObjectType> : NSObject

@property (nonatomic, readonly) BOOL isEnabled; // 缓存是否已经准备好
@property (nonatomic, readonly) CGFloat currentBufferTime; // 当前缓冲的总时长
@property (nonatomic, readonly) CGFloat currentBufferSize;

- (void)clear;
- (NSInteger)size;
- (BOOL)isEmpty;
- (void)enQueueWithObject:(id)object;
- (ObjectType)dequeue;
- (ObjectType)front;
- (void)setMaxCacheSize:(NSUInteger)maxCacheSize;
- (void)setBufferingTime:(NSTimeInterval)time;

@end

NS_ASSUME_NONNULL_END
