#ifndef quicksort_h
#define quicksort_h

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right)
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

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and no cutoff.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
  
  //Function that was changed to allow for more than 10 elements
    if (left + 1 >= right)
    {
        std::swap(a[left], a[right]);
        return;
    }

    const int &pivot = median3( a, left, right );
    
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



#endif /* quicksort_h */
