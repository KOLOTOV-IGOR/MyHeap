#include "MyHeap.h"
void show(std::vector<int> &);
void HeapSort(std::vector<int> &);

int main() {

	/*int arr[] = {5, 2, 7, 3, 6, 1, 4};
	int size = sizeof(arr)/sizeof(int);
	//cout << size << endl;
	MyHeap h(arr, size);

	//h.add(9);
	//h.show();
	h.add_in_heap(9);
	//h.remove_last(); h.remove_last();h.remove_last();
	h.show();
	cout << h.getMax() << endl;
	//h.show();*/

	std::vector<int> v = {3, 5, 1, 5, 2, -4, 6, 0, 5, 6, 4 ,2, 10, 11, 17, 54, -9};
	show(v);
	HeapSort(v);
	show(v);

	return 0;
}

void show(std::vector<int> &v) {
	for (auto i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

void HeapSort(std::vector<int> &vec) {
	MyHeap temp(vec);
	for (auto i = temp.heap_size() - 1; i >= 0 ; i--) {
		vec[i] = temp.getMax();
		temp.Heapify(0);
	}
	//return vec;
}
