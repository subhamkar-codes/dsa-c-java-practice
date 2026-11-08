public class Problem1 {
    private static class SumProduct {
        final long sum;
        final long product;

        SumProduct(long sum, long product) {
            this.sum = sum;
            this.product = product;
        }
    }

    // Keeps the same two-pass structure as the C program.
    private static SumProduct calculate(int[] values) {
        long sum = 0;
        long product = 1;

        for (int value : values) {
            sum += value;
        }
        for (int value : values) {
            product *= value;
        }

        return new SumProduct(sum, product);
    }

    public static void main(String[] args) {
        int[] values = {3, 5, 66};
        SumProduct result = calculate(values);

        System.out.println("Sum: " + result.sum);
        System.out.println("Product: " + result.product);
    }
}
