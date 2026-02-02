#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// OCF
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const & src) : std::stack<T>(src) {}
	MutantStack & operator=(MutantStack const & rhs) {
		if (this != &rhs) {
			std::stack<T>::operator=(rhs);
		}
		return *this;
	}
	~MutantStack() {}

	/*
	typedef - Creating Nicknames for Types
	typename - Telling the Compiler "This is a Type"

	(std::stack<T>) ::container_type
	std::stack doesn't store elements directly!
	It wraps another container (by default std::deque<T>)
	container_type is the type of that underlying container
	
	*/
	typedef typename std::stack<T>::container_type::iterator iterator; // Can read and modify elements
	typedef typename std::stack<T>::container_type::const_iterator const_iterator; // Read-Only Iterator
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator; // Goes Backwards - Read/Write)
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator; //  (Goes Backwards - Read-Only)

	// Iterator functions
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}
};

#endif
