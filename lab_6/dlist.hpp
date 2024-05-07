#pragma once

#include <iterator>
#include <stdexcept>

namespace rk6
{
    template <class T> class list;
    template <class T> class list_entry;
}

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

template <class T>
class rk6::list
{
    using node = rk6::list_entry<T>;
    public:
        struct iterator
        {
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = T;
            using difference_type = ptrdiff_t;
            using pointer = value_type*;
            using reference = value_type&;
            using const_pointer = const pointer;
            using reverse_iterator = std::reverse_iterator<iterator>;
            using const_reverse_iterator = std::reverse_iterator<iterator>;
            
            node * ptr;
            iterator (node * N) : ptr (N) {}
            iterator& operator++ () { ptr = ptr->next; return *this; }
            iterator operator++ (int) { auto temp = *this; ptr = ptr->next; return temp; }
            iterator& operator-- () { ptr = ptr->prev; return *this; }
            iterator operator-- (int) { auto temp = *this; ptr = ptr->prev; return temp; }
            bool operator== (iterator it) {return this->ptr == it.ptr; }
            bool operator!= (iterator it) {return this->ptr != it.ptr; }
            reference operator* () { return ptr->value; }
        };
        
        using reverse_iterator = typename iterator::const_reverse_iterator;

        list () : root (nullptr) {}
        list (T value) : root (new node(value, nullptr, nullptr)) {}

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

        node * push_front (T value) noexcept
        {
            if (!root) return root = new node(value);
            node * curr = root;
            while (curr -> next) curr = curr -> next;
            curr -> next = new node(value);
            curr -> next -> prev = curr;
            return curr -> next;
        }
        
        node * push_back (T value) noexcept
        {
            if (!root) return root = new node(value);
            node * curr = root;
            while (curr -> prev) curr = curr -> prev;
            curr -> prev = new node(value);
            curr -> prev -> next = curr;
            return curr -> prev;
        }

        node * get_first ()
        {
            if (!root) throw std::runtime_error ("List is empty");
            node * curr = root;
            while (curr -> prev) curr = curr -> prev;
            return curr;
        }
        
        node * get_last ()
        {
            if (!root) throw std::runtime_error ("List is empty");
            node * curr = root;
            while (curr -> next) curr = curr -> next;
            return curr;
        }

        node * insert (std::size_t place, T value, bool push_back = false)
        {
            node * at_place = this->get(place);
            if (push_back) return this->insert_after(at_place, value);
            else return this->insert_before(at_place, value);
        }

        node * insert_after (node * other, T value)
        {
            node * temp = new node (value, other->next, other);
            if (other->next) other->next->prev = temp;
            other->next = temp;
            return temp;
        }

        node * insert_before (node * other, T value)
        {
            node * temp = new node (value, other, other->prev);
            if (other->prev) other->prev->next = temp;
            other->prev = temp;
            return temp;
        }

        void pop (node * addr)
        {
            if (addr == root) root = addr->next;
            if (addr->next) addr->next->prev = addr->prev;
            if (addr->prev) addr->prev->next = addr->next;
            delete addr;
        }

        iterator begin() { return this->get_first(); }
        iterator end() { return this->get_last()->next; }
        reverse_iterator rbegin()
        {
            node * P = this->push_front({});
            return reverse_iterator(P);
        }
        reverse_iterator rend()   { return reverse_iterator(this->begin()); }

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
        node * root;
};
