# Algorithm and Data structures
My project is divided into two parts: 

The first part uses data structures such as red and black trees to implement insiemistic operationsby reading various numbers from a file.

The second part deals with solving the problem of minimal paths on oriented and weighted graphs using the Ford bellmann algorithm and the 
DFS for topological sorting. 

FIRST QUESTION.
The problem posed in question 1 concerns the realization of a data structure for generic sets based on RED BLACK trees.
The data structure must be able to perform the operations of UNION, INTERSECTION and DIFFERENCE
treating each tree as a set of integers.
The numbers are read from a text file where the elements of the same set are on the same line separated by a space (different lines correspond to different sets).
Subsequently the read numbers are inserted as keys of the nodes of the RED BLACK tree, all this will be
explained in more detail in the section "DESCRIPTION OF DATA STRUCTURE" and in the section "DESCRIPTION OF ALGORITHM".
The output of the problem consists in showing the results of the above operations by providing the program with a menu from which the user can choose the function to be performed using the keyboard.

DATA STRUCTURE DESCRIPTION:

The data structure treated is that of the RED BLACK trees, i.e. a self-balancing binary search tree whose height, thanks to particular conditions, remains limited allowing a logarithmic complexity in the
insertion and elimination methods (methods analyzed below)
through an "automatic" balancing of the structure, thus avoiding degradation to the worst case or transformation into a list.
Below we find the characteristics that a RED BLACK mast must satisfy.

1.	Each node of an RB tree contains:
•	The key (in this case integer).
•	Pointer to parent.
•	Pointer to right child.
•	Pointer to the left child.
•	Node color (RED/BLACK).

2.	If X is the root of a tree RB and Y represents the left subtree then Key[X] >=key[Y]
3.	If X is the root of a tree RB and *Y represents the left subtree then Key[X]<key[*Y]
4.	Each node is RED or BLACK.
5.	Keys are kept on internal nodes only.
6.	Leaves are NULL and are always BLACK in color.
7.	The root of the tree is always BLACK
8.	If a node is RED then its children are BLACK.
9.	Each path from an internal node to a leaf has the same number of BLACK nodes(BHEIGHT).
10.	Every RB tree with root x has at least 2bh(x) - 1 internal nodes, where bh(x) is the height black of node x.
11.	The black height bh(x) is the number of BLACK nodes in a simple path from node x to a leaf (excluding x).
12.	In a RB tree at least half of the nodes from the root to a leaf must be BLACK,we can also have the case where all nodes are BLACK.
13.	In an RB tree no path from a node v to a leaf is longer than twice as long as the path from v to another leaf.
14.	In a tree RB with N internal nodes we have a maximum height 2 (log2(N+1)).

PROOF POINT 8.
Proof by induction:
Base case -> bh(x) = 0 so x is a leaf and the subtree 2bh(x) - 1 = 1-1 = 0 internal nodes.
Inductive step -> node x with two children. Red child = bh(x) and black child = bh(x) - 1.
Each child has at least 2bh(x)-1 – 1 internal nodes so (2bh(x)-1 – 1) + (2bh(x)-1 – 1) + 1 = 2 bh(x) - 1 internal nodes.

PROOF POINT 12.
Demonstration:
Let h = height by property 6 (if a node is RED it cannot have RED children) and by property 8 we know that at least half of the internal nodes must be black so the B-HEIGHT must be equal in the worst case h/2 .
N >= 2h/2 -1	N -> number of nodes.
N + 1 = 2h/2
Log2 (N + 1) >= h/2
2log2 (N + 1) >= h
2log2 (N + 1) -> MAXIMUM HEIGHT OF TREE RB WITH 'N' INTERNAL NODES.

INPUT/OUTPUT DATA:

The input of the program as described in the trace is represented by a text file in which the elements (in this case whole numbers) of the same set are found on the same line separated by a space (subsequent lines correspond to different sets).
Reading takes place via the READING_FILE method which saves the entire reading in a variable passed as a parameter to the method invoked for insertion into the RB tree, ie INSERIMENTO_RB.
The output of the program consists of solving the operations UNION, INTERSECTION and
DIFFERENCE performed on RB trees where each tree represents a set.
All the mentioned functions will be analyzed in detail in the "ALGORITHM DESCRIPTION" section.

ALGORITHM DESCRIPTION:

The program is based on the creation of a data structure for the management of generic sets treated as previously analyzed RED BLACK trees.
We use the READ_FILE method to save the integer to be passed as a parameter to the method
INSERIMENTO_RB for the creation of the node to be inserted in the RB tree.
Both for the INSERIMENTO_RB method and for the DELETE_RB method we use functions to avoid unbalancing the tree and maintain a logarithmic type complexity.
For INSERIMENTO_RB we use the LEFT_ROTATE and/or RIGHT_ROTATE functions while for DELETE_RB we use the DELETE_FIXUP function which in turn calls LEFT_ROTATE and/or RIGHT_ROTATE.
The set operations are implemented through the UNION, INTERSECTION and DIFFERENCE methods based on the INSERIMENTO_RB and DELETE_RB functions.
The program also has a function ELIMINA_DUPLICATI for eliminating any nodes with repeated keys using the DELETE_RB and SEARCH_NODE methods.
Finally, the user can choose via the keyboard whether to perform a single set operation or do them all.
