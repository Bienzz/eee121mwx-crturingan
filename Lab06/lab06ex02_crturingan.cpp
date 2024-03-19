#include <iostream>
#include <vector>

#define E_ILLEGAL 420
#define DEBUG_MODE 0
#define USER_MODE 1

using namespace std;

const unsigned int MODE = DEBUG_MODE;

template <class S>
class Node {
private:
    S data;
    Node<S> *next;

public:
    Node(S data, Node* next = nullptr);
    template<typename T> friend class LinkedList;
};

template <typename S>
Node<S>::Node(S data, Node* next) : data(data), next(next) {
    if (!MODE)
        cout << "Debug mode: Node Constructor invoked for data: " << this->data << '\n';
}

template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void insertData(T val, int pos = 0);
    void deleteNode(int pos = 0);
    T getValue(int pos = 0);
    vector<T> getListValues();
    int getSize();
};

template<typename T>
LinkedList<T>::LinkedList() {
    if (!MODE)
        cout << "Debug mode: Linked List Constructor invoked" << '\n';
    this->head = new Node<T>(T(), nullptr); //data of head will never be accessed
    this->size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    if (!MODE)
        cout << "Debug mode: Linked List Destructor invoked" << '\n';
    while (this->size > 0)
        this->deleteNode();
    delete this->head;
}

template<typename T>
void LinkedList<T>::insertData(T val, int pos) {
    Node<T> *curr = this->head;

    if(pos > this->size || pos < 0) {
        cout << "Error: Invalid insertion" << '\n';
        return;
    }

    while(pos) {
        curr = curr->next;
        pos--;
    }

    Node<T> *tmpNode = new Node<T>(val);

    if(curr->next != nullptr) {
        tmpNode->next = curr->next;
    }
    curr->next = tmpNode;

    (this->size)++;
}

template<typename T>
void LinkedList<T>::deleteNode(int pos) {

    if(this->getSize() == 0 || this->getSize() <= pos) {
        cout << "Error: Invalid deletion" << '\n';
        return;
    }

    Node<T> *curr = this->head->next;
    Node<T> *prev = this->head;

    while(pos--) {
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = curr->next;
    delete curr;
    (this->size)--;
}

template<typename T>
T LinkedList<T>::getValue(int pos) {
    Node<T> *curr = this->head->next;

    if(pos >= this->size || pos < 0) {
        cout << "Error: Invalid data retrieval" << '\n';
        return -E_ILLEGAL;
    }

    while(pos--)
        curr = curr->next;

    return curr->data;
}

template<typename T>
vector<T> LinkedList<T>::getListValues() {
    vector<T> values;
    Node<T> *curr = this->head->next;

    while (curr) {
        values.push_back(curr->data);
        curr = curr->next;
    }

    return values;
}

template<typename T>
int LinkedList<T>::getSize() {
    return this->size;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N;

        LinkedList<int> list;

        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            list.insertData(val);
        }

        cin >> M;

        for (int i = 0; i < M; ++i) {
            int index;
            cin >> index;
            list.deleteNode(index);
        }

        vector<int> values = list.getListValues();
        for (auto val : values)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
