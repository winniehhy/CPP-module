#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set 
{
    private :
        searchable_bag& bag;
    
    public :
        set(searchable_bag& bag);
        set(const set& other);
        ~set();
        set& operator=(const set& other);

        void insert(int);
        void insert (int* , int);
        void print() const;
        void clear();
        bool has(int)const;

        searchable_bag& get_bag();


};

#endif