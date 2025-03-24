#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue{
    int arr[max];
    int front = -1;
    int rear = -1;
}Queue;
bool isEmpty(Queue* q){
    if(q->front == -1){
        return True;
    }
    return False;
}
bool isFull(Queue* q){
    if(q->rear==max){
        return true;
    }
}
void enqueue(Queue* q,int ele){
    if(isFull(q)==true){
     return;
    }
    else if(isEmpty(q)==false){
        q->front = q->rear = 0;
        arr[q->rear] = ele;
    }
    else{
        q->rear++;
        arr[q->rear] = ele;
    }
}
int dequeue(Queue* q){
    if(isEmpty(q)){
        return;
    }
    else if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return arr[0];
    }
    else{
        int ele = arr[q->front];
        q->front++;
        return ele;
    }
}
void bfs(int i,Queue* q){
    int visited[max];
    printf("%d",i);
    visited[i] == 1;
    enqueue(q,i);
    while(isEmpty(q)==false){
        u = dequeue(q);
        for(int v=1;v<=n;v++){
            if(A[u][v]==1 && visited[v]==0){
                printf("%d",v);
                visited[v]==1;
                enqueue(q,v);
            }
        }#include <stdio.h>
        #include <stdlib.h>
        #include <stdbool.h>
        
        #define max 100
        
        typedef struct Queue {
            int arr[max];
            int front;
            int rear;
        } Queue;
        
        void initQueue(Queue *q) {
            q->front = -1;
            q->rear = -1;
        }
        
        bool isEmpty(Queue *q) {
            return (q->front == -1);
        }
        
        bool isFull(Queue *q) {
            return (q->rear == max - 1);
        }
        
        void enqueue(Queue *q, int ele) {
            if (isFull(q)) return;
        
            if (isEmpty(q)) q->front = 0;
            q->arr[++(q->rear)] = ele;
        }
        
        int dequeue(Queue *q) {
            if (isEmpty(q)) return -1;
        
            int ele = q->arr[q->front];
            if (q->front == q->rear) initQueue(q);  // Reset queue when empty
            else q->front++;
        
            return ele;
        }
        
        void bfs(int start, int n, int A[n][n]) {
            int visited[max] = {0};
            Queue q;
            initQueue(&q);
        
            printf("%d ", start);
            visited[start] = 1;
            enqueue(&q, start);
        
            while (!isEmpty(&q)) {
                int u = dequeue(&q);
                for (int v = 0; v < n; v++) {
                    if (A[u][v] == 1 && !visited[v]) {
                        printf("%d ", v);
                        visited[v] = 1;
                        enqueue(&q, v);
                    }
                }
            }
        }
        
        int main() {
            int n = 5;
            int A[5][5] = {
                {0, 1, 1, 0, 0},
                {1, 0, 0, 1, 1},
                {1, 0, 0, 1, 0},
                {0, 1, 1, 0, 1},
                {0, 1, 0, 1, 0}
            };
        
            printf("BFS traversal: ");
            bfs(0, n, A);
        
            return 0;
        }
        
    }
}