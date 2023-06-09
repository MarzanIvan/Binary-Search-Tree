﻿#include <iostream>

using namespace std;

int* Heapify(int* array, int i, int size) {
	int left = (i << 1) + 1;
	int right = (i << 1) + 2;
	int max = i;
	if (left <= size && array[left] > array[max]) max = left;
	if (right <= size && array[right] > array[max]) max = right;
	if (max != i) {
		auto temp = array[max];
		array[max] = array[i];
		array[i] = temp;
		Heapify(array, max, size);
	}
	return array;
}

int* BuildBinaryHeap(int* array, size_t size) {
	int AmountParentNodes = (size >> 1) - 1;
	for (int i = AmountParentNodes; i >= 0; i--) {
		Heapify(array, i, size);
	}
	return array;
}

void showarray(char* letter) {
	while (*(letter++)) {
		std::cout << *letter;
	}
}

void showarray(int* array, int size) {
	for (size_t i = 0; i < size; i++) {
		cout << *(array++) << ' ';
	}
}

#include "BinarySearchTree.h"

int main() {
	int array[10] = { 16,17,9,10,5,6,8,1,2,4 };
	BinarySearchTree<int> b(array, 10);
	showarray(b.sort(), b.size);
}