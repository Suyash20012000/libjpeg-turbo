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

#define img_ht 96
#define img_wdth 96

typedef struct encoder_manager
{
unsigned long image_height;
unsigned long image_width;
unsigned long out_buf_sz;
unsigned char *output_buffer;
}encoder_context;

int encode_greyscale(unsigned char *in_buf, encoder_context mgr , unsigned long *out_buf_sz);