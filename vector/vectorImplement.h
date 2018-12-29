#include "vector.h"
using namespace std;

template <typename T>
void Vector<T>::copyFrom( T const* arr, Rank lo, Rank hi ) {
    _element = new T[ _capacity = 2 * (hi - low) ]; _size = 0;
    while(lo++ < hi) { _element[_size++] = arr[lo]; }
}

template <typename T>
void Vector<T>::expand() {
    if( _size < _capacity ) return;
    if( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY;
    T* temp = _element;
    _element = new T[_capacity <<=1];
    for(int i = 0; i < _size; i++) {_element[i] = temp[i];}
    delete [] temp; temp = nullptr;
}
template <typename T>
void Vector<T>::shrink() {
    if(_capacity < DEFAULT_CAPACITY << 1) return;
    if(_size << 2 > _capacity)
    if(_size < _capacity / 2){
        T* temp = _element;
        _element = new T[_capacity >>= 1];// careful of the use of the syntax
        for(int i = 0; i < _size; i++) { _element[i] = temp[i]; }
        delete [] temp; 
    }
}

template <typename T>
Rank Vector<T>::max( Rank lo, Rank hi ) const {
    int result = _element[lo];
    while(lo++ < hi) result = result > _element[lo] ? result : _element[0];
    return result;
}

template <typename T>
Rank Vector<T>::find( T const& e, Rank lo, Rank hi) const {
    while( (lo++ < hi) && (e != _element[lo]) );
    // if did not find the element, return a number that is greater than hi
    return lo;
} 
template <typename T>
T& Vector<T>::operator[] (Rank r) const { return _element[r]; }

template <typename T>
Vector<T> & Vector<T>::operator=( Vector<T> const& vec ) {
    // check whether the _element is nullptr or not before
   // deletion; We do not need the old data so does not have 
   // to use a temporary pointer to point to the old location
    if( _element ) delete [] _element; 
    copyFrom(vec._element, 0, vec._size);
    return *this; // careful of here that we need to return a reference to this object
}

template <typename T>
T Vector<T>::remove( Rank r) {

}
template <typename T>
int Vector<T>::remove( Rank lo, Rank hi );
template <typename T>
Rank Vector<T>::insert( Rank r, T const& e );
template <typename T>
int Vector<T>::deduplicate();
template <typename T>
void Vector<T>::traverse();
