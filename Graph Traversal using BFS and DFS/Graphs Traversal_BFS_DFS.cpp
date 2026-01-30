#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int N = 10;

// loading matrix from file
bool readMatrix(const string& filename, int matrix[N][N]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return true;
}


//BFS Implementation
void BFS(int Graph[][N], int start, int n)
{
    cout << "\nBreadth-First Search traversal:" << endl;
    int i = start;
    queue<int> q;
    int visited[N] = { 0 };

    // already visited vertex
    cout << i << " "; 

    visited[i] = 1; // mark the vertex as visited 
    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        for (int j = 1; j < N; j++)
        {
            if (Graph[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }

}


//DFS Implementation
void DFS(int Graph[][N], int start, int n)
{
    static int visited[N] = { 0 };

    if (visited[start] == 0) // the vertex not visited yet
    {
        cout << start << " ";

        visited[start] = 1;
        
        for (int j = 1; j < N; j++)
        {
            if (Graph[start][j] == 1 && visited[j] == 0)
            {
                DFS(Graph, j, n);

            }
        }
    }
}



int main() {
    int matrix[N][N];

    if (readMatrix("matrix.txt", matrix)) {
        cout << "*** Matrix loaded from 'matrix.txt' ***:\n\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }


    BFS(matrix, 1, N);

    cout << "\nDepth First Search traversal:" << endl;
    DFS(matrix, 1, N);
    return 0;
}
