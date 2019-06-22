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

template <typename Key, typename Data, typename KeyCompar >
DAL< Key, Data, KeyCompar >::_find( const Key & _z) const
{

    
}