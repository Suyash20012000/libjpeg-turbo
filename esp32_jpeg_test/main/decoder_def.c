#include "decoder.h"

int decode_jpeg(decoder_context *mgr)
{
    struct jpeg_decompress_struct cinfo;
    cinfo.out_color_space = mgr->out_color_space;
    struct jpeg_error_mgr jerr;
#ifdef PROGRESS_REPORT
    struct cdjpeg_progress_mgr progress;
#endif
    /* Initialize the JPEG decompression object with default error handling. */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    /* Add some application-specific error messages (from cderror.h) */
    jerr.addon_message_table = cdjpeg_message_table;
    jerr.first_addon_message = JMSG_FIRSTADDONCODE;
    jerr.last_addon_message = JMSG_LASTADDONCODE;

    /*specify data source for decompression*/

    if (mgr->in_buf_start == NULL || mgr->in_buf_sz == 0 || mgr->out_buf == NULL || mgr->in_buf_end == NULL) {
        return -1;
    }
    if (mgr->in_buf_sz < (mgr->in_buf_end - mgr->in_buf_start)) {
        return -2;
    }
    jpeg_mem_src(&cinfo, mgr->in_buf_start, mgr->in_buf_sz);

    /* Read file header, set default decompression parameters */
    (void)jpeg_read_header(&cinfo, TRUE);

    /* Start decompressor */
    (void)jpeg_start_decompress(&cinfo);

    unsigned char *buf[3];
    /* Process data */

    while (cinfo.output_scanline < (cinfo.output_height)) {

        buf[0] = mgr->out_buf + cinfo.image_width * cinfo.output_scanline * cinfo.out_color_components;
        jpeg_read_scanlines(&cinfo, (JSAMPARRAY) buf, cinfo.output_height);

    };

    if (mgr->in_buf_sz < (mgr->in_buf_end - mgr->in_buf_start)) {
        return -2;
    }
    mgr->out_buf_sz = cinfo.output_height * cinfo.output_width * cinfo.out_color_components;
    mgr->output_height = cinfo.output_height;
    mgr->output_width = cinfo.output_width;
    mgr->out_col_comp = cinfo.out_color_components;
    /*Finish decompression and release memory.*/
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
#ifdef PROGRESS_REPORT
    end_progress_monitor((j_common_ptr)&cinfo);
#endif
    return 0;
}