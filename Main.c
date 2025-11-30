#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "adjMat.h"

/*
	정점의 방문 여부를 기록하는 배열입니다.
	0 = 방문하지 않음. 1 = 방문함
*/
int visited[7] = { 0, };


/*
	그래프에 간선을 추가하는 유틸 함수 입니다.
	그래프의 V라는 정점에 W로 향하는 간선을 추가합니다.
*/
void addEdge(LinkedList* G[], int V, int W) {
	linked_insert(G[V], W);
}


/*
	스택을 통해 구현된 DFS입니다.
*/
void dfs(LinkedList* G[], int r) {
	
	//먼저 visited 배열을 전부 0으로 초기화합니다.
	//아직 아무 정점도 방문하지 않았기 때문입니다.
	for (int i = 0; i < 7; i++)
		visited[i] = 0;


	//시작정점 r을 스택에 push한 상태로 시작합니다.
	Stack* S = init_stack();
	stack_push(S, r);

	
	//스택이 빌 때까지 반복을 수행합니다.
	//스택이 비었다는 것은 더 이상 방문할 정점이 존재하지 않는다는 의미입니다.
	while (!stack_empty(S)) {
		//스택에서 정점을 pop 합니다.
		int v = stack_pop(S);

		//해당 정점을 아직 방문하지 않았을 때 연산을 수행합니다.
		//이미 방문한 적이 있다면 연산을 수행하지 않고 다음 loop로 진행합니다.
		if (!visited[v]) {
			
			//해당 정점을 방문합니다.
			visited[v] = 1;
			printf("dfs visit %d\n", v);

			//해당 정점의 인접 정점을 모두 스택에 push합니다.
			//여기에서는 알고리즘의 효율성을 위해 이미 방문한 정점은 push하지 않습니다.
			Node* p = G[v]->head;
			while (p != NULL) {
				if(!visited[p->v])
					stack_push(S, p->v);
				p = p->next;
			}
		}
	}

}





/*
	재귀를 통해 구현된 DFS입니다.
*/
void dfs_recursion(LinkedList* G[], int r) {
	
	//기저 조건은 해당 정점을 이미 방문한 경우 입니다.
	//역시 이 경우 함수를 그대로 종료합니다.
	if (visited[r])
		return;

	//여기까지 왔다면 이 정점은 아직 방문하지 않은 정점입니다.
	//이제 해당 정점을 방문처리 합니다.
	visited[r] = 1;
	printf("dfs recursion visit %d\n", r);

	//해당 정점의 모든 인접 정점에 대해 다시 dfs를 수행합니다.
	//역시 효율성을 위해 이미 방문한 정점에 대해서는 dfs를 수행하지 않습니다.
	Node* p = G[r]->head;
	while (p != NULL) {
		if(!visited[p->v])
			dfs_recursion(G, p->v);
		p = p->next;
	}
}

/*
	dfs_recursion을 호출하기 전 visited의 초기화를 담당하는 wrapper 함수입니다.
*/
void dfsWrap(LinkedList* G[], int r) {
	for (int i = 0; i < 7; i++) {
		visited[i] = 0;
	}
	dfs_recursion(G, r);
}





/*
	큐를 통해 구현된 BFS입니다.
*/
void bfs(LinkedList* G[], int r) {
	
	for (int i = 0; i < 7; i++)
		visited[i] = 0;

	//시작 정점을 큐에 enqueue합니다.
	Queue* Q = init_queue();
	enqueue(Q, r);

	//큐가 빌 때까지 반복합니다.
	while (!queue_empty(Q)) {
		//큐에서 정점을 dequeue합니다.
		int v = dequeue(Q);

		//해당 정점을 아직 방문하지 않았다면 연산을 수행합니다.
		if (!visited[v]) {
			visited[v] = 1;
			printf("bfs visit %d\n", v);

			//해당 정점의 모든 인접 정점을 큐에 enqueue합니다.
			Node* p = G[v]->head;
			while (p != NULL) {
				if (!visited[p->v])
					enqueue(Q, p->v);
				p = p->next;
			}
		}
	}
}


int main() {
	LinkedList* G[7];
	for (int i = 0; i < 7; i++) {
		G[i] = init_list();
	}
	addEdge(G, 0, 2);
	addEdge(G, 0, 1);
	addEdge(G, 1, 4);
	addEdge(G, 1, 3);
	addEdge(G, 1, 0);
	addEdge(G, 2, 4);
	addEdge(G, 2, 0);
	addEdge(G, 3, 6);
	addEdge(G, 3, 1);
	addEdge(G, 4, 6);
	addEdge(G, 4, 2);
	addEdge(G, 4, 1);
	addEdge(G, 5, 6);
	addEdge(G, 6, 5);
	addEdge(G, 6, 4);
	addEdge(G, 6, 3);

	dfs(G, 0);
	printf("\n");
	dfsWrap(G, 0);
	printf("\n");
	bfs(G, 0);
	printf("\n");
	adjmat_dfs_wrap();



	/*
		
		**실행 결과**
		
		dfs visit 0
		dfs visit 2
		dfs visit 4
		dfs visit 6
		dfs visit 5
		dfs visit 3
		dfs visit 1

		dfs recursion visit 0
		dfs recursion visit 1
		dfs recursion visit 3
		dfs recursion visit 6
		dfs recursion visit 4
		dfs recursion visit 2
		dfs recursion visit 5

		bfs visit 0
		bfs visit 1
		bfs visit 2
		bfs visit 3
		bfs visit 4
		bfs visit 6
		bfs visit 5
	
	*/

	return 0;
}



