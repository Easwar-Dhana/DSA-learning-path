#include <stdio.h>
#include <string.h>

/*
    In ASCII:

        'A' = 65

        'a' = 97

        Difference = 32

    So:
    'A' + 32 = 'a', 'B' + 32 = 'b', and so on.

    You must ensure the character is in uppercase range:

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  (or)  ch = ch + ('a' - 'A');
    }
*/

/**
 * Function: valid_anagram
 * -----------------------
 * Checks whether two strings are anagrams of each other (lowercase only).
 *
 * Parameters:
 *   s1 - First input string
 *   s2 - Second input string
 *
 * Returns:
 *   1 if strings are anagrams, 0 otherwise.
 */
int valid_anagram(const char* s1, const char* s2) {
    int freq[26] = {0};  // Only 26 lowercase English letters

    // Step 1: Check if lengths match
    if (strlen(s1) != strlen(s2)) {
        return 0;
    }

    // Step 2: Count characters in s1 and subtract for s2
    for (int i = 0; s1[i] != '\0'; i++) {
        freq[s1[i] - 'a']++;   // increment count for s1
        freq[s2[i] - 'a']--;   // decrement count for s2
    }

    // Step 3: Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return 0;
    }

    return 1;
}
