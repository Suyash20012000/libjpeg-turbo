#include <stdio.h>
#include "../../jpeglib.h"
inline static void esp32_rgb_ycc_convert_internal(j_compress_ptr cinfo, JSAMPARRAY input_buf,
                         JSAMPIMAGE output_buf, JDIMENSION output_row,
                         int num_rows)
{
  my_cconvert_ptr_esp32 cconvert = (my_cconvert_ptr_esp32)cinfo->cconvert;
  register int r, g, b;
  register JLONG *ctab = cconvert->rgb_ycc_tab;
  register JSAMPROW inptr;
  register JSAMPROW outptr0, outptr1, outptr2;
  register JDIMENSION col;
  JDIMENSION num_cols = cinfo->image_width;

  while (--num_rows >= 0) {
    inptr = *input_buf++;
    outptr0 = output_buf[0][output_row];
    outptr1 = output_buf[1][output_row];
    outptr2 = output_buf[2][output_row];
    output_row++;
    for (col = 0; col < num_cols; col++) {
      r = inptr[RGB_RED_ESP32];
      g = inptr[RGB_GREEN_ESP32];
      b = inptr[RGB_BLUE_ESP32];
      inptr += RGB_PIXELSIZE_ESP32;
      /* If the inputs are 0..MAXJSAMPLE, the outputs of these equations
       * must be too; we do not need an explicit range-limiting operation.
       * Hence the value being shifted is never negative, and we don't
       * need the general RIGHT_SHIFT macro.
       */
      /* Y */
      outptr0[col] = (JSAMPLE)((ctab[r + R_Y_OFF] + ctab[g + G_Y_OFF] +
                                ctab[b + B_Y_OFF]) >> 16);
      /* Cb */
      outptr1[col] = (JSAMPLE)((ctab[r + R_CB_OFF] + ctab[g + G_CB_OFF] +
                                ctab[b + B_CB_OFF]) >> 16);
      /* Cr */
      outptr2[col] = (JSAMPLE)((ctab[r + R_CR_OFF] + ctab[g + G_CR_OFF] +
                                ctab[b + B_CR_OFF]) >> 16);
    }
  }
}


/**************** Cases other than RGB -> YCbCr **************/


/*
 * Convert some rows of samples to the JPEG colorspace.
 * This version handles RGB->grayscale conversion, which is the same
 * as the RGB->Y portion of RGB->YCbCr.
 * We assume rgb_ycc_start has been called (we only use the Y tables).
 */


static void esp32_rgb_gray_convert_internal(j_compress_ptr cinfo, JSAMPARRAY input_buf,
                          JSAMPIMAGE output_buf, JDIMENSION output_row,
                          int num_rows)
{
  my_cconvert_ptr_esp32 cconvert = (my_cconvert_ptr_esp32)cinfo->cconvert;
  register int r, g, b;
  register JLONG *ctab = cconvert->rgb_ycc_tab;
  register JSAMPROW inptr;
  register JSAMPROW outptr;
  register JDIMENSION col;
  JDIMENSION num_cols = cinfo->image_width;

  while (--num_rows >= 0) {
    inptr = *input_buf++;
    outptr = output_buf[0][output_row];
    output_row++;
    for (col = 0; col < num_cols; col++) {
      r = inptr[RGB_RED_ESP32];
      g = inptr[RGB_GREEN_ESP32];
      b = inptr[RGB_BLUE_ESP32];
      inptr += RGB_PIXELSIZE_ESP32;
      
      outptr[col] = (JSAMPLE)((ctab[r + R_Y_OFF] + ctab[g + G_Y_OFF] +
                               ctab[b + B_Y_OFF]) >> 16);
    }
  }
}

