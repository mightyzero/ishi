#ifndef CORE_FUNCTIONAL_ZIP_H
#define CORE_FUNCTIONAL_ZIP_H

#include <tuple>
#include <utility>
#include <iterator>
#include <type_traits>

// We don't overload operator++ for this because there are only 2 forms of
// operator++, neither of which takes tuple as a parameter, so no deduction is
// possible, so calling syntax will be too verbose.
template <std::size_t i, typename... Iters>
inline typename std::enable_if<(i < sizeof...(Iters))>::type
increment(std::tuple<Iters...>& tuple) {
	std::get<i>(tuple)++;
	increment<i + 1>(tuple);
}

template <std::size_t i, typename... Iters>
inline typename std::enable_if<(i == sizeof...(Iters))>::type
increment(std::tuple<Iters...>& tuple) {}


/** Iterator for traversing multiple containers of possibly different types */
template <typename C1, typename... Cs>
class Zipper {
public:
	class iterator
	    : std::iterator<
	          std::forward_iterator_tag,
	          std::tuple<typename C1::value_type, typename Cs::value_type...>> {

	public:
		typedef std::tuple<typename C1::value_type, typename Cs::value_type...>
		value_type;
		// typedef difference_type;
		// typedef pointer;
		typedef std::tuple<typename C1::reference, typename Cs::reference...>
		reference;
		typedef std::forward_iterator_tag iterator_category;

	protected:
		std::tuple<typename C1::iterator, typename Cs::iterator...> current;

	public:
		// Common Iterator methods
		explicit iterator(C1 c1, Cs... cs)
		: current(std::begin(c1), std::begin(cs)...) {}

		explicit iterator(typename C1::iterator it1, typename Cs::iterator... its)
		: current(it1, its...) {}

		iterator(const iterator& other) : current(other.current) {}

		iterator& operator=(const iterator& other) {
			current = other.current;
			return this;
		}

		// prefix increment
		iterator& operator++() {
			increment(current);
			return this;
		}

		// reference operator*() const;
		// friend void swap(iterator& lhs, iterator& rhs); //C++11 I think

		// Common Input Iterator methods
		// iterator operator++(int); //postfix increment
		// value_type operator*() const;
		// pointer operator->() const;
		// friend bool operator==(const iterator&, const iterator&);
		// friend bool operator!=(const iterator&, const iterator&);

		// Common Output Iterator methods
		// once an input iterator has been dereferenced, it is
		// undefined to dereference one before that.
		// reference operator*() const;
		// iterator operator++(int); //postfix increment
	};

private:
	iterator m_begin;
	iterator m_end;

public:
	Zipper(C1& c1, Cs&... cs)
	: m_begin(c1.begin(), cs.begin()...), m_end(c1.begin(), cs.begin()...) {}

	Zipper(const Zipper& other) : m_begin(other.m_begin), m_end(other.m_end) {}

	void operator=(const Zipper& other) {
		m_begin = other.m_begin;
		m_end = other.m_end;
	}


	iterator& begin() { return m_begin; }

	iterator& end() { return m_end; }
};

template <typename T>
using decay_t = typename std::decay<T>::type;

template <typename... Types>
Zipper<decay_t<Types>...> zip(Types&&... args) {
	return Zipper<decay_t<Types>...>(std::forward<Types>(args)...);
}

#endif // CORE_FUNCTIONAL_ZIP_H
