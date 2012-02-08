/*
 * readkeys.c
 *
 *  Created on: Feb 8, 2012
 *      Author: pfl
 */


// Allways include the matching header file
#include "readkeys.h"


int ReadKeys(int RawKeys)
{
	static int key_count[MAXbit-1] = { 0,0,0,0,0,0,0,0 };

	int loop_counter;

	for (loop_counter=0; loop_counter<MAXbit; loop_counter++) {
		if( RawKeys & (1 << loop_counter)) {
			key_count[ loop_counter ] = key_count[ loop_counter ]+1;
		}
		else {
			key_count[ loop_counter ] = 0;
		}
	}

	for (loop_counter=0; loop_counter<MAXbit; loop_counter++) {
		if (key_count[ loop_counter ] > 5) {
			key_count[ loop_counter ] = 0;
				return loop_counter;
			}
	}


	//	if (RawKeys == 1 << KEY0bit) {
	//
	//		if (key0_count == 5)
	//		{
	//			return KEY0_EVENT;
	//		}
	//		key0_count++;
	//	}
	//	if (RawKeys == 1 << KEY1bit) {
	//
	//		if (key1_count == 5)
	//		{
	//			return KEY1_EVENT;
	//		}
	//		key1_count++;
	//	}

	// Allways return even if not keypress was detected, dont wait for it !
	return NO_EVENT;
}


