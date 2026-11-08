import java.util.Arrays;

public class ArrayDeletion {
    // Removes the item at index and returns the new logical size.
    private static int deleteAt(int[] values, int size, int index) {
        if (size < 0 || size > values.length) {
            throw new IllegalArgumentException("Size must fit inside the array capacity");
        }
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index is outside the used portion of the array");
        }

        for (int i = index; i < size - 1; i++) {
            values[i] = values[i + 1];
        }

        values[size - 1] = 0; // Clear the now-unused slot for clarity.
        return size - 1;
    }

    public static void main(String[] args) {
        int[] values = new int[100];
        int[] startingValues = {7, 8, 12, 27, 88};
        System.arraycopy(startingValues, 0, values, 0, startingValues.length);

        int size = startingValues.length;
        int indexToDelete = 0;
        size = deleteAt(values, size, indexToDelete);

        // Arrays.copyOf displays only the used portion, not the spare capacity.
        System.out.println(Arrays.toString(Arrays.copyOf(values, size)));
    }
}
