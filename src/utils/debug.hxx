#pragma once
#include <stdio.h>
#ifndef YAE_DEBUG_LEVEL
#define YAE_DEBUG_LEVEL 4
#endif
#ifdef YAE_DISABLE_LOG
#define YAE_ERR(fmt_str, ...) ;
#define YAE_WARN(fmt_str, ...) ;
#define YAE_LOG(fmt_str, ...) ;
#define YAE_DEBUG(fmt_str, ...) ;
#else
#define YAE_ERR(fmt_str, ...) if ((YAE_DEBUG_LEVEL > 0)) printf("[ERROR]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define YAE_WARN(fmt_str, ...) if ((YAE_DEBUG_LEVEL > 1)) printf("[WARNING]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__ )
#define YAE_LOG(fmt_str, ...) if ((YAE_DEBUG_LEVEL) > 2) printf("[LOG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define YAE_DEBUG(fmt_str, ...) if ((YAE_DEBUG_LEVEL > 3)) printf("[DEBUG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#endif