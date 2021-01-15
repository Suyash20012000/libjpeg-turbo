#include "../../../../simd/esp32/jsimd.h"
#include <stdlib.h>

short dct_table[64]={1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1,  
                     1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1, 
                     1 , 1 , 1 , 1 , 1 , 2 , 2 , 1 , 1 , 1 , 1 , 1,
                     1 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2,
                     1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 2 , 2 , 2,
                     2 , 2 , 2 , 2};

typedef unsigned char buf;
typedef buf *buf_ptr;
typedef buf_ptr *buf_ptr1;

void jsimd_idct_test (short *coef_block, buf_ptr1 output_buf)
{

    //gettimeofday(&start,NULL);
    long tmp0, tmp1, tmp2, tmp3;
    long tmp10, tmp11, tmp12, tmp13;
    long z1, z2, z3, z4, z5;
    short *inptr;
    short *quantptr;
    int *wsptr;
    unsigned char *outptr;
    unsigned char *range_limit = malloc(128);
    int ctr;
    int workspace[64];      /* buffers data between passes */


    /* Pass 1: process columns from input, store into work array. */
    /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
    /* furthermore, we scale the results by 2**2. */

    inptr = coef_block;
    quantptr =dct_table;

    wsptr = workspace;
    for (ctr = 8; ctr > 0; ctr--) {
        /* Due to quantization, we will usually find that many of the input
         * coefficients are zero, especially the AC terms.  We can exploit this
         * by short-circuiting the IDCT calculation for any column in which all
         * the AC terms are zero.  In that case each output is equal to the
         * DC coefficient (with scale factor as needed).
         * With typical images and quantization tables, half or more of the
         * column DCT calculations can be simplified this way.
         */

        if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 &&
                inptr[8 * 3] == 0 && inptr[8 * 4] == 0 &&
                inptr[8 * 5] == 0 && inptr[8 * 6] == 0 &&
                inptr[8 * 7] == 0) {
            /* AC terms all zero */
            int dcval = LEFT_SHIFT(DEQUANTIZE_ESP32(inptr[8 * 0],
                                                    quantptr[8 * 0]), 2);

            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval;

            inptr++;                  /* advance pointers to next column */
            quantptr++;
            wsptr++;
            continue;
        }
        /* Even part: reverse the even part of the forward DCT. */
        /* The rotator is sqrt(2)*c(-6). */
        z2 = DEQUANTIZE_ESP32(inptr[8 * 2], quantptr[8 * 2]); 

        z3 = DEQUANTIZE_ESP32(inptr[8 * 6], quantptr[8 * 6]);

        z1 = MULTIPLY_ESP32(z2 + z3, FIX1_0_541196100);

        tmp2 = z1 + MULTIPLY_ESP32(z3, -FIX1_1_847759065);
        tmp3 = z1 + MULTIPLY_ESP32(z2, FIX1_0_765366865);

        z2 = DEQUANTIZE_ESP32(inptr[8 * 0], quantptr[8 * 0]);
        z3 = DEQUANTIZE_ESP32(inptr[8 * 4], quantptr[8 * 4]);

        tmp0 = LEFT_SHIFT(z2 + z3, 13);
        tmp1 = LEFT_SHIFT(z2 - z3, 13);

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        /* Odd part per figure 8; the matrix is unitary and hence its
         * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
         */

        tmp0 = DEQUANTIZE_ESP32(inptr[8 * 7], quantptr[8 * 7]);
        tmp1 = DEQUANTIZE_ESP32(inptr[8 * 5], quantptr[8 * 5]);
        tmp2 = DEQUANTIZE_ESP32(inptr[8 * 3], quantptr[8 * 3]);
        tmp3 = DEQUANTIZE_ESP32(inptr[8 * 1], quantptr[8 * 1]);

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

        wsptr[8 * 0] = (int)DESCALE_ESP32(tmp10 + tmp3, 13 - 2);
        wsptr[8 * 7] = (int)DESCALE_ESP32(tmp10 - tmp3, 13 - 2);
        wsptr[8 * 1] = (int)DESCALE_ESP32(tmp11 + tmp2, 13 - 2);
        wsptr[8 * 6] = (int)DESCALE_ESP32(tmp11 - tmp2, 13 - 2);
        wsptr[8 * 2] = (int)DESCALE_ESP32(tmp12 + tmp1, 13 - 2);
        wsptr[8 * 5] = (int)DESCALE_ESP32(tmp12 - tmp1, 13 - 2);
        wsptr[8 * 3] = (int)DESCALE_ESP32(tmp13 + tmp0, 13 - 2);
        wsptr[8 * 4] = (int)DESCALE_ESP32(tmp13 - tmp0, 13 - 2);

        inptr++;                    /* advance pointers to next column */
        quantptr++;
        wsptr++;
    }

    /* Pass 2: process rows from work array, store into output array. */
    /* Note that we must descale the results by a factor of 8 == 2**3, */
    /* and also undo the 2 scaling. */

    wsptr = workspace;
    
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + 0;
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
            unsigned char dcval = range_limit[(int)DESCALE_ESP32((long)wsptr[0],
                                        2 + 3) & RANGE_MASK_ESP32];

            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;

            wsptr += 8;         /* advance pointer to next row */
            continue;
        }
#endif

        /* Even part: reverse the even part of the forward DCT. */
        /* The rotator is sqrt(2)*c(-6). */

        z2 = (long)wsptr[2];
        z3 = (long)wsptr[6];

        z1 = MULTIPLY_ESP32(z2 + z3, FIX1_0_541196100);
        tmp2 = z1 + MULTIPLY_ESP32(z3, -FIX1_1_847759065);
        tmp3 = z1 + MULTIPLY_ESP32(z2, FIX1_0_765366865);

        tmp0 = LEFT_SHIFT((long)wsptr[0] + (long)wsptr[4], 13);
        tmp1 = LEFT_SHIFT((long)wsptr[0] - (long)wsptr[4], 13);

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        /* Odd part per figure 8; the matrix is unitary and hence its
         * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
         */

        tmp0 = (long)wsptr[7];
        tmp1 = (long)wsptr[5];
        tmp2 = (long)wsptr[3];
        tmp3 = (long)wsptr[1];

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

        wsptr += 8;           /* advance pointer to next row */
    }
    // printing the output so as to view it and compare it with orignal generated array test_arr.
   int z;
   for(z=0;z<64;z++)
   {
       printf(" %d ",outptr[z]);
   } 
   printf("end");    
}
