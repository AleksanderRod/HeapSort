## C++ MaxHeap and Heapsort Algorithm Summary

This C++ project implements a **MaxHeap** data structure and demonstrates the **Heap Sort** algorithm. The `MaxHeap` class is responsible for constructing and managing a max heap, which allows efficient sorting and retrieval of the maximum element. The key operations include insertion, deletion of the maximum element, and the construction of the heap itself. The heap sort algorithm uses these operations to sort an array of integers.

### Key Methods in the `MaxHeap` Class:
1. **insert(int element)**:
   - Inserts a new element into the heap and ensures that the heap maintains the max-heap property by using the `heapifyUp()` function.
   
2. **deleteMax()**:
   - Removes and returns the maximum element (the root of the heap), then rebalances the heap using the `heapifyDown()` function.

3. **heapifyUp(int index)**:
   - Restores the max-heap property by comparing an inserted element with its parent and swapping them if necessary, continuing until the correct position is found.

4. **heapifyDown(int index)**:
   - Restores the max-heap property after deletion by comparing the parent node with its children and swapping with the larger child if necessary, ensuring that the largest value is at the root.

5. **buildHeap(vector<int>& A, int n)**:
   - Constructs a max-heap from an unsorted array by calling `heapifyDown()` starting from the middle of the array, ensuring the max-heap structure is built correctly.

6. **heapsort(vector<int>& A, int n)**:
   - Sorts an array by first building a max-heap from the array, then repeatedly removing the maximum element (using `deleteMax()`) and storing it in sorted order. The result is a sorted array in ascending order.

### Heapsort Algorithm:
The heap sort algorithm implemented in this project operates in two phases:
1. **Build Heap**: Convert the unsorted array into a max-heap.
2. **Sorting**: Repeatedly extract the maximum element (the root of the heap), move it to the end of the array, and then rebuild the heap with the remaining elements. This process continues until all elements are sorted.

This project highlights the power of the heap data structure in efficiently sorting elements, with a time complexity of **O(n log n)** for heapsort.

### How To Run The Program:
g++ -o heapsort demo.cpp maxheap.cpp

./heapsort inputs/input.10.1

time for f in inputs/input.10*; do echo $f; ./heapsort $f; done
