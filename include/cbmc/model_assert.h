/**
 * \file model_assert.h
 *
 * Support for model checking assertions and overrides at model check time.
 *
 * \copyright 2017 Velo Payments, Inc.  All rights reserved.
 */

#ifndef CBMC_MODEL_ASSERT_HEADER_GUARD
#define CBMC_MODEL_ASSERT_HEADER_GUARD

#include <assert.h>
#include <stdlib.h>
#include <cbmc/allocator.h>

/* Configuration options for the model checker. */
#if CBMC
#define MODEL_ASSERT(x) __CPROVER_assert((x), #x)
#define MODEL_ASSUME(x) __CPROVER_assume((x))
#define MODEL_EXEMPT(x)
#ifndef CBMC_NO_MALLOC_OVERRIDE
#define malloc cbmc_malloc
#define free cbmc_free
#endif /* CBMC_NO_MALLOC_OVERRIDE */
#else
#define MODEL_ASSERT(x)
#define MODEL_ASSUME(x)
#define MODEL_EXEMPT(x) x
#endif

#endif /* CBMC_MODEL_ASSERT_HEADER_GUARD */
