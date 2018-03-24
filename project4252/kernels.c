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
    //naive_rotate(dim, src, dst);
	//RIDX(i, j, N) = i * N + j

	//RIDX(i, j, dim)  = i*N + j
	//RIDX(dim-1-j, i, dim) = (dim-1-j)*dim + i
	//dim*dim - dim - dim*j + i
	//dim^2 - jdim - dim + i
	//dim*(j+1) = dim*j + dim
	//dimj
	int i, j;

	int dst_index;
	int dst_index_2;
	int dst_index_3;
	int dst_index_4;
	int dst_index_5;
	int dst_index_6;
	int dst_index_7;
	int dst_index_8;
	int dst_index_9;
	int dst_index_10;
	int dst_index_11;
	int dst_index_12;
	int dst_index_13;
	int dst_index_14;
	int dst_index_15;
	int dst_index_16;
	int dst_index_17;
	int dst_index_18;
	int dst_index_19;
	int dst_index_20;
	int dst_index_21;
	int dst_index_22;
	int dst_index_23;
	int dst_index_24;
	int dst_index_25;
	int dst_index_26;
	int dst_index_27;
	int dst_index_28;
	int dst_index_29;
	int dst_index_30;
	int dst_index_31;
	int dst_index_32;

	int dimsq_minus_dim = (dim*dim)-dim;
	int dim_times_2 = dim*2;
	int dim_times_3 = dim*3;
	int dim_times_4 = dim*4;
	int dim_times_5 = dim*5;
	int dim_times_6 = dim*6;
	int dim_times_7 = dim*7;
	int dim_times_8 = dim*8;
	int dim_times_9 = dim*9;
	int dim_times_10 = dim*10;
	int dim_times_11 = dim*11;
	int dim_times_12 = dim*12;
	int dim_times_13 = dim*13;
	int dim_times_14 = dim*14;
	int dim_times_15 = dim*15;
	int dim_times_16 = dim*16;
	int dim_times_17 = dim*17;
	int dim_times_18 = dim*18;
	int dim_times_19 = dim*19;
	int dim_times_20 = dim*20;
	int dim_times_21 = dim*21;
	int dim_times_22 = dim*22;
	int dim_times_23 = dim*23;
	int dim_times_24 = dim*24;
	int dim_times_25 = dim*25;
	int dim_times_26 = dim*26;
	int dim_times_27 = dim*27;
	int dim_times_28 = dim*28;
	int dim_times_29 = dim*29;
	int dim_times_30 = dim*30;
	int dim_times_31 = dim*31;
	int dimsq_minus_dim_plus_i, idim, idim_plus_j, dim_times_j;

	for (i = 0; i < dim; i++){
		dimsq_minus_dim_plus_i = dimsq_minus_dim + i;
		idim = i*dim;
		for (j = 0; j < dim; j+=32){
			idim_plus_j = idim+j;

			dst_index = dimsq_minus_dim_plus_i - (dim*j);

			dst[dst_index] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
                        dst[dst_index+=dim] = src[idim_plus_j++];
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
    naive_smooth(dim, src, dst);
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

