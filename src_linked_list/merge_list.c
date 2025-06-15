#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>


/**
 * Recursively merges two sorted linked lists.
 *
 * @param head1 Pointer to the head of the first sorted list.
 * @param head2 Pointer to the head of the second sorted list.
 * @return Pointer to the head of the merged sorted list.
 */
Node_t* merge_sorted_list(Node_t* head1, Node_t* head2) {

    // Base cases: if one list is empty, return the other
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    // Recursively merge based on smaller value
    if (head1->data <= head2->data) 
    {
        head1->next = merge_sorted_list(head1->next, head2);
        return head1;
    } 

    else 
    {
        head2->next = merge_sorted_list(head1, head2->next);
        return head2;
    }
}