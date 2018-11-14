#ifndef quicksort_h
#define quicksort_h

using std::vector;

/
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> &a, int left, int right)
{
    int center = ( left + right ) / 2;

    if( a[center] < a[left] )
        std::swap( a[left], a[center] );
    if( a[right] < a[left] )
        std::swap( a[left], a[right] );
    if( a[right] < a[center] )
        std::swap( a[center], a[right] );

    // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

/
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort( vector<Comparable> &a, int left, int right )
{
    // This is where we change the quicksort to enter more than 10 pieces of data
    // For a base case of two elements, if left is greater -> swap

    if(left + 2 <= right)
    {

    // invoke median3 to select pivot
    const Comparable &pivot = median3(a, left, right);

    //begin partitioning
    int i = left, j = right - 1;
    for( ; ; )
    {
        while( a[ ++i ] < pivot ) {}
        while( pivot < a[ --j ] ) {}
        if( i < j )
            std::swap( a[ i ], a[ j ] );
        else
            break;

    }

    std::swap( a[i], a[right - 1]); //restore pivot
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
    }
    else{
        if(a[left] > a[right])
      std::swap(a[left], a[right]);
      return;
}
}

/**
 * Driver for quicksort
 */
template <typename Comparable>
void quicksort( std::vector<Comparable> &a )
{
    quicksort(a,0,a.size() - 1);
}
#endif /* quicksort_h */
