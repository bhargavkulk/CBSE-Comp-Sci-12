# Algorithms

There are 2 types of algorithms taught in CBSE:

* Searching Algorithms
  * Linear Search
  * Binary Search
* Sorting Algorithms
  * Bubble Sort
  * Selection Sort
  * Insertion Sort

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
Now this is the sorted and unsorted subarrays:
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
