typedef unsigned char buf;
typedef buf *buf_ptr;
typedef buf_ptr *buf_ptr1; // done according to JSAMPARRAY
void jsimd_idct_test(short *coef_block, buf_ptr1 output_buf);
