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
#define SUCCESS 0
#define ERR_INVALID_ARGS -1
#define OUT_OF_MEMORY -2
typedef struct encoder_manager {
    unsigned int image_height;
    unsigned int image_width;
    unsigned long out_buf_sz;
    unsigned char *output_buffer;
    J_COLOR_SPACE in_col_space;
    unsigned char *inp_buf;
    int in_col_components;
    unsigned int quality;
    unsigned long out_buf_mem_alloc;
} encoder_context;

int encode_image(encoder_context *mgr);
