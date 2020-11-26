#include <stdio.h>
#include <stddef.h>

#include "jpeglib.h"
#include "cderror.h"
static const char *const cdjpeg_message_table[] = {
#include "cderror.h"
    NULL
};
#include "jversion.h"
#include "jconfigint.h"

#define ERR_INVALID_ARG -1
#define SUCCESS 0
#define OUT_OF_MEMORY -2

typedef struct decoder_manager {
    unsigned long in_buf_sz;
    unsigned char *out_buf; //12 times size of image
    unsigned long out_buf_sz;
    JDIMENSION output_width;
    JDIMENSION output_height;
    int out_col_comp;
    J_COLOR_SPACE out_color_space;
    unsigned char *in_buf_start;
    unsigned char *in_buf_end;
    unsigned long out_buf_mem_alloc;

} decoder_context;
int decode_jpeg(decoder_context *mgr);
