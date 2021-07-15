#pragma once

template<class T>
class UniquePtr
{
public:
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	UniquePtr(T* _ptr = nullptr) : ptr(_ptr) {};

	UniquePtr(UniquePtr<T>&& uptr) {
		ptr = uptr.ptr;
		uptr.ptr = nullptr;
	}


	~UniquePtr() {
		delete ptr;
	}

	T operator*() {
		return *ptr;
	}

private:
	T* ptr;
};