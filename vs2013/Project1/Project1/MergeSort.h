#pragma once
//πÈ≤¢≈≈–Ú
class MergeSort
{
public:
	MergeSort();
	~MergeSort();
	void OnInit();

private:
	int temp[100];
	void Merge(int *a, int low, int mid, int high);
	void CMergeSort(int *a, int low, int high);

};

