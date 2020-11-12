#include "encoder.h"

int encode_greyscale(unsigned char *in_buf, encoder_context mgr , unsigned long *out_buf_sz)
{
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
#ifdef PROGRESS_REPORT
  struct cdjpeg_progress_mgr progress;
#endif

  /* Initialize the JPEG compression object with default error handling. */
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);
  /* Add some application-specific error messages (from cderror.h) */
  jerr.addon_message_table = cdjpeg_message_table;
  jerr.first_addon_message = JMSG_FIRSTADDONCODE;
  jerr.last_addon_message = JMSG_LASTADDONCODE;

  /* Initialize JPEG parameters.
   * Much of this may be overridden later.
   * In particular, we don't yet know the input file's color space,
   * but we need to provide some value for jpeg_set_defaults() to work.
   */

  cinfo.image_width = mgr.image_width;
  cinfo.image_height = mgr.image_height;
  cinfo.input_components = 1;
  cinfo.in_color_space = JCS_GRAYSCALE; /* arbitrary guess */
  jpeg_set_defaults(&cinfo);

#ifdef PROGRESS_REPORT
  start_progress_monitor((j_common_ptr)&cinfo, &progress);
#endif

  /* Specify data destination for compression */
  jpeg_mem_dest(&cinfo, &mgr.output_buffer,out_buf_sz);

  /* Start compressor */
  jpeg_start_compress(&cinfo, TRUE);

  unsigned char *buf[3]; //96
  while (cinfo.next_scanline < cinfo.image_height) {
      buf[0] = in_buf + cinfo.image_width * cinfo.next_scanline;
      jpeg_write_scanlines(&cinfo, (JSAMPARRAY) buf, 1);
  }
  /* Finish compression and release memory */
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

#ifdef PROGRESS_REPORT
  end_progress_monitor((j_common_ptr)&cinfo);
#endif

  /* All done. */
  return 0;                     /* suppress no-return-value warnings */
}
