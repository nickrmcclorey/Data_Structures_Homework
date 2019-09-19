#include "HashTable.h"
#include "List.h"

template <class T>
class ChainedTable : public HashTable<List<T> > {
        public:
            ChainedTable(int arraySize = 100);
            ~ChainedTable();
            void AddItem(T *newElement);
            int GetLength();
            T* RemoveItem(T value);
            T* GetItem(T value);
};

template <class T>
ChainedTable<T>::ChainedTable(int arraySize) : HashTable<List<T> >::HashTable(arraySize){
    for (int k = 0; k < arraySize; k++) {
        this->array[k].data = new List<T>;
    }
};

template <class T>
void ChainedTable<T>::AddItem(T *newElement) {
    int index = this->Hash(*newElement);
    this->array[index].data->AddItem(newElement);
}

template <class T>
T* ChainedTable<T>::RemoveItem(T value) {
    int index = this->Hash(value);
    return this->array[index].data->GetItem(&value);
}

template <class T>
T* ChainedTable<T>::GetItem(T value) {
    int index = this->Hash(value);
    this->array[index].data->Reset();
    if (this->array[index].data->IsEmpty()) {
        return nullptr;
    }
    
    T* entry = this->array[index].data->SeeNext();
    while (entry != nullptr && *entry != value) {
        entry = this->array[index].data->SeeNext();
        this->comparisons++;
    }

    return entry;
}

template <class T>
int ChainedTable<T>::GetLength() {
    int sum = 0;
    for (int k = 0; k < this->maxSize; k++) {
        sum += this->array[k].data->Size();
    }

    return sum;
}

template <class T>
ChainedTable<T>::~ChainedTable() {}