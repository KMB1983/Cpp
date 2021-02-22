#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>

#include <stdlib.h>

using namespace std;

int cntLines(const char* filename) {
    ifstream file(filename);
    string line;
    int cnt = 0;
    while (getline(file, line)) cnt++;
    file.close();
    return cnt;
}

class Graph{
private:
    int n, **G;
public:
    Graph(const char* filename) ; //graph constructor

    inline const int numberOfVertices() { return n;}
    inline int* &operator[](int index) const { return G[index]; }

    friend ostream& operator<<(ostream &out, Graph& g);

    void bfs(int s, int e);
    void dfs(int s, int e);

};

void showPath(int s, int e, int path[]){
    if (s != e) {
        showPath(s, path[e], path);
        cout << e << " ";
    }
}

void Graph::bfs(int s, int e) {
    int path[n], visited[n];
    std::queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == e) break;
        for (int v=0; v<n; v++){
            if (G[u][v] && !visited[v]) {
                visited[v] = 1;
                path[v]=u;
                q.push(v);
            }
        }
    }
    showPath(s, e, path);
}

void Graph::dfs(int s, int e) {
    int path[n], visited[n];
    std::stack<int> stk;
    stk.push(s);

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (u == e) break;
        for (int v=0; v<n; v++){
            if (G[u][v] && !visited[v]) {
                visited[v] = 1;
                path[v]=u;
                stk.push(v);
            }
        }
    }
    showPath(s, e, path);
}



ostream& operator<<(ostream &out, Graph& g) {
    for (size_t i=0; i<g.numberOfVertices(); i++) {
        for (size_t j=0; j<g.numberOfVertices(); j++) {
            out << g[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

Graph::Graph(const char* filename): n(0), G(0) {
    n = cntLines(filename);
    G = new int*[n]; // init array of pointers

    ifstream inputFile(filename);
    string line;
    for (size_t i=0; getline(inputFile, line); i++) {
        G[i] = new int[n]; //matrix n x n
        stringstream values(line);
        string val;
        for (size_t j=0; getline(values, val, '\t'); j++) {
            G[i][j] = atoi(val.c_str());
        }
    }
    inputFile.close();

}



int main() {

    Graph graph("adjmatrix2.txt");
    cout << graph << endl;
    graph.bfs(0, 7);
    cout << endl;
    graph.dfs(0, 7);

    return 0;
}

