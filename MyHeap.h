#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::swap;

class MyHeap {

private:
	int size;
	std::unique_ptr<int[]> heap;
public:
	MyHeap() : size(10), heap(new int[10]) {
		//for (int i = 0; i < size; i++) heap[i] = 0;
		//The code above isn't necassary! There is smart pointer's constructor works!
	}
	~MyHeap() {}
	MyHeap(int size) : size(size), heap(new int[size]) {
		fill_heap();
		build_heap();
	}
	MyHeap(int *a, int size) : size(size), heap(new int[size]) {
		for (auto i = 0; i < size; i++) {
			heap[i] = a[i];
		}
		build_heap();
	}

	MyHeap(std::vector<int> &a) : size(a.size()), heap(new int[size]) {
		for (auto i = 0; i < size; i++) {
			heap[i] = a[i];
		}
		build_heap();
	}

	void fill_heap() {
		for (auto i = 0; i < size; i++) {
			cin >> heap[i];
		}
	}
	void show() {
		cout << size << endl;
		for (auto i = 0; i < size; i++) cout << heap[i] << " ";
		cout << endl;
	}

	int parent(int i) {
                //if (i > 0 && i < size) {
                        return (i-1)/2;
                //}
                //else cout << "Error: exit beyond the border of heap!\n";
        }
        int left(int i) {
                //if (i >= 0 && i < size) {
                        return 2*i + 1;
                //}
                //else cout << "Error: exit beyond the border of heap!\n";
        }
        int right(int i) {
                //if (i >= 0 && i < size) {
                        return 2*i + 2;
                //}
                //else cout << "Error: exit beyond the border of heap!\n";
        }

	void Heapify(int i)
	{
    		int l;
    		int r;
    		int largest;

    		for (; ; )
    		{
        		l = left(i); //2 * i + 1;
        		r = right(i); //2 * i + 2;
        		largest = i;

        		if (l < size && heap[l] > heap[largest])
        		{
            			largest = l;
        		}

        		if (r < size && heap[r] > heap[largest])
        		{
            			largest = r;
        		}

        		if (largest == i)
        		{
            			break;
        		}

			swap(heap[i], heap[largest]);
        		i = largest;
    		}
	}

	void build_heap() {
		for (auto i = size/2; i >= 0; i--) {
			Heapify(i);
		}
	}

	void add(const int x) {
		std::unique_ptr<int[]> temp(new int[size+1]);
		for (auto i = 0; i < size; i++) temp[i] = heap[i];
		temp[size] = x;

		size += 1;
		heap = std::move(temp);
	}

	void remove_last() {
		std::unique_ptr<int[]> temp(new int[size-1]);
		for (auto i = 0; i < size-1; i++) temp[i] = heap[i];

		size -= 1;
		heap = std::move(temp);
	}

	void add_in_heap(const int value) {
		add(value);
    		int i = size - 1;

    		while (i > 0 && heap[parent(i)] < heap[i])
    		{
			swap(heap[i], heap[parent(i)]);
       			i = parent(i);
    		}
	}

	int getMax() {
		int max = heap[0];
		heap[0] = heap[size-1];
		remove_last();
		
		return max;
	}

	int heap_size() { return size; }

};
















