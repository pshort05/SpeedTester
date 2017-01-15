/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Paul Short @ 2012 paul@short-associates.com
 * 
 */

#define NUMBER_OF_RUNS  60

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <unistd.h>

int main()
{
    double dStart, dEnd;
    struct timeval tvCurrentTime, tvEndTime;
    int iReturn;
	long i;
	char szBuffer[1024];
	char *ptr = &szBuffer[1024];

	

	// get the program up to speed to get rid of any startup jitter
	for( i=0; i<NUMBER_OF_RUNS;i++ )
		memset( szBuffer, 0, sizeof(szBuffer) );

	// put some data into the buffer
	for ( i=0; i<1000; i++ )
		szBuffer[i]= 0x50;


	//==========================================================================
	//
	//			START Test # 1
	//
	//==========================================================================
	
    // Get the start time in Milliseconds
    iReturn = gettimeofday(&tvCurrentTime, NULL);
    dStart = (double)tvCurrentTime.tv_sec + (double)(tvCurrentTime.tv_usec/NUMBER_OF_RUNS);
	for ( i=0; i<NUMBER_OF_RUNS; i++ )
	{
		usleep(1000000);
	}
    iReturn = gettimeofday(&tvEndTime, NULL);
    dEnd = (double)tvEndTime.tv_sec + (double)(tvEndTime.tv_usec/NUMBER_OF_RUNS);
    printf( "1st Option Processed %d loops in %f seconds\n\n", NUMBER_OF_RUNS, dEnd-dStart); 


	//==========================================================================
	//
	//			START Test # 2
	//
	//==========================================================================

    // Get the start time in Milliseconds
    iReturn = gettimeofday(&tvCurrentTime, NULL);
    dStart = (double)tvCurrentTime.tv_sec + (double)(tvCurrentTime.tv_usec/NUMBER_OF_RUNS);
	for ( i=0; i<NUMBER_OF_RUNS; i++ )
	{
		sleep(1);
	}
    iReturn = gettimeofday(&tvEndTime, NULL);
    dEnd = (double)tvEndTime.tv_sec + (double)(tvEndTime.tv_usec/NUMBER_OF_RUNS);
    printf( "2nd Option Processed %d loops in %f seconds\n\n", NUMBER_OF_RUNS, dEnd-dStart); 

	return (0);
}
