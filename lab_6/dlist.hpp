/* Doubly linked list (DLL) implementatioan
 * Author - Nikolay Gubankov (nikgub_)
 */

#pragma once

#include <iterator>
#include <stdexcept>

namespace rk6
{
    template <class T> class list;
    template <class T> class list_entry;
}

/*
 * Class template that represents a node of a DLL
 * @field value - value at this node
 * @field next - next node in DLL
 * @dield prev - previous node in DLL
 */
template <class T>
struct rk6::list_entry
{
    friend rk6::list<T>;
    using node = rk6::list_entry<T>;
    T value;
    node * next;
    node * prev;
    list_entry (T v = {}, node * n = nullptr, node * p = nullptr)
        : value (v), next (n), prev (p)
        {
        }
};

/* Class template representing DLL that can be passed by value and doesnt decay into a pointer
 * Total size on x86_64 architecture - 8 bytes
 */
template <class T>
class rk6::list
{
    using node = rk6::list_entry<T>;
   
    public:
        /* Bidirectional aist iterator as defined by C++11 iterator classification
         */
        struct iterator
        {
            // All of these must be defined according to C++11 (and onward)
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = T;
            using difference_type = ptrdiff_t;
            using pointer = value_type*;
            using reference = value_type&;
            using const_pointer = const pointer;
            using reverse_iterator = std::reverse_iterator<iterator>;
            using const_reverse_iterator = std::reverse_iterator<iterator>;
            
            // Pointer to a node at a list
            node * ptr;
            
            // All of these must be defined according to C++11 (and onward)
            iterator (node * N) : ptr (N) {}
            iterator& operator++ () { ptr = ptr->next; return *this; }
            iterator operator++ (int) { auto temp = *this; ptr = ptr->next; return temp; }
            iterator& operator-- () { ptr = ptr->prev; return *this; }
            iterator operator-- (int) { auto temp = *this; ptr = ptr->prev; return temp; }
            bool operator== (iterator it) {return this->ptr == it.ptr; }
            bool operator!= (iterator it) {return this->ptr != it.ptr; }
            reference operator* () { return ptr->value; }
        };
        
        // Simply for convenience
        using reverse_iterator = typename iterator::const_reverse_iterator;

        // Default constructor
        list () : root (nullptr) {}
        // Constructor that initializes first element
        list (T value) : root (new node(value, nullptr, nullptr)) {}

        /* Returns list's element at index
         * @param d - index to return
         */
        node * get (std::size_t d = 0)
        {
            if (!root) throw std::runtime_error ("List is empty");
            if (!d) return this->get_first();
            node * curr = this->get_first();
            if (d > 0)
            {
                for (std::size_t i = 0; i < d; i++)
                {
                    curr = curr -> next;
                    if (!curr) throw std::out_of_range("rk6::list::get");
                }
            }
            return curr;
        }

        /* Adds an element to the front of list
         * @param value - value to add
         */
        node * push_front (T value) noexcept
        {
            if (!root) return root = new node(value);
            node * curr = root;
            while (curr -> next) curr = curr -> next;
            curr -> next = new node(value);
            curr -> next -> prev = curr;
            return curr -> next;
        }
        
        /* Adds an element to the back of list
         * @param value - value to add
         * Returns the added node's address
         */
        node * push_back (T value) noexcept
        {
            if (!root) return root = new node(value);
            node * curr = root;
            while (curr -> prev) curr = curr -> prev;
            curr -> prev = new node(value);
            curr -> prev -> next = curr;
            return curr -> prev;
        }

        /* Returns the first element in the list (not to be confused with list's root)
         */
        node * get_first ()
        {
            if (!root) throw std::runtime_error ("List is empty");
            node * curr = root;
            while (curr -> prev) curr = curr -> prev;
            return curr;
        }
        
        /* Returns the last element in the list (not to be confused with list's root)
         */
        node * get_last ()
        {
            if (!root) throw std::runtime_error ("List is empty");
            node * curr = root;
            while (curr -> next) curr = curr -> next;
            return curr;
        }

        /* Returns list's current size
         */
        std::size_t size ()
        {
            std::size_t ret = 0;
            node * curr = this->get_first();
            while (curr)
            {
                curr = curr -> next;
                ret++;
            }
            return ret;
        }

        /* Inserts an element at index
         * @param place - index
         * @param value - value to insert
         */
        node * insert (std::size_t place, T value)
        {
            node * at_place = this->get(place);
            if (push_back) return this->insert_after(at_place, value);
            else return this->insert_before(at_place, value);
        }

        /* Inserts an element after a node
         * @param other - address of a target node
         * @param value - value to insert
         */
        node * insert_after (node * other, T value)
        {
            node * temp = new node (value, other->next, other);
            if (other->next) other->next->prev = temp;
            other->next = temp;
            return temp;
        }

        /* Inserts an element before a node
         * @param other - address of a target node
         * @param value - value to insert
         */
        node * insert_before (node * other, T value)
        {
            node * temp = new node (value, other, other->prev);
            if (other->prev) other->prev->next = temp;
            other->prev = temp;
            return temp;
        }

        /* Deletes a node
         * @param addr - node to delete
         */
        void pop (node * addr)
        {
            if (addr == root) root = addr->next;
            if (addr->next) addr->next->prev = addr->prev;
            if (addr->prev) addr->prev->next = addr->next;
            delete addr;
        }

        /* Swaps two nodes in a list
         * Does not provide a guard against swapping nodes outside of a list
         * @param first, second - nodes to swap
         */
        void stupid_swap (node * first, node * second)
        {
            this->insert_after (first, second->value);
            this->insert_after (second, first->value);
            this->pop (second);
            this->pop (first);
        }

        iterator begin() { return this->get_first(); }
        iterator end() { return this->get_last()->next;}
        // Unused and unstable, omits the last element
        reverse_iterator rbegin() { return reverse_iterator(this->get_last()); }
        // Unused and unstable
        reverse_iterator rend()   { return reverse_iterator(this->begin()); }

        /* Deletes all nodes in a list
         */
        ~list ()
        {
            node * curr = this->get_first(), * temp;
            while (curr)
            {
                temp = curr;
                curr = curr -> next;
                delete temp;
            }
        }
    private:
        /* Pointer to the root of the list
         * Root is the first element upon initializing list
         * Will not be first after new elements are pushed back so don't rely on it
         */
        node * root;
};
