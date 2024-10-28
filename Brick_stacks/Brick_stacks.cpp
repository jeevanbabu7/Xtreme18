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

void solve(multiset<int> &s, vector<vector<int>> &ans, int x, int index, int &cnt) {
	auto it = s.begin();
	vector<int> temp;
	ans.push_back(temp);
	ans[index].pb(*it);

	int prev = *it;
	s.erase(it);
	cnt--;
	while(1) {
		
		auto it1 = s.lower_bound(prev + x);
		
		if(it1 == s.end()) 
				break;
		else {
			prev = *it1;
			ans[index].pb(*it1);
			s.erase(it1);
			cnt--;
		}
	}
}

int main(){
	
	int n, x;
	cin >> n >> x;
	multiset<int> st;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		st.insert(t);
	}
	
	vector<vector<int>> ans;
	
	int cnt = n, ind = 0;
	while(cnt > 0) {
		solve(st, ans, x, ind, cnt);
		ind++;
		
	}
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size(); ++i) {		
		int m = ans[i].size();
		cout << m << " ";
		
		for(int j = m - 1;j >= 0;j--) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
