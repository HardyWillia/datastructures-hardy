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
using std::swap;
using std::move;



//Function to get the file contents
vector<int> get_file(){

    ifstream recordFile;
    string filename;
    string line;
    vector<int> nums;

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

            nums.push_back(stoi(line));
    }

    return nums;
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
	iota(ivec.begin(), ivec.end(), 0);
        std::reverse(ivec.begin(), ivec.end());
        return ivec;
    }
    else
    {
        std::vector<int> ivec(n);
       iota(ivec.begin(), ivec.end(), 0);
	while(ivec.begin() != ivec.end()){
		*ivec.begin()++ = val;
		++val;
	}
        return ivec;
    }
}

void runSmallDataSet(vector<int> &dataSet)
{
    
    vector<int> original = get_file();
    vector<int> sortheap = original;
    vector<int> sortmerge = original;
    vector<int> sortquick = original;
    vector<int> sortinsert = original;


    cout << "Vector before heap sort: ";
    for(vector<int>::iterator iter = sortheap.begin(); iter != sortheap.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Vector after heap sort: ";
    heapsort<int>(sortheap);
    for(vector<int>::iterator iter = sortheap.begin(); iter != sortheap.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Vector before merge sort: ";
    for(vector<int>::iterator iter = sortmerge.begin(); iter != sortmerge.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Vector after merge sort: ";
    mergeSort<int>(sortmerge);
    for(vector<int>::iterator iter = sortmerge.begin(); iter != sortmerge.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n";
    cout << endl;
	
    cout << "Vector before quick sort: ";
    for(vector<int>::iterator iter = sortquick.begin(); iter != sortquick.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Vector after quick sort: ";
    quicksort<int>(sortquick);
    for(vector<int>::iterator iter = sortquick.begin(); iter != sortquick.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << endl;
	
    cout << "Vector before insertion sort: ";
    for(vector<int>::iterator iter = sortinsert.begin(); iter != sortinsert.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Vector after insertion sort: ";
    insertSort<int>(sortinsert);
    for(vector<int>::iterator iter = sortinsert.begin(); iter != sortinsert.end(); iter++)
    {
        cout << *iter << " ";
    }

    cout << endl;
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
    start = clock();
    heapsort<int>(randomVec);
    stop = clock();
    cout << "Heap sort random: " << runtime(start, stop) << endl;
    
    start = clock();
    heapsort<int>(ascVec);
    stop = clock();
    cout << "Heap sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    heapsort<int>(descVec);
    stop = clock();
    cout << "Heap sort descending: " << runtime(start, stop) << endl;

    cout << endl;
	

    // Merge Sort
    start = clock();
    mergeSort<int>(randomVec);
    stop = clock();
    cout << "Merge sort random: " << runtime(start, stop) << endl;

    start = clock();
    mergeSort<int>(ascVec);
    stop = clock();
    cout << "Merge sort ascending: " << runtime(start, stop) << endl;
	
    start = clock(); 
    mergeSort<int>(descVec);
    stop = clock();
    cout << "Merge sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Quick Sort
    
    start = clock();
    quicksort<int>(randomVec, 0, randomVec.size() - 1);
    stop = clock();
    cout << "Quick sort random: " << runtime(start, stop) << endl;

    start = clock();
    quicksort<int>(ascVec);
    stop = clock();
    cout << "Quick sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    quicksort<int>(descVec);
    stop = clock();
    cout << "Quick sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    // Insert Sort
    start = clock();
    insertSort<int>(randomVec);
    stop = clock();
    cout << "Insertion sort random: " << runtime(start, stop) << endl;

    start = clock();
    insertSort<int>(ascVec);
    stop = clock();
    cout << "Insertion sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    insertSort<int>(descVec);
    stop = clock();
    cout << "Insertion sort descending: " << runtime(start, stop) << endl;

    cout << endl;
	

}


//Main running program
int main(int argc, const char *argv[])
{

    vector<int> dataSet;

    int N = 0;

    cout << "Enter the number of integers to sort: ";
    cin >> N;
    cout << endl;

    runSmallDataSet(dataSet);

    runLargeDataset(N);

    return 0;
}
