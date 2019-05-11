/* * * * * * * * * * * *
 * * * vector.hpp  * * *
 * * * * * * * * * * * */ 
 
#ifndef _VECTOR_
#define _VECTOR_

	#include <iostream>
	#include <string>
	#include "vectorDebug.hpp"

	/* Шаблонный класс Vect */
	template <class T> class Vect {
		public:
			Vect() : first(0), last(0) {}
			Vect(size_t _n, const T& _v = T()) {
				Allocate( _n );
				for (size_t i = 0; i < _n; ++i) {
					*(first + i) = _v;
				}
			}
			Vect( const Vect& ); // конструктор копирования
			Vect& operator =(const Vect&); // перегрузка операции присваивания

			/* Деструктор */
			~Vect() {
				#ifdef DEBUG
					cout << "Call destructor of " << markName << endl;
				#endif
			Destroy();
			first = 0,
		    last = 0;
		}
		
		/* Установка отладочного имени */
		void mark(std::string& name) {
			markName = name;
		}

		/* Получение отладочного имени */
		std::string mark() const {
			return markName;
		}

		/* Получение размера вектора */
		size_t size() const;

		/* Получение указателя на 1-й элемент */
		T* begin() const {
			return first;
		}

		/* Получение указателя на n + 1 элемент */
		T* end() const {
			return last;
		}

		/* Операция индексирования */
		T& operator[](size_t i);

		/* Вставка элемента в позицию _P */
		void insert(T* _P, const T& _x);

		/* Вставка элемента элемента в конец вектора */
		void push_back(const T& _x);

		/* Удаление элемента из конца вектора */
		void pop_back();

		/* Вывод содержимого вектора */
		void show() const;
	
	protected:
		/* Распределение вектора в памяти */
		void Allocate( size_t _n ) {
			first = new T [_n * sizeof(T)];
			last = first + _n;
		}

		/* Удаление вектора из памяти */
		void Destroy() {
			for ( T* p = first; p != last; ++p ) {
				p->~T(); 
			}
			delete [] first;
		}

		T* first; // указатель на 1-й элемент
		T* last;  // указатель на элемент, следующий за последним
		std::string markName;
	};

	/**
	 * Конструктор копирования
	 *
	 */
	template <class T> Vect<T>::Vect(const Vect& other) {   
		size_t n = other.size();
		Allocate( n );
		for (size_t i = 0; i < n; ++i) {
			*(first + i) = *(other.first + i);
		}
		markName = string("Copy of ") + other.markName;
		#ifdef DEBUG
			cout << "Copy constructor: " << markName << endl;
		#endif
	}

	/**
	 * Операция присваивания
	 *
	 */
	template <class T> Vect<T>& Vect<T>::operator =(const Vect& other) {
		if (this == &other) {
			return *this;
		}
		Destroy();
		size_t n = other.size();
		Allocate(n);
		for (size_t i = 0; i < n; ++i) {
			*(first + i) = *(other.first + i);
		}
		return *this;
	}


	/**
	 * Получение размера вектора
	 *
	 */
	template <class T> size_t Vect<T>::size() const {
		if (first > last) {
			throw VectorDebug();
		}
		return (0 == first ? 0 : last - first);
	}

	/**
	 * Операция доступа по индексу
	 *
	 */
	template <class T> T& Vect<T>::operator[](size_t i) { 
		if (i < 0 || i > ( size() - 1 )) {
			throw VectRangeErr(0, last - first - 1, i);
		}
		return ( *( first + i ) );
	}

	/**
	 * Вставка элемента со значением _x в позицию _P
	 *
	 */
	template <class T> void Vect<T>::insert(T* _P, const T& _x) {
		size_t n = size() + 1; // новый размер
		T* new_first = new T [n * sizeof(T)];
		T* new_last = new_first + n;
		size_t offset = _P - first; // смещение
		for (size_t i = 0; i < offset; ++i) {
			*(new_first + i) = *(first + i);
	    }
		*( new_first + offset ) = _x;
		for (size_t i = offset; i < n; ++i) {
			*(new_first + i + 1) = *(first + i);
		}
		Destroy();
		first = new_first;
		last = new_last;
	}

	/**
	 * Вставка элемента в конец вектора
	 *
	 */
	template <class T> void Vect<T>::push_back(const T& _x) {
		if (!size()) {
			Allocate(1);
			*first = _x;
		} else {
			insert( end(), _x );
		}
	}

	/**
	 * Удаление элемента из конца вектора
	 *
	 */
	template <class T> void Vect<T>::pop_back() {
		if (last == first) {
			throw VectPopErr();
		}
		T* p = end() - 1;
		p->~T();
		last--;
	}

	/**
	 * Вывод содержимого вектора
	 *
	 */
	template <class T> void Vect<T>::show() const {
		cout << "Contents of " << markName << ":" << endl;
		size_t n = size();
		if (n != 0) {
			for (size_t i = 0; i < n; ++i) {
				cout << *(first + i) << " ";
			}
		} else {
			cout << "Vector is empty";
		}
		cout << endl;
	}

#endif /* _VECTOR_ */

/* * * * * * * * * * * */ 