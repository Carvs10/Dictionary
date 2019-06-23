#ifndef DAL_H
#define DAL_H

#include <iostream>
#include <string>

template < typename Key, typename Data, typename KeyCompar >
class DAL
{


    private:
        struct NodeD // Struxt of Node, represents pair (Key, Info) .
        {
            Key id; // 
            Data inf;
        };

        int _find ( const Key & _z) const ; // Search Auxiliar Method.

        static const int DEF_SIZE = 50;
        int m_size; // Size of the current list.
        int  m_capacity; // Maximum capacity of the list.
        NodeD * mpt_Data; 

    public:

        //Constructor and Desctuctor.

        DAL ( int MaxSz = DEF_SIZE );

        virtual ~DAL()
        { delete [] mpt_Data;};

        /*! remove from list the element associated with key _k,
         * and saves in _s
         * 
         * @param _k key to be removed
         * @param _s saves the value to be removed
         * 
         * @return true if finds teh element.
         * 
         */

        bool remove ( const Key & _k, Data & _s );
        
        /*! Search the element from key _k.
         * 
         * @param _k key to be searched.
         * @param _s saves the key to be searched.
         * 
         * @return true if the _k is in the list .
         */

        bool search ( const Key & _k, Data & _s) const; // Public Search

        /*! Inserts int the list the element for key _newID and info _newInfo.
         *
         * @param _newKey, key to be inserted.
         * @param _newInfo, value to be inserted
         * 
         * @return true if success, otherwise false 
         */

        bool insert ( const Key & _newKey, const Data & _newInfo);

        /*! Recovers the minor key value in the list .
         *
         * return -1 if the list is empty, otherwise the key value
         * 
        */

        Key min () const;

        
        /*! Recovers the bigger key value in the list .
         *
         * return -1 if the list is empty, otherwise the key value
         * 
        */

        Key max () const;

        /*! recovers in _y, the sucessor for key _k
         *
         * @param _k, the key to be found
         * @param _y, the sucessor for _k
         * 
         * @return true if finds.
         */

        bool sucessor ( const Key & _k, Key _y) const;
        
        /*! recovers in _y, the predecessor for key _k
         *
         * @param _k, the key to be found
         * @param _y, the predecessor for _k
         * 
         * @return true if finds.
         */


        bool predecessor ( const Key & _k, Key _y ) const;


        //! Overload of operator<< for prints the list(Dictionary)
        inline friend
        std::ostream &operator <<( std::ostream& _os, const DAL & _oList)
        {

            _os << "----------------------------------------\n";
            for( int i = 0; i < _oList.m_size; i++)
            {
                
                _os << "Element Nº(" << i+1 << ") = {id: " << _oList.mpt_Data[i].id << ", info: "
                        << _oList.mpt_Data[i].inf << "}\n";
            }

            _os << "----------------------------------------";

            return os; 
        }

};


template < typename Key, typename Data, typename KeyCompar >
class DSAL : public DAL < Key, Data, KeyCompar>{


    public:

        DSAL( int MaxSz )
                : DAL< Key, Data, KeyCompar>(MaxSz)
        {/* empty */};

        virtual ~DSAL()
        {/* empty */};

        /*! remove from list the element associated with key _k,
         * and saves in _s
         * 
         * @param _k key to be removed
         * @param _s saves the value to be removed
         * 
         * @return true if finds teh element.
         * 
         */

        bool remove( const Key & _k, Data & _s);

        /*! Recovers the minor key value in the list .
         *
         * return -1 if the list is empty, otherwise the key value
         * 
        */

        Key min() const;


        /*! Recovers the bigger key value in the list .
         *
         * return -1 if the list is empty, otherwise the key value
         * 
        */
    
        Key max() const;

        /*! recovers in _y, the sucessor for key _k
         *
         * @param _k, the key to be found
         * @param _y, the sucessor for _k
         * 
         * @return true if finds
         */

        bool sucessor( const Key & _k, Key & _y) const;

        /*! recovers in _y, the predecessor for key _k
         *
         * @param _k, the key to be found
         * @param _y, the predecessor for _k
         * 
         * @return true if finds
         */


        bool predecessor( const Key & _k, Key & _y) const;

        /*! Inserts int the list the element for key _newID and info _newInfo.
         *
         * @param _newID, key to be inserted.
         * @param _newInfo, value to be inserted
         * 
         * @return true if success, otherwise false 
         */

        bool insert( const Key & _newID, const Data & _newInfo );

    private:

        int _find( const Key & _x) const;


};

#include "dict.inl"

#endif