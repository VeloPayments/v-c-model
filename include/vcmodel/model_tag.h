/**
 * \file vcmodel/model_tag.h
 *
 * \brief Model Tagging macros for data structures.
 *
 * \copyright 2020 Justin Handville (part of rcpr). Usage granted to Velo
 * Payments under the MIT License.
 *
 * Modifications \copyright 2020 Velo Payments.
 */

#ifndef  VCMODEL_MODEL_TAG_HEADER_GUARD
# define VCMODEL_MODEL_TAG_HEADER_GUARD

#if CBMC
# define MODEL_STRUCT_TAG_REF(name) \
    model_struct_tag_ ## name
# define MODEL_STRUCT_TAG(name) \
    int MODEL_STRUCT_TAG_REF(name)
# define MODEL_STRUCT_TAG_GLOBAL_REF(name) \
    model_global_struct_tag_ ## name
# define MODEL_STRUCT_TAG_GLOBAL_INIT(name) \
    int nondet_ ## name ## _tag(); \
    MODEL_STRUCT_TAG_GLOBAL_REF(name) = nondet_ ## name ## _tag(); \
    MODEL_ASSUME(MODEL_STRUCT_TAG_GLOBAL_REF(name) != 0)
# define MODEL_STRUCT_TAG_GLOBAL_EXTERN(name) \
    extern int MODEL_STRUCT_TAG_GLOBAL_REF(name)
# define MODEL_STRUCT_TAG_INIT(var, name) \
    var = MODEL_STRUCT_TAG_GLOBAL_REF(name)
# define MODEL_ASSERT_STRUCT_TAG_INITIALIZED(var, name) \
    MODEL_ASSERT(var == MODEL_STRUCT_TAG_GLOBAL_REF(name))
# define MODEL_ASSERT_STRUCT_TAG_NOT_INITIALIZED(var, name) \
    MODEL_ASSERT(var != MODEL_STRUCT_TAG_GLOBAL_REF(name))
#else
# define MODEL_STRUCT_TAG_REF(name)
# define MODEL_STRUCT_TAG(name)
# define MODEL_STRUCT_TAG_GLOBAL_REF(name)
# define MODEL_STRUCT_TAG_GLOBAL_INIT(name)
# define MODEL_STRUCT_TAG_GLOBAL_EXTERN(name)
# define MODEL_STRUCT_TAG_INIT(var, name)
# define MODEL_ASSERT_STRUCT_TAG_INITIALIZED(var, name)
# define MODEL_ASSERT_STRUCT_TAG_NOT_INITIALIZED(var, name)
#endif

#endif /*VCMODEL_MODEL_TAG_HEADER_GUARD*/
