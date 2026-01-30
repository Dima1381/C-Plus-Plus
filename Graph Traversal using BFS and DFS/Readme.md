Graph Traversal using BFS and DFS (C++)

This project demonstrates the implementation of graph traversal algorithms — Breadth-First Search (BFS) and Depth-First Search (DFS) — using an adjacency matrix in C++.

The program reads a graph from a file (matrix.txt), displays the adjacency matrix, and then performs BFS and DFS traversals starting from a specified vertex.

Breadth-First Search (BFS) — explores the graph level by level using a queue.
Depth-First Search (DFS) — explores the graph depth-wise using recursion.

📁 Project Structure
─ main.cpp    // Source code
─ matrix.txt  // Adjacency matrix input file
─ README.md   // Project description


📥 Input

The graph is represented as an adjacency matrix stored in matrix.txt

Matrix size is fixed at 10 × 10

1 means there is an edge between vertices

0 means no edge

Example (matrix.txt):

0 1 0 0 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0
...

🎓 Purpose

This project was created for educational purposes to demonstrate:

Graph representation using adjacency matrices

BFS and DFS traversal techniques in C++

File input handling
