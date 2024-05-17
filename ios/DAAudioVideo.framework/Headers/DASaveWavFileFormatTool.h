//
//  DASaveWavFileFormatTool.h
//  DAAudioVideo
//
//  Created by Darren on 2021/8/20.
//

#import <Foundation/Foundation.h>
#import "DAAudioVideo.h"

NS_ASSUME_NONNULL_BEGIN

@interface DASaveWavFileFormatTool : NSObject

/// 将pcm文件转换成g711a格式
/// - Parameters:
///   - pcmPath: pcm文件路径
///   - g711aPath: g711a文件路径
+ (BOOL)transformPCMFileToG711AFile:(NSString *)pcmPath g711aPath:(NSString *)g711aPath;

/// 文件转化为wav文件
/// - Parameters:
///   - audioPath: 需要转换的文件路径（例如g711a）
///   - filePath: wav文件路径
///   - channels: 通道数（以获取支持的报警音频文件格式信息指令为准）
///   - sampleRate: 采样率（以获取支持的报警音频文件格式信息指令为准）
///   - bitsPerSample: 码率（以获取支持的报警音频文件格式信息指令为准）
///   - codeID: 编码（以获取支持的报警音频文件格式信息指令为准）
+ (BOOL)saveWavFormatWithAudioPath:(NSString *)audioPath filePath:(NSString *)filePath channels:(unsigned int)channels sampleRate:(unsigned int)sampleRate bitsPerSample:(unsigned int)bitsPerSample codeID:(DAMediaCodeID)codeID;

@end

NS_ASSUME_NONNULL_END
