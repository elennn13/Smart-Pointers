#pragma once
#include<map>
#include <iostream>

namespace my {

	template <typename ANY>
	class shared_ptr {

	private:
		ANY* data; // данные которые хранятся в умном указателе
		std::map<ANY*, unsigned> all_ptrs; // all_ptrs мапа
		void clear();


	public:
		shared_ptr();
		shared_ptr(ANY* address);
		~shared_ptr();
		void reset(ANY* address = nullptr);
		ANY* get() const;
		ANY& operator*();  // ссылка на указатель на тип ANY
		const ANY& operator*() const;
		ANY& operator->();
		const ANY& operator->() const;
 	};

	template <typename T>
	void shared_ptr_test(T* address);


}

template <typename ANY>
void my::shared_ptr<ANY>::clear() {
	all_ptrs.erase(data);
	delete[] data;
	data = nullptr;
}

template <typename ANY>
my::shared_ptr<ANY>::shared_ptr() { // констр по умолчанию
	data = nullptr;
}

template <typename ANY>
my::shared_ptr<ANY>::shared_ptr(ANY* address) {
	reset(address);
}

template <typename ANY>
my::shared_ptr<ANY>::~shared_ptr() {
	if (data != nullptr) {
		all_ptrs[data] -= 1;
		if (all_ptrs[data] <= 0)
			clear();
	}
}

template <typename ANY>
void my::shared_ptr<ANY>::reset(ANY* address) {
	if (data != nullptr) {
		all_ptrs[data] -= 1; // уменьшаем счетчик
		if (all_ptrs[data] <= 0)
			clear(); // удаление элементов
		}
	if (address == nullptr) return;

	if (all_ptrs.count(data) > 0) 
		all_ptrs[data] += 1; //увелич  счетчик
	else
		all_ptrs[data] = 1;
	data = address;
}

template <typename ANY>
ANY* my::shared_ptr<ANY>::get() const {
	return data;
}

template <typename ANY>
ANY& my::shared_ptr<ANY>::operator*() {
	return *data;
}

template <typename ANY>
const ANY& my::shared_ptr<ANY>::operator*() const{
	return *data;
}

// TODO добавить кое что
template <typename ANY>
ANY& my::shared_ptr<ANY>::operator->() {
	return *data;
}

template <typename ANY>
const ANY& my::shared_ptr<ANY>::operator->() const {
	return *data;
}


// функция для тестов

template <typename T>
void my::shared_ptr_test(T* address) {
	my::shared_ptr<T> ptr;
	ptr.reset(address);

	std::cout << "Test:  ptr (beg) = " << ptr.get() << std::endl;
	std::cout << "Test: *ptr (beg) = " << *ptr.get() << std::endl;
	{
		my::shared_ptr<T> tmp(ptr.get());
		std::cout << "Test:  tmp = " << tmp.get() << std::endl;
		std::cout << "Test: *tmp = " << *tmp.get() << std::endl;
	}
	std::cout << "Test:  ptr (end) = " << ptr.get() << std::endl;
	std::cout << "Test: *ptr (end) = " << *ptr.get() << std::endl;
}