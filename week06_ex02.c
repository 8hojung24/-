#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayQueueNodeType {
	char data;
}ArrayQueueNode;

typedef struct ArrayQueueType {
	int maxCount;
	int currentCount;
	int front;
	int rear;
	ArrayQueueNode *pData;
}ArrayQueue;

int isArrayQueueFull(ArrayQueue * pQueue);
int isArrayQueueEmpty(ArrayQueue * pQueue);

ArrayQueue * createArrayQueue(int size) {
	if (size <= 0) { printf("입력 사이즈는 0보다 커야 합니다.\n"); return NULL; }
	ArrayQueue *pReturn = NULL;

	pReturn = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (pReturn == NULL) { 
		printf("메모리 할당 실패하였습니다.\n"); 
		free(pReturn); 
		return NULL; 
	}
	memset(pReturn, 0, sizeof(ArrayQueue));
	pReturn->maxCount = size;
	pReturn->front = -1;
	pReturn->rear = -1;

	pReturn->pData = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode) *size);
	if (pReturn->pData == NULL) {
		printf("메모리 할당 실패하였습니다.\n");
		free(pReturn);
		return NULL;
	}
	memset(pReturn->pData, 0, sizeof(ArrayQueueNode)* size);

	return pReturn;
}

int enqueueAQ(ArrayQueue* pQueue, char data) {
	int ret = 0;

	if (pQueue != NULL) {
		if (isArrayQueueFull(pQueue) == 0) {
			pQueue->rear = (pQueue->rear + 1) % pQueue->maxCount;
			pQueue->pData[pQueue->rear].data = data;
			pQueue->currentCount++;
			ret = 1;
		}
		else {
			printf("오류, 큐가 가득 찼습니다, enqueueAQ()\n");
		}
	}
	return ret;
}

int isArrayQueueFull(ArrayQueue *pQueue) {
	int ret = 0;

	if (pQueue != NULL) {
		if (pQueue->currentCount == pQueue->maxCount) {
			ret = 1;
		}
	}
	return ret;
}

ArrayQueueNode *dequeuAQ(ArrayQueue *pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == 0) {
			pReturn = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
			if (pReturn != NULL) {
				pQueue->front = (pQueue->front + 1) % pQueue->maxCount;
				pReturn->data = pQueue->pData[pQueue->front].data;
				pQueue->currentCount--;
			}
			else {
				printf("오류, 메모리 할당, dequeueAQ()\n");
			}
		}
	}
	return pReturn;
}

int isArrayQueueEmpty(ArrayQueue *pQueue) {
	int ret = 0;
	if (pQueue != NULL) {
		if (pQueue->currentCount == pQueue->maxCount) { ret = 1; }
	}
	return ret;
}

ArrayQueueNode *peekAQ(ArrayQueue *pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == 0) {
			pReturn = &(pQueue->pData[pQueue->front + 1]);
		}
	}
	return pReturn;
}

void deleteArrayQueue(ArrayQueue *pQueue) {
	if (pQueue != NULL) {
		if (pQueue->pData != NULL) {
			free(pQueue->pData);
		}
		free(pQueue);
	}
}

void displayArrayQueue(ArrayQueue *pQueue) {
	int position = 0;
	if (pQueue != NULL) {
		printf("큐의 크기: %d, 현재 노드 개수: %d\n",
			pQueue->maxCount, pQueue->currentCount);

		for (int i = pQueue->front + 1; i <= pQueue->front + pQueue->currentCount; i++) {
			position = i % pQueue->maxCount;
			printf("[%d]-[%c]\n", position, pQueue->pData[position].data);
		}
	}
}

int main(int arge, char *argv[]) {
	ArrayQueue *pQueue = NULL;
	ArrayQueueNode *pNode = NULL;

	pQueue = createArrayQueue(4);
	if (pQueue != NULL) {
		enqueueAQ(pQueue, 'A');
		enqueueAQ(pQueue, 'B');
		enqueueAQ(pQueue, 'C');
		pNode = dequeuAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}
		pNode = dequeuAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}
		displayArrayQueue(pQueue);
		enqueueAQ(pQueue, 'D');
		pNode = dequeuAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}
		enqueueAQ(pQueue, 'E');
		displayArrayQueue(pQueue);
		deleteArrayQueue(pQueue);
	}
	return 0;
}