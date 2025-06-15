#include<stdio.h>


#include <stdio.h>
#include <stdlib.h>

/**
 * Function: two_sum
 * -----------------
 * Finds two indices in the array whose elements sum to the target value.
 *
 * Parameters:
 *   a      - Pointer to the array of integers
 *   size   - Number of elements in the array
 *   target - Target sum to find
 *
 * Returns:
 *   Pointer to an array of two integers containing the indices.
 *   Returns NULL if no such pair exists.
 *   Note: Caller is responsible for freeing the returned array.
 */
int* two_sum(int* a, int size, int target) {
    int* result = (int*)malloc(2 * sizeof(int));  // dynamically allocated

    if (result == NULL) {
        return NULL;  // malloc failed
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] + a[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    free(result);
    return NULL;  // no valid pair found
}
