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

SECOND QUESTION :

The problem posed in question 2 is that of calculating the route which maximizes the satisfaction of tourists who visit the archipelago starting from a generic island towards all the others.
The archipelago in this case is seen as a graph where the "islands" are generic NODES and the "bridges" that is, the connections between the islands represent the ARCS belonging to the graph.
The graph as written in the trace is directed and acyclic with the "quality" of the link it represents the
WEIGHT of the bow which can also be a negative quantity.
The output of the problem consists in the search for a maximum path within the graph to maximize the tourist's satisfaction and complete the visit of all the islands starting from any one.
The graph being acyclic has an optimal substructure and therefore it is not an NP-HARD problem.

DATA STRUCTURE DESCRIPTION:
The data structure used to carry out the problem is a graph G, i.e. an ordered pair of V (set of nodes) and E (set of arcs).
The elements of the set E are pairs of elements (u, v) of nodes belonging to V, so we can state that E is a proper subset of V x V.
The graph treated in the trace is oriented and weighted where the edges are ordered pairs (u, v) of nodes belonging to V.
The trace also states that the direction and the quality values of the connections for each island are specified in the input, which can also be negative.

ALGORITHM DESCRIPTION:
The problem has the optimal substructure, this guarantees us that, having computed the longest path between the source s and a node u, then the computed paths s and the predecessors of u will certainly be maximum.
The graph G as described in the trace is a DAG (Direct Acyclic Graph) therefore we can perform a topological
ordering i.e. a linear ordering of all its vertices such that if G contains an arc (u, v) then u appears before v in the ordering so as to compute all the paths from source node s to v.
The topological sorting is done through the DFS algorithm, i.e. a depth visit with the use of a stack data structure to store the order of the vertices.
Before calling the DFS for the topological sorting we use the Initialized_single_source function
to initialize the distance of the source from itself to 0, the distances of the other nodes to minus infinity and the parents to NIL to later modify them with the computation of the maximum path.
After doing all this and storing the sorted nodes on the stack, we extract them and pass each node the list of its neighbors by calling the RELAX function to relax them, improving the path maximum of the node found up to that point by modifying the attribute d or the distance from the source node and the parent ÿ.
By doing this, each node will be assigned the maximum value of the path starting from the source node if the parent for the maximum path is determined.

COMPLEXITY STUDY:

The time complexity of this algorithm is determined by the two functions DFS and MAXIMUM_PATH.
The DFS function used for topological sorting has a cost THETA(V + E), i.e. the sum of the set of vertices V and the number of arcs E.
The MAX_PATH function takes a "while" to scan all the vertices popped off the stack (K) and also runs a "for" loop to iterate through the adjacency list, so we have a time complexity of THETA (V + E ).
The total we have 2[THETA (V + E)] which is asymptotically equivalent to THETA(V + E).



