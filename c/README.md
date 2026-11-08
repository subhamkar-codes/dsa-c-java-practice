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

Each file is a separate program. Compile and run one at a time.

## Compile and run

You need a C compiler such as GCC.

From this folder, in Windows PowerShell:

```powershell
gcc .\array_insertion.c -o .\array_insertion.exe
.\array_insertion.exe
```

On macOS or Linux:

```bash
gcc array_insertion.c -o array_insertion
./array_insertion
```

Replace `array_insertion.c` with another source filename to run a different program. `timecomplx/problem2.c` is currently empty and has no program to compile.

## Notes

- `11_array_deletion.c` currently shifts the values and then writes the supplied element into the deleted position. Check the code when studying the deletion logic.
- `12_binarySearch.c` contains a linear-search loop after a return statement, so that loop is unreachable.
- These programs are for learning and practicing DSA concepts.
