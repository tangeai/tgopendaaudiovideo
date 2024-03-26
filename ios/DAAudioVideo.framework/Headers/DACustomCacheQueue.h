//
//  DACustomQueue.h
//  DAAudioVideo
//
//  Created by Darren on 2020/6/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface DACustomCacheQueue <__covariant ObjectType> : NSObject

@property (nonatomic, readonly) BOOL isEnabled; // 缓存是否已经准备好

- (void)enableCache:(BOOL)enable;
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
