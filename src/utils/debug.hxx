#pragma once
#ifndef YAE_DEBUG_LEVEL
#define YAE_DEBUG_LEVEL 0
#endif
#ifdef YAE_DISABLE_LOG
#define YAE_LOG(fmt_str, ...) ;
#define YAE_WARN(fmt_str, ...) ;
#define YAE_ERR(fmt_str, ...) ;
#else
#define YAE_LOG(fmt_str, ...) if ((YAE_DEBUG_LEVEL) > 0) printf("[LOG]: " fmt_str __VA_OPT__(,) __VA_ARGS__)
#define YAE_WARN(fmt_str, ...) if ((YAE_DEBUG_LEVEL > 1)) printf("[WARNING]: " fmt_str __VA_OPT__(,) __VA_ARGS__)
#define YAE_ERR(fmt_str, ...) if ((YAE_DEBUG_LEVEL > 2)) printf("[ERROR]: " fmt_str __VA_OPT__(,) __VA_ARGS__)
#endif