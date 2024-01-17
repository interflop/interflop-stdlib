#ifndef __INTERFLOP_VINTERFACE_H__
#define __INTERFLOP_VINTERFACE_H__

struct interflop_vector_op_interface_t
{
  void (*op_vector_float_1) (float *a, float *b, float *c, void *context);
  void (*op_vector_float_4) (float *a, float *b, float *c, void *context);
  void (*op_vector_float_8) (float *a, float *b, float *c, void *context);
  void (*op_vector_float_16) (float *a, float *b, float *c, void *context);

  void (*op_vector_double_1) (double *a, double *b, double *c, void *context);
  void (*op_vector_double_2) (double *a, double *b, double *c, void *context);
  void (*op_vector_double_4) (double *a, double *b, double *c, void *context);
  void (*op_vector_double_8) (double *a, double *b, double *c, void *context);
};

struct interflop_vector_type_t
{
  struct interflop_vector_op_interface_t add;
  struct interflop_vector_op_interface_t sub;
  struct interflop_vector_op_interface_t mul;
  struct interflop_vector_op_interface_t div;
};

struct interflop_backend_vector_interface_t
{
  struct interflop_vector_type_t scalar;
  struct interflop_vector_type_t vector128;
  struct interflop_vector_type_t vector256;
  struct interflop_vector_type_t vector512;
};

#endif