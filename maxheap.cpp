/**
 * Author:    Aleksander Rodriguez
 * Created:   10/26/2023
 **/
 
#include "maxheap.hpp"
#include <stdio.h>
#include <iostream>

MaxHeap::MaxHeap() {}
MaxHeap::~MaxHeap() {}

/*
ALL YOUR CODE GOES HERE
The methods below either
  - don't do anything at all, or
  - return 0 just so that the code compiles

You have to implement every method in this class
 */
 
int MaxHeap::size() { 
  int count=0;
  for(int x = 0; x < arr.size(); x++) {
   // cout << *it << " ";
    count++;
  }
  return count-1;
  }

// finding the left node of a parent
int MaxHeap::left(int parent) {
  return (parent * 2);
}

// finding the right node of a parent
int MaxHeap::right(int parent) {
  return (parent * 2) + 1;
}

int MaxHeap::parent(int child) { 
  int parent = (child/2);   // child/2 will get you the parent
  return parent;
}

// we want to not use the first element to make things easier
int ins=0;
void MaxHeap::insert(int element) {
  // we want to make the first element useless
  if( ins == 0) 
  {
    arr.insert(arr.end(), -1);
    ins++;
  }

  // insert our useful elements 
  arr.insert(arr.end(), element);
  heapifyUp(size());

  
}

int MaxHeap::deleteMax() {
  int max = arr[1];
  //swap
    int temp = arr[1];
    arr[1] = arr[size()];
    arr[size()] = temp;
    arr.pop_back();

    heapifyDown(1);

  return max;
}

void MaxHeap::display() {
  cout << "MaxHeap:- ";
  for(int x = 1; x < arr.size(); x++) {
    cout << arr[x] << " ";
  }
  
  cout << endl;
  cout << "The size is: " << size() << endl << endl;
}

void MaxHeap::heapifyUp(int index) {
  // we have reached the top
  if(index == 1)
  {
    return;
  }

  // store the parent index in par
  // (didn't want to type extra stuff)
  int par = parent(index);

  // check if the inserted element is greater than its parent 
  if(arr[index] > arr[par])
  {
    //swap
    int temp = arr[index];
    arr[index] = arr[par];
    arr[par] = temp;
  }

  // this will run until the index == 1 
  heapifyUp(par);


}

void MaxHeap::heapifyDown(int index) {
int maxLeaf;

// find which leaf of the parent is greater 
if( left(index) <= size() && right(index) <= size() && arr[left(index)] > arr[right(index)])
{
  maxLeaf = left(index);
}
else if ( left(index) <= size() && right(index) <= size() && arr[left(index)] < arr[right(index)])
{
  maxLeaf = right(index);
}
else if (left(index) <= size()) // if left exist and right doesnt
{
  maxLeaf = left(index);
}
else if (right(index) <= size())  // right exist and left doesnt
{
  maxLeaf = right(index);
}
else{
  return;
}

//cout << "max leaf: " << arr[maxLeaf] << endl ;

// check if the max leaf is greater than its parent 
if( maxLeaf <= size() && arr[maxLeaf] > arr[index])
{
  int temp = arr[maxLeaf]; // 800 
  arr[maxLeaf] = arr[index];// 400
  arr[index] = temp; // 800
}
else 
{
  return;// if it's not then this function will stop running 
}

// we will run this funtion recursively until the it is a true max heap
heapifyDown(maxLeaf);
}

void MaxHeap::buildHeap(vector<int>& A,int n) {
  /*
  arr = A;
  cout << "made it to build heap" << endl;
  for(int x = 1; x < n; x++) {
    cout << arr[x] << " ";
  }
  cout << endl;
  */


  arr = A;
  
  // main build heap function 
  for(int i = n/2; i >= 1 ; i--)
  {
    //cout << i << endl;
    
    heapifyDown(i);
  }

  // makes sure the max heap is passed
  A=arr;
}

void MaxHeap::heapsort(vector<int>& A,int n) {
  A.insert(A.begin(), -1);
  n = n+1;
buildHeap(A, n);
  arr = A;
  // make a new vector to store the heap sort 
  vector<int> sorted;

  // all we got to do is do deleteMax() unitl the max heap vector is empty
  while(!(arr.empty()))
  {
    int num = deleteMax();
    //num;
    sorted.insert(sorted.begin(), num);
  }
  sorted.erase(sorted.begin());
  A=sorted;
 
}
