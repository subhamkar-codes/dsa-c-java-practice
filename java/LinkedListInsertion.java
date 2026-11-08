public class LinkedListInsertion {
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

    private static Node insertAtFirst(Node head, int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        return newNode;
    }

    // Inserts at a zero-based position: index 0 means the front.
    private static Node insertAtIndex(Node head, int data, int index) {
        if (index < 0) {
            throw new IndexOutOfBoundsException("Index cannot be negative");
        }

        Node newNode = new Node(data);
        if (index == 0) {
            newNode.next = head;
            return newNode;
        }

        Node previous = head;
        for (int i = 0; i < index - 1; i++) {
            if (previous == null) {
                throw new IndexOutOfBoundsException("Index is outside the list");
            }
            previous = previous.next;
        }
        if (previous == null) {
            throw new IndexOutOfBoundsException("Index is outside the list");
        }

        newNode.next = previous.next;
        previous.next = newNode;
        return head;
    }

    private static Node insertAtEnd(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null) {
            return newNode;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
        return head;
    }

    private static Node insertAfterNode(Node head, Node previous, int data) {
        if (previous == null) {
            throw new IllegalArgumentException("Previous node cannot be null");
        }

        Node newNode = new Node(data);
        newNode.next = previous.next;
        previous.next = newNode;
        return head;
    }

    public static void main(String[] args) {
        Node head = new Node(7);
        Node second = new Node(11);
        Node third = new Node(15);
        Node fourth = new Node(65);

        head.next = second;
        second.next = third;
        third.next = fourth;

        System.out.println("Linked list before insertion");
        traverse(head);

        System.out.println("\nAfter insertion at the start");
        head = insertAtFirst(head, 56);
        traverse(head);

        System.out.println("\nAfter insertion at index 3");
        head = insertAtIndex(head, 49, 3);
        traverse(head);

        System.out.println("\nAfter insertion at the end");
        head = insertAtEnd(head, 99);
        traverse(head);

        System.out.println("\nAfter inserting 37 after node 11");
        // 'second' still refers to the original node containing 11.
        head = insertAfterNode(head, second, 37);
        traverse(head);
    }
}
