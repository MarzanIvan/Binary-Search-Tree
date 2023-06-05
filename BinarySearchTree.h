#pragma once

template <class Ttype>
struct BinarySearchTree {
	Ttype* array;
	int size;

	BinarySearchTree() {
		array = nullptr;
		size = 0;
	}
	
	BinarySearchTree(int* array, size_t size) {
		int IndexOfLatestParentNode = (size >> 1) - 1;
		this->size = size;
		this->array = array;
		for (int i = 0; i >= 0; i--) {
			Heapify(i, size);
		}
	}

	~BinarySearchTree() {
		if (size) {
			delete[] array;
		}
	}

	void Heapify(int index, size_t size);
	
};

template <class Ttype>
void BinarySearchTree<Ttype>::Heapify(int index, size_t size) {
	int LeftNodeIndex = (i << 1) + 1;
	int RightNodeIndex = (i << 1) + 2;
	int MaxNodeIndex = index;
	if (LeftNodeIndex <= size && array[LeftNodeIndex] > array[MaxNodeIndex]) {
		MaxNodeIndex = LeftNodeIndex;
	}
	if (RightNodeIndex <= size && array[RightNodeIndex] > array[MaxNodeIndex]) {
		MaxNodeIndex = RightNodeIndex;
	}
	if (MaxNodeIndex != index) {
		auto temp = array[MaxNodeIndex];
		array[MaxNodeIndex] = array[index];
		array[index] = temp;
		Heapify(MaxNodeIndex, size);
	}
}

