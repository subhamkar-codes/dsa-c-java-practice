# C DSA Practice

This folder contains my Data Structures and Algorithms practice programs written in C.

## Programs

| File | Topic |
| --- | --- |
| `problem1.c` | Array sum and product; basic time complexity |
| `timecomplx/problem2.c` | Time complexity practice |
| `11_array_deletion.c` | Array deletion |
| `array_insertion.c` | Array insertion |
| `adt_array_implitation_08.c` | Array ADT |
| `12_LinearSearch.c` | Linear search |
| `12_binarySearch.c` | Binary search |
| `14_LinkedList.c` | Linked list traversal |
| `15_linkedListInsertion.c` | Linked list insertion |
| `18_linkedList_deletation.c` | Linked-list deletion: first node, index, last node, and by value |
| `20_circular_linkedlist.c` | Circular linked-list traversal, insertion, and deletion |
| `21_DoublyLinkedList.c` | Doubly linked-list traversal, insertion, and deletion |

Each file is a separate program. Compile and run one at a time.

## Compile and run

You need a C compiler such as GCC.

From this folder, in Windows PowerShell:

```powershell
gcc .\array_insertion.c -o .\array_insertion.exe
.\array_insertion.exe
```

To run the linked-list examples:

```powershell
gcc .\20_circular_linkedlist.c -o .\circular_linkedlist.exe
.\circular_linkedlist.exe

gcc .\21_DoublyLinkedList.c -o .\doubly_linked_list.exe
.\doubly_linked_list.exe
```

On macOS or Linux:

```bash
gcc 21_DoublyLinkedList.c -o doubly_linked_list
./doubly_linked_list
```

Replace the source filename to compile another program. `timecomplx/problem2.c` is currently empty and has no program to compile.

## Notes

- `11_array_deletion.c` shifts the values and then writes the supplied element into the deleted position.
- `12_binarySearch.c` contains a linear-search loop after a return statement, so that loop is unreachable.
- The expanded `20_circular_linkedlist.c` example covers insertion at the beginning, end, index, and after a value; and deletion from the beginning, end, index, and by value.
- The corrected `21_DoublyLinkedList.c` example fixes the cycle and disconnected node in the original. It includes the same insertion and deletion cases, displays forward and backward, and limits each traversal to 100 nodes.
- These programs are for learning and practicing DSA concepts.
