#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "adjMat.h"

/*
	인접 행렬을 통해 구현된 그래프의 탐색 방법입니다.
	
	인접 리스트의 경우 인접 정점만 뽑아서 리스트에 저장합니다.
	하지만 인접 행렬은 V x V의 행렬을 통해 
	정점 i와 j가 연결 되어있다면 해당 칸을 1로 표기합니다.

	무방향 그래프는 i->j로 가는 간선이 있다면  **G[i][j] == 1 이라면** 
	j->i로 가는 간선 또한 존재합니다.         **G[j][i] == 1 이다.**
	따라서 무방향 그래프를 인접 행렬로 표현할 경우 대칭 행렬이 됩니다.

	그래프는 일반적으로 자기 자신에서 자기 자신으로 가는 간선(self loop)은 존재하지 않습니다.
	따라서 i->i는 항상 0이 됩니다.           **G[i][i] == 0 이며, 이는 대각선 요소를 의미한다**
*/


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
				if (G[v][i] != 0 && !visited[i])
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

