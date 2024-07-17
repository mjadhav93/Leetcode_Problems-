/*1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/


#include <stdlib.h>
#include <stdio.h>

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode** table;
} HashTable;

unsigned int hash(int key, int size) {
    return abs(key) % size;
}

HashNode* createNode(int key, int value) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable* createTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashNode**)malloc(size * sizeof(HashNode*));
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable* hashTable, int key, int value) {
    unsigned int hashIndex = hash(key, hashTable->size);
    HashNode* newNode = createNode(key, value);
    if (hashTable->table[hashIndex] == NULL) {
        hashTable->table[hashIndex] = newNode;
    } else {
        HashNode* temp = hashTable->table[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

HashNode* search(HashTable* hashTable, int key) {
    unsigned int hashIndex = hash(key, hashTable->size);
    HashNode* node = hashTable->table[hashIndex];
    while (node != NULL) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* hashTable = createTable(numsSize);
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HashNode* node = search(hashTable, complement);
        if (node != NULL) {
            result[0] = node->value;
            result[1] = i;
            *returnSize = 2;
            free(hashTable->table);
            free(hashTable);
            return result;
        }
        insert(hashTable, nums[i], i);
    }
    *returnSize = 0;
    free(hashTable->table);
    free(hashTable);
    return NULL;
}

