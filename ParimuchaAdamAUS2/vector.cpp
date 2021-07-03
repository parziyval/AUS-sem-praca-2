#include "vector.h"
#include "ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		memcpy(this->memory_, other.memory_, size_);
	}

	//DU
	//move konstruktor
	Vector::Vector(Vector&& other) noexcept :
		Vector(other.size_) 
	{
		memory_ = other.memory_;
		//size_ = other.size_ //nvm ci volat Vector(other.size_) alebo toto
		other.size_ = 0;
		other.memory_ = nullptr;
	}

	Vector::~Vector()
	{
		free(memory_);
		this->memory_ = nullptr; 
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other); //+pri dynamic caste sa kontroluje typova hierarchia
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			size_ = other.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_,other.memory_,size_);
		}
		return *this;
	}

	//DU
	//move operator priradenia
	Vector& Vector::operator=(Vector&& other)
	{
		if (this != &other)
		{
			delete[] memory_;
			memory_ = other.memory_;
			size_ = other.size_;

			other.memory_ = nullptr;
			other.size_ = 0;
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		return this == &other || size_ == other.size_ && memcmp(memory_,other.memory_,size_) == 0;
	}

	byte& Vector::operator[](const int index) //vracia referenciu bytu ku ktoremu pristupujeme
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index"); //+skontroluje ci je index platny
		//byte* ptrB = reinterpret_cast<byte*>(memory_); //+reinterpret_cast len natvrdo zmeni typ, mozeme to pouzit lebo adresa je vzdy int
		//ptrB += index;
		//return *ptrB;
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte Vector::operator[](const int index) const //vracia kopiu bytu ku ktoremu pristupujeme
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest) //skopiruje [count] bytov zacinajucich na [index] na adresu [dest] a vrati adresu [dest]
	{
		DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Invalid end index");
		memcpy(&dest, getBytePointer(index), count);
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		DSRoutines::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid end index"); //skontroluj koncove indexy
		DSRoutines::rangeCheckExcept(destStartIndex + length, src.size_ + 1, "Invalid end index"); //skontroluj koncove indexy
		if (&src == &dest && abs(destStartIndex - srcStartIndex) < length) //identita pamati a prekryv pamati (ak kopirujeme z vektora do toho isteho vektora), pouzijeme memmove, aby sme nepokazili pamat
		{
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else 
		{
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index");
		return reinterpret_cast<byte*>(memory_) + index;
	}

}