#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>


/**
 * Detects if there is a cycle in the linked list using Floyd's Cycle Detection Algorithm.
 *
 * @param head Pointer to the head of the list.
 * @return true if a cycle is detected, false otherwise.
 */
bool detect_cycle(Node_t* head)
{
    if (!head) return false;

    Node_t* slow = head;
    Node_t* fast = head;

    // Traverse the list with two pointers
    while (fast && fast->next) {
        slow = slow->next;           // moves 1 step
        fast = fast->next->next;     // moves 2 steps

        // If they meet, cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If we exit loop, no cycle
    return false;
}