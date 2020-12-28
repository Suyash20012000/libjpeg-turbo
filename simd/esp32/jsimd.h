#include <stdio.h>
#include "../../jpeglib.h"
#include "../../jpegint.h"

#define ONE_HALF_ESP32        ((JLONG)1 << (16 - 1))
#define FIX_ESP32_NEW(x)          ((JLONG)((x) * (1L << 16) + 0.5))
#define CBCR_OFFSET_ESP32     ((JLONG)128 << 16)
#define FIX1_0_298631336  ((JLONG)2446)          /* FIX1(0.298631336) */
#define FIX1_0_390180644  ((JLONG)3196)          /* FIX1(0.390180644) */
#define FIX1_0_541196100  ((JLONG)4433)          /* FIX1(0.541196100) */
#define FIX1_0_765366865  ((JLONG)6270)          /* FIX1(0.765366865) */
#define FIX1_0_899976223  ((JLONG)7373)          /* FIX1(0.899976223) */
#define FIX1_1_175875602  ((JLONG)9633)          /* FIX1(1.175875602) */
#define FIX1_1_501321110  ((JLONG)12299)         /* FIX1(1.501321110) */
#define FIX1_1_847759065  ((JLONG)15137)         /* FIX1(1.847759065) */
#define FIX1_1_961570560  ((JLONG)16069)         /* FIX1(1.961570560) */
#define FIX1_2_053119869  ((JLONG)16819)         /* FIX1(2.053119869) */
#define FIX1_2_562915447  ((JLONG)20995)         /* FIX1(2.562915447) */
#define FIX1_3_072711026  ((JLONG)25172)         /* FIX1(3.072711026) */
#define RANGE_MASK_ESP32  (MAXJSAMPLE * 4 + 3)
#define IDCT_range_limit_ESP32(cinfo)  ((cinfo)->sample_range_limit + CENTERJSAMPLE)
#define DEQUANTIZE_ESP32(coef, quantval)  (((short)(coef)) * (quantval))
#define MULTIPLY_ESP32(var, const)  ((var) * (const))
#define DESCALE_ESP32(x, n)  RIGHT_SHIFT((x) + (((JLONG)1) << ((n) - 1)), n)

#define CONST_SCALE_ESP32  (((JLONG)1) << 14)

#define FIX_ESP32(x)  ((JLONG)((x) * CONST_SCALE_ESP32 + 0.5))

#define FIX2_0_298631336  ((JLONG)2446)          /* FIX(0.298631336) */
#define FIX2_0_390180644  ((JLONG)3196)          /* FIX(0.390180644) */
#define FIX2_0_541196100  ((JLONG)4433)          /* FIX(0.541196100) */
#define FIX2_0_765366865  ((JLONG)6270)          /* FIX(0.765366865) */
#define FIX2_0_899976223  ((JLONG)7373)          /* FIX(0.899976223) */
#define FIX2_1_175875602  ((JLONG)9633)          /* FIX(1.175875602) */
#define FIX2_1_501321110  ((JLONG)12299)         /* FIX(1.501321110) */
#define FIX2_1_847759065  ((JLONG)15137)         /* FIX(1.847759065) */
#define FIX2_1_961570560  ((JLONG)16069)         /* FIX(1.961570560) */
#define FIX2_2_053119869  ((JLONG)16819)         /* FIX(2.053119869) */
#define FIX2_2_562915447  ((JLONG)20995)         /* FIX(2.562915447) */
#define FIX2_3_072711026  ((JLONG)25172)         /* FIX(3.072711026) */


#define FIX3_0_382683433  ((JLONG)98)            /* FIX(0.382683433) */
#define FIX3_0_541196100  ((JLONG)139)           /* FIX(0.541196100) */
#define FIX3_0_707106781  ((JLONG)181)           /* FIX(0.707106781) */
#define FIX3_1_306562965  ((JLONG)334)           /* FIX(1.306562965) */

#define DESCALE_ESP32_FDCT(x, n)  RIGHT_SHIFT(x, n)
#define MULTIPLY_ESP32_FDCT(var, const)  ((short)DESCALE_ESP32_FDCT((var) * (const), 8))

#define ISHIFT_TEMPS
#define SHIFT_TEMPS

#define DEQUANTIZE_ESP32_IDCT_FAST(coef, quantval)  (((short)(coef)) * (quantval))

#define DESCALE_e_ESP32_IDCT_FAST(x, n)  RIGHT_SHIFT(x, n)
#define MULTIPLY_ESP32_IDCT_FAST(var, const)  ((short)DESCALE_e_ESP32_IDCT_FAST((var) * (const), 8))

#define FIX4_1_082392200  ((JLONG)277)           /* FIX(1.082392200) */
#define FIX4_1_414213562  ((JLONG)362)           /* FIX(1.414213562) */
#define FIX4_1_847759065  ((JLONG)473)           /* FIX(1.847759065) */
#define FIX4_2_613125930  ((JLONG)669)           /* FIX(2.613125930) */

#define IRIGHT_SHIFT_ESP32(x, shft)   ((x) >> (shft))
#define IDESCALE_ESP32(x, n)  ((int)IRIGHT_SHIFT_ESP32(x, n))

typedef struct {
  struct jpeg_color_converter pub; /* public fields */

  /* Private state for RGB->YCC conversion */
  JLONG *rgb_ycc_tab;           /* => table for RGB to YCbCr conversion */
} my_color_converter_esp32;

typedef my_color_converter_esp32 *my_cconvert_ptr_esp32;

//dec
typedef struct {
  struct jpeg_color_deconverter pub; /* public fields */

  /* Private state for YCC->RGB conversion */
  int *Cr_r_tab;                /* => table for Cr to R conversion */
  int *Cb_b_tab;                /* => table for Cb to B conversion */
  JLONG *Cr_g_tab;              /* => table for Cr to G conversion */
  JLONG *Cb_g_tab;              /* => table for Cb to G conversion */

  /* Private state for RGB->Y conversion */
  JLONG *rgb_y_tab;             /* => table for RGB to Y conversion */
} my_color_deconverter_esp32_dec;

typedef my_color_deconverter_esp32_dec *my_cconvert_ptr_esp32_dec;
