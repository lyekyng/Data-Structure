#include <iostream>
#include<string>
using namespace std;


class myArray {
private:
	int* arr;
	int size;
public:
	myArray(int capacity) {
		this->size = capacity;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}
	void at(int i) {
		cout << "index [ " << i << " ] : " << arr[i]<< endl;
	}
	void add(int index, int z) {
		for (int i = size - 1; i >= index; i--)
			arr[i + 1] = arr[i];
		arr[index] = z;
		cout << "index [ " << index << " ] added" << endl << endl;
	}
	void remove(int index) {
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
			arr[size] = 0;
		}
	}
	void set(int i, int z) {
		arr[i] = z;
	}
	void findMax() {
		int max = -1;
		for (int i = 0; i < size; i++) {
			if (arr[i] > max)
				max = arr[i];
		}
		cout << "MAX INDEX : " << max << endl << endl;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};



int main() {
	int num, size, x, y;
	cout << "Number of commands, size of array : ";
	cin >> num >> size;	
	myArray arr(size);

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		if (str == "at") {
			cin >> x;
			arr.at(x);
		}
		else if (str == "add") {
			cin >> x >> y;
			arr.add(x, y);
		}
		else if (str == "remove") {
			cin >> x;
			arr.remove(x);
		}
		else if (str == "set") {
			cin >> x >> y;
			arr.set(x, y);
		}
		else if (str == "find_max") {
			arr.findMax();
		}
		else if (str == "print") {
			cout << "@@@@@@@@ PRINT @@@@@@@@ ";
			arr.print();
		}
		else {
			cout << "WRONG command ! " << endl;
			continue;
		}
	}

}



