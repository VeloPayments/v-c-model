/**
 * \file allocator.h
 *
 * Model checking allocator overrides.
 *
 * \copyright 2017 Velo Payments, Inc.  All rights reserved.
 */

#ifndef CBMC_ALLOCATOR_HEADER_GUARD
#define CBMC_ALLOCATOR_HEADER_GUARD

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Perform a model checked allocation procedure that can fail
 * nondeterministically.
 *
 * \param size      The size of the memory region to allocate.
 *
 * \returns a pointer to a newly allocated memory region of the given size, or
 *          NULL if allocation fails.
 */
void* cbmc_malloc(size_t size);

/**
 * Free a memory region previously allocated by cbmc_malloc.
 *
 * \note - this routine asserts that the pointer is not NULL.  If this assertion
 * can fail, then the model checker will report an error.
 */
void cbmc_free(void* ptr);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* CBMC_ALLOCATOR_HEADER_GUARD */
