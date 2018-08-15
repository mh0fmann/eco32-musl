/*
 * set the new thead local storage in $27
 */

.global __set_thread_area
//int __set_thread_area(void* p);
__set_thread_area:
	ori $27,$4,0
    ori $2,$0,0
	jr $31
