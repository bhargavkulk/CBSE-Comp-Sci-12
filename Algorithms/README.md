# Algorithms

There are 2 types of algorithms taught in CBSE:

* Searching Algorithms
  * Linear Search
  * Binary Search
* Sorting Algorithms
  * Bubble Sort
  * Selection Sort
  * Insertion Sort

## Bubble Sort:
Bubble sort is a very simple sorting algorithm that works by swapping adjacent elements in an array until they are in order.
Taking this unsorted array:
```
+-----+-----+-----+-----+-----+-----+-----+
|  7  |  3  |  4  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```
The outer loop starts at index = 0 and ends at the second last index, because comparisons are to be made for the current and next element. Running this till the last element would mean that the comparing the last element with something out of bounds, and we don't want that to happen.
Now the inner loop for the comparisons starts. Now we just swap adjacent elements.

```
1: j = 0
7 and 3 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  7  |  4  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
2: j = 1
7 and 4 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  7  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
3: j = 2
7 and 2 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  2  |  7  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
4: j = 3
7 and 6 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  2  |  6  |  7  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
5: j = 4
7 and 1 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  2  |  6  |  1  |  7  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
6: j = 5
7 and 5 swapped
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  2  |  6  |  1  |  5  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
now j = 6 so break out of loop
```
All of these swaps happen in 1 run of the outer loop.
Here are the arrays after each run of the outer loop:
```
1: i = 0
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  2  |  6  |  1  |  5  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
2: i = 1
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  2  |  4  |  1  |  5  |  6  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
3: i = 2
+-----+-----+-----+-----+-----+-----+-----+
|  2  |  1  |  3  |  4  |  5  |  6  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
4: i = 3
+-----+-----+-----+-----+-----+-----+-----+
|  1  |  2  |  3  |  4  |  5  |  6  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
5: i = 4
+-----+-----+-----+-----+-----+-----+-----+
|  1  |  2  |  3  |  4  |  5  |  6  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
6: i = 5
+-----+-----+-----+-----+-----+-----+-----+
|  1  |  2  |  3  |  4  |  5  |  6  |  7  |
+-----+-----+-----+-----+-----+-----+-----+
now i = 6 so break out of outer loop
```

If you look at the passes of the outer loop, you will see that the last i + 1 elemenst are always sorted. So we never need to compare them in the inner loop.
so the inner loop condition can be changed from `j < len - 1` to `j < len - i - 1` to make the loop more efficient.

## Insertion Sort:
Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
Taking this unsorted array:

```
+-----+-----+-----+-----+-----+-----+-----+
|  7  |  3  |  4  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```

The outer loop in insertion sort starts from index = 1. Now we can visualize the array being split into two parts along the first index.

```
+-----+ +-----+-----+-----+-----+-----+-----+
|  7  | |  3  |  4  |  2  |  6  |  1  |  5  |
+-----+ +-----+-----+-----+-----+-----+-----+
```

The "array" in the front is the sorted subarray, and the other "array" is the unsorted subarray. Now we take the number in index 1 and insert it into the sorted array. Insertion is done by pushing elements back until we can safely put in the number in the sorted subarray.
In this case, first we compare 3 with 7. As 3 is less than 7, it is possible that 3 can be inserted even further. So we then push back 7.
```
+-----+-----+-----+-----+-----+-----+-----+
|  7  |  7  |  4  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```
Now we have come to the end of the array. So we have to place 3 in the front.
```
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  7  |  4  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```
Now these are the sorted and unsorted subarrays:
```
+-----+-----+ +-----+-----+-----+-----+-----+
|  3  |  7  | |  4  |  2  |  6  |  1  |  5  |
+-----+-----+ +-----+-----+-----+-----+-----+
```
Now we have to insert 4 into the array.
So first we compare 4 and 7. 4 is less than 7 so we push 7 back.
```
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  7  |  7  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```
Now we compare 4 and 3. 4 is greater than 3, so we found the position where we need to insert 4. So we now insert 4.
```
+-----+-----+-----+-----+-----+-----+-----+
|  3  |  4  |  7  |  2  |  6  |  1  |  5  |
+-----+-----+-----+-----+-----+-----+-----+
```
Now we continue doing this until the array is sorted.
