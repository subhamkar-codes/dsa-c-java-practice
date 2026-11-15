public class CircularLinkedList {
    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private static int length(Node head) {
        if (head == null) {
            return 0;
        }
        int count = 1;
        Node current = head.next;
        while (current != head) {
            count++;
            current = current.next;
        }
        return count;
    }

    private static void display(Node head) {
        if (head == null) {
            System.out.println("(empty list)");
            return;
        }

        Node current = head;
        int index = 0;
        do {
            System.out.println("Index " + index + ": " + current.data);
            current = current.next;
            index++;
        } while (current != head);
    }

    // Insert at the front and reconnect the tail to the new head.
    private static Node insertAtBeginning(Node head, int data) {
        Node node = new Node(data);
        if (head == null) {
            node.next = node;
            return node;
        }

        Node tail = head;
        while (tail.next != head) {
            tail = tail.next;
        }
        node.next = head;
        tail.next = node;
        return node;
    }

    private static Node insertAtEnd(Node head, int data) {
        if (head == null) {
            return insertAtBeginning(null, data);
        }

        Node node = new Node(data);
        Node tail = head;
        while (tail.next != head) {
            tail = tail.next;
        }
        tail.next = node;
        node.next = head;
        return head;
    }

    // Index is zero-based; index == length appends to the list.
    private static Node insertAtIndex(Node head, int index, int data) {
        int size = length(head);
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Insert index must be between 0 and size");
        }
        if (index == 0) {
            return insertAtBeginning(head, data);
        }

        Node previous = head;
        for (int i = 1; i < index; i++) {
            previous = previous.next;
        }
        Node node = new Node(data);
        node.next = previous.next;
        previous.next = node;
        return head;
    }

    // Inserts after the first node containing targetValue.
    private static Node insertAfterValue(Node head, int targetValue, int data) {
        if (head == null) {
            throw new IllegalArgumentException("Cannot insert after a value in an empty list");
        }

        Node current = head;
        do {
            if (current.data == targetValue) {
                Node node = new Node(data);
                node.next = current.next;
                current.next = node;
                return head;
            }
            current = current.next;
        } while (current != head);

        throw new IllegalArgumentException("Target value was not found: " + targetValue);
    }

    private static Node deleteFirst(Node head) {
        if (head == null || head.next == head) {
            return null;
        }

        Node tail = head;
        while (tail.next != head) {
            tail = tail.next;
        }
        Node newHead = head.next;
        tail.next = newHead;
        return newHead;
    }

    private static Node deleteLast(Node head) {
        if (head == null || head.next == head) {
            return null;
        }

        Node previous = head;
        Node current = head.next;
        while (current.next != head) {
            previous = current;
            current = current.next;
        }
        previous.next = head;
        return head;
    }

    // Index is zero-based; valid deletion indexes are 0 through size - 1.
    private static Node deleteAtIndex(Node head, int index) {
        int size = length(head);
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Delete index is outside the list");
        }
        if (index == 0) {
            return deleteFirst(head);
        }

        Node previous = head;
        for (int i = 1; i < index; i++) {
            previous = previous.next;
        }
        previous.next = previous.next.next;
        return head;
    }

    // Deletes the first node containing value; unchanged if absent.
    private static Node deleteByValue(Node head, int value) {
        if (head == null) {
            return null;
        }
        if (head.data == value) {
            return deleteFirst(head);
        }

        Node previous = head;
        Node current = head.next;
        while (current != head && current.data != value) {
            previous = current;
            current = current.next;
        }
        if (current == head) {
            throw new IllegalArgumentException("Value was not found: " + value);
        }

        previous.next = current.next;
        return head;
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertAtEnd(head, 4);
        head = insertAtEnd(head, 13);
        head = insertAtEnd(head, 6);
        head = insertAtEnd(head, 1);

        System.out.println("Starting circular list:");
        display(head);

        System.out.println("\nInsert 54 at the beginning:");
        head = insertAtBeginning(head, 54);
        display(head);

        System.out.println("\nInsert 99 at the end:");
        head = insertAtEnd(head, 99);
        display(head);

        System.out.println("\nInsert 25 at index 3:");
        head = insertAtIndex(head, 3, 25);
        display(head);

        System.out.println("\nInsert 37 after the first node containing 13:");
        head = insertAfterValue(head, 13, 37);
        display(head);

        System.out.println("\nDelete the first node:");
        head = deleteFirst(head);
        display(head);

        System.out.println("\nDelete the last node:");
        head = deleteLast(head);
        display(head);

        System.out.println("\nDelete the node at index 2:");
        head = deleteAtIndex(head, 2);
        display(head);

        System.out.println("\nDelete the first node containing 25:");
        head = deleteByValue(head, 25);
        display(head);
    }
}
