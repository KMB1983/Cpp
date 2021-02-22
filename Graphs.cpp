#include  <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef std::vector<std::vector<int>> AdjMatrix;

template<typename K, typename V>
void printMap(const std::unordered_map<K, V>& mymap) {
    for (const auto& m: mymap) {
        std::cout << "{" << m.first << ": " << m.second<<"}\n";
    }
}

void loadGraph(int v, int e, AdjMatrix& matrix){

    int sv, ev;
    for (size_t i=0; i<e; i++) {
        std::cin>>sv>>ev;
        matrix[sv][ev] = 1;
        matrix[ev][sv] = 1;
    }

    return;

}

void printDFS(int s, const AdjMatrix& matrix, std::vector<bool>& visited) {
    std::cout << s << " -- ";
    visited[s] = true;
    for (size_t i=0; i<matrix.size(); i++) {
        if (matrix[s][i] == 1 && visited[i] == false) {
            printDFS(i, matrix, visited);
        }
    }
    return;
}

void DFS(const AdjMatrix& matrix) {
    // works for disconnected graphs
    int n = matrix.size();
    int cnt=0;
    std::vector<bool> visited(n, false);
    for (size_t i=0; i<n; i++){
        if (!visited[i]) {
            cnt++;
            printDFS(i, matrix, visited);
        }
    }
    std::cout << "Number of components: " << cnt;
}

void printBFS(AdjMatrix matrix, int sv, vector<bool>& visited) {
    int n = matrix.size();
    queue<int> q;
    q.push(sv);
    visited[sv]=true;

    while (!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " -- ";
        q.pop();
        for (size_t i=0; i<n; i++) {
            if (matrix[currentVertex][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(const AdjMatrix& matrix) {
    // works for disconnected graphs
    int n = matrix.size();
    std::vector<bool> visited(n, false);
    for (size_t i=0; i<n; i++){
        if (!visited[i]) {
            printBFS(matrix, i, visited);
        }
    }
}

int main() {
    // 4 v, 3, e, 0 2 2 1 1 3
    // 7 7 0 1 0 2 1 5 5 4 3 4 2 3 2 6    out 0 1 5 4 3 2 6
    //unordered_map<int, bool> mymap = {{1, true}, {2, false}};
    //printMap(mymap);

    int vertices = 7;
    int edges = 7;
    AdjMatrix matrix(vertices, std::vector<int>(vertices, 0));
    loadGraph(vertices, edges, matrix);

    std::vector<bool> visited(vertices, false);
    DFS(matrix);

    std::cout << "\n==========================\n";
    BFS(matrix);



    return 0;
}
