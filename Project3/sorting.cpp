/* 
    Willia Hardy
    wjh25@zips.uakron.edu
    2905326
    Project3
*/

#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "heapsort.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <ctime>
#include <numeric>
#include <cstdlib>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::ifstream;
using std::iota;
using std::istringstream;
using std::string;
using std::vector;


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
        iota(ivec.begin(), ivec.end(), 0);
        std::reverse(ivec.begin(), ivec.end());
        return ivec;
    }
    else
    {
        std::vector<int> ivec(n);
        iota(ivec.begin(), ivec.end(), 0);
        return ivec;
    }
}

void runSmallDataSet(vector<int> &dataSet)
{
    // Heap Sort
    HeapSort heap(dataSet);
    cout << "vector before heap sort: ";
    print(heap.getVec());
    heap.sort();
    cout << "vector after heap sort: ";
    print(heap.getVec());
    cout << endl;

    // Merge Sort
    MergeSort merg(dataSet);
    cout << "vector before merge sort: ";

    print(merg.getVec());

    merg.sort();
    cout << "vector after merge sort: ";

    print(merg.getVec());
    cout << endl;

    // Quick Sort
    QuickSort quick(dataSet);
    cout << "vector before quick sort: ";

    print(quick.getVec());

    quick.sort();
    cout << "vector after quick sort: ";

    print(quick.getVec());
    cout << endl;

    // Insert Sort
    InsertSort inser(dataSet);
    cout << "vector before insertion sort: ";

    print(inser.getVec());

    inser.sort();
    cout << "vector after insertion sort: ";

    print(inser.getVec());
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
    cout << "heap sort random: " << runtime(start, stop) << endl;

    HeapSort heapAsc(randomVec);
    start = clock();
    heapAsc.sort();
    stop = clock();
    cout << "heap sort ascending: " << runtime(start, stop) << endl;

    HeapSort heapDesc(randomVec);
    start = clock();
    heapDesc.sort();
    stop = clock();
    cout << "heap sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Merge Sort
    MergeSort mergeRandom(randomVec);
    start = clock();
    mergeRandom.sort();
    stop = clock();
    cout << "merge sort random: " << runtime(start, stop) << endl;

    MergeSort mergeAsc(randomVec);
    start = clock();
    mergeAsc.sort();
    stop = clock();
    cout << "merge sort ascending: " << runtime(start, stop) << endl;

    MergeSort mergeDesc(randomVec);
    start = clock();
    mergeDesc.sort();
    stop = clock();
    cout << "merge sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Quick Sort
    QuickSort quickRandom(randomVec);
    start = clock();
    quickRandom.sort();
    stop = clock();
    cout << "quick sort random: " << runtime(start, stop) << endl;

    QuickSort quickAsc(randomVec);
    start = clock();
    quickAsc.sort();
    stop = clock();
    cout << "quick sort ascending: " << runtime(start, stop) << endl;

    QuickSort quickDesc(randomVec);
    start = clock();
    quickDesc.sort();
    stop = clock();
    cout << "quick sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Insert Sort
    InsertSort insertionRandom(randomVec);
    start = clock();
    insertionRandom.sort();
    stop = clock();
    cout << "insertion sort random: " << runtime(start, stop) << endl;

    InsertSort insertionAsc(randomVec);
    start = clock();
    insertionAsc.sort();
    stop = clock();
    cout << "insertion sort ascending: " << runtime(start, stop) << endl;

    InsertSort insertionDesc(randomVec);
    start = clock();
    insertionDesc.sort();
    stop = clock();
    cout << "insertion sort descending: " << runtime(start, stop) << endl;

    cout << endl;

}

int main(int argc, const char *argv[])
{

    vector<int> dataSet;

    // readData([&](string &line) {
    //     std::istringstream iss(line);
    //     for (std::string s; iss >> s;)
    //     {
    //         // Convert string to an int
    //         int i = std::stoi(s);
    //         dataSet.push_back(i);
    //     }
    // });
    int N = 0;

    cout << "Enter the number of integers to sort: ";
    cin >> N;
    cout << endl;

    runSmallDataSet(dataSet);

    runLargeDataset(N);

    return 0;
}