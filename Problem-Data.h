/*==============================================================================
Project: Linear programming by deep neural network
Theme: Visualization of Linear Programming Problem (ViLiPP)
Module: Problem-Data.h (Problem Data)
Prefix: PD
Author: Nikolay A. Olkhovsky
This source code is developed based on the BSF skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#include "Problem-Types.h"			// Problem Parameters 
using namespace std;
//========================== Problem variables ====================================
static int				PD_n;		// Space dimension
static int				PD_m;		// Number of inequalities
static PT_integer_T		PD_K;		// Number of receptive fied points
static PT_integer_T		PD_id;		// Number of current precedent
static PT_integer_T		PD_problemsNumber;
static PT_integer_T		PD_currentProblem;
static PT_integer_T		PD_tracesNumber;
static PT_integer_T		PD_currentTrace;
static PT_integer_T		PD_testSum;
static PT_integer_T		PD_read_state;	// State of problem trace processing
static bool				PD_initState;	// Flag to initial state when parameter is not set
//========================== Problem data structures ==============================
static PT_matrix_T PD_A;	// Matrix of the system Ax <= b
static PT_column_T PD_b;	// Column of the constant terms of the system Ax <= b
static PT_vector_T PD_c;	// Coefficients of the objective function <c,x>
static PT_matrix_T PD_E;	// Matrix of vectors e(i) forming basis othogonal to objective function
static PT_vector_T PD_g;	// Point of retina
static PT_vector_T PD_z;	// Center of retina
static PT_vector_T PD_nextPoint;	// Next point in the trace
static PT_vector_T PD_answerVector;	// Answer for the precedent

#ifdef PP_IMAGE_OUT
static PT_image_T PD_I; // Retina
#endif

#ifdef PP_RECEPTIVE_FIELD_OUT
static PT_field_T PD_field;
#endif
//========================== Files ================================================
static FILE* PD_stream_lppFile;
static string PD_lppFilename; /* LPP file in the following format:
------------ begin of file -------------
numOfProblems
m n
A_11 A_12 ... A_1n b_1
A_21 A_22 ... A_2n b_2
...
A_m1 A_m2 ... A_mn b_m
c_1 c_2 ... c_n
...
------------ end of file----------------*/
static FILE* PD_stream_traceFile;
static string PD_traceFilename; /* TRACE file in the following format:
------------ begin of file -------------
numOfTraces
m n
A_11 A_12 ... A_1n b_1
A_21 A_22 ... A_2n b_2
...
A_m1 A_m2 ... A_mn b_m
...
------------ end of file----------------*/
static FILE* PD_stream_outFile;
static string PD_outFilename;

static FILE* PD_stream_retFile;
static string PD_retFilename; /* OUT file in the following format:
------------ begin of file -------------
numOfRetinas
m n
R_1 R_2 ... R_n
...
------------ end of file----------------*/