#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node_t;

Node_t *
create_node(int data)
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));

    if (new_node == NULL)
    {
        printf("memory is not allocated \n");
        exit(1);
    }
    new_node->val = data;
    new_node->next = NULL;

    return new_node;
}

void print_list(Node_t *node)
{
    // printf("value of node is %d\n", node);
    while (node)
    {
        printf("node data and addr is %d and %d\n and next addr is %d\n", node->val, &node->val, node->next);
        node = node->next;
    }
}

void min_value(Node_t *node)
{
    int min = node->val;
    Node_t *current_node = node->next;

    while (current_node)
    {
        if (current_node->val < min)
        {
            min = current_node->val;
        }
        current_node = current_node->next;
    }

    printf("min value is :- %d", min);
}

void add_node(Node_t **head, int data)
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    new_node->val = data;
    new_node->next = (*head);

    (*head) = new_node;
}

void delete_node(Node_t **head, int value)
{
    // is head is the one we are going to delete
    Node_t *temp = *head;
    Node_t *prev = NULL;

    if (temp && temp->val == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->val != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;

    free(temp);
}

Node_t *list_reverse(Node_t *node)
{

    Node_t *current = node;
    Node_t *prev = NULL;
    Node_t *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void detect_cycle(Node_t *head)
{
    Node_t *fast = head, *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            printf("cycle exists");
            return;
        }
    }

    printf("cycle doesn't exists");
}

Node_t *middle_list(Node_t *head)
{
    Node_t *fast = head, *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    Node_t *node1 = create_node(5);
    Node_t *node2 = create_node(7);
    Node_t *node3 = create_node(6);
    Node_t *node4 = create_node(2);
    Node_t *node5 = create_node(8);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // node4->next = node1;
    //  min_value(node1);
    //  add_node(&node1, 12);
    //  print_list(node1);
    //  delete_node(&node1, 5);

    print_list(node1);
    Node_t *reversed_list = list_reverse(node1);
    // print_list(reversed_list);

    // detect_cycle(node1);
    Node_t *middle_node = middle_list(node1);
    printf("middle node value is %d", middle_node->val);
}
