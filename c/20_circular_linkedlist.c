#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *createNode(int data) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        perror("Could not allocate a node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

static int listLength(const Node *head) {
    if (head == NULL) {
        return 0;
    }

    int count = 1;
    const Node *current = head->next;
    while (current != head) {
        count++;
        current = current->next;
    }
    return count;
}

static void display(const Node *head) {
    if (head == NULL) {
        puts("(empty list)");
        return;
    }

    const Node *current = head;
    int index = 0;
    do {
        printf("Index %d: %d\n", index, current->data);
        current = current->next;
        index++;
    } while (current != head);
}

// Insert at the front. The last node must point to the new head.
static Node *insertAtBeginning(Node *head, int data) {
    Node *node = createNode(data);
    if (head == NULL) {
        node->next = node;
        return node;
    }

    Node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    node->next = head;
    tail->next = node;
    return node;
}

static Node *insertAtEnd(Node *head, int data) {
    if (head == NULL) {
        return insertAtBeginning(NULL, data);
    }

    Node *node = createNode(data);
    Node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = node;
    node->next = head;
    return head;
}

// Index is zero-based; insertion at index == length appends to the list.
static Node *insertAtIndex(Node *head, int index, int data) {
    int length = listLength(head);
    if (index < 0 || index > length) {
        fprintf(stderr, "Insert index %d is out of range.\n", index);
        return head;
    }
    if (index == 0) {
        return insertAtBeginning(head, data);
    }

    Node *previous = head;
    for (int i = 1; i < index; i++) {
        previous = previous->next;
    }
    Node *node = createNode(data);
    node->next = previous->next;
    previous->next = node;
    return head;
}

// Inserts after the first node containing targetValue.
static Node *insertAfterValue(Node *head, int targetValue, int data) {
    if (head == NULL) {
        fprintf(stderr, "Cannot insert after %d: the list is empty.\n", targetValue);
        return head;
    }

    Node *current = head;
    do {
        if (current->data == targetValue) {
            Node *node = createNode(data);
            node->next = current->next;
            current->next = node;
            return head;
        }
        current = current->next;
    } while (current != head);

    fprintf(stderr, "Value %d was not found.\n", targetValue);
    return head;
}

static Node *deleteFirst(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    Node *newHead = head->next;
    tail->next = newHead;
    free(head);
    return newHead;
}

static Node *deleteLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node *previous = head;
    Node *current = head->next;
    while (current->next != head) {
        previous = current;
        current = current->next;
    }
    previous->next = head;
    free(current);
    return head;
}

// Index is zero-based; valid deletion indexes are 0 through length - 1.
static Node *deleteAtIndex(Node *head, int index) {
    int length = listLength(head);
    if (index < 0 || index >= length) {
        fprintf(stderr, "Delete index %d is out of range.\n", index);
        return head;
    }
    if (index == 0) {
        return deleteFirst(head);
    }

    Node *previous = head;
    for (int i = 1; i < index; i++) {
        previous = previous->next;
    }
    Node *removed = previous->next;
    previous->next = removed->next;
    free(removed);
    return head;
}

// Deletes the first node containing value. If absent, the list is unchanged.
static Node *deleteByValue(Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == value) {
        return deleteFirst(head);
    }

    Node *previous = head;
    Node *current = head->next;
    while (current != head && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == head) {
        fprintf(stderr, "Value %d was not found.\n", value);
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

static void freeList(Node *head) {
    if (head == NULL) {
        return;
    }

    Node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = NULL;

    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    Node *head = NULL;
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 13);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 1);

    puts("Starting circular list:");
    display(head);

    puts("\nInsert 54 at the beginning:");
    head = insertAtBeginning(head, 54);
    display(head);

    puts("\nInsert 99 at the end:");
    head = insertAtEnd(head, 99);
    display(head);

    puts("\nInsert 25 at index 3:");
    head = insertAtIndex(head, 3, 25);
    display(head);

    puts("\nInsert 37 after the first node containing 13:");
    head = insertAfterValue(head, 13, 37);
    display(head);

    puts("\nDelete the first node:");
    head = deleteFirst(head);
    display(head);

    puts("\nDelete the last node:");
    head = deleteLast(head);
    display(head);

    puts("\nDelete the node at index 2:");
    head = deleteAtIndex(head, 2);
    display(head);

    puts("\nDelete the first node containing 25:");
    head = deleteByValue(head, 25);
    display(head);

    freeList(head);
    return EXIT_SUCCESS;
}
