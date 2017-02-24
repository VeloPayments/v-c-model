/**
 * \file allocator.c
 *
 * Implementation of model checking allocator overrides.
 *
 * \copyright 2017 Velo Payments, Inc.  All rights reserved.
 */
#define CBMC_NO_MALLOC_OVERRIDE
#include <cbmc/model_assert.h>

/* Enable this compilation unit only under CBMC. */
#ifdef CBMC

/**
 * Non-deterministic boolean value, provided by the model checker.
 *
 * \returns true or false in a nondeterministic manner.
 */
_Bool nondet_bool();

/**
 * Perform a model checked allocation procedure that can fail
 * nondeterministically.
 *
 * \param size      The size of the memory region to allocate.
 *
 * \returns a pointer to a newly allocated memory region of the given size, or
 *          NULL if allocation fails.
 */
void* cbmc_malloc(size_t size)
{
    if (nondet_bool())
    {
        return malloc(size);
    }
    else
    {
        return NULL;
    }
}

/**
 * Free a memory region previously allocated by cbmc_malloc.
 *
 * \note - this routine asserts that the pointer is not NULL.  If this assertion
 * can fail, then the model checker will report an error.
 */
void cbmc_free(void* mem)
{
    MODEL_ASSERT(mem != NULL);
    free(mem);
}

#endif /* defined CBMC */
