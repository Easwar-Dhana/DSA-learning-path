

typedef struct Node
{
    /* data of a node */
    int val;
    
    /* Pointer to next node */
    struct Node *next;

} Node_t;


Node_t* reverse_list(Node_t* head);