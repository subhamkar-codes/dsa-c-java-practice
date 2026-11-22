class ArrayStack {
    int size;
    int top;
    int[] arr;

    ArrayStack(int size) {
        this.size = size;
        this.top = -1;
        this.arr = new int[size];
    }

    boolean isEmpty() {
        return top == -1;
    }

    boolean isFull() {
        return top == size - 1;
    }
}

public class StackInArray {
    public static void main(String[] args) {
        ArrayStack stack = new ArrayStack(3);

        // Manually place values in the array, as in the C program.
        stack.arr[0] = 7;
        stack.top++;

        stack.arr[1] = 11;
        stack.top++;

        stack.arr[2] = 12;
        stack.top++;

        if (stack.isEmpty()) {
            System.out.println("The Stack is empty");
        } else {
            System.out.println("The stack is not empty");
        }

        if (stack.isFull()) {
            System.out.println("The stack is full");
        } else {
            System.out.println("The stack is not full");
        }
    }
}
