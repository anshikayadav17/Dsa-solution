class Solution {
public:

    double dfs(string current, string target,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {

        // If either variable doesn't exist
        if (graph.find(current) == graph.end() ||
            graph.find(target) == graph.end()) {
            return -1.0;
        }

        // We reached the target
        if (current == target) {
            return 1.0;
        }

        // Mark current variable as visited
        visited.insert(current);

        // Explore all neighbours
        for (auto& neighbour : graph[current]) {

            string next = neighbour.first;
            double value = neighbour.second;

            // Don't visit the same variable again
            if (visited.count(next)) {
                continue;
            }

            // Recursively find next / target
            double result = dfs(next, target, graph, visited);

            // If a valid path was found
            if (result != -1.0) {
                return value * result;
            }
        }

        // No path exists
        return -1.0;
    }


    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {

        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];

            double value = values[i];

            // a / b = value
            graph[a].push_back({b, value});

            // b / a = 1 / value
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> answer;

        // Process every query
        for (auto& query : queries) {

            string start = query[0];
            string target = query[1];

            unordered_set<string> visited;

            double result = dfs(start, target, graph, visited);

            answer.push_back(result);
        }

        return answer;
    }
};
