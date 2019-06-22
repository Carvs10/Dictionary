///DAL

///Constuctor
template <typename Key, typename Data, typename KeyCompar >
DAL< Key, Data, KeyCompar >::DAL(int MaxSz)
    
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
template <typename Key, typename Data, typename KeyCompar >
int DAL< Key, Data, KeyCompar >::_find( const Key & _z) const
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


template <typename Key, typename Data, typename KeyCompar >
bool DAL< Key, Data, KeyCompar >::search( const Key & _k, Data & _s) const
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

template <typename Key, typename Data, typename KeyCompar >
bool DAL< Key, Data, KeyCompar >::remove( const Key & _k, Data _s)
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


template <typename Key, typename Data, typename KeyCompar >
bool DAL< Key, Data, KeyCompar >::insert( const Key & _newKey, const Data& _newInfo)
{


    // Check if it's possible to insert the element
    // In the case size == capacity, returns false;
    if( m_size == m_capacity)
    {
        return false;
    }
    else
    {
        
        mpt_Data[ m_size ].if = _newKey;
        mpt_Data[ m_size ].inf = _newInfo;

        ++m_size;

        return true;
    }
    
}

template <typename Key, typename Data, typename KeyCompar >
Key DAL< Key, Data, KeyCompar >::min() const
{

    // Checks if the list is empty
    if( m_size == 0 )
    {
        throw std::out_of_range(" Empty Dictionary!\n");
    }

    // Compare Function.
    KeyCompar comp;

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

template <typename Key, typename Data, typename KeyCompar >
Key DAL< Key, Data, KeyCompar >::max() const
{

    // Checks if the list is empty
    if( m_size == 0 )
    {
        throw std::out_of_range(" Empty Dictionary!\n");
    }

    // Compare Function
    KeyCompar comp;

    // Asumming first element is the bigger, once the list ins't in order
    int bigger = mpt_Data[i].id;
    int curr;

    for( int i = 1; i < m_size; i++)
    {

        curr = mpt_Data[i].id;
        if( comp( bigger, curr) )
        {
            bigger = curr;
        }

        return bigger;
    }


}