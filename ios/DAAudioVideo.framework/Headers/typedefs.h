/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This file contains platform-specific typedefs and defines.
// Much of it is derived from Chromium's build/build_config.h.

#ifndef WEBRTC_TYPEDEFS_H_
#define WEBRTC_TYPEDEFS_H_

// For access to standard POSIXish features, use WEBRTC_POSIX instead of a
// more specific macro.
#if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || \
    defined(WEBRTC_ANDROID)
#define WEBRTC_POSIX
#endif

// 处理器架构检测
#if defined(_M_X64) || defined(__x86_64__)
#define WEBRTC_ARCH_X86_64
#define WEBRTC_ARCH_64_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(_M_IX86) || defined(__i386__)
#define WEBRTC_ARCH_X86_FAMILY
#define WEBRTC_ARCH_X86
#define WEBRTC_ARCH_32_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(__ARMEL__) || defined(__arm__) || defined(__aarch64__) || defined(__arm64__)
// 支持所有ARM架构（32位和64位）
#if defined(__aarch64__) || defined(__arm64__)
#define WEBRTC_ARCH_ARM64
#define WEBRTC_ARCH_64_BITS
#else
#define WEBRTC_ARCH_ARM
#define WEBRTC_ARCH_32_BITS
#endif
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(__MIPSEL__)
#define WEBRTC_ARCH_32_BITS
#define WEBRTC_ARCH_LITTLE_ENDIAN
#elif defined(__powerpc__)
#define WEBRTC_ARCH_PPC
#if defined(__PPC64__) || defined(__powerpc64__)
#define WEBRTC_ARCH_64_BITS
#else
#define WEBRTC_ARCH_32_BITS
#endif
#define WEBRTC_ARCH_BIG_ENDIAN
#else
#error Please add support for your architecture in typedefs.h
#endif

// 确保定义了字节序
#if !defined(WEBRTC_ARCH_LITTLE_ENDIAN) && !defined(WEBRTC_ARCH_BIG_ENDIAN)
// 默认使用小端序（大多数现代架构都是小端序）
#define WEBRTC_ARCH_LITTLE_ENDIAN
#endif

#if !(defined(WEBRTC_ARCH_LITTLE_ENDIAN) ^ defined(WEBRTC_ARCH_BIG_ENDIAN))
#error Define either WEBRTC_ARCH_LITTLE_ENDIAN or WEBRTC_ARCH_BIG_ENDIAN
#endif

#if defined(__SSE2__) || defined(_MSC_VER)
#define WEBRTC_USE_SSE2
#endif

#if !defined(_MSC_VER)
#include <stdint.h>
#else
// Define C99 equivalent types, since MSVC doesn't provide stdint.h.
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef __int64             int64_t;
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned __int64    uint64_t;
#endif

// Borrowed from Chromium's base/compiler_specific.h.
// Annotate a virtual method indicating it must be overriding a virtual
// method in the parent class.
// Use like:
//   virtual void foo() OVERRIDE;
#if defined(_MSC_VER)
#define OVERRIDE override
#elif defined(__clang__)
// Clang defaults to C++03 and warns about using override. Squelch that.
// Intentionally no push/pop here so all users of OVERRIDE ignore the warning
// too. This is like passing -Wno-c++11-extensions, except that GCC won't die
// (because it won't see this pragma).
#pragma clang diagnostic ignored "-Wc++11-extensions"
#define OVERRIDE override
#elif defined(__GNUC__) && __cplusplus >= 201103 && \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100) >= 40700
// GCC 4.7 supports explicit virtual overrides when C++11 support is enabled.
#define OVERRIDE override
#else
#define OVERRIDE
#endif

// Annotate a function indicating the caller must examine the return value.
// Use like:
//   int foo() WARN_UNUSED_RESULT;
// TODO(ajm): Hack to avoid multiple definitions until the base/ of webrtc and
// libjingle are merged.
#if !defined(WARN_UNUSED_RESULT)
#if defined(__GNUC__)
#define WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#define WARN_UNUSED_RESULT
#endif
#endif  // WARN_UNUSED_RESULT

#endif  // WEBRTC_TYPEDEFS_H_
