#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INITIAL_SIZE 101
#define LOAD_FACTOR 0.85

typedef struct Node {
  char *key;
  int value;
  struct Node *next;
} Node;

typedef struct map {
  Node **table;
  int capacity;
  int size;
} hashmap;

hashmap *createMap() {
  hashmap *newMap = (hashmap *)malloc(sizeof(hashmap));
  newMap->capacity = INITIAL_SIZE;
  newMap->size = 0;
  newMap->table = calloc(newMap->capacity, sizeof(Node *));
  return newMap;
}

Node *createNode(char *key, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = strdup(key);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;  
}

unsigned long hash(char *key, int capacity) {
  unsigned long index = 5381;
  int c;
  while ((c = *key++)) {
    index = ((index << 5) + index) + c;
  }
  return index % capacity;
}

int sizes[] = {2311, 2713, 3517, 3919, 4723, 5527, 6733, 7537, 9547, 9949};
int nextSize(int currentSize) {
  int size = sizeof(sizes) / sizeof(sizes[0]);
  for (int i = 0; i < size; i++) {
    if (currentSize < sizes[i]) {
      return sizes[i];      
    }
  }
  return (sizes[size - 1] * 2) + 1;  
}

void reHash(hashmap *map) {
  int oldCapacity = map->capacity;
  int newCapacity = nextSize(oldCapacity);

  Node **old = map->table;
  
  Node **table = calloc(newCapacity, sizeof(Node *));
  map->capacity = newCapacity;
  map->size = 0;

  for (int i = 0; i < oldCapacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      Node *next = entry->next;
      unsigned long index = hash(entry->key, map->capacity);
      entry->next = map->table[index];
      map->table[index] = entry;
      map->size++;
      entry = next;      
    }
  }
  free(old);
}

void insertNode(hashmap *map, char *key, int data) {
  if ((float)map->size / map->capacity >= LOAD_FACTOR) {
    reHash(map);    
  }    
  unsigned long index = hash(key, map->capacity);
  Node *entry = map->table[index];
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      entry->value = data;
      return;
    }
    entry = entry->next;
  }
  Node *new = createNode(key, data);
  new->next = map->table[index];
  map->table[index] = new;
  map->size++;  
}

int lookUpByData(hashmap *map, char *key) {
  unsigned long index = hash(key, map->capacity);
  Node *entry = map->table[index];
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }
  return INT_MIN;
}

void clear(hashmap *map, char *key) {
  unsigned long index = hash(key, map->capacity);
  Node *entry = map->table[index];
  Node *prev = NULL;
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      if (prev) {
	prev->next = entry->next;
      } else {
	map->table[index] = entry->next;        
      }
      free(entry->key);
      free(entry);
    }
    prev = entry;
    entry = entry->next;
  }
  map->size--;  
}

void freeMap(hashmap *map) {
  for (int i = 0; i < map->capacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      Node *temp = entry->next;
      free(entry->key);
      free(entry);
      entry = temp;      
    }
  }
  free(map->table);
  free(map);
}

void displayMap(hashmap *map) {
  for (int i = 0; i < map->capacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      printf("yes\n");
      entry = entry->next;
    }
    printf("no\n");    
  }
}


int main() {

  hashmap *newMap = createMap();

  insertNode(newMap, "chanh", 12);
  insertNode(newMap, "vy", 13);
  
  displayMap(newMap);
  
  freeMap(newMap);
  
  return EXIT_SUCCESS;  
}  
