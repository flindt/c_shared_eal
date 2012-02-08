/*
 ============================================================================
 Name        : c_ReadKeys.c
 Author      : pfl
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum bitNumbers { KEY0bit, KEY1bit, KEY2bit, KEY3bit, KEY4bit, KEY5bit, KEY6bit, KEY7bit, MAXbit };
enum events {  KEY0_EVENT, KEY1_EVENT, KEY2_EVENT, KEY3_EVENT, KEY4_EVENT,NO_EVENT};

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

void testReadKeys(void)
{
	// Testing key0 only
	if ( ReadKeys(0x01) != NO_EVENT ) { printf(" failed on 1. call"); }
	else if ( ReadKeys(0x01) != NO_EVENT ) { printf(" failed on 2. call"); }
	else if ( ReadKeys(0x01) != NO_EVENT ) { printf(" failed on 3. call"); }
	else if ( ReadKeys(0x01) != NO_EVENT ) { printf(" failed on 4. call"); }
	else if ( ReadKeys(0x01) != NO_EVENT ) { printf(" failed on 5. call"); }
	else if ( ReadKeys(0x01) != KEY0_EVENT ) { printf(" failed on 6. call"); }
	// test key1 only
	else if ( ReadKeys(0x02) != NO_EVENT ) { printf(" failed on 7. call"); }
	else if ( ReadKeys(0x02) != NO_EVENT ) { printf(" failed on 8. call"); }
	else if ( ReadKeys(0x02) != NO_EVENT ) { printf(" failed on 9. call"); }
	else if ( ReadKeys(0x02) != NO_EVENT ) { printf(" failed on 10. call"); }
	else if ( ReadKeys(0x02) != NO_EVENT ) { printf(" failed on 11. call"); }
	else if ( ReadKeys(0x02) != KEY1_EVENT ) { printf(" failed on 12. call"); }
	// let go of keys
	else if ( ReadKeys(0x00) != NO_EVENT) { printf(" failed on 13. call"); }
	// test key0 and key1 at the same time
	else if ( ReadKeys(0x18) != NO_EVENT ) { printf(" failed on 14. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT ) { printf(" failed on 15. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT ) { printf(" failed on 16. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT ) { printf(" failed on 17. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT ) { printf(" failed on 18. call"); }
	else if ( ReadKeys(0x18) != KEY3_EVENT ) { printf(" failed on 19. call"); }
	else if ( ReadKeys(0x18) != KEY4_EVENT) { printf(" failed on 20. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT) { printf(" failed on 21. call"); }
	else if ( ReadKeys(0x18) != NO_EVENT) { printf(" failed on 22. call"); }
	else printf("passed !");
}

int main(void) {
	puts("Testing the readkeys function ..."); /* prints !!!Hello World!!! */
	testReadKeys();
	return EXIT_SUCCESS;
}












