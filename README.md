Description of Code: This code creates a max heap as one inserts a value using the insert() function and the heapifyUp() function. The heapifyUp() uses the parent funtion as well. It will also display the max heap as it is sorted in the array the heap is stored in. It also has the ability to get and delete the max of the heap using the deletemax() function. It can also take an unsorted array with integers and perform a heapsort. This is done by multiple functions, including, a buildheap(), heapifyDown(), right(), and left(). Heapify down allows the integer in question to be places accordingly to the heap max.

No extra credit done. 

How To Run The Program:

g++ -o heapsort demo.cpp maxheap.cpp

./heapsort inputs/input.10.1

time for f in inputs/input.10*; do echo $f; ./heapsort $f; done
