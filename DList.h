#pragma once
using namespace std;



template <typename T>
struct Node {
	T data;
	Node* next, * prev;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		:data{data}, prev{ prev }, next{next} {}
};


template <typename T>
class DList
{
public:
	DList() = default;
	DList(const DList<T>& other) {
		clone(this, other);
	}
	void operator=(const DList<T>& other) {
		clone(this, other);
	}
	void addHead(const T& data);
	void addTail(const T& data);
	void removeHead();
	void removeTail();
	void print() const;
	void printR() const;
	bool isEmpty() const;
	void removeData(const T& data);
	void clear();
	void addBefore(const T& place, const T& data);
	void addAfter(const T& place, const T& data);
	int replaceAll(const T& place, const T& data);
	DList<T> operator+(const DList<T>& other)const;
	void operator+=(const DList<T>& other);
	DList<T> operator*(const DList<T>& other);
	void reverse();
private:
	Node<T>* findData(const T& data);
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
	void clone(DList<T>* dest, const DList <T>& source);
	void replace(Node<T>* place, const T& data);
};













template<typename T>
inline void DList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, nullptr, head);
	if (isEmpty()) {
		tail = tmp;
	}
	else {
		head->prev = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline void DList<T>::addTail(const T& data)
{
	Node<T>* tmp = new Node<T>(data, tail, nullptr);
	if (isEmpty()) {
		head = tmp;
	}
	else {
		tail->next = tmp;
	}
	tail = tmp;
	++size;
}

template<typename T>
inline void DList<T>::removeHead()
{
	if (isEmpty()) {
		return;
	}
	auto tmp = head;
	head = tmp->next;
	if (isEmpty()) {
		tail = nullptr;
	}
	else {
		head->prev = nullptr;
	}
	delete tmp;
	--size;
}

template<typename T>
inline void DList<T>::removeTail()
{
	if (isEmpty()) {
		return;
	}
	auto tmp = tail;
	tail = tmp->prev;
	if (isEmpty()) {
		head = nullptr;
	}
	else {
		tail->next = nullptr;
	}
	delete tmp;
	--size;
}



template<typename T>
inline void DList<T>::print() const
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	auto tmp = tail;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}



template<typename T>
inline bool DList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void DList<T>::removeData(const T& data)
{
	auto find = findData(data);
	if (find == nullptr) return;
	if (find == head) {
		removeHead(); 
		return;
	}
	if (find == tail) {
		removeTail();
		return;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;
	delete find;
	--size;
}

template<typename T>
inline void DList<T>::clear()
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		removeHead();
		tmp = tmp->next;
	}
	size = 0;
}

template<typename T>
inline void DList<T>::addBefore(const T& place, const T& data)
{
	auto find = findData(place);
	if (find == nullptr) {
		return;
	}
	if (find == head) {
		addHead(data);
	}
	Node<T>* tmp = new Node<T>(data, find->prev, find);
	find->prev->next = tmp;
	find->prev = tmp;
}

template<typename T>
inline void DList<T>::addAfter(const T& place, const T& data)
{
	auto find = findData(place);
	if (find == nullptr) {
		return;
	}
	if (find == tail) {
		addTail(data);
	}
	Node<T>* tmp = new Node<T>(data, find, find->next);
	find->next->prev = tmp;
	find->next = tmp;
}



template<typename T>
inline int DList<T>::replaceAll(const T& place, const T& data)
{
	int counter = 0;
	auto pointer = head;
	while (pointer != nullptr)
	{
		if (pointer->data == place) {
			replace(pointer,data);
			counter++;
		}
		pointer = pointer->next;
	}

	return counter;
}

template<typename T>
inline DList<T> DList<T>::operator+(const DList<T>& other) const
{
	DList<T>newList;
	auto currentPointer = head;
	auto otherPoitner = other.head;
	while (currentPointer != nullptr)
	{
		newList.addTail(currentPointer->data);
		currentPointer = currentPointer->next;
	}
	while (otherPoitner != nullptr)
	{
		newList.addTail(otherPoitner->data);
		otherPoitner = otherPoitner->next;
	}
	return newList;
}

template<typename T>
inline void DList<T>::operator+=(const DList<T>& other)
{
	auto otherPoitner = other.head;
	while (otherPoitner != nullptr)
	{
		addTail(otherPoitner->data);
		otherPoitner = otherPoitner->next;
	}
}

template<typename T>
inline DList<T> DList<T>::operator*(const DList<T> &other)
{
	DList<T>newList;
	auto otherPoitner = other.head;
	while (otherPoitner != nullptr)
	{

		if (findData(otherPoitner->data) != nullptr && newList.findData(otherPoitner->data) == nullptr){
			newList.addTail(otherPoitner->data);
		}
		otherPoitner = otherPoitner->next;
	}
	return newList;
}

//template<typename T>
//void DList<T>::reverse()
//{
//	auto head_ = head;
//	auto tail_ = tail;
//	for (int i = 0; i < size / 2; i++)
//	{
//		if (i == 0)
//		{
//			head = tail_;
//			tail = head_;
//			head_->next->prev = head;
//			head->next = head_->next;
//			tail_->prev->next = tail;
//			tail->prev = tail_->prev;
//			head->prev = nullptr;
//			tail->next = nullptr;
//			head_ = head->next;
//			tail_ = tail->prev;
//			continue;
//		}
//		auto tmp = head_;
//		auto tmp_ = tail_;
//		head_->prev->next = tail_;
//		head_->next->prev = tail_;
//		head_ = tail_;
//		head_->next = tmp->next;
//		head_->prev = tmp->prev;
//
//
//		tail_->next->prev = tmp;
//		tail_->prev->next = tmp;
//		tail_ = tmp;
//		tail_->prev = tmp_->prev;
//		tail_->next = tmp_->next;
//		head_ = tail_->next;
//		tail_ = tmp->prev;
//
//	}
//}

//template<typename T>
//void DList<T>::reverse() {
//
//	Node<T>* current = head;
//	Node<T>* tmp = nullptr;
//
//
//
//	while (current != nullptr)
//	{
//		tmp = current->prev;
//		current->prev = current->next;
//		current->next = tmp;
//		current = current->prev;
//	}
//
//	tmp = head;
//	head = tail;
//	tail = tmp;
//}


template<typename T>
void DList<T>::reverse() {
	Node<T>* tmp = nullptr;

	tmp = head;
	head = tail;
	tail = tmp;

	Node<T>* current = tail;

	while (current != nullptr)
	{
		tmp = current->prev;
		current->prev = current->next;
		current->next = tmp;
		current = current->prev;
	}
}


template<typename T>
inline Node<T>* DList<T>::findData(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}


template<typename T>
inline void DList<T>::clone(DList<T>* dest, const DList<T>& source)
{
	if (!dest->isEmpty())
	{
		dest->clear();
	}
	Node<T>* tmp_ = source.head;
	while (tmp_ != nullptr)
	{
		dest->addTail(tmp_->data);
		tmp_ = tmp_->next;
	}
}

template<typename T>
inline void DList<T>::replace(Node<T>* place, const T& data)
{
	Node<T>* find = place;
	if (find == head) {
		removeHead();
		addHead(data);
	}
	if (find == tail) {
		removeTail();
		addTail(data);
	}
	auto tmp = new Node<T>(data, find->prev, find->next);
	find->prev->next = tmp;
	find->next->prev = tmp;
}
