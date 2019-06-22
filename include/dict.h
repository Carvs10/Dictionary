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

        

        bool remove ();


        bool search ();


        bool insert ();


        Key min () const;


        Key max () const;


        bool sucessor () const;


        bool predecessor () const;


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

        bool remove();


        bool insert();


        Key min() const;

    
        Key max() const;


        bool sucessor() const;


        bool predecessor() const;

    private:

        int _find() const;


};





#endif