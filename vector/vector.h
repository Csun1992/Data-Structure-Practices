typedef int Rank;
#define DEFAULT_CAPACITY 3
#include<iostream>
using namespace std;

template <typename T>
class Vector{
protected:
    Rank _size; int _capacity; T* _element;
    void copyFrom( T const* , Rank , Rank );
    void expand();
    void shrink();
    Rank max( Rank , Rank ) const;
    
public:
    // Note how we created the default constructor. Two things worth noting are
    // 1. Use of initialization list and how we positioned the initialization list
    // 2. How we use a "for" loop to both assign initial elements and increase _size at same time
    Vector( int cap = DEFAULT_CAPACITY, int size = 0, T init = 0 )
    { _element = T[_capacity = cap], for(_size = 0; _size < size; _element[_size++] = init); } 
    // Note how the copy constructor just call a protected function 
    Vector( T const* arr, Rank n ) { copyFrom(arr, 0, n); }
    Vector( T const* arr, Rank lo, Rank hi ) { copyFrom(arr, lo, hi); }
    Vector(Vector<T> const& V ) { copyFrom(V._element, 0, V._size); }
    // Destructor, only delete the data members that are dynamically allocated
    // For other data members, just leave to the garbage collector
    ~Vector() { delete [] _element; _element = nullptr; }
    // Accessors
    Rank size() const { return _size; }
    // see how clean the code is in writing the empty() function
    bool empty() const { return !_size; }
    Rank find( T const& e ) const { return find( e, 0, _size ); };
    Rank find( T const& , Rank , Rank ) const; 
    T& operator[] (Rank ) const;
    Vector<T> & operator=( Vector<T> const& );
    T remove( Rank );
    int remove( Rank lo, Rank hi );
    Rank insert( Rank r, T const& e );
    Rank insert(T const& e) { return insert(_size, e); }
    int deduplicate();
    void traverse();
};
