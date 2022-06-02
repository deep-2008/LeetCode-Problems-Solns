class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        map<int, bool> visited;
int m = 0;

// mark the forbidden position as visited.
for (int f : forbidden)
{
	visited[f] = true;
	m = max(m, f);
}

// the trick
m = a + b + max(m, x);

// bfs
queue<pair<int, bool>> que;
int s = 0;
int c = 0;

que.push({0, true});
visited[0] = true;

while (s = que.size())
{
	while (s --)
	{
		int i = que.front().first;
		bool forward = que.front().second;
		que.pop();
		
		// ending case
		if (i == x)
			return c;
		
		// check jump backward first
		int ii = i - b;

		if (forward && ii >= 0 && ! visited[ii])
		{
			que.push({ii, false});
			visited[ii] = true;
		}
		
		// jump forward
		int jj = i + a;
		
		if (jj <= m && ! visited[jj])
		{
			que.push({jj, true});
			visited[jj] = true;
		}
	}
	
	++ c;
}

return -1;
    }
};