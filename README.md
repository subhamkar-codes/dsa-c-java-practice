# Circular Singly Linked List in C and Java

This folder contains complete C and Java examples based on `20_circular_linkedlist.c`. The original sample showed traversal and insertion at the beginning; these versions add common insertion and deletion operations.

## Folder structure

```text
CircularLinkedList/
├── c/
│   └── README.md
└── java/
    └── README.md
```

## Circular-list rule

An empty list has `head == NULL` in C and `head == null` in Java. In a non-empty list, the last node points back to the head. For one node, that node points to itself. Traversal therefore stops when it reaches the head again, rather than when `next` is null.

## Operations included

### Insertion

- At the beginning
- At the end
- At a zero-based index (`0` through the current length; inserting at the length appends)
- After the first node containing a target value

### Deletion

- First node
- Last node
- At a zero-based index (`0` through `length - 1`)
- First node containing a target value

The sample `main` runs all eight operations. Index operations use zero-based positions in both languages. C reports invalid insert/delete requests and leaves the list unchanged; Java throws an exception for invalid indexes or missing insertion targets. Deleting a missing value in Java also throws an exception.

## Complexity

These implementations keep only a `head` reference, so they may need to scan the list to find the tail or a target node.

| Operation | Time | Extra space |
| --- | --- | --- |
| Display / length | O(n) | O(1) |
| Insert at beginning / end | O(n) | O(1) per inserted node |
| Insert at index / after value | O(n) | O(1) per inserted node |
| Delete first / last / at index / by value | O(n) | O(1) |

Keeping a tail reference in the list structure could make insertion at the beginning and end O(1), but this example uses a head reference to match the original lesson.

## Run the C version

From the `c` folder, using GCC in Windows PowerShell:

```powershell
gcc .\20_circular_linkedlist.c -o .\circular_list.exe
.\circular_list.exe
```

On macOS or Linux:

```bash
gcc 20_circular_linkedlist.c -o circular_list
./circular_list
```

The C program frees every remaining node before exiting.

## Run the Java version

From the `java` folder, with a JDK installed:

```powershell
javac .\CircularLinkedList.java
java CircularLinkedList
```

Java automatically reclaims removed nodes, so there is no `free` call.
