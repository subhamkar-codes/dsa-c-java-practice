#include <stdio.h>
#include <stdlib.h>

#define MAX_TRAVERSAL_NODES 100

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
    size_t size;
} DoublyLinkedList;

static void initializeList(DoublyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

static Node *createNode(int data) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        perror("Could not allocate a node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Link a new node between left and right. Either neighbor may be NULL.
static void linkBetween(DoublyLinkedList *list, Node *left, Node *right, int data) {
    Node *node = createNode(data);
    node->prev = left;
    node->next = right;

    if (left != NULL) {
        left->next = node;
    } else {
        list->head = node;
    }

    if (right != NULL) {
        right->prev = node;
    } else {
        list->tail = node;
    }
    list->size++;
}

// Find a zero-based index, starting from whichever end is closer.
static Node *nodeAtIndex(const DoublyLinkedList *list, size_t index) {
    if (index < list->size / 2) {
        Node *current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    Node *current = list->tail;
    for (size_t i = list->size - 1; i > index; i--) {
        current = current->prev;
    }
    return current;
}

static Node *firstNodeWithValue(const DoublyLinkedList *list, int value) {
    Node *current = list->head;
    for (size_t visited = 0; current != NULL && visited < list->size; visited++) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

static int insertAtBeginning(DoublyLinkedList *list, int data) {
    linkBetween(list, NULL, list->head, data);
    return 1;
}

static int insertAtEnd(DoublyLinkedList *list, int data) {
    linkBetween(list, list->tail, NULL, data);
    return 1;
}

// Valid insertion indexes are 0 through size; size means append.
static int insertAtIndex(DoublyLinkedList *list, int index, int data) {
    if (index < 0 || (size_t)index > list->size) {
        fprintf(stderr, "Insert index %d is out of range.\n", index);
        return 0;
    }
    if ((size_t)index == list->size) {
        return insertAtEnd(list, data);
    }

    Node *right = nodeAtIndex(list, (size_t)index);
    linkBetween(list, right->prev, right, data);
    return 1;
}

// Insert after the first node containing targetValue.
static int insertAfterValue(DoublyLinkedList *list, int targetValue, int data) {
    Node *target = firstNodeWithValue(list, targetValue);
    if (target == NULL) {
        fprintf(stderr, "Value %d was not found; nothing was inserted.\n", targetValue);
        return 0;
    }
    linkBetween(list, target, target->next, data);
    return 1;
}

static int deleteNode(DoublyLinkedList *list, Node *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);
    list->size--;
    return 1;
}

static int deleteFirst(DoublyLinkedList *list) {
    if (list->head == NULL) {
        return 0;
    }
    return deleteNode(list, list->head);
}

static int deleteLast(DoublyLinkedList *list) {
    if (list->tail == NULL) {
        return 0;
    }
    return deleteNode(list, list->tail);
}

static int deleteAtIndex(DoublyLinkedList *list, int index) {
    if (index < 0 || (size_t)index >= list->size) {
        fprintf(stderr, "Delete index %d is out of range.\n", index);
        return 0;
    }
    return deleteNode(list, nodeAtIndex(list, (size_t)index));
}

// Delete the first node containing value.
static int deleteByValue(DoublyLinkedList *list, int value) {
    Node *node = firstNodeWithValue(list, value);
    if (node == NULL) {
        fprintf(stderr, "Value %d was not found; nothing was deleted.\n", value);
        return 0;
    }
    return deleteNode(list, node);
}

// Both traversals stop at the list size and at an absolute display limit.
static void displayForward(const DoublyLinkedList *list) {
    if (list->head == NULL) {
        puts("(empty list)");
        return;
    }

    const Node *current = list->head;
    size_t limit = list->size < MAX_TRAVERSAL_NODES
        ? list->size : MAX_TRAVERSAL_NODES;
    size_t visited = 0;
    while (current != NULL && visited < limit) {
        printf("%d ", current->data);
        current = current->next;
        visited++;
    }
    if (current != NULL) {
        printf("... [traversal stopped by the size/safety limit]");
    }
    putchar('\n');
}

static void displayBackward(const DoublyLinkedList *list) {
    if (list->tail == NULL) {
        puts("(empty list)");
        return;
    }

    const Node *current = list->tail;
    size_t limit = list->size < MAX_TRAVERSAL_NODES
        ? list->size : MAX_TRAVERSAL_NODES;
    size_t visited = 0;
    while (current != NULL && visited < limit) {
        printf("%d ", current->data);
        current = current->prev;
        visited++;
    }
    if (current != NULL) {
        printf("... [traversal stopped by the size/safety limit]");
    }
    putchar('\n');
}

static void showList(const DoublyLinkedList *list) {
    printf("Forward:  ");
    displayForward(list);
    printf("Backward: ");
    displayBackward(list);
}

static void clearList(DoublyLinkedList *list) {
    Node *current = list->head;
    size_t remaining = list->size;
    while (current != NULL && remaining > 0) {
        Node *next = current->next;
        free(current);
        current = next;
        remaining--;
    }
    initializeList(list);
}

int main(void) {
    DoublyLinkedList list;
    initializeList(&list);

    for (int value = 1; value <= 5; value++) {
        insertAtEnd(&list, value);
    }
    puts("Starting list:");
    showList(&list);

    puts("\nInsert 0 at the beginning:");
    insertAtBeginning(&list, 0);
    showList(&list);

    puts("\nInsert 6 at the end:");
    insertAtEnd(&list, 6);
    showList(&list);

    puts("\nInsert 99 at index 3:");
    insertAtIndex(&list, 3, 99);
    showList(&list);

    puts("\nInsert 44 after the first node containing 4:");
    insertAfterValue(&list, 4, 44);
    showList(&list);

    puts("\nDelete the first node:");
    deleteFirst(&list);
    showList(&list);

    puts("\nDelete the last node:");
    deleteLast(&list);
    showList(&list);

    puts("\nDelete the node at index 2:");
    deleteAtIndex(&list, 2);
    showList(&list);

    puts("\nDelete the first node containing 4:");
    deleteByValue(&list, 4);
    showList(&list);

    clearList(&list);
    return EXIT_SUCCESS;
}
