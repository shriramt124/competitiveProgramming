## trees
* there are two ways to represent the trees 

### Adjecency matrix 
 --> suppose there are N nodes then we will create a N*N matrix where matrix[i][j] represent the directed node from  i->j if node i->j is connected the we will store 1 in matrix[i][j] otherwise we will store 0

 ### adnecency list 

 --> In list representation, for a node i, we store children of that node. This approach is more space efficient than adjacency matrix when number of edges are significantly less than vertices.

 0    1      2
 1    3      4
 2    5

 in the above matrix 
 0 denotes that 0node value is connected with 1 and 2 node value 
 1 denotes that 1node value is connected with 3 and 4 node value 
 2 denotes that 2node value is connected with 5 node value only 

 the tree is represented as like this 


          0
      1      2
    3    4       5