# Compile and run an ADA program
gnatmake nome_do_programa.adb
./nome_do_programa

or

gcc-4.9 -c nome_do_programa.adb
gnatbind -x nome_do_programa.adb
gnatlink nome_do_programa.adb
./nome_do_programa

# Definition

Segment tree can be used to do preprocessing and query in moderate time. With segment tree, preprocessing time is O(n) and time to for range minimum query is O(Logn). The extra space required is O(n) to store the segment tree.

Representation of Segment trees
* Leaf Nodes are the elements of the input array.
* Each internal node represents minimum of all leaves under it.

An array representation of tree is used to represent Segment Trees. For each node at index i, the left child is at index 2*i+1, right child at 2*i+2 and the parent is at floor of (i - 1)/2.

## Construction of Segment Tree from given array

We start with a segment arr[0 . . . n-1]. and every time we divide the current segment into two halves(if it has not yet become a segment of length 1), and then call the same procedure on both halves, and for each such segment, we store the minimum value in a segment tree node.
All levels of the constructed segment tree will be completely filled except the last level. Also, the tree will be a Full Binary Tree because we always divide segments in two halves at every level. Since the constructed tree is always full binary tree with n leaves, there will be n-1 internal nodes. So total number of nodes will be 2*n – 1.

[Credits](http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/)

