#define FAST_FLOAT float
#define MULTIPLIER short
#include "../../jinclude.h"
#include "../../jpeglib.h"
#include "../../jsimd.h"
#include "../../jdct.h"
#include "../../jsimddct.h"
#include "jsimd.h"

#define R_Y_OFF         0                       
#define G_Y_OFF         (1 * (255 + 1))  
#define B_Y_OFF         (2 * (255 + 1))  
#define R_CB_OFF        (3 * (255 + 1))
#define G_CB_OFF        (4 * (255 + 1))
#define B_CB_OFF        (5 * (255 + 1))
#define R_CR_OFF        B_CB_OFF                
#define G_CR_OFF        (6 * (255 + 1))
#define B_CR_OFF        (7 * (255 + 1))

//#include "jccolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 0
#define RGB_GREEN_ESP32 1
#define RGB_BLUE_ESP32 2
#define RGB_PIXELSIZE_ESP32 3
#define esp32_rgb_ycc_convert_internal esp32_extrgb_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extrgb_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_rgb_convert_internal
#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 0
#define RGB_GREEN_ESP32 1
#define RGB_BLUE_ESP32 2
#define RGB_PIXELSIZE_ESP32 4
#define RGB_ALPHA_ESP32 3
#define esp32_rgb_ycc_convert_internal esp32_extrgbx_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extrgbx_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_rgbx_convert_internal
#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 2
#define RGB_GREEN_ESP32 1
#define RGB_BLUE_ESP32 0
#define RGB_PIXELSIZE_ESP32 3
#define esp32_rgb_ycc_convert_internal esp32_extbgr_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extbgr_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_bgr_convert_internal
#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 2
#define RGB_GREEN_ESP32 1
#define RGB_BLUE_ESP32 0
#define RGB_PIXELSIZE_ESP32 4
#define RGB_ALPHA_ESP32 3
#define esp32_rgb_ycc_convert_internal esp32_extbgrx_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extbgrx_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_bgrx_convert_internal

#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 3
#define RGB_GREEN_ESP32 2
#define RGB_BLUE_ESP32 1
#define RGB_PIXELSIZE_ESP32 4
#define RGB_ALPHA_ESP32 0
#define esp32_rgb_ycc_convert_internal esp32_extxbgr_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extxbgr_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_xbgr_convert_internal

#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

#define RGB_RED_ESP32 1
#define RGB_GREEN_ESP32 2
#define RGB_BLUE_ESP32 3
#define RGB_PIXELSIZE_ESP32 4
#define RGB_ALPHA_ESP32 0
#define esp32_rgb_ycc_convert_internal esp32_extxrgb_ycc_convert_internal
#define esp32_rgb_gray_convert_internal esp32_extxrgb_gray_convert_internal
#define esp32_ycc_rgb_convert_internal esp32_dec_extycc_xrgb_convert_internal

#include "jccolext_esp32.c"
#include "jdcolext_esp32.c"

#undef RGB_RED_ESP32
#undef RGB_GREEN_ESP32
#undef RGB_BLUE_ESP32
#undef RGB_PIXELSIZE_ESP32
#undef esp32_rgb_ycc_convert_internal
#undef esp32_rgb_gray_convert_internal
#undef esp32_ycc_rgb_convert_internal
#undef RGB_ALPHA_ESP32

GLOBAL(int)
jsimd_can_rgb_gray(void)
{
    return 1;
}

GLOBAL(int)
jsimd_can_rgb_ycc(void)
{
    return 1;
}

GLOBAL(int)
jsimd_can_ycc_rgb(void)
{
    return 1;
}

GLOBAL(void)
jsimd_rgb_gray_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
  switch(cinfo->in_color_space){

    case JCS_EXT_RGB:
      esp32_extrgb_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    case JCS_EXT_RGBX:
    case JCS_EXT_RGBA:
      esp32_extrgbx_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    case JCS_EXT_BGR:
      esp32_extbgr_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    case JCS_EXT_BGRX:
    case JCS_EXT_BGRA:
      esp32_extbgrx_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    case JCS_EXT_XBGR:
    case JCS_EXT_ABGR:
      esp32_extxbgr_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    case JCS_EXT_XRGB:
    case JCS_EXT_ARGB:
      esp32_extxrgb_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
    default:
      esp32_extrgb_gray_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;

  } 
}

GLOBAL(void)
jsimd_rgb_ycc_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
  switch (cinfo->in_color_space) {
  case JCS_EXT_RGB:

    esp32_extrgb_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  case JCS_EXT_RGBX:
  case JCS_EXT_RGBA:
  
    esp32_extrgbx_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  case JCS_EXT_BGR:
    esp32_extbgr_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  case JCS_EXT_BGRX:
  case JCS_EXT_BGRA:
    esp32_extbgrx_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  case JCS_EXT_XBGR:
  case JCS_EXT_ABGR:
    esp32_extxbgr_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  case JCS_EXT_XRGB:
  case JCS_EXT_ARGB:
  
    esp32_extxrgb_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  default:
    esp32_extrgb_ycc_convert_internal(cinfo, input_buf, output_buf, output_row,
                                 num_rows);
    break;
  }
}

GLOBAL(void)
jsimd_ycc_rgb_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
  switch (cinfo->out_color_space) {
  case JCS_EXT_RGB:
    esp32_dec_extycc_rgb_convert_internal(cinfo, input_buf, input_row, output_buf,
                                num_rows);
    break;
  case JCS_EXT_RGBX:
  case JCS_EXT_RGBA:
    esp32_dec_extycc_rgbx_convert_internal(cinfo, input_buf, input_row, output_buf,
                                 num_rows);
    break;
  case JCS_EXT_BGR:
    esp32_dec_extycc_bgr_convert_internal(cinfo, input_buf, input_row, output_buf,
                                num_rows);
    break;
  case JCS_EXT_BGRX:
  case JCS_EXT_BGRA:
    esp32_dec_extycc_bgrx_convert_internal(cinfo, input_buf, input_row, output_buf,
                                 num_rows);
    break;
  case JCS_EXT_XBGR:
  case JCS_EXT_ABGR:
    esp32_dec_extycc_xbgr_convert_internal(cinfo, input_buf, input_row, output_buf,
                                 num_rows);
    break;
  case JCS_EXT_XRGB:
  case JCS_EXT_ARGB:
    esp32_dec_extycc_xrgb_convert_internal(cinfo, input_buf, input_row, output_buf,
                                 num_rows);
    
    break;
  default:
    esp32_dec_extycc_rgb_convert_internal(cinfo, input_buf, input_row, output_buf,
                             num_rows);
    
    break;
  }
}

GLOBAL(void)
jsimd_idct_islow(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                JCOEFPTR coef_block, JSAMPARRAY output_buf,
                JDIMENSION output_col)
{
  JLONG tmp0, tmp1, tmp2, tmp3;
  JLONG tmp10, tmp11, tmp12, tmp13;
  JLONG z1, z2, z3, z4, z5;
  JCOEFPTR inptr;
  short *quantptr;
  int *wsptr;
  JSAMPROW outptr;
  JSAMPLE *range_limit = IDCT_range_limit_ESP32(cinfo);
  int ctr;
  int workspace[DCTSIZE2];      /* buffers data between passes */
  SHIFT_TEMPS

  /* Pass 1: process columns from input, store into work array. */
  /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
  /* furthermore, we scale the results by 2**2. */

  inptr = coef_block;
  quantptr = (short *)compptr->dct_table;
  wsptr = workspace;
  for (ctr = DCTSIZE; ctr > 0; ctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any column in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * column DCT calculations can be simplified this way.
     */

    if (inptr[DCTSIZE * 1] == 0 && inptr[DCTSIZE * 2] == 0 &&
        inptr[DCTSIZE * 3] == 0 && inptr[DCTSIZE * 4] == 0 &&
        inptr[DCTSIZE * 5] == 0 && inptr[DCTSIZE * 6] == 0 &&
        inptr[DCTSIZE * 7] == 0) {
      /* AC terms all zero */
      int dcval = LEFT_SHIFT(DEQUANTIZE_ESP32(inptr[DCTSIZE * 0],
                             quantptr[DCTSIZE * 0]), 2);

      wsptr[DCTSIZE * 0] = dcval;
      wsptr[DCTSIZE * 1] = dcval;
      wsptr[DCTSIZE * 2] = dcval;
      wsptr[DCTSIZE * 3] = dcval;
      wsptr[DCTSIZE * 4] = dcval;
      wsptr[DCTSIZE * 5] = dcval;
      wsptr[DCTSIZE * 6] = dcval;
      wsptr[DCTSIZE * 7] = dcval;

      inptr++;                  /* advance pointers to next column */
      quantptr++;
      wsptr++;
      continue;
    }

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */

    z2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 2], quantptr[DCTSIZE * 2]);
    z3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 6], quantptr[DCTSIZE * 6]);

    z1 = MULTIPLY_ESP32(z2 + z3, FIX1_0_541196100);
    tmp2 = z1 + MULTIPLY_ESP32(z3, -FIX1_1_847759065);
    tmp3 = z1 + MULTIPLY_ESP32(z2, FIX1_0_765366865);

    z2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 0], quantptr[DCTSIZE * 0]);
    z3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 4], quantptr[DCTSIZE * 4]);

    tmp0 = LEFT_SHIFT(z2 + z3, 13);
    tmp1 = LEFT_SHIFT(z2 - z3, 13);

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */

    tmp0 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 7], quantptr[DCTSIZE * 7]);
    tmp1 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 5], quantptr[DCTSIZE * 5]);
    tmp2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 3], quantptr[DCTSIZE * 3]);
    tmp3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 1], quantptr[DCTSIZE * 1]);

    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = MULTIPLY_ESP32(z3 + z4, FIX1_1_175875602); /* sqrt(2) * c3 */

    tmp0 = MULTIPLY_ESP32(tmp0, FIX1_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp1 = MULTIPLY_ESP32(tmp1, FIX1_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp2 = MULTIPLY_ESP32(tmp2, FIX1_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp3 = MULTIPLY_ESP32(tmp3, FIX1_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY_ESP32(z1, -FIX1_0_899976223); /* sqrt(2) * ( c7-c3) */
    z2 = MULTIPLY_ESP32(z2, -FIX1_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY_ESP32(z3, -FIX1_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY_ESP32(z4, -FIX1_0_390180644); /* sqrt(2) * ( c5-c3) */

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    wsptr[DCTSIZE * 0] = (int)DESCALE_ESP32(tmp10 + tmp3, 13 - 2);
    wsptr[DCTSIZE * 7] = (int)DESCALE_ESP32(tmp10 - tmp3, 13 - 2);
    wsptr[DCTSIZE * 1] = (int)DESCALE_ESP32(tmp11 + tmp2, 13 - 2);
    wsptr[DCTSIZE * 6] = (int)DESCALE_ESP32(tmp11 - tmp2, 13 - 2);
    wsptr[DCTSIZE * 2] = (int)DESCALE_ESP32(tmp12 + tmp1, 13 - 2);
    wsptr[DCTSIZE * 5] = (int)DESCALE_ESP32(tmp12 - tmp1, 13 - 2);
    wsptr[DCTSIZE * 3] = (int)DESCALE_ESP32(tmp13 + tmp0, 13 - 2);
    wsptr[DCTSIZE * 4] = (int)DESCALE_ESP32(tmp13 - tmp0, 13 - 2);

    inptr++;                    /* advance pointers to next column */
    quantptr++;
    wsptr++;
  }

  /* Pass 2: process rows from work array, store into output array. */
  /* Note that we must descale the results by a factor of 8 == 2**3, */
  /* and also undo the 2 scaling. */

  wsptr = workspace;
  for (ctr = 0; ctr < DCTSIZE; ctr++) {
    outptr = output_buf[ctr] + output_col;
    /* Rows of zeroes can be exploited in the same way as we did with columns.
     * However, the column calculation has created many nonzero AC terms, so
     * the simplification applies less often (typically 5% to 10% of the time).
     * On machines with very fast multiplication, it's possible that the
     * test takes more time than it's worth.  In that case this section
     * may be commented out.
     */

#ifndef NO_ZERO_ROW_TEST
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 &&
        wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
      /* AC terms all zero */
      JSAMPLE dcval = range_limit[(int)DESCALE_ESP32((JLONG)wsptr[0],
                                               2 + 3) & RANGE_MASK_ESP32];

      outptr[0] = dcval;
      outptr[1] = dcval;
      outptr[2] = dcval;
      outptr[3] = dcval;
      outptr[4] = dcval;
      outptr[5] = dcval;
      outptr[6] = dcval;
      outptr[7] = dcval;

      wsptr += DCTSIZE;         /* advance pointer to next row */
      continue;
    }
#endif

    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */

    z2 = (JLONG)wsptr[2];
    z3 = (JLONG)wsptr[6];

    z1 = MULTIPLY_ESP32(z2 + z3, FIX1_0_541196100);
    tmp2 = z1 + MULTIPLY_ESP32(z3, -FIX1_1_847759065);
    tmp3 = z1 + MULTIPLY_ESP32(z2, FIX1_0_765366865);

    tmp0 = LEFT_SHIFT((JLONG)wsptr[0] + (JLONG)wsptr[4], 13);
    tmp1 = LEFT_SHIFT((JLONG)wsptr[0] - (JLONG)wsptr[4], 13);

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */

    tmp0 = (JLONG)wsptr[7];
    tmp1 = (JLONG)wsptr[5];
    tmp2 = (JLONG)wsptr[3];
    tmp3 = (JLONG)wsptr[1];

    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = MULTIPLY_ESP32(z3 + z4, FIX1_1_175875602); /* sqrt(2) * c3 */

    tmp0 = MULTIPLY_ESP32(tmp0, FIX1_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp1 = MULTIPLY_ESP32(tmp1, FIX1_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp2 = MULTIPLY_ESP32(tmp2, FIX1_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp3 = MULTIPLY_ESP32(tmp3, FIX1_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY_ESP32(z1, -FIX1_0_899976223); /* sqrt(2) * ( c7-c3) */
    z2 = MULTIPLY_ESP32(z2, -FIX1_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY_ESP32(z3, -FIX1_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY_ESP32(z4, -FIX1_0_390180644); /* sqrt(2) * ( c5-c3) */

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */

    outptr[0] = range_limit[(int)DESCALE_ESP32(tmp10 + tmp3,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[7] = range_limit[(int)DESCALE_ESP32(tmp10 - tmp3,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[1] = range_limit[(int)DESCALE_ESP32(tmp11 + tmp2,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[6] = range_limit[(int)DESCALE_ESP32(tmp11 - tmp2,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[2] = range_limit[(int)DESCALE_ESP32(tmp12 + tmp1,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[5] = range_limit[(int)DESCALE_ESP32(tmp12 - tmp1,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[3] = range_limit[(int)DESCALE_ESP32(tmp13 + tmp0,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[4] = range_limit[(int)DESCALE_ESP32(tmp13 - tmp0,
                                         13 + 2 + 3) &
                            RANGE_MASK_ESP32];

    wsptr += DCTSIZE;           /* advance pointer to next row */
  }
}

GLOBAL(void)
jsimd_fdct_islow(short *data)
{

  JLONG tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  JLONG tmp10, tmp11, tmp12, tmp13;
  JLONG z1, z2, z3, z4, z5;
  short *dataptr;
  int ctr;
  SHIFT_TEMPS

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true DCT; */
  /* furthermore, we scale the results by 2**2. */

  dataptr = data;
  for (ctr = DCTSIZE - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = (short)LEFT_SHIFT(tmp10 + tmp11, 2);
    dataptr[4] = (short)LEFT_SHIFT(tmp10 - tmp11, 2);

    z1 = MULTIPLY_ESP32(tmp12 + tmp13, FIX2_0_541196100);
    dataptr[2] = (short)DESCALE_ESP32(z1 + MULTIPLY_ESP32(tmp13, FIX2_0_765366865),
                                  13 - 2);
    dataptr[6] = (short)DESCALE_ESP32(z1 + MULTIPLY_ESP32(tmp12, -FIX2_1_847759065),
                                  13 - 2);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = MULTIPLY_ESP32(z3 + z4, FIX2_1_175875602); /* sqrt(2) * c3 */

    tmp4 = MULTIPLY_ESP32(tmp4, FIX2_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp5 = MULTIPLY_ESP32(tmp5, FIX2_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp6 = MULTIPLY_ESP32(tmp6, FIX2_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp7 = MULTIPLY_ESP32(tmp7, FIX2_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY_ESP32(z1, -FIX2_0_899976223); /* sqrt(2) * ( c7-c3) */
    z2 = MULTIPLY_ESP32(z2, -FIX2_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY_ESP32(z3, -FIX2_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY_ESP32(z4, -FIX2_0_390180644); /* sqrt(2) * ( c5-c3) */

    z3 += z5;
    z4 += z5;

    dataptr[7] = (short)DESCALE_ESP32(tmp4 + z1 + z3, 13 - 2);
    dataptr[5] = (short)DESCALE_ESP32(tmp5 + z2 + z4, 13 - 2);
    dataptr[3] = (short)DESCALE_ESP32(tmp6 + z2 + z3, 13 - 2);
    dataptr[1] = (short)DESCALE_ESP32(tmp7 + z1 + z4, 13 - 2);

    dataptr += DCTSIZE;         /* advance pointer to next row */
  }

  /* Pass 2: process columns.
   * We remove the 2 scaling, but leave the results scaled up
   * by an overall factor of 8.
   */

  dataptr = data;
  for (ctr = DCTSIZE - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[DCTSIZE * 0] + dataptr[DCTSIZE * 7];
    tmp7 = dataptr[DCTSIZE * 0] - dataptr[DCTSIZE * 7];
    tmp1 = dataptr[DCTSIZE * 1] + dataptr[DCTSIZE * 6];
    tmp6 = dataptr[DCTSIZE * 1] - dataptr[DCTSIZE * 6];
    tmp2 = dataptr[DCTSIZE * 2] + dataptr[DCTSIZE * 5];
    tmp5 = dataptr[DCTSIZE * 2] - dataptr[DCTSIZE * 5];
    tmp3 = dataptr[DCTSIZE * 3] + dataptr[DCTSIZE * 4];
    tmp4 = dataptr[DCTSIZE * 3] - dataptr[DCTSIZE * 4];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[DCTSIZE * 0] = (short)DESCALE_ESP32(tmp10 + tmp11, 2);
    dataptr[DCTSIZE * 4] = (short)DESCALE_ESP32(tmp10 - tmp11, 2);

    z1 = MULTIPLY_ESP32(tmp12 + tmp13, FIX2_0_541196100);
    dataptr[DCTSIZE * 2] =
      (short)DESCALE_ESP32(z1 + MULTIPLY_ESP32(tmp13, FIX2_0_765366865),
                       13 + 2);
    dataptr[DCTSIZE * 6] =
      (short)DESCALE_ESP32(z1 + MULTIPLY_ESP32(tmp12, -FIX2_1_847759065),
                       13 + 2);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = MULTIPLY_ESP32(z3 + z4, FIX2_1_175875602); /* sqrt(2) * c3 */

    tmp4 = MULTIPLY_ESP32(tmp4, FIX2_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp5 = MULTIPLY_ESP32(tmp5, FIX2_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp6 = MULTIPLY_ESP32(tmp6, FIX2_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp7 = MULTIPLY_ESP32(tmp7, FIX2_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY_ESP32(z1, -FIX2_0_899976223); /* sqrt(2) * ( c7-c3) */
    z2 = MULTIPLY_ESP32(z2, -FIX2_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY_ESP32(z3, -FIX2_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY_ESP32(z4, -FIX2_0_390180644); /* sqrt(2) * ( c5-c3) */

    z3 += z5;
    z4 += z5;

    dataptr[DCTSIZE * 7] = (short)DESCALE_ESP32(tmp4 + z1 + z3,
                                            13 + 2);
    dataptr[DCTSIZE * 5] = (short)DESCALE_ESP32(tmp5 + z2 + z4,
                                            13 + 2);
    dataptr[DCTSIZE * 3] = (short)DESCALE_ESP32(tmp6 + z2 + z3,
                                            13 + 2);
    dataptr[DCTSIZE * 1] = (short)DESCALE_ESP32(tmp7 + z1 + z4,
                                            13 + 2);

    dataptr++;                  /* advance pointer to next column */
  }
}

GLOBAL(void)
jsimd_idct_ifast(j_decompress_ptr cinfo,
                              jpeg_component_info *compptr,
                              JCOEFPTR coef_block, JSAMPARRAY output_buf,
                              JDIMENSION output_col)
{
  short tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  short tmp10, tmp11, tmp12, tmp13;
  short z5, z10, z11, z12, z13;
  JCOEFPTR inptr;
  short *quantptr;
  int *wsptr;
  JSAMPROW outptr;
  JSAMPLE *range_limit = IDCT_range_limit_ESP32(cinfo);
  int ctr;
  int workspace[DCTSIZE2];      /* buffers data between passes */
  SHIFT_TEMPS                   /* for DESCALE */
  ISHIFT_TEMPS                  /* for IDESCALE_ESP32 */

  /* Pass 1: process columns from input, store into work array. */

  inptr = coef_block;
  quantptr = (short *)compptr->dct_table;
  wsptr = workspace;
  for (ctr = DCTSIZE; ctr > 0; ctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any column in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * column DCT calculations can be simplified this way.
     */

    if (inptr[DCTSIZE * 1] == 0 && inptr[DCTSIZE * 2] == 0 &&
        inptr[DCTSIZE * 3] == 0 && inptr[DCTSIZE * 4] == 0 &&
        inptr[DCTSIZE * 5] == 0 && inptr[DCTSIZE * 6] == 0 &&
        inptr[DCTSIZE * 7] == 0) {
      /* AC terms all zero */
      int dcval = (int)DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 0], quantptr[DCTSIZE * 0]);

      wsptr[DCTSIZE * 0] = dcval;
      wsptr[DCTSIZE * 1] = dcval;
      wsptr[DCTSIZE * 2] = dcval;
      wsptr[DCTSIZE * 3] = dcval;
      wsptr[DCTSIZE * 4] = dcval;
      wsptr[DCTSIZE * 5] = dcval;
      wsptr[DCTSIZE * 6] = dcval;
      wsptr[DCTSIZE * 7] = dcval;

      inptr++;                  /* advance pointers to next column */
      quantptr++;
      wsptr++;
      continue;
    }

    /* Even part */

    tmp0 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 0], quantptr[DCTSIZE * 0]);
    tmp1 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 2], quantptr[DCTSIZE * 2]);
    tmp2 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 4], quantptr[DCTSIZE * 4]);
    tmp3 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 6], quantptr[DCTSIZE * 6]);

    tmp10 = tmp0 + tmp2;        /* phase 3 */
    tmp11 = tmp0 - tmp2;

    tmp13 = tmp1 + tmp3;        /* phases 5-3 */
    tmp12 = MULTIPLY_ESP32_IDCT_FAST(tmp1 - tmp3, FIX4_1_414213562) - tmp13; /* 2*c4 */

    tmp0 = tmp10 + tmp13;       /* phase 2 */
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    /* Odd part */

    tmp4 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 1], quantptr[DCTSIZE * 1]);
    tmp5 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 3], quantptr[DCTSIZE * 3]);
    tmp6 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 5], quantptr[DCTSIZE * 5]);
    tmp7 = DEQUANTIZE_ESP32_IDCT_FAST(inptr[DCTSIZE * 7], quantptr[DCTSIZE * 7]);

    z13 = tmp6 + tmp5;          /* phase 6 */
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;

    tmp7 = z11 + z13;           /* phase 5 */
    tmp11 = DEQUANTIZE_ESP32_IDCT_FAST(z11 - z13, FIX4_1_414213562); /* 2*c4 */

    z5 = DEQUANTIZE_ESP32_IDCT_FAST(z10 + z12, FIX4_1_847759065); /* 2*c2 */
    tmp10 = DEQUANTIZE_ESP32_IDCT_FAST(z12, FIX4_1_082392200) - z5; /* 2*(c2-c6) */
    tmp12 = MULTIPLY_ESP32_IDCT_FAST(z10, -FIX4_2_613125930) + z5; /* -2*(c2+c6) */

    tmp6 = tmp12 - tmp7;        /* phase 2 */
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;

    wsptr[DCTSIZE * 0] = (int)(tmp0 + tmp7);
    wsptr[DCTSIZE * 7] = (int)(tmp0 - tmp7);
    wsptr[DCTSIZE * 1] = (int)(tmp1 + tmp6);
    wsptr[DCTSIZE * 6] = (int)(tmp1 - tmp6);
    wsptr[DCTSIZE * 2] = (int)(tmp2 + tmp5);
    wsptr[DCTSIZE * 5] = (int)(tmp2 - tmp5);
    wsptr[DCTSIZE * 4] = (int)(tmp3 + tmp4);
    wsptr[DCTSIZE * 3] = (int)(tmp3 - tmp4);

    inptr++;                    /* advance pointers to next column */
    quantptr++;
    wsptr++;
  }

  /* Pass 2: process rows from work array, store into output array. */
  /* Note that we must descale the results by a factor of 8 == 2**3, */
  /* and also undo the 2 scaling. */

  wsptr = workspace;
  for (ctr = 0; ctr < DCTSIZE; ctr++) {
    outptr = output_buf[ctr] + output_col;
    /* Rows of zeroes can be exploited in the same way as we did with columns.
     * However, the column calculation has created many nonzero AC terms, so
     * the simplification applies less often (typically 5% to 10% of the time).
     * On machines with very fast multiplication, it's possible that the
     * test takes more time than it's worth.  In that case this section
     * may be commented out.
     */

#ifndef NO_ZERO_ROW_TEST
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 &&
        wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
      /* AC terms all zero */
      JSAMPLE dcval =
        range_limit[IDESCALE_ESP32(wsptr[0], 2 + 3) & RANGE_MASK_ESP32];

      outptr[0] = dcval;
      outptr[1] = dcval;
      outptr[2] = dcval;
      outptr[3] = dcval;
      outptr[4] = dcval;
      outptr[5] = dcval;
      outptr[6] = dcval;
      outptr[7] = dcval;

      wsptr += DCTSIZE;         /* advance pointer to next row */
      continue;
    }
#endif

    /* Even part */

    tmp10 = ((short)wsptr[0] + (short)wsptr[4]);
    tmp11 = ((short)wsptr[0] - (short)wsptr[4]);

    tmp13 = ((short)wsptr[2] + (short)wsptr[6]);
    tmp12 =
      MULTIPLY_ESP32_IDCT_FAST((short)wsptr[2] - (short)wsptr[6], FIX4_1_414213562) - tmp13;

    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    /* Odd part */

    z13 = (short)wsptr[5] + (short)wsptr[3];
    z10 = (short)wsptr[5] - (short)wsptr[3];
    z11 = (short)wsptr[1] + (short)wsptr[7];
    z12 = (short)wsptr[1] - (short)wsptr[7];

    tmp7 = z11 + z13;           /* phase 5 */
    tmp11 = MULTIPLY_ESP32_IDCT_FAST(z11 - z13, FIX4_1_414213562); /* 2*c4 */

    z5 = MULTIPLY_ESP32_IDCT_FAST(z10 + z12, FIX4_1_847759065); /* 2*c2 */
    tmp10 = MULTIPLY_ESP32_IDCT_FAST(z12, FIX4_1_082392200) - z5; /* 2*(c2-c6) */
    tmp12 = MULTIPLY_ESP32_IDCT_FAST(z10, -FIX4_2_613125930) + z5; /* -2*(c2+c6) */

    tmp6 = tmp12 - tmp7;        /* phase 2 */
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;

    /* Final output stage: scale down by a factor of 8 and range-limit */

    outptr[0] =
      range_limit[IDESCALE_ESP32(tmp0 + tmp7, 2 + 3) & RANGE_MASK_ESP32];
    outptr[7] =
      range_limit[IDESCALE_ESP32(tmp0 - tmp7, 2 + 3) & RANGE_MASK_ESP32];
    outptr[1] =
      range_limit[IDESCALE_ESP32(tmp1 + tmp6, 2 + 3) & RANGE_MASK_ESP32];
    outptr[6] =
      range_limit[IDESCALE_ESP32(tmp1 - tmp6, 2 + 3) & RANGE_MASK_ESP32];
    outptr[2] =
      range_limit[IDESCALE_ESP32(tmp2 + tmp5, 2 + 3) & RANGE_MASK_ESP32];
    outptr[5] =
      range_limit[IDESCALE_ESP32(tmp2 - tmp5, 2 + 3) & RANGE_MASK_ESP32];
    outptr[4] =
      range_limit[IDESCALE_ESP32(tmp3 + tmp4, 2 + 3) & RANGE_MASK_ESP32];
    outptr[3] =
      range_limit[IDESCALE_ESP32(tmp3 - tmp4, 2 + 3) & RANGE_MASK_ESP32];

    wsptr += DCTSIZE;           /* advance pointer to next row */
  }
}

GLOBAL(void)
jsimd_fdct_ifast(short *data)
{
  short tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  short tmp10, tmp11, tmp12, tmp13;
  short z1, z2, z3, z4, z5, z11, z13;
  short *dataptr;
  int ctr;
  SHIFT_TEMPS

  /* Pass 1: process rows. */

  dataptr = data;
  for (ctr = DCTSIZE - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    /* Even part */

    tmp10 = tmp0 + tmp3;        /* phase 2 */
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = tmp10 + tmp11; /* phase 3 */
    dataptr[4] = tmp10 - tmp11;

    z1 = MULTIPLY_ESP32_FDCT(tmp12 + tmp13, FIX3_0_707106781); /* c4 */
    dataptr[2] = tmp13 + z1;    /* phase 5 */
    dataptr[6] = tmp13 - z1;

    /* Odd part */

    tmp10 = tmp4 + tmp5;        /* phase 2 */
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;

    /* The rotator is modified from fig 4-8 to avoid extra negations. */
    z5 = MULTIPLY_ESP32_FDCT(tmp10 - tmp12, FIX3_0_382683433); /* c6 */
    z2 = MULTIPLY_ESP32_FDCT(tmp10, FIX3_0_541196100) + z5; /* c2-c6 */
    z4 = MULTIPLY_ESP32_FDCT(tmp12, FIX3_1_306562965) + z5; /* c2+c6 */
    z3 = MULTIPLY_ESP32_FDCT(tmp11, FIX3_0_707106781); /* c4 */

    z11 = tmp7 + z3;            /* phase 5 */
    z13 = tmp7 - z3;

    dataptr[5] = z13 + z2;      /* phase 6 */
    dataptr[3] = z13 - z2;
    dataptr[1] = z11 + z4;
    dataptr[7] = z11 - z4;

    dataptr += DCTSIZE;         /* advance pointer to next row */
  }

  /* Pass 2: process columns. */

  dataptr = data;
  for (ctr = DCTSIZE - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[DCTSIZE * 0] + dataptr[DCTSIZE * 7];
    tmp7 = dataptr[DCTSIZE * 0] - dataptr[DCTSIZE * 7];
    tmp1 = dataptr[DCTSIZE * 1] + dataptr[DCTSIZE * 6];
    tmp6 = dataptr[DCTSIZE * 1] - dataptr[DCTSIZE * 6];
    tmp2 = dataptr[DCTSIZE * 2] + dataptr[DCTSIZE * 5];
    tmp5 = dataptr[DCTSIZE * 2] - dataptr[DCTSIZE * 5];
    tmp3 = dataptr[DCTSIZE * 3] + dataptr[DCTSIZE * 4];
    tmp4 = dataptr[DCTSIZE * 3] - dataptr[DCTSIZE * 4];

    /* Even part */

    tmp10 = tmp0 + tmp3;        /* phase 2 */
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[DCTSIZE * 0] = tmp10 + tmp11; /* phase 3 */
    dataptr[DCTSIZE * 4] = tmp10 - tmp11;

    z1 = MULTIPLY_ESP32_FDCT(tmp12 + tmp13, FIX3_0_707106781); /* c4 */
    dataptr[DCTSIZE * 2] = tmp13 + z1; /* phase 5 */
    dataptr[DCTSIZE * 6] = tmp13 - z1;

    /* Odd part */

    tmp10 = tmp4 + tmp5;        /* phase 2 */
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;

    /* The rotator is modified from fig 4-8 to avoid extra negations. */
    z5 = MULTIPLY_ESP32_FDCT(tmp10 - tmp12, FIX3_0_382683433); /* c6 */
    z2 = MULTIPLY_ESP32_FDCT(tmp10, FIX3_0_541196100) + z5; /* c2-c6 */
    z4 = MULTIPLY_ESP32_FDCT(tmp12, FIX3_1_306562965) + z5; /* c2+c6 */
    z3 = MULTIPLY_ESP32_FDCT(tmp11, FIX3_0_707106781); /* c4 */

    z11 = tmp7 + z3;            /* phase 5 */
    z13 = tmp7 - z3;

    dataptr[DCTSIZE * 5] = z13 + z2; /* phase 6 */
    dataptr[DCTSIZE * 3] = z13 - z2;
    dataptr[DCTSIZE * 1] = z11 + z4;
    dataptr[DCTSIZE * 7] = z11 - z4;

    dataptr++;                  /* advance pointer to next column */
  }
}

GLOBAL(void)
jsimd_idct_6x6(j_decompress_ptr cinfo, jpeg_component_info *compptr,
              JCOEFPTR coef_block, JSAMPARRAY output_buf,
              JDIMENSION output_col)
{
  JLONG tmp0, tmp1, tmp2, tmp10, tmp11, tmp12;
  JLONG z1, z2, z3;
  JCOEFPTR inptr;
  short *quantptr;
  int *wsptr;
  JSAMPROW outptr;
  JSAMPLE *range_limit = IDCT_range_limit_ESP32(cinfo);
  int ctr;
  int workspace[6 * 6];         /* buffers data between passes */
  SHIFT_TEMPS

  /* Pass 1: process columns from input, store into work array. */

  inptr = coef_block;
  quantptr = (short *)compptr->dct_table;
  wsptr = workspace;
  for (ctr = 0; ctr < 6; ctr++, inptr++, quantptr++, wsptr++) {
    /* Even part */

    tmp0 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 0], quantptr[DCTSIZE * 0]);
    tmp0 = LEFT_SHIFT(tmp0, 13);
    /* Add fudge factor here for final descale. */
    tmp0 += ((JLONG)1) << (13 - 2 - 1);
    tmp2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 4], quantptr[DCTSIZE * 4]);
    tmp10 = MULTIPLY_ESP32(tmp2, FIX_ESP32(0.707106781));   /* c4 */
    tmp1 = tmp0 + tmp10;
    tmp11 = RIGHT_SHIFT(tmp0 - tmp10 - tmp10, 13 - 2);
    tmp10 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 2], quantptr[DCTSIZE * 2]);
    tmp0 = MULTIPLY_ESP32(tmp10, FIX_ESP32(1.224744871));   /* c2 */
    tmp10 = tmp1 + tmp0;
    tmp12 = tmp1 - tmp0;

    /* Odd part */

    z1 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 1], quantptr[DCTSIZE * 1]);
    z2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 3], quantptr[DCTSIZE * 3]);
    z3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 5], quantptr[DCTSIZE * 5]);
    tmp1 = MULTIPLY_ESP32(z1 + z3, FIX_ESP32(0.366025404)); /* c5 */
    tmp0 = tmp1 + LEFT_SHIFT(z1 + z2, 13);
    tmp2 = tmp1 + LEFT_SHIFT(z3 - z2, 13);
    tmp1 = LEFT_SHIFT(z1 - z2 - z3, 2);

    /* Final output stage */

    wsptr[6 * 0] = (int)RIGHT_SHIFT(tmp10 + tmp0, 13 - 2);
    wsptr[6 * 5] = (int)RIGHT_SHIFT(tmp10 - tmp0, 13 - 2);
    wsptr[6 * 1] = (int)(tmp11 + tmp1);
    wsptr[6 * 4] = (int)(tmp11 - tmp1);
    wsptr[6 * 2] = (int)RIGHT_SHIFT(tmp12 + tmp2, 13 - 2);
    wsptr[6 * 3] = (int)RIGHT_SHIFT(tmp12 - tmp2, 13 - 2);
  }

  /* Pass 2: process 6 rows from work array, store into output array. */

  wsptr = workspace;
  for (ctr = 0; ctr < 6; ctr++) {
    outptr = output_buf[ctr] + output_col;

    /* Even part */

    /* Add fudge factor here for final descale. */
    tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (2 + 2));
    tmp0 = LEFT_SHIFT(tmp0, 13);
    tmp2 = (JLONG)wsptr[4];
    tmp10 = MULTIPLY_ESP32(tmp2, FIX_ESP32(0.707106781));   /* c4 */
    tmp1 = tmp0 + tmp10;
    tmp11 = tmp0 - tmp10 - tmp10;
    tmp10 = (JLONG)wsptr[2];
    tmp0 = MULTIPLY_ESP32(tmp10, FIX_ESP32(1.224744871));   /* c2 */
    tmp10 = tmp1 + tmp0;
    tmp12 = tmp1 - tmp0;

    /* Odd part */

    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    tmp1 = MULTIPLY_ESP32(z1 + z3, FIX_ESP32(0.366025404)); /* c5 */
    tmp0 = tmp1 + LEFT_SHIFT(z1 + z2, 13);
    tmp2 = tmp1 + LEFT_SHIFT(z3 - z2, 13);
    tmp1 = LEFT_SHIFT(z1 - z2 - z3, 13);

    /* Final output stage */

    outptr[0] = range_limit[(int)RIGHT_SHIFT(tmp10 + tmp0,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[5] = range_limit[(int)RIGHT_SHIFT(tmp10 - tmp0,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[1] = range_limit[(int)RIGHT_SHIFT(tmp11 + tmp1,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[4] = range_limit[(int)RIGHT_SHIFT(tmp11 - tmp1,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[2] = range_limit[(int)RIGHT_SHIFT(tmp12 + tmp2,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];
    outptr[3] = range_limit[(int)RIGHT_SHIFT(tmp12 - tmp2,
                                             13 + 2 + 3) &
                            RANGE_MASK_ESP32];

    wsptr += 6;         /* advance pointer to next row */
  }
}

GLOBAL(void)
jsimd_idct_12x12(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                JCOEFPTR coef_block, JSAMPARRAY output_buf,
                JDIMENSION output_col)
{
  JLONG tmp10, tmp11, tmp12, tmp13, tmp14, tmp15;
  JLONG tmp20, tmp21, tmp22, tmp23, tmp24, tmp25;
  JLONG z1, z2, z3, z4;
  JCOEFPTR inptr;
  short *quantptr;
  int *wsptr;
  JSAMPROW outptr;
  JSAMPLE *range_limit = IDCT_range_limit_ESP32(cinfo);
  int ctr;
  int workspace[8 * 12];        /* buffers data between passes */
  SHIFT_TEMPS

  /* Pass 1: process columns from input, store into work array. */

  inptr = coef_block;
  quantptr = (short *)compptr->dct_table;
  wsptr = workspace;
  for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
    /* Even part */

    z3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 0], quantptr[DCTSIZE * 0]);
    z3 = LEFT_SHIFT(z3, 13);
    /* Add fudge factor here for final descale. */
    z3 += ((JLONG)1) << (13 - 2 - 1);

    z4 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 4], quantptr[DCTSIZE * 4]);
    z4 = MULTIPLY_ESP32(z4, FIX_ESP32(1.224744871)); /* c4 */

    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    z1 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 2], quantptr[DCTSIZE * 2]);
    z4 = MULTIPLY_ESP32(z1, FIX_ESP32(1.366025404)); /* c2 */
    z1 = LEFT_SHIFT(z1, 13);
    z2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 6], quantptr[DCTSIZE * 6]);
    z2 = LEFT_SHIFT(z2, 13);

    tmp12 = z1 - z2;

    tmp21 = z3 + tmp12;
    tmp24 = z3 - tmp12;

    tmp12 = z4 + z2;

    tmp20 = tmp10 + tmp12;
    tmp25 = tmp10 - tmp12;

    tmp12 = z4 - z1 - z2;

    tmp22 = tmp11 + tmp12;
    tmp23 = tmp11 - tmp12;

    /* Odd part */

    z1 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 1], quantptr[DCTSIZE * 1]);
    z2 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 3], quantptr[DCTSIZE * 3]);
    z3 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 5], quantptr[DCTSIZE * 5]);
    z4 = DEQUANTIZE_ESP32(inptr[DCTSIZE * 7], quantptr[DCTSIZE * 7]);

    tmp11 = MULTIPLY_ESP32(z2, FIX_ESP32(1.306562965));                  /* c3 */
    tmp14 = MULTIPLY_ESP32(z2, -FIX1_0_541196100);                  /* -c9 */

    tmp10 = z1 + z3;
    tmp15 = MULTIPLY_ESP32(tmp10 + z4, FIX_ESP32(0.860918669));          /* c7 */
    tmp12 = tmp15 + MULTIPLY_ESP32(tmp10, FIX_ESP32(0.261052384));       /* c5-c7 */
    tmp10 = tmp12 + tmp11 + MULTIPLY_ESP32(z1, FIX_ESP32(0.280143716));  /* c1-c5 */
    tmp13 = MULTIPLY_ESP32(z3 + z4, -FIX_ESP32(1.045510580));            /* -(c7+c11) */
    tmp12 += tmp13 + tmp14 - MULTIPLY_ESP32(z3, FIX_ESP32(1.478575242)); /* c1+c5-c7-c11 */
    tmp13 += tmp15 - tmp11 + MULTIPLY_ESP32(z4, FIX_ESP32(1.586706681)); /* c1+c11 */
    tmp15 += tmp14 - MULTIPLY_ESP32(z1, FIX_ESP32(0.676326758)) -        /* c7-c11 */
             MULTIPLY_ESP32(z4, FIX_ESP32(1.982889723));                 /* c5+c7 */

    z1 -= z4;
    z2 -= z3;
    z3 = MULTIPLY_ESP32(z1 + z2, FIX1_0_541196100);                 /* c9 */
    tmp11 = z3 + MULTIPLY_ESP32(z1, FIX1_0_765366865);              /* c3-c9 */
    tmp14 = z3 - MULTIPLY_ESP32(z2, FIX1_1_847759065);              /* c3+c9 */

    /* Final output stage */

    wsptr[8 * 0]  = (int)RIGHT_SHIFT(tmp20 + tmp10, 13 - 2);
    wsptr[8 * 11] = (int)RIGHT_SHIFT(tmp20 - tmp10, 13 - 2);
    wsptr[8 * 1]  = (int)RIGHT_SHIFT(tmp21 + tmp11, 13 - 2);
    wsptr[8 * 10] = (int)RIGHT_SHIFT(tmp21 - tmp11, 13 - 2);
    wsptr[8 * 2]  = (int)RIGHT_SHIFT(tmp22 + tmp12, 13 - 2);
    wsptr[8 * 9]  = (int)RIGHT_SHIFT(tmp22 - tmp12, 13 - 2);
    wsptr[8 * 3]  = (int)RIGHT_SHIFT(tmp23 + tmp13, 13 - 2);
    wsptr[8 * 8]  = (int)RIGHT_SHIFT(tmp23 - tmp13, 13 - 2);
    wsptr[8 * 4]  = (int)RIGHT_SHIFT(tmp24 + tmp14, 13 - 2);
    wsptr[8 * 7]  = (int)RIGHT_SHIFT(tmp24 - tmp14, 13 - 2);
    wsptr[8 * 5]  = (int)RIGHT_SHIFT(tmp25 + tmp15, 13 - 2);
    wsptr[8 * 6]  = (int)RIGHT_SHIFT(tmp25 - tmp15, 13 - 2);
  }

  /* Pass 2: process 12 rows from work array, store into output array. */

  wsptr = workspace;
  for (ctr = 0; ctr < 12; ctr++) {
    outptr = output_buf[ctr] + output_col;

    /* Even part */

    /* Add fudge factor here for final descale. */
    z3 = (JLONG)wsptr[0] + (((JLONG)1) << (2 + 2));
    z3 = LEFT_SHIFT(z3, 13);

    z4 = (JLONG)wsptr[4];
    z4 = MULTIPLY_ESP32(z4, FIX_ESP32(1.224744871)); /* c4 */

    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    z1 = (JLONG)wsptr[2];
    z4 = MULTIPLY_ESP32(z1, FIX_ESP32(1.366025404)); /* c2 */
    z1 = LEFT_SHIFT(z1, 13);
    z2 = (JLONG)wsptr[6];
    z2 = LEFT_SHIFT(z2, 13);

    tmp12 = z1 - z2;

    tmp21 = z3 + tmp12;
    tmp24 = z3 - tmp12;

    tmp12 = z4 + z2;

    tmp20 = tmp10 + tmp12;
    tmp25 = tmp10 - tmp12;

    tmp12 = z4 - z1 - z2;

    tmp22 = tmp11 + tmp12;
    tmp23 = tmp11 - tmp12;

    /* Odd part */

    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    z4 = (JLONG)wsptr[7];

    tmp11 = MULTIPLY_ESP32(z2, FIX_ESP32(1.306562965));                  /* c3 */
    tmp14 = MULTIPLY_ESP32(z2, -FIX1_0_541196100);                  /* -c9 */

    tmp10 = z1 + z3;
    tmp15 = MULTIPLY_ESP32(tmp10 + z4, FIX_ESP32(0.860918669));          /* c7 */
    tmp12 = tmp15 + MULTIPLY_ESP32(tmp10, FIX_ESP32(0.261052384));       /* c5-c7 */
    tmp10 = tmp12 + tmp11 + MULTIPLY_ESP32(z1, FIX_ESP32(0.280143716));  /* c1-c5 */
    tmp13 = MULTIPLY_ESP32(z3 + z4, -FIX_ESP32(1.045510580));            /* -(c7+c11) */
    tmp12 += tmp13 + tmp14 - MULTIPLY_ESP32(z3, FIX_ESP32(1.478575242)); /* c1+c5-c7-c11 */
    tmp13 += tmp15 - tmp11 + MULTIPLY_ESP32(z4, FIX_ESP32(1.586706681)); /* c1+c11 */
    tmp15 += tmp14 - MULTIPLY_ESP32(z1, FIX_ESP32(0.676326758)) -        /* c7-c11 */
             MULTIPLY_ESP32(z4, FIX_ESP32(1.982889723));                 /* c5+c7 */

    z1 -= z4;
    z2 -= z3;
    z3 = MULTIPLY_ESP32(z1 + z2, FIX1_0_541196100);                 /* c9 */
    tmp11 = z3 + MULTIPLY_ESP32(z1, FIX1_0_765366865);              /* c3-c9 */
    tmp14 = z3 - MULTIPLY_ESP32(z2, FIX1_1_847759065);              /* c3+c9 */

    /* Final output stage */

    outptr[0]  = range_limit[(int)RIGHT_SHIFT(tmp20 + tmp10,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[11] = range_limit[(int)RIGHT_SHIFT(tmp20 - tmp10,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[1]  = range_limit[(int)RIGHT_SHIFT(tmp21 + tmp11,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[10] = range_limit[(int)RIGHT_SHIFT(tmp21 - tmp11,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[2]  = range_limit[(int)RIGHT_SHIFT(tmp22 + tmp12,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[9]  = range_limit[(int)RIGHT_SHIFT(tmp22 - tmp12,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[3]  = range_limit[(int)RIGHT_SHIFT(tmp23 + tmp13,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[8]  = range_limit[(int)RIGHT_SHIFT(tmp23 - tmp13,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[4]  = range_limit[(int)RIGHT_SHIFT(tmp24 + tmp14,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[7]  = range_limit[(int)RIGHT_SHIFT(tmp24 - tmp14,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[5]  = range_limit[(int)RIGHT_SHIFT(tmp25 + tmp15,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];
    outptr[6]  = range_limit[(int)RIGHT_SHIFT(tmp25 - tmp15,
                                              13 + 2 + 3) &
                             RANGE_MASK_ESP32];

    wsptr += 8;         /* advance pointer to next row */
  }
}

// Empty functions 

GLOBAL(int) 
jsimd_can_ycc_rgb565(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_c_can_null_convert(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_ycc_rgb565_convert(j_decompress_ptr cinfo,
                                      JSAMPIMAGE input_buf,
                                      JDIMENSION input_row,
                                      JSAMPARRAY output_buf, int num_rows)
{

}
GLOBAL(void) 
jsimd_c_null_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf,
                                  JSAMPIMAGE output_buf, JDIMENSION output_row,
                                  int num_rows)
{

}

GLOBAL(int) 
jsimd_can_h2v2_downsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_h2v1_downsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_h2v2_smooth_downsample(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_h2v2_downsample(j_compress_ptr cinfo,
                                   jpeg_component_info *compptr,
                                   JSAMPARRAY input_data,
                                   JSAMPARRAY output_data)
{

}

GLOBAL(void) 
jsimd_h2v1_downsample(j_compress_ptr cinfo,
                                   jpeg_component_info *compptr,
                                   JSAMPARRAY input_data,
                                   JSAMPARRAY output_data)
{

}

GLOBAL(void) 
jsimd_h2v2_smooth_downsample(j_compress_ptr cinfo,
                                          jpeg_component_info *compptr,
                                          JSAMPARRAY input_data,
                                          JSAMPARRAY output_data)
{

}
GLOBAL(int) 
jsimd_can_h2v2_upsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_h2v1_upsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_int_upsample(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_h2v2_upsample(j_decompress_ptr cinfo,
                                 jpeg_component_info *compptr,
                                 JSAMPARRAY input_data,
                                 JSAMPARRAY *output_data_ptr)
{

}
GLOBAL(void) 
jsimd_h2v1_upsample(j_decompress_ptr cinfo,
                                 jpeg_component_info *compptr,
                                 JSAMPARRAY input_data,
                                 JSAMPARRAY *output_data_ptr)
{

}
GLOBAL(void) 
jsimd_int_upsample(j_decompress_ptr cinfo,
                                jpeg_component_info *compptr,
                                JSAMPARRAY input_data,
                                JSAMPARRAY *output_data_ptr)
{

}

GLOBAL(int) 
jsimd_can_h2v2_fancy_upsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_h2v1_fancy_upsample(void)
{
    return 0;
}
GLOBAL(int) 
jsimd_can_h1v2_fancy_upsample(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_h2v2_fancy_upsample(j_decompress_ptr cinfo,
                                       jpeg_component_info *compptr,
                                       JSAMPARRAY input_data,
                                       JSAMPARRAY *output_data_ptr)
{

}

GLOBAL(void) 
jsimd_h2v1_fancy_upsample(j_decompress_ptr cinfo,
                                       jpeg_component_info *compptr,
                                       JSAMPARRAY input_data,
                                       JSAMPARRAY *output_data_ptr)
{

}

GLOBAL(void) 
jsimd_h1v2_fancy_upsample(j_decompress_ptr cinfo,
                                       jpeg_component_info *compptr,
                                       JSAMPARRAY input_data,
                                       JSAMPARRAY *output_data_ptr)
{

}

GLOBAL(int) 
jsimd_can_h2v2_merged_upsample(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_can_h2v1_merged_upsample(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_h2v2_merged_upsample(j_decompress_ptr cinfo,
                                        JSAMPIMAGE input_buf,
                                        JDIMENSION in_row_group_ctr,
                                        JSAMPARRAY output_buf)
{

}
GLOBAL(void) 
jsimd_h2v1_merged_upsample(j_decompress_ptr cinfo,
                                        JSAMPIMAGE input_buf,
                                        JDIMENSION in_row_group_ctr,
                                        JSAMPARRAY output_buf)
{

}

GLOBAL(int) 
jsimd_can_huff_encode_one_block(void)
{
    return 0;
}

GLOBAL(JOCTET *) 
jsimd_huff_encode_one_block(void *state, JOCTET *buffer,
                                             JCOEFPTR block, int last_dc_val,
                                             c_derived_tbl *dctbl,
                                             c_derived_tbl *actbl)
{
    return 0; // return added due to int data type
}

GLOBAL(int) 
jsimd_can_encode_mcu_AC_first_prepare(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_encode_mcu_AC_first_prepare
  (const JCOEF *block, const int *jpeg_natural_order_start, int Sl, int Al,
   JCOEF *values, size_t *zerobits)
{

}

GLOBAL(int) 
jsimd_can_encode_mcu_AC_refine_prepare(void)
{
    return 0;
}

GLOBAL(int) 
jsimd_encode_mcu_AC_refine_prepare
  (const JCOEF *block, const int *jpeg_natural_order_start, int Sl, int Al,
   JCOEF *absvalues, size_t *bits)
{
    return 0; // return added due to int data type
}

// empty idct/fdct functions

GLOBAL(int) 
jsimd_can_convsamp(void)
{
    return 0;
}
GLOBAL(int) 
jsimd_can_convsamp_float(void)
{
    return 0;
}
GLOBAL(void) 
jsimd_convsamp(JSAMPARRAY sample_data, JDIMENSION start_col,
                            DCTELEM *workspace)
{

}
GLOBAL(void) 
jsimd_convsamp_float(JSAMPARRAY sample_data, JDIMENSION strt_col,
                                  FAST_FLOAT *workspace)
{

}
GLOBAL(int) 
jsimd_can_fdct_islow(void)
{
    return 1;
}
GLOBAL(int) 
jsimd_can_fdct_ifast(void)
{
    return 1;
}
GLOBAL(int) 
jsimd_can_fdct_float(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_fdct_float(FAST_FLOAT *data)
{

}
GLOBAL(int) 
jsimd_can_quantize(void)
{
    return 0;
}
GLOBAL(int) 
jsimd_can_quantize_float(void)
{
    return 0;
}
GLOBAL(void) 
jsimd_quantize(JCOEFPTR coef_block, DCTELEM *divisors,
                            DCTELEM *workspace)
{

}
GLOBAL(void) 
jsimd_quantize_float(JCOEFPTR coef_block, FAST_FLOAT *divisors,
                                  FAST_FLOAT *workspace)
{

}
GLOBAL(int) 
jsimd_can_idct_2x2(void)
{
    return 0;
}
GLOBAL(int) 
jsimd_can_idct_4x4(void)
{
    return 0;
}
GLOBAL(int) 
jsimd_can_idct_6x6(void)
{
    return 1;
}
GLOBAL(int) 
jsimd_can_idct_12x12(void)
{
    return 1;
}

GLOBAL(void) 
jsimd_idct_2x2(j_decompress_ptr cinfo,
                            jpeg_component_info *compptr, JCOEFPTR coef_block,
                            JSAMPARRAY output_buf, JDIMENSION output_col)
{

}
GLOBAL(void) 
jsimd_idct_4x4(j_decompress_ptr cinfo,
                            jpeg_component_info *compptr, JCOEFPTR coef_block,
                            JSAMPARRAY output_buf, JDIMENSION output_col)
{

}

GLOBAL(int) 
jsimd_can_idct_islow(void)
{
    return 1;
}
GLOBAL(int) 
jsimd_can_idct_ifast(void)
{
    return 1;
}
GLOBAL(int) 
jsimd_can_idct_float(void)
{
    return 0;
}

GLOBAL(void) 
jsimd_idct_float(j_decompress_ptr cinfo,
                              jpeg_component_info *compptr,
                              JCOEFPTR coef_block, JSAMPARRAY output_buf,
                              JDIMENSION output_col)
{

}
