#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "adjacencyMatrix.h"

void adjmat_dfs(int G[][7], int r) {
	for (int i = 0; i < 7; i++)
		visited[i] = 0;
	
	Stack* S = init_stack();
	stack_push(S, r);

	while (!stack_empty(S)) {
		int v = stack_pop(S);
		if (!visited[v]) {
			visited[v] = 1;
			printf("adjacency matrix dfs visit %d\n", v);
			for (int i = 0; i < 7; i++) {
				if (G[v][i] != 0 && !visited[G[v][i]])
					stack_push(S, i);
			}
		}
	}
}

void adjmat_dfs_wrap() {
	int G[7][7] = { {0, 1, 1, 0, 0, 0, 0},
					{1, 0, 0, 1, 1, 0, 0},
					{1, 0, 0, 0, 1, 0, 0},
					{0, 1, 0, 0, 0, 0, 1},
					{0, 1, 1, 0, 0, 0, 1},
					{0, 0, 0, 0, 0, 0, 1},
					{0, 0, 0, 1, 1, 1, 0} };
	adjmat_dfs(G, 0);
}

