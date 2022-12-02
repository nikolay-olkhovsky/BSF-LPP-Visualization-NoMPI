/*==============================================================================
Project: LiFe
Theme: Apex Method
Module: Problem-bsfTypes.h (Predefined BSF Problem Types)
Prefix: PT_bsf
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/
#pragma once
#include "Problem-Types.h"		// Problem Types 
//=========================== BSF Types =========================
struct PT_bsf_parameter_T {		// Type of Parameter for workers (current approximation)
	PT_integer_T k;
	int state;
};

struct PT_bsf_mapElem_T {		// Type of map-list elements
	int inequalityNo;
};

struct PT_bsf_reduceElem_T {	// Type of reduce-list elements for Job 0 (default)	
	PT_float_T objectiveDistance;
};

struct PT_bsf_reduceElem_T_1 {	// Type of reduce-list elements for Job 1
	bool pointIn;
};

struct PT_bsf_reduceElem_T_2 {	// Type of reduce-list elements for Job 2
	bool pointIn;
};

struct PT_bsf_reduceElem_T_3 {	// Type of reduce-list elements for Job 3
// Not used
};