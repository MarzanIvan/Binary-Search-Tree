#pragma once

template <class Ttype>
struct BinarySearchTree {
	Ttype* array;
	int size;

	BinarySearchTree() {
		array = nullptr;
		size = 0;
	}

	~BinarySearchTree() {
		if (size) {
			delete[] array;
		}
	}
};

