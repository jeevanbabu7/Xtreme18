#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define all(v) v.begin(),v.end()


using namespace std;

const int mod = 1000000007;

int main(){
	
	
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n + 1); // To store project IDs
	
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];			
	}	
	
	vector<vector<int>> g(n + 1);
	vector<int> indegree(n + 1, 0);
	for(int i = 0;i < m; ++i) {
		int a, b;
		cin >> a >> b;
		
		g[a].push_back(b);	
		indegree[b]++;
		
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for(int i = 1;i <= n; ++i) {
		if(indegree[i] == 0) {
			pq.push({v[i], i});
		}
	}
	
	vector<int> seq;
	while(!pq.empty()) {
		
		int node = pq.top().second;
		int gId = pq.top().first;
		pq.pop();
		
		seq.pb(node);
		
		for(auto it: g[node]) {
			indegree[it]--;
			if(indegree[it] == 0) {
				pq.push({v[it], it});
			}
		}
	}
	
	if(seq.size() != n) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < n; ++i)
	{
		cout << seq[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}
