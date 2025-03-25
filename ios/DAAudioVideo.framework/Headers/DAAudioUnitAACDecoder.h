//
//  DAAudioUnitAACDecoder.h
//  DAAudioVideo
//
//  Created by Darren on 2022/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DAAudioConfigModel,DACameraP2PAudioData;

@interface DAAudioUnitAACDecoder : NSObject

+ (instancetype)decoderWithConfig:(DAAudioConfigModel *)config;
- (void)decoderAudioDataWithAudio:(DACameraP2PAudioData *)audio callBack:(void(^)(unsigned char *buffer, unsigned int length))callBack;
- (void)clearDecoder;

@end

NS_ASSUME_NONNULL_END
