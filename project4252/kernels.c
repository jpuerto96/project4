/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

 */
team_t team = {
    "dkiselevjpuerto",              /* Team name */

    "Daniel Kiselev",     /* First member full name */
    "dkiselev@u.rochester.edu",  /* First member email address */

    "Juan Puerto",                   /* Second member full name (leave blank if none) */
    "jpuerto@u.rochester.edu"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst)
{
	int i, j;
	int dst_index_plus_i, dst_index, dim_mult;
	dim_mult = dim*dim - dim;
	int tmp_i, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32;

        for (i = 0; i < dim; i+=32) {
		tmp_i = i;
                i3 = ++tmp_i*dim;
                i8 = ++tmp_i*dim;
                i10 = ++tmp_i*dim;
                i15 = ++tmp_i*dim;
                i16 = ++tmp_i*dim;
                i17 = ++tmp_i*dim;
                i18 = ++tmp_i*dim;
                i19 = ++tmp_i*dim;
                i20 = ++tmp_i*dim;
                i21 = ++tmp_i*dim;
                i22 = ++tmp_i*dim;
                i23 = ++tmp_i*dim;
                i24 = ++tmp_i*dim;
                i25 = ++tmp_i*dim;
                i26 = ++tmp_i*dim;
                i27 = ++tmp_i*dim;
                i28 = ++tmp_i*dim;
                i29 = ++tmp_i*dim;
                i30 = ++tmp_i*dim;
                i31 = ++tmp_i*dim;
                i32 = ++tmp_i*dim;
                for (j = 0; j < dim; j++) {
                        dst_index = dim_mult - dim*j;
                        dst_index_plus_i = dst_index + i;
                        dst[dst_index_plus_i++] = src[i * dim + j];
                        dst[dst_index_plus_i++] = src[i2 + j];
                        dst[dst_index_plus_i++] = src[i3 + j];
                        dst[dst_index_plus_i++] = src[i4 + j];
                        dst[dst_index_plus_i++] = src[i5 + j];
                        dst[dst_index_plus_i++] = src[i6 + j];
                        dst[dst_index_plus_i++] = src[i7 + j];
                        dst[dst_index_plus_i++] = src[i8 + j];
                        dst[dst_index_plus_i++] = src[i9 + j];
                        dst[dst_index_plus_i++] = src[i10 + j];
                        dst[dst_index_plus_i++] = src[i11 + j];
                        dst[dst_index_plus_i++] = src[i12 + j];
                        dst[dst_index_plus_i++] = src[i13 + j];
                        dst[dst_index_plus_i++] = src[i14 + j];
                        dst[dst_index_plus_i++] = src[i15 + j];
                        dst[dst_index_plus_i++] = src[i16 + j];
                        dst[dst_index_plus_i++] = src[i17 + j];
                        dst[dst_index_plus_i++] = src[i18 + j];
                        dst[dst_index_plus_i++] = src[i19 + j];
                        dst[dst_index_plus_i++] = src[i20 + j];
                        dst[dst_index_plus_i++] = src[i21 + j];
                        dst[dst_index_plus_i++] = src[i22 + j];
                        dst[dst_index_plus_i++] = src[i23 + j];
                        dst[dst_index_plus_i++] = src[i24 + j];
                        dst[dst_index_plus_i++] = src[i25 + j];
                        dst[dst_index_plus_i++] = src[i26 + j];
                        dst[dst_index_plus_i++] = src[i27 + j];
                        dst[dst_index_plus_i++] = src[i28 + j];
                        dst[dst_index_plus_i++] = src[i29 + j];
                        dst[dst_index_plus_i++] = src[i30 + j];
                        dst[dst_index_plus_i++] = src[i31 + j];
                        dst[dst_index_plus_i++] = src[i32 + j];
                }
        }
}
/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *********************************************************************/

{
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

 */
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

 */
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

 */
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

 */
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
{
}


 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}
