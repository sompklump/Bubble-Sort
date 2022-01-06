using namespace std;
#include <string>
#include <iostream>
#include "Main.h";

int o[150];
int ARR_SIZE = 0;
int randLength = 0;

int main() {
	// Random length between 1 and 150 for O
	srand(time(0));
	randLength = rand() % (sizeof(o) / sizeof(o[0]));

	for (int i = 0; i <= randLength; i++) {
		o[i] = rand() % 2483184 + 1;
	}
	cout << "Original Array" << endl;
	ARR_SIZE = (sizeof(o) / sizeof(o[0]));
	PrintAllElementsOfArray(o, ARR_SIZE);

	int i = 0;
	while (true)
	{
		if (i >= ARR_SIZE)
			i = 0;
		// Current size of index
		int n = o[i];

		RearrangeArray(o, i);
		if (CheckArray(o, ARR_SIZE))
			break;
		i += 1;
	}
	PrintAllElementsOfArray(o, ARR_SIZE);
	cout << "\nLength of array is " << randLength << endl;
	system("pause");
	return 0;
}

void PrintAllElementsOfArray(int arr[], int size)
{
	cout << "Done!\r\n\tHere's your list, ordered." << endl;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) continue;
		printf("El: %d\n", arr[i]);
	}
}
bool CheckArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0) continue;
		int next = i + 1;
		if (next >= ARR_SIZE) {
			//cout << "Next reached" << endl;
			return true;
		}
		if (arr[i] > arr[next]) {
			//cout << i << " was bigger than " << arr[next] << endl;
			return false;
		}
	}
}
void RearrangeArray(int arr[], int i) {
	int next = i + 1;
	if (next >= ARR_SIZE) return;
	if (arr[i] > arr[next]) {
		int nextOg = arr[next];
		// Switch the two values
		arr[next] = arr[i];
		arr[i] = nextOg;
	}
}