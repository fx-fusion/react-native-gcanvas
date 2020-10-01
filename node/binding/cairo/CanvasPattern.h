// Copyright (c) 2011 LearnBoost <tj@learnboost.com>

#pragma once

#include <cairo.h>
#include <napi.h>

/*
 * Canvas types.
 */

typedef enum {
  NO_REPEAT,  // match CAIRO_EXTEND_NONE
  REPEAT,  // match CAIRO_EXTEND_REPEAT
  REPEAT_X, // needs custom processing
  REPEAT_Y // needs custom processing
} repeat_type_t;

extern const cairo_user_data_key_t *pattern_repeat_key;

class Pattern: public Napi::ObjectWrap<Pattern> {
  public:
    static void init(Napi::Env env);
    static Napi::Object NewInstance(const Napi::CallbackInfo &info);
    static repeat_type_t get_repeat_type_for_cairo_pattern(cairo_pattern_t *pattern);

    Pattern(const Napi::CallbackInfo &info);
    // Pattern(cairo_surface_t *surface, repeat_type_t repeat);
    inline cairo_pattern_t *pattern(){ return _pattern; }
  private:
    ~Pattern();
    static Napi::FunctionReference constructor;
    cairo_pattern_t *_pattern;
    repeat_type_t _repeat;
};