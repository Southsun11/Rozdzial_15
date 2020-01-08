#pragma once
template <typename T>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	class Node
	{
	public:
		T item;
		Node* next;
		Node(T i) :item(i), next(nullptr) {}
	};
	Node* front;
	Node* tail;
	int items;
	const int qsize;
	QueueTP(const QueueTP & q) :qsize(0) {};
	QueueTP& operator=(const QueueTP& q) { return *this; };
public:
	QueueTP(int qs = Q_SIZE);
	virtual  ~QueueTP();
	bool isempty()
	{
		return items == 0;
	}
	bool isfull()
	{
		return items == qsize;
	}
	int queuecount()
	{
		return items;
	}
	bool enqueue(const T &item);
	bool dequeue(T& item);

};

template <typename T>
QueueTP<T>::QueueTP(int qs) :qsize(qs)
{
	front = nullptr;
	tail = nullptr;
}

template <typename T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename T>
bool QueueTP<T>::enqueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node(item);
	items++;
	if (front == nullptr)
		front = add;
	else
		tail->next = add;
	tail = add;
	return true;
}

template <typename T>
bool QueueTP<T>::dequeue(T & item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if(items == 0)
		tail = nullptr;
	return true;
}

