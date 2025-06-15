#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>



/**
 * Creates a new node with given data
 */
Node_t* create_node(int data) {
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * Removes the N-th node from the end of the list (1-based index).
 * By moving the fast pointer n steps ahead, the slow pointer ends up just before the target node. 
 * This makes deletion simple and avoids needing a length counter.
 */
Node_t* remove_nth_node_from_end(Node_t* head, int n) {
    // Create dummy node to handle edge cases (like deleting the head)
    Node_t* dummy = create_node(0);
    dummy->next = head;

    Node_t *fast = dummy, *slow = dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast->next != NULL) {
            fast = fast->next;
        } else {
            // n is larger than list length
            free(dummy);
            return head;
        }
    }

    // Move both pointers until fast->next is NULL (i.e end of list)
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the target node
    Node_t* node_to_delete = slow->next;
    if (node_to_delete != NULL) {
        slow->next = node_to_delete->next;
        free(node_to_delete);
    }

    Node_t* new_head = dummy->next;
    free(dummy);
    return new_head;
}
