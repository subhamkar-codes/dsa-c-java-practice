# Java DSA Practice

This folder contains Java versions of my Data Structures and Algorithms practice programs in C. I’m using the translations to learn Java while continuing to practice the same DSA concepts.

## Programs

| Java file | Topic |
| --- | --- |
| `Problem1.java` | Array sum and product |
| `Problem2.java` | Placeholder; the corresponding C file was empty |
| `ArrayDeletion.java` | Array deletion |
| `ArrayInsertion.java` | Array insertion |
| `ArrayADT.java` | Array ADT and console input |
| `LinearSearch.java` | Linear search |
| `BinarySearch.java` | Binary search |
| `LinkedListTraversal.java` | Linked list traversal |
| `LinkedListInsertion.java` | Linked list insertion |
| `LinkedListDeletion.java` | Singly linked-list deletion |
| `CircularLinkedList.java` | Circular linked-list traversal, insertion, and deletion |

Each Java file is a standalone program with its own `main` method.

## Compile and run

You need a JDK. From this folder, compile and run a program like this:

```powershell
javac .\BinarySearch.java
java BinarySearch
```

For example, to run the circular linked-list program:

```powershell
javac .\CircularLinkedList.java
java CircularLinkedList
```

Replace the class name with another program to run it. `ArrayADT` reads two integer values from the console.

## Java features practiced

- Classes, objects, constructors, and references
- `Scanner` for reading input
- `Arrays` helpers for searching and displaying arrays
- Streams and lambdas
- Exceptions for invalid indexes and input
- Automatic memory management for linked-list nodes

The manual implementations are included so I can learn how the algorithms work before relying on Java’s built-in collections.

## Linked-list notes

`LinkedListDeletion.java` handles empty lists and invalid indexes. Deleting the head takes O(1); deleting by index, from the end, or by value takes O(n).

`CircularLinkedList.java` demonstrates insertion at the beginning, end, index, and after a value; and deletion from the beginning, end, index, and by value. Its indexes are zero-based. Because it stores only a head reference, operations that need to find the tail take O(n) time to reconnect the circle.

## Translation notes

Some Java versions include safety checks or corrections, noted in their source code. For example, `ArrayDeletion.java` performs an actual deletion, while the supplied C version writes a value into the deleted position.
