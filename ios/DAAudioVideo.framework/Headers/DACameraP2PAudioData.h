//
//  DACameraP2PAudioData.h
//  DAAudioVideo
//
//  Created by Darren on 2020/11/12.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DAAudioConfigModel;

@interface DACameraP2PAudioData : NSObject

@property (nonatomic, assign) unsigned int frameId;
@property (nonatomic, assign) unsigned int flags;
@property (nonatomic, assign) unsigned int timeStamp;
@property (nonatomic, assign) NSInteger dataInterval;
@property (nonatomic, assign) unsigned int dataLength;
@property (nonatomic, assign) unsigned int decodeLength;
@property (nonatomic, assign) unsigned int channel;
@property (nonatomic, assign, nullable) unsigned char *buffer;
@property (nonatomic, assign, nullable) unsigned char *pcmBuffer;
@property (nonatomic, assign) NSInteger sessionId;
@property (nonatomic, strong) DAAudioConfigModel *config;
@property (nonatomic, assign) int64_t iphoneTimeStamp; // 手机接收到帧的本地时间

@end

NS_ASSUME_NONNULL_END
