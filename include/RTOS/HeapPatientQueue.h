// heappatientqueue.h
#pragma once

#include "../stl/cstdint.h"
#include "../stl/type_traits.h"
#include "../stl/utility.h"

namespace vAVR {

    template<typename TypeNode, stl::uint8_t CAPACITY>
    class HeapPatientQueue
    {
        static_assert(CAPACITY > 127, "Queue is too big for the buffer");
        using size_type = size_t;

    public:
        HeapPatientQueue() = default;
        ~HeapPatientQueue() = default;

        // construct from an element
        explicit HeapPatientQueue(TypeNode* val);

        // delete move and copy constructors
        HeapPatientQueue(const HeapPatientQueue&) = delete;
        HeapPatientQueue(HeapPatientQueue&&) = delete;
        // delete move and copy assignments
        HeapPatientQueue& operator=(const HeapPatientQueue&) = delete;
        HeapPatientQueue& operator=(HeapPatientQueue&&) = delete;

        // basic operations of HeapPatientQueue
        bool isEmpty() const;
        bool isFull() const;
        size_type size() const;

        // push a new element
        void push_back(const TypeNode* value, stl::int8_t priority);

        // pop and get an element
        TypeNode* pop_front();

    private:
        stl::int8_t count = -1;

        struct heapPair
        {
            heapPair(TypeNode* n, stl::int8_t p) 
                : node(n), priority(p) {}
            TypeNode* node;
            stl::int8_t priority;
        };
        heapPair elements[CAPACITY];

        void swap(stl::int8_t child, stl::int8_t parent);
        void bubbleUpNode(stl::int8_t index);
        void bubbleDownRoot(stl::int8_t indexRoot);
    };

    template<typename TypeNode, stl::uint8_t CAPACITY>
    HeapPatientQueue<TypeNode, CAPACITY>::HeapPatientQueue(TypeNode* val)
    {
        elements[0] = heapPair(val, 1);
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    bool HeapPatientQueue<TypeNode, CAPACITY>::isEmpty() const
    {
        return (count == -1);
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    bool HeapPatientQueue<TypeNode, CAPACITY>::isFull() const
    {
        return (count == CAPACITY - 1);
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    typename HeapPatientQueue<TypeNode, CAPACITY>::size_type HeapPatientQueue<TypeNode, CAPACITY>::size() const
    {
        return CAPACITY;
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    void HeapPatientQueue<TypeNode, CAPACITY>::push_back(const TypeNode* value, stl::int8_t priority)
    {
        if (isFull()) return; //TODO: I don't want to ignore these. Implement some waiting once kernel

        ++count;
        elements[count] = heapPair(value, priority);
        bubbleUpNode(count);
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    TypeNode* HeapPatientQueue<TypeNode, CAPACITY>::pop_front()
    {
        if (isEmpty()) return nullptr; //TODO: I don't want to ignore these. Implement some waiting once kernel

        TypeNode* node = (this->elements[0]).node;
        (this->elements[0]) = (this->elements[count]);
        --count;
        bubbleDownRoot(0);
        return node;
    }

    template<typename TypeNode, stl::uint8_t CAPACITY>
    void HeapPatientQueue<TypeNode, CAPACITY>::swap(stl::int8_t child, stl::int8_t parent)
    {
        // store the parent on a temporal value
        auto tmp = this->elements[parent];
        // save the children on the parent's position
        this->elements[parent] = this->elements[child];
        // put the parent back to his new position (at children)
        this->elements[child] = tmp;
    }

    /*
     * Implementation notes: bubbleUpNode
     * ------------------------------------
     * This function sorts the Heap to its appropiate order,
     * moving a given node up to his correspondent position
     *   Pseudocode:
     *      given index x on the array, compare if it has
     *      a more important priority than his parent,
     *      if so, swap them, otherwise finish.
     */
    template<typename TypeNode, stl::uint8_t CAPACITY>
    void HeapPatientQueue<TypeNode, CAPACITY>::bubbleUpNode(stl::int8_t index)
    {
        stl::int8_t parent = index / 2; // integer division, it floors the result
        while (this->elements[index].priority
            < this->elements[parent].priority)
        {
            this->swap(index, parent);
            // update parent and children indexes
            index = parent;
            parent = index / 2;
        }
    }

    /*
     * Implementation notes: bubbleDownRoot
     * ------------------------------------
     * This function moves down an index that has
     * childrens with more priority. The parameter
     * "indexRoot" is the index suspected
     * to be in the wrong place
     *  Pseudocode:
     *    Given an index, explore if it has a smaller
     *       value than both its children.
     *    If one children is smaller, we swap it with the children
     *       that has the highest priority
     *    Else, the value is sorted.
     */
    template<typename TypeNode, stl::uint8_t CAPACITY>
    void HeapPatientQueue<TypeNode, CAPACITY>::bubbleDownRoot(stl::int8_t indexRoot)
    {
        while (indexRoot * 2 < this->count)
        {
            stl::int8_t indexPrior = (this->elements[indexRoot]).priority;
            stl::int8_t lfChldPr = (this->elements[indexRoot * 2]).priority;
            stl::int8_t rgChldPr = 127;

            if (indexRoot * 2 + 1 < (this->count))
            {
                rgChldPr = (this->elements[indexRoot * 2 + 1]).priority;
            }

            // if it has a children with more priority
            if ((indexPrior > lfChldPr) || (indexPrior > rgChldPr))
            {
                if (lfChldPr < rgChldPr) // must swap with left
                {
                    this->swap(indexRoot, indexRoot * 2);
                    indexRoot = indexRoot * 2;

                }
                else // must swap with right (ignoring case of equality, just choose right)
                {
                    this->swap(indexRoot, indexRoot * 2 + 1);
                    indexRoot = indexRoot * 2 + 1;
                }
            }
        }
    }
}