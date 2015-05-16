#ifndef CORE_COMMON_H
#define CORE_COMMON_H

#include <stdint.h> // *int*_t
#include <assert.h> // assert

#define ASSERT assert
#define SASSERT static_assert

/*
 * Define common number types
 */
#ifndef uint32
#define uint32 uint32_t
#endif // uint32

#ifndef uint
#define uint unsigned int
#endif // uint

#endif // CORE_COMMON_H
