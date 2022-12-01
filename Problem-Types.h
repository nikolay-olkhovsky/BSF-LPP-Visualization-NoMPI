/*==============================================================================
Project: LiFe
Theme: Apex Method
Module: Problem-Types.h (BSF Types)
Prefix: PT
Author: Leonid B. Sokolinsky
This source code has been produced with using BSF-skeleton
==============================================================================*/			
#pragma once
#include "Problem-Include.h"		// Problem "Include" Files
#include "Problem-Parameters.h"		// Problem Parameters 
//=========================== Problem Types =========================
typedef double			PT_float_T;
typedef int				PT_integer_T;
typedef PT_float_T		PT_vector_T[PP_MAX_N];
typedef PT_vector_T		PT_matrix_T[PP_MAX_M];
//typedef PT_float_T	PT_point_T[PP_MAX_N];
typedef PT_float_T		PT_column_T[PP_MAX_M];

#ifdef PP_IMAGE_OUT
typedef PT_float_T* PT_image_T;
#endif

#ifdef PP_RECEPTIVE_FIELD_OUT
typedef PT_float_T** PT_field_T;
#endif