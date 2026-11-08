import java.util.Arrays;
import java.util.Scanner;

public class ArrayADT {
    private static class IntArray {
        private final int totalSize;
        private final int usedSize;
        private final int[] values;

        IntArray(int totalSize, int usedSize) {
            if (totalSize < 0 || usedSize < 0 || usedSize > totalSize) {
                throw new IllegalArgumentException("Require 0 <= used size <= total capacity");
            }
            this.totalSize = totalSize;
            this.usedSize = usedSize;
            this.values = new int[totalSize];
        }

        void set(int index, int value) {
            if (index < 0 || index >= usedSize) {
                throw new IndexOutOfBoundsException("Index is outside the used portion");
            }
            values[index] = value;
        }

        void show() {
            System.out.println(Arrays.toString(Arrays.copyOf(values, usedSize)));
        }

        int capacity() {
            return totalSize;
        }
    }

    public static void main(String[] args) {
        IntArray marks = new IntArray(10, 2);
        System.out.println("Enter " + marks.usedSize + " values (capacity: " + marks.capacity() + "):");

        try (Scanner scanner = new Scanner(System.in)) {
            for (int i = 0; i < marks.usedSize; i++) {
                System.out.print("Value " + i + ": ");
                if (!scanner.hasNextInt()) {
                    throw new IllegalArgumentException("Please enter an integer");
                }
                marks.set(i, scanner.nextInt());
            }
        }

        System.out.println("Used values:");
        marks.show();
    }
}
