//
//  DADeviceVideoPlayView.h
//  DAAudioVideo
//
//  Created by Darren on 2020/10/9.
//  Copyright © 2020 Darren. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "DACameraP2PVideoData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,DAVideoPlayViewContentMode) {
    DAVideoPlayViewContentMode_ScaleToFill,
    DAVideoPlayViewContentMode_ScaleAspectFit,
    DAVideoPlayViewContentMode_ScaleAspectFill
};

@interface DADeviceVideoPlayView : UIView

@property (nonatomic, assign) int64_t iphoneTimeStamp;;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) CMSampleBufferRef sampleBuffer;
@property (nonatomic, assign) DAVideoPlayViewContentMode mode;
@property (nonatomic, assign) CGFloat rotateDegree;
@property (nonatomic, assign) float sharpness;  // 0.0 表示无锐化，1.0 表示完全锐化
@property (nonatomic, assign) float saturation; // 0.0 表示去饱和（灰度），1.0 保持原饱和度，>1.0 增加饱和度
@property (nonatomic, assign) float brightness; // -1.0 降低亮度，0.0 保持不变，1.0 增加亮度
@property (nonatomic, assign) float contrast;   // < 1.0 减少对比度，1.0 保持原对比度，>1.0 增加对比度

- (UIImage *)snapShotImage;

@end

NS_ASSUME_NONNULL_END
