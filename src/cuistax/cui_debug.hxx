#pragma once
#include <stdio.h>
#ifndef CUISTAX_DEBUG_LEVEL
#define CUISTAX_DEBUG_LEVEL 4
#endif
#ifdef CUISTAX_DISABLE_LOG
#define CUISTAX_ERR(fmt_str, ...) ;
#define CUISTAX_WARN(fmt_str, ...) ;
#define CUISTAX_LOG(fmt_str, ...) ;
#define CUISTAX_DEBUG(fmt_str, ...) ;
#else
#define CUISTAX_ERR(fmt_str, ...) if ((CUISTAX_DEBUG_LEVEL > 0)) printf("[ERROR]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define CUISTAX_WARN(fmt_str, ...) if ((CUISTAX_DEBUG_LEVEL > 1)) printf("[WARNING]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__ )
#define CUISTAX_LOG(fmt_str, ...) if ((CUISTAX_DEBUG_LEVEL) > 2) printf("[LOG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#define CUISTAX_DEBUG(fmt_str, ...) if ((CUISTAX_DEBUG_LEVEL > 3)) printf("[DEBUG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
#endif