import java.util.Arrays;

public class LinearSearch {
    private static int linearSearch(int[] values, int target) {
        for (int i = 0; i < values.length; i++) {
            if (values[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] values = {1, 3, 5, 56, 4, 323, 5, 4, 54634, 56, 34};
        int target = 54634;

        int index = linearSearch(values, target);
        System.out.println("Manual linear search: " + target + " found at index " + index);

        // Java Stream/lambda example: checks whether any item matches the target.
        boolean foundWithStream = Arrays.stream(values).anyMatch(value -> value == target);
        System.out.println("Found using a Stream: " + foundWithStream);
    }
}
