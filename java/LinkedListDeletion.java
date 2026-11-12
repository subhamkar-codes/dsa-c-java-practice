public class LinkedListDeletion {
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

    // Case 1: delete the first node.
    private static Node deleteFirst(Node head) {
        return head == null ? null : head.next;
    }

    // Case 2: delete the node at a zero-based index.
    private static Node deleteAtIndex(Node head, int index) {
        if (index < 0 || head == null) {
            throw new IndexOutOfBoundsException("Index is outside the list");
        }
        if (index == 0) {
            return head.next;
        }

        Node previous = head;
        for (int i = 0; i < index - 1; i++) {
            if (previous.next == null) {
                throw new IndexOutOfBoundsException("Index is outside the list");
            }
            previous = previous.next;
        }

        if (previous.next == null) {
            throw new IndexOutOfBoundsException("Index is outside the list");
        }

        previous.next = previous.next.next;
        return head;
    }

    // Case 3: delete the last node.
    private static Node deleteLast(Node head) {
        if (head == null || head.next == null) {
            return null;
        }

        Node current = head;
        while (current.next.next != null) {
            current = current.next;
        }

        current.next = null;
        return head;
    }

    // Case 4: delete the first node containing value.
    private static Node deleteWithValue(Node head, int value) {
        if (head == null) {
            return null;
        }
        if (head.data == value) {
            return head.next;
        }

        Node previous = head;
        while (previous.next != null && previous.next.data != value) {
            previous = previous.next;
        }

        if (previous.next != null) {
            previous.next = previous.next.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        head.next = new Node(3);
        head.next.next = new Node(8);
        head.next.next.next = new Node(1);

        System.out.println("Linked list before deletion");
        traverse(head);

        // Try deleteFirst(head), deleteAtIndex(head, 2), or deleteLast(head).
        head = deleteWithValue(head, 8);

        System.out.println("Linked list after deleting 8");
        traverse(head);
    }
}