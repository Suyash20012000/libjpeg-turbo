#include <stdio.h>
#include <stddef.h>

#include "../../jpeglib.h"
#include "../../cderror.h"
static const char * const cdjpeg_message_table[] = {
#include "../../cderror.h"
  NULL
};
#include "../../jversion.h"          
#include "../../jconfigint.h"
#define input_buf_size 20 //kb
#define inp_image_width 94  
#define inp_image_height 94


typedef struct decoder_manager
{
    unsigned long in_buf_sz;
    unsigned char *out_buf; //12 times size of image
    unsigned long out_buf_sz;
    JDIMENSION output_width;
    JDIMENSION output_height;
    int out_col_comp;
    J_COLOR_SPACE out_color_space;
    
}decoder_context;
int decode_jpeg(unsigned char *in_buf, decoder_context *mgr, J_COLOR_SPACE color);
