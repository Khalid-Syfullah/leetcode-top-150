#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<pair<string, double>>> buildGraph(
    const vector<vector<string>>& equations,
    const vector<double>& values
) {
    unordered_map<string, vector<pair<string, double>>> graph;
    for (size_t i = 0; i < equations.size(); i++) {
        const string& dividend = equations[i][0];
        const string& divisor = equations[i][1];
        double value = values[i];
        graph[dividend].push_back({divisor, value});
        graph[divisor].push_back({dividend, 1.0 / value});
    }
    return graph;
}

double dfs(
    const string& current,
    const string& target,
    double product,
    const unordered_map<string, vector<pair<string, double>>>& graph,
    unordered_map<string, bool>& visited
) {
    if (current == target) return product;
    visited[current] = true;
    auto it = graph.find(current);
    if (it != graph.end()) {
        for (const auto& edge : it->second) {
            if (visited.count(edge.first)) continue;
            double answer = dfs(edge.first, target, product * edge.second, graph, visited);
            if (answer != -1.0) return answer;
        }
    }
    return -1.0;
}

vector<double> calcEquation(
    const vector<vector<string>>& equations,
    const vector<double>& values,
    const vector<vector<string>>& queries
) {
    auto graph = buildGraph(equations, values);
    vector<double> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++) {
        const string& start = queries[i][0];
        const string& end = queries[i][1];
        if (!graph.count(start) || !graph.count(end)) {
            result[i] = -1.0;
            continue;
        }
        if (start == end) {
            result[i] = 1.0;
            continue;
        }
        unordered_map<string, bool> visited;
        result[i] = dfs(start, end, 1.0, graph, visited);
    }
    return result;
}

int main() {
    vector<vector<string>> equations1 = {{"a","b"},{"b","c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> res1 = calcEquation(equations1, values1, queries1);
    cout << "[";
    for (size_t i = 0; i < res1.size(); i++) { if (i) cout << ", "; cout << res1[i]; }
    cout << "]\n";

    vector<vector<string>> equations2 = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    vector<double> res2 = calcEquation(equations2, values2, queries2);
    cout << "[";
    for (size_t i = 0; i < res2.size(); i++) { if (i) cout << ", "; cout << res2[i]; }
    cout << "]\n";
    return 0;
}
