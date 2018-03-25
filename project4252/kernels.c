/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following team struct
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

/*
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
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
                i2 = ++tmp_i*dim;
                i3 = ++tmp_i*dim;
                i4 = ++tmp_i*dim;
                i5 = ++tmp_i*dim;
                i6 = ++tmp_i*dim;
                i7 = ++tmp_i*dim;
                i8 = ++tmp_i*dim;
                i9 = ++tmp_i*dim;
                i10 = ++tmp_i*dim;
                i11 = ++tmp_i*dim;
                i12 = ++tmp_i*dim;
                i13 = ++tmp_i*dim;
                i14 = ++tmp_i*dim;
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
 *     registered test function.
 *********************************************************************/

void register_rotate_functions()
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate, rotate_descr);
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

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum *sum)
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/*
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */
static void accumulate_sum(pixel_sum *sum, pixel p)
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/*
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum)
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/*
 * avg - Returns averaged pixel value at (i,j)
 */
static pixel avg(int dim, int i, int j, pixel *src)
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++)
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++)
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst)
{
  int curr;
//i = 0,j = 0, = 0
  dst[0].red = (src[0].red + src[1].red + src[dim].red + src[dim + 1].red) / 4;
  dst[0].green = (src[0].green + src[1].green + src[dim].green + src[dim + 1].green) / 4;
  dst[0].blue = (src[0].blue + src[1].blue + src[dim].blue + src[dim + 1].blue) / 4;


//i = N-1, j = 0, = (dim - 1)*dim
  int dst1 = (dim - 1)*dim;
  dst[dst1].red = (src[(dim - 1)*dim].red + src[(dim - 1)*dim + 1].red + src[(dim - 2)*dim].red + src[(dim - 2)*dim + 1].red) / 4;
  dst[dst1].green = (src[(dim - 1)*dim].green + src[(dim - 1)*dim + 1].green + src[(dim - 2)*dim].green + src[(dim - 2)*dim + 1].green) / 4;
  dst[dst1].blue = (src[(dim - 1)*dim].blue + src[(dim - 1)*dim + 1].blue + src[(dim - 2)*dim].blue + src[(dim - 2)*dim + 1].blue) / 4;


//i = 0, j = N-1, = dim-1
  int dst2 = (dim - 1);
  dst[dst2].red = (src[dim - 1].red + src[dim - 2].red + src[dim * 2 - 1].red + src[dim * 2 - 2].red) / 4;
  dst[dst2].green = (src[dim - 1].green + src[dim - 2].green + src[dim * 2 - 1].green + src[dim * 2 - 2].green) / 4;
  dst[dst2].blue = (src[dim - 1].blue + src[dim - 2].blue + src[dim * 2 - 1].blue + src[dim * 2 - 2].blue) / 4;


//i = N-1, j = N-1, = N*N-1
//N^2 -N + N -1 = N^2 -1
  int dst3 =  dim * dim - 1;
  dst[dst3].red = (src[dim * dim - 1].red + src[dim * dim - 2].red + src[dim * (dim - 1) - 1].red + src[dim * (dim - 1) - 2].red) / 4;
  dst[dst3].green = (src[dim * dim - 1].green + src[dim * dim - 2].green + src[dim * (dim - 1) - 1].green + src[dim * (dim - 1) - 2].green) / 4;
  dst[dst3].blue = (src[dim * dim - 1].blue + src[dim * dim - 2].blue +  src[dim * (dim - 1) - 1].blue + src[dim * (dim - 1) - 2].blue) / 4;



//EDGE i = 1 to i = n-1 , J = 0
//left
  for (curr = dim; curr < (dim - 1)*dim; curr +=dim){
    dst[curr].red = (src[curr].red + src[curr-dim].red + src[curr+dim].red + src[curr+1].red + src[curr-dim + 1].red + src[curr+dim +1].red) / 6;
    dst[curr].green = (src[curr].green + src[curr-dim].green + src[curr+dim].green + src[curr+1].green + src[curr-dim + 1].green + src[curr+dim +1].green) / 6;
    dst[curr].blue = (src[curr].blue + src[curr-dim].blue + src[curr+dim].blue + src[curr+1].blue + src[curr-dim + 1].blue + src[curr+dim +1].blue) / 6;
  }
//EDGE j = 1 to j = n-1 , i = 0
//top
  for (int j = 1; j < dim - 1; j++){
      dst[j].red = (src[j].red + src[j - 1].red + src[j + 1].red + src[j + dim].red + src[j + 1 + dim].red + src[j - 1 + dim].red) / 6;
      dst[j].green = (src[j].green + src[j - 1].green + src[j + 1].green + src[j + dim].green + src[j + 1 + dim].green + src[j - 1 + dim].green) / 6;
      dst[j].blue = (src[j].blue + src[j - 1].blue + src[j + 1].blue + src[j + dim].blue + src[j + 1 + dim].blue + src[j - 1 + dim].blue) / 6;
  }
//EDGE j = 1 to j = n-1 , i = n-1
//bottom
for (curr = ((dim*dim)-dim +1) ; curr < ((dim*dim)-1); curr++){
    dst[curr].red = (src[curr].red + src[curr - 1].red + src[curr + 1].red + src[curr - dim].red + src[curr + 1 - dim].red + src[curr - 1 - dim].red) / 6;
    dst[curr].green = (src[curr].green + src[curr - 1].green + src[curr + 1].green + src[curr - dim].green + src[curr + 1 - dim].green + src[curr - 1 - dim].green) / 6;
    dst[curr].blue = (src[curr].blue + src[curr - 1].blue + src[curr + 1].blue + src[curr - dim].blue + src[curr + 1 - dim].blue + src[curr - 1 - dim].blue) / 6;

}

//EDGE i = 1 to i = n-1 , j = n-1
//right
for (curr = (dim)+dim-1; curr < ((dim*dim)-1); curr+=dim){
    dst[curr].red = (src[curr].red + src[curr - 1].red + src[curr - dim].red + src[curr + dim].red + src[curr - dim - 1].red + src[curr - 1 + dim].red) / 6;
    dst[curr].blue = (src[curr].blue + src[curr - 1].blue + src[curr - dim].blue + src[curr + dim].blue + src[curr - dim - 1].blue + src[curr - 1 + dim].blue) / 6;
    dst[curr].green = (src[curr].green + src[curr - 1].green + src[curr - dim].green + src[curr + dim].green + src[curr - dim - 1].green + src[curr - 1 + dim].green) / 6;
}

//REST

  for (i = dim; i < dim*dim - dim;  i+=dim)
  {
      for (j = 1; j < dim - 1; j++)
      {
          curr = i+j;
          dst[curr].red = (src[curr - dim -1].red + src[curr - dim].red + src[curr - dim + 1].red +  src[curr -1].red + src[curr].red + src[curr + 1].red
            + src[curr + dim -1].red + src[curr + dim].red + src[curr + dim + 1].red) / 9;
          dst[curr].green = (src[curr - dim -1].green + src[curr - dim].green + src[curr - dim + 1].green +  src[curr -1].green + src[curr].green + src[curr + 1].green
            + src[curr + dim -1].green + src[curr + dim].green + src[curr + dim + 1].green) / 9;
          dst[curr].blue = (src[curr - dim -1].blue + src[curr - dim].blue + src[curr - dim + 1].blue +  src[curr -1].blue + src[curr].blue + src[curr + 1].blue
            + src[curr + dim -1].blue + src[curr + dim].blue + src[curr + dim + 1].blue) / 9;
      }
  }
}


/*********************************************************************
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}
