import java.util.Arrays;

public class ArrayInsertion {
    // Inserts at index and returns the new logical size.
    private static int insertAt(int[] values, int size, int capacity, int element, int index) {
        if (capacity != values.length || size < 0 || size > capacity) {
            throw new IllegalArgumentException("Size/capacity do not match the array");
        }
        if (size == capacity) {
            throw new IllegalStateException("There is no free capacity for insertion");
        }
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index must be between 0 and size inclusive");
        }

        for (int i = size - 1; i >= index; i--) {
            values[i + 1] = values[i];
        }
        values[index] = element;
        return size + 1;
    }

    public static void main(String[] args) {
        int[] values = new int[100];
        int[] startingValues = {7, 8, 12, 27, 88};
        System.arraycopy(startingValues, 0, values, 0, startingValues.length);

        int size = startingValues.length;
        size = insertAt(values, size, values.length, 45, 3);

        System.out.println(Arrays.toString(Arrays.copyOf(values, size)));
    }
}
