class Solution {
public:    
	int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
		int nodes = scores.size();

		auto compare = [&scores] (const int& nodeA, const int& nodeB) {
			return scores[nodeA] > scores[nodeB];
		};
		vector<vector<int>> graph;
		graph.resize(nodes);

		for(auto& e : edges) { // O(n * log(3))
			int nodeA = e[0], nodeB = e[1];
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);

			sort(graph[nodeA].begin(), graph[nodeA].end(), compare);
			sort(graph[nodeB].begin(), graph[nodeB].end(), compare);

			if(graph[nodeA].size() > 3) graph[nodeA].pop_back(); 
			if(graph[nodeB].size() > 3) graph[nodeB].pop_back();
		}

		int ans = -1;
		for(auto& e : edges) { // O(n * 9)
			int nodeA = e[0], nodeB = e[1];

			for(auto& a : graph[nodeA]) // O(9)
				for(auto& b : graph[nodeB]) 
					if(a != nodeB && b != nodeA && a != b) 
						ans = max(ans, scores[nodeA] + scores[nodeB] + scores[a] + scores[b]);
		}
		return ans;
	}
};