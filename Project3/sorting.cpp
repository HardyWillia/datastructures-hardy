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
	
    cout << "Vector before quick sort (no cutoff): ";
    for(vector<int>::iterator iter = sortquick.begin(); iter != sortquick.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Vector after quick sort (no cutoff): ";
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


void runLargeDataset(int N){
    

     // Define clock variable which will be used for timing
     clock_t start, stop;

    //Get random numbers to generate
    vector<int> ascVec;
    for (int x = 1; x <= N; x++)
    {
        ascVec.push_back(x);
    }

    vector<int> descVec;
    for (int x = N; x != 0; x--)
    {
        descVec.push_back(x);
    }

    vector<int> randomVec;
    for (int x = 1; x <= N; ++x)
    {
        int y = rand() % N+1;
        randomVec.push_back(y);

    }

    vector<int> randomVec2 = randomVec;
    vector<int> descVec2 = descVec;
    vector<int> ascVec2 = ascVec;

     // Heap Sort
    start = clock();
    heapsort(randomVec2);
    stop = clock();
    cout << "Heap sort random: " << runtime(start, stop) << endl;
    
    start = clock();
    heapsort(ascVec2);
    stop = clock();
    cout << "Heap sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    heapsort(descVec2);
    stop = clock();
    cout << "Heap sort descending: " << runtime(start, stop) << endl;

    cout << endl;
	

    randomVec2 = randomVec;
    descVec2 = descVec;
    ascVec2 = ascVec;
	
    // Merge Sort
    start = clock();
    mergeSort(randomVec2);
    stop = clock();
    cout << "Merge sort random: " << runtime(start, stop) << endl;

    start = clock();
    mergeSort(ascVec2);
    stop = clock();
    cout << "Merge sort ascending: " << runtime(start, stop) << endl;
	
    start = clock(); 
    mergeSort(descVec2);
    stop = clock();
    cout << "Merge sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    randomVec2 = randomVec;
    descVec2 = descVec;
    ascVec2 = ascVec;
	
    // Quick Sort
    start = clock();
    quicksort(randomVec2);
    stop = clock();
    cout << "Quick sort random: " << runtime(start, stop) << endl;

    start = clock();
    quicksort(ascVec2);
    stop = clock();
    cout << "Quick sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    quicksort(descVec2);
    stop = clock();
    cout << "Quick sort descending: " << runtime(start, stop) << endl;

    cout << endl;

    randomVec2 = randomVec;
    descVec2 = descVec;
    ascVec2 = ascVec;
	
    // Insert Sort
    start = clock();
    insertSort(randomVec2);
    stop = clock();
    cout << "Insertion sort random: " << runtime(start, stop) << endl;

    start = clock();
    insertSort(ascVec2);
    stop = clock();
    cout << "Insertion sort ascending: " << runtime(start, stop) << endl;

    start = clock();
    insertSort(descVec2);
    stop = clock();
    cout << "Insertion sort descending: " << runtime(start, stop) << endl;

    cout << endl;
	

}


//Main running program
int main(int argc, const char *argv[])
{

    vector<int> dataSet;

    int N;

    cout << "Enter the number of integers to sort: ";
    cin >> N;
    cout << endl;

    runSmallDataSet(dataSet);

    runLargeDataset(N);

    return 0;
}
