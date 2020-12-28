#include <stdio.h>
#include "../../jpeglib.h"

inline static void esp32_ycc_rgb_convert_internal(j_decompress_ptr cinfo, JSAMPIMAGE input_buf,
                         JDIMENSION input_row, JSAMPARRAY output_buf,
                         int num_rows)
{
  my_cconvert_ptr_esp32_dec cconvert = (my_cconvert_ptr_esp32_dec)cinfo->cconvert;
  register int y, cb, cr;
  register JSAMPROW outptr;
  register JSAMPROW inptr0, inptr1, inptr2;
  register JDIMENSION col;
  JDIMENSION num_cols = cinfo->output_width;
  /* copy these pointers into registers if possible */
  register JSAMPLE *range_limit = cinfo->sample_range_limit;
  register int *Crrtab = cconvert->Cr_r_tab;
  register int *Cbbtab = cconvert->Cb_b_tab;
  register JLONG *Crgtab = cconvert->Cr_g_tab;
  register JLONG *Cbgtab = cconvert->Cb_g_tab;
  SHIFT_TEMPS

  while (--num_rows >= 0) {
    inptr0 = input_buf[0][input_row];
    inptr1 = input_buf[1][input_row];
    inptr2 = input_buf[2][input_row];
    input_row++;
    outptr = *output_buf++;
    for (col = 0; col < num_cols; col++) {
      y  = inptr0[col];
      cb = inptr1[col];
      cr = inptr2[col];
      /* Range-limiting is essential due to noise introduced by DCT losses. */
      outptr[RGB_RED_ESP32] =   range_limit[y + Crrtab[cr]];
      outptr[RGB_GREEN_ESP32] = range_limit[y +
                              ((int)RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr],
                                                16))];
      outptr[RGB_BLUE_ESP32] =  range_limit[y + Cbbtab[cb]];
      /* Set unused byte to 0xFF so it can be interpreted as an opaque */
      /* alpha channel value */
#ifdef RGB_ALPHA_ESP32
      outptr[RGB_ALPHA_ESP32] = 0xFF;
#endif
      outptr += RGB_PIXELSIZE_ESP32;
    }
  }
}