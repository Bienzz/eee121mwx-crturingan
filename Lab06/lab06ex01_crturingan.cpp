#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <class S>
class DNode {
private:
    S data;
    DNode<S> *next;
    DNode<S> *prev;

public:
    DNode(S data, DNode *next = NULL, DNode *prev = NULL);
    template <typename T>
    friend class DLinkedList;
};

template <typename S>
DNode<S>::DNode(S data, DNode *next, DNode *prev) : data(data), next(next), prev(prev) {}

template <class T>
class DLinkedList {
private:
    DNode<T> *head;
    DNode<T> *tail;
    int size;

public:
    DLinkedList();
    ~DLinkedList();
    void addFront(T val);
    void addBack(T val);
    void insertAtIndex(T val, int index);
    void removeAtIndex(int index);
    T removeFront();
    T removeBack();
    T front();
    T back();
    int getSize();
};

template <typename T>
DLinkedList<T>::DLinkedList()
{
    this->head = new DNode<T>(T(), NULL, NULL);
    this->tail = new DNode<T>(T(), NULL, NULL);
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->size = 0;
}

template <typename T>
DLinkedList<T>::~DLinkedList()
{
    while (this->size > 0)
        this->removeBack();
    delete this->head;
    delete this->tail;
}

template <typename T>
void DLinkedList<T>::addFront(T val)
{
    DNode<T> *tmpNode = new DNode<T>(T(val), this->head->next, this->head);
    this->head->next = tmpNode;
    tmpNode->next->prev = tmpNode;
    this->size++;
}

template <typename T>
void DLinkedList<T>::addBack(T val)
{
    DNode<T> *tmpNode = new DNode<T>(T(val), this->tail, this->tail->prev);
    this->tail->prev = tmpNode;
    tmpNode->prev->next = tmpNode;
    this->size++;
}

template <typename T>
void DLinkedList<T>::insertAtIndex(T val, int index)
{
    // Check if the index is valid
    if (index < 0 || index > this->size)
    {
        std::cout << "Invalid index\n";
        return;
    }
    // Traverse to the node before the specified index
    DNode<T> *current = this->head;
    for (int i = 0; i < index; ++i)
        current = current->next;
    // Create a new node with the given value and insert it into the list
    DNode<T> *tmpNode = new DNode<T>(T(val), current->next, current);
    current->next = tmpNode;
    tmpNode->next->prev = tmpNode;
    this->size++;
}

template <typename T>
void DLinkedList<T>::removeAtIndex(int index)
{
    // Check if the index is valid
    if (index < 0 || index >= this->size)
    {
        std::cout << "Invalid index\n";
        return;
    }
    // Traverse to the node at the specified index
    DNode<T> *current = this->head;
    for (int i = 0; i <= index; ++i)
        current = current->next;
    // Remove the node at the specified index from the list
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    this->size--;
}


template <typename T>
T DLinkedList<T>::removeFront()
{
    DNode<T> *tmpNode = this->head->next;
    tmpNode->next->prev = this->head;
    this->head->next = tmpNode->next;
    T tmpVal = tmpNode->data;
    delete tmpNode;
    this->size--;
    return tmpVal;
}

template <typename T>
T DLinkedList<T>::removeBack()
{
    DNode<T> *tmpNode = this->tail->prev;
    tmpNode->prev->next = this->tail;
    this->tail->prev = tmpNode->prev;
    T tmpVal = tmpNode->data;
    delete tmpNode;
    this->size--;
    return tmpVal;
}

template <typename T>
T DLinkedList<T>::front()
{
    return this->head->next->data;
}

template <typename T>
T DLinkedList<T>::back()
{
    return this->tail->prev->data;
}

template <typename T>
int DLinkedList<T>::getSize()
{
    return this->size;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M, P;
        cin >> N;

        DLinkedList<int> dl;

        for (int i = 0; i < N; ++i)
        {
            int val;
            cin >> val;
            dl.addBack(val);
        }

        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            int val, index;
            cin >> val >> index;
            dl.insertAtIndex(val, index);
        }

        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int index;
            cin >> index;
            dl.removeAtIndex(index);
        }

        // Print the linked list
        while (dl.getSize())
        {
            std::cout << dl.removeFront();
            if (dl.getSize() > 0)
                cout << " ";
        }
        cout << std::endl;
    }

    return 0;
} 