//
//  DACameraP2PVideoData.h
//  DAAudioVideo
//
//  Created by Darren on 2020/6/2.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "DAAudioVideoDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface DACameraP2PVideoData : NSObject

@property (nonatomic, assign) unsigned int frameId;
@property (nonatomic, assign) unsigned int flags;      //表示是否是I帧
@property (nonatomic, assign) unsigned int exFlags;
@property (nonatomic, assign) DAVideoFrameType type;
@property (nonatomic, assign) DAMediaCodeID codecId;
@property (nonatomic, assign) unsigned int timeStamp;   //视频帧时间
@property (nonatomic, assign) NSInteger timeInterval;   //用于视频播放时UI上展示当前的播放时间点
@property (nonatomic, assign) NSInteger utcCloudTimeInterval;   //云录像实时时间戳
@property (nonatomic, assign) NSInteger dataInterval;   //用于云回放标记该帧在哪一个5秒的文件中
@property (nonatomic, assign) NSInteger utcTimeStamp;   //sd卡录像用于判断当前录像时间 或 实时时间戳
@property (nonatomic, assign) unsigned int dataLength;
@property (nonatomic, assign) unsigned int channel;
@property (nonatomic, assign, nullable) unsigned char *buffer;
@property (nonatomic, assign, nullable) CMSampleBufferRef sampleBuffer;
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic, assign) NSInteger sessionId;
@property (nonatomic, assign) int64_t iphoneTimeStamp; // 手机接收到帧的本地时间
@property (nonatomic, assign) unsigned int videoType; // 0 实时 1卡录像 2云录像
- (BOOL)isHardwareDecoderSupport;

@end

NS_ASSUME_NONNULL_END
