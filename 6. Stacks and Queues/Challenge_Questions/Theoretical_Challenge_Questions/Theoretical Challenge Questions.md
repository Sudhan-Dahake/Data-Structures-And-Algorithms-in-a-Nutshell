# STACKS AND QUEUES
## CHALLENGE QUESTIONS
### Question 1

```
A Queue data structure would be appropriate in this situation. This is because its based on FIFO (First In First Out), 
so whoever comes first gets seen by the doctor and whoever comes last gets seen at the very end.
```

```
Assuming we are using a Linked representation to implement queue ADT, 
the data that needs to be stored are:
1. head pointer (A pointer to the first node (or reference to the first patient), for removing a patient from a queue).
2. tail pointer (A pointer at the very last node (or reference to the very last patient), this is to add a new node
(or add a new patient) at the back in constant time).

Functions needed:
1. Enqueue - To add a new patient at the end of the queue.
2. Dequeue - To remove a patient from the front of the queue.
3. peek - To see the next patient at the front of the queue.
```

### Question 2

```
A Stack data structure would be appropriate in this situation. This is because its based on LIFO (Last In First Out),
this is because once the person wants to put away a T-shirt the robot puts it on the top of the pile,
and if the person wants a T-shirt the robot gives it from the top of the pile, which exactly follows LIFO.
```

```
Assuming we are using a Linked representation to implement Stack ADT,
the data that needs to be stored is:
the head pointer (A pointer to the top of the stack (or reference to the last T-shirt in the pile)).

Functions needed:
1. push - To add a T-shirt to the top of the pile.
2. pop - To remove a T-shirt from the top of the pile.
3. peek - To see the T-shirt at the top of the pile.
```

### Question 3 - 4

```
Code based Question
```

### Question 5

```
The efficiency of implementing a queue using a Linked List or Sequential List depends on 
specific requirements and design constraints of the situation.

Linked List:
1. A Linked List is a better option if the amount of data to be stored is unknown or may vary. 
This is because linked list can dynamically grow without the need for reallocation or resizing.

2. Insertion and deletion have both constant (O(1)) time complexity for Enqueue and Dequeue operations,
assuming that both head and tail pointers are maintained properly.


Sequential List:
1. A Sequential List is more memory efficient if the size of the queue is known and relatively small. 
Compared with Linked List, Sequential List have less memory overhead. This is because Linked List needs to 
store additional memory pointers.

2. Contiguous (consecutive blocks of memory) memory allocation leads to faster access time for elements.
```