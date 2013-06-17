// Copyright 2013 Google Inc. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the COPYING file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS. All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.
// -----------------------------------------------------------------------------
//
// Alpha decoder: internal header.
//
// Author: Urvang (urvang@google.com)

#ifndef WEBP_DEC_ALPHAI_H_
#define WEBP_DEC_ALPHAI_H_

#include "./webpi.h"
#include "../utils/filters.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

struct VP8LDecoder;  // Defined in dec/vp8li.h.

typedef struct ALPHDecoder ALPHDecoder;
struct ALPHDecoder {
  int width_;
  int height_;
  int method_;
  WEBP_FILTER_TYPE filter_;
  int pre_processing_;
  struct VP8LDecoder* vp8l_dec_;
  VP8Io io_;
  size_t bytes_per_pixel_;  // Although alpha channel requires only 1 byte per
                            // pixel, sometimes VP8LDecoder may need to allocate
                            // 4 bytes per pixel internally during decode.
};

//------------------------------------------------------------------------------
// internal functions. Not public.

// Allocates a new alpha decoder instance.
ALPHDecoder* ALPHNew(void);

// Clears and deallocates an alpha decoder instance.
void ALPHDelete(ALPHDecoder* const dec);

//------------------------------------------------------------------------------

#if defined(__cplusplus) || defined(c_plusplus)
}    // extern "C"
#endif

#endif  /* WEBP_DEC_ALPHAI_H_ */