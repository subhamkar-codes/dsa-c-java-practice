import java.util.Arrays;

public class BinarySearch {
    // Binary search requires the input array to be sorted in ascending order.
    private static int binarySearch(int[] values, int target) {
        int low = 0;
        int high = values.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoids possible integer overflow.

            if (values[mid] == target) {
                return mid;
            }
            if (values[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] values = {1, 3, 5, 56, 64, 73, 123, 225, 444, 54634};
        int target = 444;

        int index = binarySearch(values, target);
        System.out.println("Manual binary search: " + target + " found at index " + index);

        // Java's library version is useful in applications; implement the loop above for DSA practice.
        int libraryIndex = Arrays.binarySearch(values, target);
        System.out.println("Arrays.binarySearch: " + libraryIndex);
    }
}
