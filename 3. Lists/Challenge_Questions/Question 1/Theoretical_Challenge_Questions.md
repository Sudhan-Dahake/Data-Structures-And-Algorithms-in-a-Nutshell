# Lists
## THEORETICAL CHALLENGE QUESTIONS
### Question 1

```
Sequential lists and linked lists share the same abstract data type, and thus provide the same functionality.
However, their internal implementations of this "signature" are different. Name a few instances
when it would be better to use a sequential list rather than a linked list, and vice versa.
```

**When to Use a Sequential List (Array):**

1. **Fast Access by Index**: Sequential lists provide O(1) - constannt time access to elements by index,
making them ideal for use cases requiring frequent random access. For instance, in applications like
lookup tables or matrix manipulation, the ability to directly access an element without traversing the
structure ensures speed and efficiency.

2. **Better Cache Performance**: Arrays are stored in contiguous memory blocks, which means that
when an element is accessed, the CPU cache prefetches nearby elements. This improves performance in
scenarios that require iterating over large datasets or performing numerical computations,
where memory locality plays a significant role in efficiency.

3. **Smaller Memory Overhead**: Sequential lists store only the data without any additional overhead
like pointers, making them more memory-efficient than linked lists. This characteristic is crucial in
scenarios with strict memory constraints, such as embedded systems or devices with limited RAM.

4. **Fixed-Size of Predictable Growth**: Arrays work best when the size of the data is known or grows
predictably, avoiding the overhead of resizing operations. This is useful in fixed-size datasets like
storing the months of a year or any scenario where the size does not change frequently.


**When to use a Linked List:**

1. **Frequent Insertions and Deletions**: Linked lists excel in situations requiring frequent insertions
and deletions at arbitary positions, as these operations are O(1) and do not involve shifting elements.
This makes them a natural choice for applications like dynamic playlists or real-time scheduling systems,
where updates are frequent.

2. **Dynamic Memory Allocation**: Unlike arrays, linked lists grow and shrink dynamically without
requiring pre-allocated memory. This makes them ideal for applications where the data size is
unpredictable, such as handling streams of data or managing a real-time queue.

3. **No Fixed Size Limit**: Linked lists do not require contiguous (next to each other) memory blocks, so they
are not limited by the size of available contiguous memory. This makes them particularly useful for
handling large or sparse datasets, such as graph representations with variable node degrees.

4. **Frequent Resizing**: Arrays require expensive resizing operations when their capacity is exceeded,
as data must be copied to a larger block of memory. Linked lists avoid this entirely, making them
more efficient for stacks, queues, or data structure where the size fluctuates unpredictably.