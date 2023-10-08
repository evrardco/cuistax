#pragma once
#include <stdio.h>
#ifndef CUISTAX_LOG_LEVEL
#define CUISTAX_LOG_LEVEL 4
#endif
#ifndef CUISTAX_LOG
    #define CUISTAX_ERR(fmt_str, ...) do {} while(0)
    #define CUISTAX_WARN(fmt_str, ...) do {} while(0)
    #define CUISTAX_LOG(fmt_str, ...) do {} while(0)
    #define CUISTAX_DEBUG(fmt_str, ...) do {} while(0)
#else
    #if CUISTAX_LOG_LEVEL > 0
        #define CUISTAX_ERR(fmt_str, ...)  printf("[ERROR]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
    #else
        #define CUISTAX_ERR(fmt_str, ...) do {} while(0)
    #endif
    #if CUISTAX_LOG_LEVEL > 1
        #define CUISTAX_WARN(fmt_str, ...) printf("[WARNING]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__ )
    #else
        #define CUISTAX_WARN(fmt_str, ...) do {} while(0)
    #endif
    #if CUISTAX_LOG_LEVEL > 2
        #define CUISTAX_LOG(fmt_str, ...) printf("[LOG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
    #else
        #define CUISTAX_LOG(fmt_str, ...) do {} while(0)
    #endif
    #if CUISTAX_LOG_LEVEL > 3
        #define CUISTAX_DEBUG(fmt_str, ...) printf("[DEBUG]: " fmt_str "\n" __VA_OPT__(,) __VA_ARGS__)
    #else
        #define CUISTAX_DEBUG(fmt_str, ...) do {} while(0)
    #endif
    
#endif