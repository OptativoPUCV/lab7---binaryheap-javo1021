#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq == NULL) return;

  if(pq->size == pq->capac){
    pq->capac = pq->capac *2 + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if(pq->heapArray == NULL) exit(EXIT_FAILURE);
  }
  heapElem newElem;
  newElem.data = data;
  newElem.priority = priority;

  int i = pq->size;
  pq->heapArray[i] = newElem;
  pq->size++;

  while(i > 0 && newElem.priority > pq->heapArray[(i-1) / 2].priority){
    pq->heapArray[i] = pq->heapArray[(i - 1) / 2];
    pq->heapArray[(i-1) /2]=newElem;
    i = (i-1) /2;
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* heap = (Heap*)malloc(sizeof(heapElem)*3);
  
  if(heap == NULL) exit(EXIT_FAILURE);

  heap->heapArray = (heapElem*)malloc(sizeof(heapElem) *3 );
  if(heap->heapArray == NULL) exit(EXIT_FAILURE);

  heap->size = 0;
  heap->capac = 3;
   return heap;
}
