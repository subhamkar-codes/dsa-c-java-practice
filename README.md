# DSA Practice in C and Java

This repository tracks my progress learning data structures and algorithms in C and carrying the same concepts into Java. It contains practice programs, Java translations, and notes on time and space complexity.

## Repository structure

```text
dsa-c-java-practice/
├── c/       # C practice programs
├── java/    # Java versions and Java-specific examples
└── README.md
```

## Topics

- Array ADT, insertion, and deletion
- Linear search and binary search
- Singly linked list traversal and insertion
- Basic time and space complexity examples

## C and Java versions

Where possible, each Java program follows the corresponding C program so I can compare the syntax and understand how the same algorithm works in both languages. The Java versions also demonstrate features such as `Scanner`, `Arrays` utilities, Streams, and input validation.

Some translations include small corrections or improvements, which are noted in the relevant source files. For example, the supplied C array-deletion program overwrites the deleted position; its Java version performs an actual deletion. The supplied `timecomplx/problem2.c` file was empty, so its Java counterpart is only a placeholder.

## Running the programs

Each program is standalone. Compile and run the file you want to practice.

### C

From the `c` folder:

```bash
gcc array_insertion.c -o array_insertion
./array_insertion
```

On Windows PowerShell:

```powershell
gcc .\array_insertion.c -o .\array_insertion.exe
.\array_insertion.exe
```

### Java

From the `java` folder:

```bash
javac BinarySearch.java
java BinarySearch
```

Replace `BinarySearch` with the class name of another program. A JDK is required.

## Learning notes

I’m using this repository to strengthen my understanding of DSA while practicing in both C and Java. The focus is on implementing the algorithms myself and understanding their complexity, not only using built-in collections.
