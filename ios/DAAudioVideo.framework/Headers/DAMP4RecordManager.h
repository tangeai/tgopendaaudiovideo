//
//  DAMP4RecordManager.h
//  DAAudioVideo
//
//  Created by Darren on 2021/6/3.
//  Copyright © 2021 Darren. All rights reserved.
//

#import <UIKit/UIkit.h>

NS_ASSUME_NONNULL_BEGIN

@class DACameraP2PVideoData,DACameraP2PAudioData;

@interface DAMP4RecordManager : NSObject

@property (nonatomic, assign, readonly) BOOL isRecording;
@property (nonatomic, assign) NSInteger minRecordTime;//默认最短录像时长1s
@property (nonatomic, assign, readonly) NSInteger recordTimeCount;
@property (nonatomic, copy) void(^stopRecordCallback)(NSString *filePath);
@property (nonatomic, assign) float sharpness;  // 0.0 表示无锐化，1.0 表示完全锐化
@property (nonatomic, assign) float saturation; // 0.0 表示去饱和（灰度），1.0 保持原饱和度，>1.0 增加饱和度
@property (nonatomic, assign) float brightness; // -1.0 降低亮度，0.0 保持不变，1.0 增加亮度
@property (nonatomic, assign) float contrast;   // < 1.0 减少对比度，1.0 保持原对比度，>1.0 增加对比度
@property (nonatomic, assign) BOOL downloadModeOpen;

- (void)startRecordWithFileName:(NSString *)fileName;
- (void)startRecordWithFileName:(NSString *)fileName widthPixel:(int)width heightPixel:(int)height;
- (void)stopRecordWithVideoPath:(nullable void(^)(NSString *filePath))callBack;

- (BOOL)writeVideoData:(DACameraP2PVideoData *)videoData;
- (BOOL)writeAudioData:(DACameraP2PAudioData *)audioData;

- (BOOL)autoWriteVideoData:(DACameraP2PVideoData *)videoData;
- (BOOL)autoWriteAudioData:(DACameraP2PAudioData *)audioData;

@end

NS_ASSUME_NONNULL_END
