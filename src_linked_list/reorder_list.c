#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>


void reorder_list(Node_t** head_ref){

	if(*head_ref == NULL || (*head_ref)->next == nullptr) return;

	/* finding the middle of the list using fast and slow pointers,
	 traverse slow once and fast twice*/

	Node_t* slow = *head_ref, *fast = *head_ref;

	// step1 - find the middle
	while(fast->next && fast->next->next){

		slow = slow->next;
		fast = fast->next->next;
	}

	// step2 - reverse the second half
	Node_t* second_half = reverse_list(slow->next);
	slow->next = NULL; // brake first half


	// Step3 - Merge the two half alternatively
	Node_t* first_half = *head_ref;

    Node_t* temp1, *temp2;
	while(second_half){

		// temp points to next of each half to preserve the original link intact when you switch links alternatively. save forward points.
		temp1 = first_half->next;
		temp2 = second_half->next;

		// merge links aternatively
		first_half->next = second_half;
		second_half->next = temp1;

		// move forward
		first_half = temp1;
		second_half = temp2;

	}

}