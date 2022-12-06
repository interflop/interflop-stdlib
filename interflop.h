#ifndef __INTERFLOP_H__
#define __INTERFLOP_H__

#include <stdarg.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* interflop backend interface */

/* interflop float compare predicates, follows the same order than
 * LLVM's FCMPInstruction predicates */
enum FCMP_PREDICATE {
  FCMP_FALSE,
  FCMP_OEQ,
  FCMP_OGT,
  FCMP_OGE,
  FCMP_OLT,
  FCMP_OLE,
  FCMP_ONE,
  FCMP_ORD,
  FCMP_UNO,
  FCMP_UEQ,
  FCMP_UGT,
  FCMP_UGE,
  FCMP_ULT,
  FCMP_ULE,
  FCMP_UNE,
  FCMP_TRUE,
};

/* Enumeration of types managed by function instrumentation */
enum FTYPES {
  FFLOAT,
  FDOUBLE,
  FQUAD,
  FFLOAT_PTR,
  FDOUBLE_PTR,
  FQUAD_PTR,
  FTYPES_END
};

typedef enum {
  /* Allows changing current virtual precision range */
  /* signature: void set_range_binary64(int precision) */
  INTERFLOP_SET_RANGE_BINARY64 = 5,
  /* signature: void set_range_binary32(int precision) */
  INTERFLOP_SET_RANGE_BINARY32 = 4,
  /* Allows changing current virtual precision */
  /* signature: void set_precision_binary64(int precision) */
  INTERFLOP_SET_PRECISION_BINARY64 = 3,
  /* signature: void set_precision_binary32(int precision) */
  INTERFLOP_SET_PRECISION_BINARY32 = 2,
  /* Allows perturbing one floating-point value */
  /* signature: void inexact(enum FTYPES type, void *value, int precision) */
  INTERFLOP_INEXACT_ID = 1,
  INTERFLOP_CUSTOM_ID = -1
} interflop_call_id;

/* User function to directly call low-level backend functions */
/* Takes an id to identify the actual function to call and variadic argument */
void interflop_call(interflop_call_id id, ...);

typedef struct interflop_function_info {
  // Indicate the identifier of the function
  char *id;
  // Indicate if the function is from library
  short isLibraryFunction;
  // Indicate if the function is intrinsic
  short isIntrinsicFunction;
  // Indicate if the function use double
  short useFloat;
  // Indicate if the function use float
  short useDouble;
} interflop_function_info_t;

/* Verificarlo call stack */
typedef struct interflop_function_stack {
  interflop_function_info_t **array;
  long int top;
} interflop_function_stack_t;

struct interflop_backend_interface_t {

  void (*interflop_add_float)(float a, float b, float *c, void *context);
  void (*interflop_sub_float)(float a, float b, float *c, void *context);
  void (*interflop_mul_float)(float a, float b, float *c, void *context);
  void (*interflop_div_float)(float a, float b, float *c, void *context);
  void (*interflop_cmp_float)(enum FCMP_PREDICATE p, float a, float b, int *c,
                              void *context);

  void (*interflop_add_double)(double a, double b, double *c, void *context);
  void (*interflop_sub_double)(double a, double b, double *c, void *context);
  void (*interflop_mul_double)(double a, double b, double *c, void *context);
  void (*interflop_div_double)(double a, double b, double *c, void *context);
  void (*interflop_cmp_double)(enum FCMP_PREDICATE p, double a, double b,
                               int *c, void *context);

  void (*interflop_cast_double_to_float)(double a, float *b, void *context);
  void (*interflop_fma_float)(float a, float b, float c, float *res,
                              void *context);
  void (*interflop_fma_double)(double a, double b, double c, double *res,
                               void *context);

  void (*interflop_enter_function)(interflop_function_stack_t *stack,
                                   void *context, int nb_args, va_list ap);

  void (*interflop_exit_function)(interflop_function_stack_t *stack,
                                  void *context, int nb_args, va_list ap);

  void (*interflop_user_call)(void *context, interflop_call_id id, va_list ap);
  /* interflop_finalize: called at the end of the instrumented program
   * execution */
  void (*interflop_finalize)(void *context);
};

/* interflop_init: called at initialization before using a backend.
 * It returns an interflop_backend_interface_t structure with callbacks
 * for each of the numerical instrument hooks.
 *
 * argc: number of arguments passed to the backend
 *
 * argv: arguments passed to the backend, argv[0] always contains the name of
 * the backend library. argv[] may be deallocated after the call to
 * interflop_init. To make it persistent, a backend must copy it.
 *
 * context: the backend is free to make this point to a backend-specific
 * context. The frontend will pass the context back as the last argument of the
 * above instrumentation hooks.
 * */

struct interflop_backend_interface_t interflop_init(void *context);

#if defined(__cplusplus)
}
#endif

#endif /* __INTERFLOP_H__ */
