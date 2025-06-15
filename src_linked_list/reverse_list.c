#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

/**
 * Function: reverse_list
 * ----------------------
 * Reverses a singly linked list.
 *
 * @param head: A pointer to the head node of the singly linked list.
 *
 * @return: A pointer to the new head node of the reversed list.
 */

Node_t* reverse_list(Node_t* head) {
    
    // Initialize current pointer to the head of the list.
    Node_t* curr = head;

    // prev will eventually become the new head; start as NULL.
    Node_t* prev = NULL;

    // next is used to temporarily store the next node during traversal.
    Node_t* next = NULL;

    /**
     * Traverse through the list and reverse the links.
     * At each step:
     * 1. Store the next node (curr->next).
     * 2. Reverse the current node's pointer to point to the previous node.
     * 3. Move prev to curr, and curr to next to proceed.
     */
    while (curr) {
        next = curr->next;     // Step 1: Save next node
        curr->next = prev;     // Step 2: Reverse the link
        prev = curr;           // Step 3a: Move prev forward
        curr = next;           // Step 3b: Move curr forward
    }

    // At the end, prev points to the new head of the reversed list.
    return prev;
}
