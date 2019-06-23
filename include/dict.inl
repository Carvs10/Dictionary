///DAL

///Constuctor
template <typename Key, typename Data, typename KeyComparator >
DAL< Key, Data, KeyComparator >::DAL(int MaxSz)
    
    //Default values
    : m_size( 0 )                    
    , m_capacity( MaxSz )            // Max Capacity = 50
    , mpt_Data( nullptr )            // Pointer to begin = nullptr
{

    if( MaxSz < 0)
    {
        std::cout << "Invalid value! Inserts a valid value!\n";
    }
    else{
        mpt_Data = new NodeD[ MaxSz];
    }
}

// Auxiliar Search
template <typename Key, typename Data, typename KeyComparator >
int DAL< Key, Data, KeyComparator >::_find( const Key & _z) const
{
    for( auto i = 0; i < m_size; i++){

        auto found = mpt_Data[ i].id;
        if( found == _z )
        {
            return i;
        } 
    }

    //returns -1 if _z was not found.
    return -1;

}


template <typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::search( const Key & _k, Data & _s) const
{

    //realizes the auxiliar serach
    
    int _p = _find( _k );

    // If the aux serch return -1, the element isn't in dictioanry
    if( _p != -1 )
    {

        _s = mpt_Data[ _p ].inf;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator>::remove( const Key & _k, Data & _s )
{
    
    // if the list is empty 
    if(m_size == 0)
    {
        return false;
    }

    // Position of the element in the list;
    auto pos = _find( _k );

    if( pos != -1 ) //! Not the last element
    {

        _s = mpt_Data[ pos ].inf;
        std::copy( &mpt_Data[ pos +1 ], &mpt_Data[ m_size+1], &mpt_Data[ pos ]);
        --m_size;

        return true;
    }
    else if( pos == (m_size-1) ) // The last elment
    {
        _s = mpt_Data[ pos].inf;
        --m_size;

        return true;
    }

    return false;
}


template <typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::insert( const Key & _newKey, const Data& _newInfo)
{


    // Check if it's possible to insert the element
    // In the case size == capacity, returns false;
    if( m_size == m_capacity)
    {
        return false;
    }
    else
    {
        
        mpt_Data[ m_size ].id = _newKey;
        mpt_Data[ m_size ].inf = _newInfo;

        ++m_size;

        return true;
    }
    
}

template <typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::min() const
{

    // Checks if the list is empty
    if( m_size == 0 )
    {
        throw std::out_of_range(" Empty Dictionary!\n");
    }

    // Compare Function.
    KeyComparator comp;

    // Asumming first element is the minor, once the list ins't in order
    int smaller = mpt_Data[ 0 ].id;
    int curr;

    for( int i = 1; i < m_size; i++)
    {

        curr = mpt_Data[i].id;
        if( comp( curr, smaller) )
        {
            smaller = curr;
        }
    }

    return smaller;

}

template <typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::max() const
{

    // Checks if the list is empty
    if( m_size == 0 )
    {
        throw std::out_of_range(" Empty Dictionary!\n");
    }

    // Compare Function
    KeyComparator comp;

    // Asumming first element is the bigger, once the list ins't in order
    int bigger = mpt_Data[0].id;
    int curr;

    for( int i = 1; i < m_size; i++)
    {

        curr = mpt_Data[i].id;
        if( comp( bigger, curr ) )
        {
            bigger = curr;
        }

    }

    return bigger;

}


template <typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::sucessor( const Key & _k, Key & _y) const
{

    // Checks for an empty list.
    if( m_size == 0 )
    {
        return false;
    }

    // Check if the elements is the bigger, for this case, it wouldn't have a succes.
    if( _k == max() )
    {
        return false;
    }

    // The element isn't in the dicionary.
    if( _find(_k) == -1)
    {
        return false;
    }

    KeyComparator comp;

    int succ = max();
    int curr;


    for(int i = 0; i < m_size; i++)
    {

        curr = mpt_Data[i].id;
        if( comp( _k, curr ) and comp( curr, succ ) )
        {
            succ = curr;
        }
    }

    _y = succ;
    return true;

}

template <typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::predecessor( const Key & _k, Key & _y ) const
{

    // Checks for an empty list.
    if( m_size == 0 )
    {
        return false;
    }

    // Check if the elements is the minor, for this case, it wouldn't have a predece.
    if( _k == min() )
    {
        return false;
    }

    // The element isn't in the dicionary.
    if( _find(_k) == -1 )
    {
        return false;
    }

    KeyComparator comp;

    int prev = min();
    int curr;


    for(int i = 0; i < m_size; i++)
    {

        curr = mpt_Data[i].id;
        if( comp( _k, curr ) and comp( curr, prev ) )
        {
            prev = curr;
        }
    }

    _y = prev;
    return true;
}

// DSAL

// Binary Search
template <typename Key, typename Data, typename KeyComparator>
int DSAL<Key, Data, KeyComparator>::_find( const Key & _x) const
{

    KeyComparator comp;
    int first, last, sz;


    sz = DAL< Key, Data, KeyComparator>::m_size;
    last = sz -1;
    first = 0;

    while( first <= last )
    {

        int mid = ( first + last )/2;
        int curr = DAL< Key, Data, KeyComparator>::mpt_Data[mid].id;

        if( _x == curr )
        {
            return mid;
        }
        else if (comp(_x, curr) )
        {
            last = mid-1;
        }
        else{
            first = mid+1;
        }

    }

    return -1;

}


template < typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::remove( const Key & _k, Data & _s)
{

    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;


    //Checks for an empty Dictionary.
    if( mi_size == 0 )
    {
        return false;
    }

    // Search for key _k position.
    auto pos = _find(_k);

    // If it's the first element.
    if( pos == (mi_size -1) )
    {

        _s = mi_Data[pos].inf;
        --mi_size;
        return true;
    }


    else if( pos != -1 )
    {
        _s = mi_Data[ pos ].inf;

        for(auto i = pos; i < mi_size-1; ++i)
        {

            mi_Data[ i ].id = mi_Data[ i +1 ].id;
            mi_Data[ i ].inf = mi_Data[ i + 1].inf;
        }

        --mi_size;
        return true;
    }

    return false;
}



template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::insert( const  Key & _newID, const Data & _newInfo)
{

    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;
    auto &mi_capacity = DAL<Key, Data, KeyComparator>::m_capacity;


    //Check if it'possible to insert
    if( mi_size == mi_capacity)
    {
        throw std::out_of_range("Full Dictionary!! Not possible to insert\n");
    }

    //Compare Funciton.
    KeyComparator comp;

    //Auxiliar Key to insertion;
    Key d_;


    auto test_p = 0;
    int pos = _find( _newID);

    //Search the right position to insert
    
    while( test_p < mi_size )
    {

        d_ = mi_Data[ test_p ].id;
        if( comp(d_, _newID ) )
        {
            pos = test_p;
        }

        ++test_p;
    }

    //Insertion in the end
    if( pos == mi_size-1 )
    {
        mi_Data[ mi_size ].id = _newID;
        mi_Data[ mi_size ].inf = _newInfo;

        ++mi_size;

        return true;
    }
    else if( pos == -1) // Insertion at the begin
    {

        // Reorganizes the list
        for( auto i = mi_size; i > pos+1; --i)
        {
            mi_Data[ i ].id = mi_Data[ i-1 ].id;
            mi_Data[ i ].inf = mi_Data[ i-1 ].inf;


        }

        mi_Data[ 0 ].id = _newID;
        mi_Data[ 0 ].inf = _newInfo;

        ++mi_size;

        return true;
    }
    else    // Otherwise it's at the middle
    {
        for( auto i = mi_size; i > pos+1; --i)
        {
            mi_Data[ i ].id = mi_Data[ i-1 ].id;
            mi_Data[ i ].inf = mi_Data[ i-1 ].inf;
        }

        mi_Data[ pos+1 ].id = _newID;
        mi_Data[ pos+1 ].inf = _newInfo;

        ++mi_size;

    }

    return false;
    

}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::min() const
{
    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

    //Check for an empty dictionary.
    if( mi_size == 0)
    {
        throw std::out_of_range(" Empty Dictionary!\n" );
    }

    return mi_Data[0].id;
}


template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::max() const
{

    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;


    if( mi_size == 0)
    {
        throw std::out_of_range( "Empty Dictionary!\n");
    }


    return mi_Data[ mi_size -1].id;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::sucessor( const Key & _k, Key & _y) const
{

    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

    // Position for key _k.
    int pos = _find(_k );

    // Exceptions
    //Position out of range
    if( pos == -1)
    {
        return false;
    }
    // Empty Dictionar or element is the last one.
    if( mi_size == 0 or pos == mi_size-1)
    {
        return false;
    }

    _y = mi_Data[pos+1].id;
    return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::predecessor(const Key & _k, Key & _y) const
{

    auto &mi_size = DAL<Key, Data, KeyComparator>::m_size;
    auto &mi_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

    // Position for key _k.
    int pos = _find(_k );
    

    //Position out of range
    if( pos == -1)
    {
        return false;
    }

    //  Empty Dictionar or element is the first one
    if( mi_size == 0 or pos == 0)
    {

        return false;
    }

    _y = mi_Data[ pos-1 ].id;
    return true;
}