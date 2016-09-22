#include "trace.h"

template <class T> class vector
{
	T* v;
	
	public:
		int count;
		vector(int size) {
			count = 1;
			v = new T(size);
			TRACE(rge, "vector<T>::vector(int)");
			cerr << "  count = " << count << endl;
		};
	
		~vector() {
			TRACE(rge, "vector<T>::~vector");
			cerr << "  count = " << count-- << endl;
		};

		T& elem(int i) {return v[i];};
		T& operator[](int i) {return v[i];};
};

template<> class vector<void*>
{
	void** p;
	static int count;
	
	public:
		vector(int size) {
			p = new void*[size];
			TRACE(rge, "vector<void*>::vector(int)");
			cerr << "  count = " << ++count << endl;
		}
	
		~vector() {
			TRACE(rge, "vector<void*>::~vector");
			cerr << "  count = " << count-- << endl;
		};

	void*& elem(int i) {return p[i];}
	void*& operator[](int i) {return p[i];}
};

template<class T> class vector<T*>:public vector<void*>
{
	public:
		explicit vector(int size): vector<void*>(size) {
			TRACE(rge, "vector<T*>::vector(int)");
		};
	
		~vector() {
			TRACE(rge, "vector<T*>::~vector");
		};
		
		T*& operator[](int i) {
			static T* t = (T*)vector<void*>::elem(i);
			return t;
		}
	
		T*& elem(int i) {
			static T* t = (T*)vector<void*>::elem(i);
			return t;
		}
};
