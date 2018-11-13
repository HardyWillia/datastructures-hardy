/* 
    Willia Hardy
    wjh25@zips.uakron.edu
    2905326
    Project3
*/


#include "heapsort.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::atoi;


vector<string> get_file(){

    ifstream recordFile;
    string filename;
    string line;
    vector<string> lines;

    //Prompt the user for a file that has the graph data
    cout << "Please enter the file name to process: ";
    cin >> filename;

    recordFile.open(filename.c_str());

    if(recordFile.fail()){
            cout << "There was an error opening the file, try again: ";
            cin >> filename;
            recordFile.open(filename.c_str());
    }

    while(getline(recordFile, line)){

        if(line.length() > 0){
            lines.push_back(line);
        }
    }

    return lines;
}


void print(vector<int> &vec)
{
    for (vector<int>::iterator item = vec.begin(); item != vec.end(); ++item)
    {
        cout << *item << ' ';
    }

    cout << endl;
}

vector<int> generateDataSet(int n, string type = "")
{
	int val = 0;
    if (!type.compare("RANDOM"))
    {
        std::vector<int> ivec;

        for (int i = 1; i < n; ++i)
            ivec.push_back(rand());
        return ivec;
    }
    else if (!type.compare("DESC"))
    {
        std::vector<int> ivec(n);
        while(ivec.begin() != ivec.end()){
		*ivec.begin()++ = val;
		++val;
		
	 }
        std::reverse(ivec.begin(), ivec.end());
        return ivec;
    }
    else
    {
        std::vector<int> ivec(n);
       // iota(ivec.begin(), ivec.end(), 0);
	while(ivec.begin() != ivec.end()){
		*ivec.begin()++ = val;
		++val;
	}
        return ivec;
    }
}

void runSmallDataSet(vector<int> &dataSet)
{
    // Heap Sort
    HeapSort heap(dataSet);
    cout << "Vector before heap sort: ";
    print(heap.getVec());
    heap.sort();
    cout << "Vector after heap sort: ";
    print(heap.getVec());
    cout << endl;

    // Merge Sort
    MergeSort merg(dataSet);
    cout << "Vector before merge sort: ";
    print(merg.getVec());
    merg.sort();
    cout << "Vector after merge sort: ";
    print(merg.getVec());
    cout << endl;

    // Quick Sort
    QuickSort quick(dataSet);
    cout << "Vector before quick sort: ";
    print(quick.getVec());
    quick.sort();
    cout << "Vector after quick sort: ";
    print(quick.getVec());
    cout << endl;

    // Insert Sort
    InsertSort insertion(dataSet);
    cout << "Vector before insertion sort: ";
    print(insertion.getVec());
    insertion.sort();
    cout << "Vector after insertion sort: ";
    print(insertion.getVec());
    cout << endl;
}


double runtime(clock_t start, clock_t stop)
{
    return double(stop - start) / double(CLOCKS_PER_SEC);
}


void runLargeDataset(int n){
    // Define clock variable which will be used for timing
        clock_t start, stop;

    vector<int> randomVec = generateDataSet(n, "RANDOM");
    vector<int> descVec = generateDataSet(n, "DESC");
    vector<int> ascVec = generateDataSet(n);


     // Heap Sort
    HeapSort heapRandom(randomVec);
    start = clock();
    heapRandom.sort();
    stop = clock();
    cout << "Heap sort random: " << runtime(start, stop) << endl;

    HeapSort heapAsc(randomVec);
    start = clock();
    heapAsc.sort();
    stop = clock();
    cout << "Heap sort ascending: " << runtime(start, stop) << endl;

    HeapSort heapDesc(randomVec);
    start = clock();
    heapDesc.sort();
    stop = clock();
    cout << "Heap sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Merge Sort
    MergeSort mergeRandom(randomVec);
    start = clock();
    mergeRandom.sort();
    stop = clock();
    cout << "Merge sort random: " << runtime(start, stop) << endl;

    MergeSort mergeAsc(randomVec);
    start = clock();
    mergeAsc.sort();
    stop = clock();
    cout << "Merge sort ascending: " << runtime(start, stop) << endl;

    MergeSort mergeDesc(randomVec);
    start = clock();
    mergeDesc.sort();
    stop = clock();
    cout << "Merge sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Quick Sort
    QuickSort quickRandom(randomVec);
    start = clock();
    quickRandom.sort();
    stop = clock();
    cout << "Quick sort random: " << runtime(start, stop) << endl;

    QuickSort quickAsc(randomVec);
    start = clock();
    quickAsc.sort();
    stop = clock();
    cout << "Quick sort ascending: " << runtime(start, stop) << endl;

    QuickSort quickDesc(randomVec);
    start = clock();
    quickDesc.sort();
    stop = clock();
    cout << "Quick sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Insert Sort
    InsertSort insertionRandom(randomVec);
    start = clock();
    insertionRandom.sort();
    stop = clock();
    cout << "Insertion sort random: " << runtime(start, stop) << endl;

    InsertSort insertionAsc(randomVec);
    start = clock();
    insertionAsc.sort();
    stop = clock();
    cout << "Insertion sort ascending: " << runtime(start, stop) << endl;

    InsertSort insertionDesc(randomVec);
    start = clock();
    insertionDesc.sort();
    stop = clock();
    cout << "Insertion sort descending: " << runtime(start, stop) << endl;

    cout << endl;

}

int main(int argc, const char *argv[])
{

    vector<int> dataSet;

    // get the data from the input file
    vector<string> records = get_file();

	string line;
	istringstream iss(line);    

    // iterate through it to get what we want
    for(string s; iss >> s;)
    {

	int i = atoi(s.c_str());
	dataSet.push_back(i);
    }

    int N = 0;

    cout << "Enter the number of integers to sort: ";
    cin >> N;
    cout << endl;

    runSmallDataSet(dataSet);

    runLargeDataset(N);

    return 0;
}
