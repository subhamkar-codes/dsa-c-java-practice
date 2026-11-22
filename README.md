# Doubly Linked List in C and Java

This folder contains corrected C and Java implementations based on `21_DoublyLinkedList.c`. The original sample had a link error that connected node 3 back to node 2, creating a cycle, and node 4 was disconnected. The fixed versions maintain both `prev` and `next` links and include all the common insertion and deletion cases.

## Folder structure

```text
DoublyLinkedList/

├── c/
│   └── README.md
│
└── java/
    └── README.md
```

## Operations

### Insert

- At the beginning
- At the end
- At a zero-based index (`0` through the current size; inserting at `size` appends)
- After the first node containing a target value

### Delete

- First node
- Last node
- At a zero-based index (`0` through `size - 1`)
- First node containing a target value

The sample `main` demonstrates every operation and prints the list forward and backward after each change. It starts with `1 2 3 4 5`.

## Link rules and traversal limit

- The first node's `prev` is `NULL`/`null`.
- The last node's `next` is `NULL`/`null`.
- For neighboring nodes, `left.next == right` and `right.prev == left`.
- Forward traversal starts at the head; backward traversal starts at the tail.
- Both display methods stop after at most 100 nodes. The list size also bounds traversal, so a broken link cannot make display run forever. Increase `MAX_TRAVERSAL_NODES` if you want to display more than 100 nodes.

## Complexity

The list stores both `head` and `tail`.

| Operation | Time | Extra space |
| --- | --- | --- |
| Insert at beginning / end | O(1) | O(1) for the new node |
| Insert at index | O(min(index, n - index)) | O(1) for the new node |
| Insert after a value | O(n) to search | O(1) for the new node |
| Delete first / last | O(1) | O(1) |
| Delete at index | O(min(index, n - index)) | O(1) |
| Delete by value | O(n) to search | O(1) |
| Display | O(min(n, 100)) | O(1) |

Here, `n` is the number of nodes. Finding an index starts from the closer end because the list has both a head and a tail.

## Run the C version

From the `c` folder with GCC, in Windows PowerShell:

```powershell
gcc .\21_DoublyLinkedList.c -o .\doubly_linked_list.exe
.\doubly_linked_list.exe
```

On macOS or Linux:

```bash
gcc 21_DoublyLinkedList.c -o doubly_linked_list
./doubly_linked_list
```

The C program frees all remaining nodes before it exits.

## Run the Java version

From the `java` folder with a JDK installed:

```powershell
javac .\DoublyLinkedList.java
java DoublyLinkedList
```

Java automatically reclaims nodes that are no longer linked into the list.
