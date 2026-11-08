public class LinkedListTraversal {
    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private static void traverse(Node current) {
        while (current != null) {
            System.out.println("Element: " + current.data);
            current = current.next;
        }
    }

    public static void main(String[] args) {
        Node head = new Node(7);
        Node second = new Node(11);
        Node third = new Node(15);

        head.next = second;
        second.next = third;

        traverse(head);
    }
}
