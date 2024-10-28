Obervations
1. It is a Topological sorting problem
	- Given graph is directed and we have to remove the nodes based on the rules given and also the indegree of that node should be 0.

2. Normal queue won't work because we have to remove the nodes based on the group 	IDs and project IDs. So use the priority priority queue to sort them based on the group ID and project ID. Note: use minimum heap

3. Use BFS instead of DFS 
