#ifndef CORE_FUNCTIONAL_MAP_H
#define CORE_FUNCTIONAL_MAP_H

#include <core/functional/Zip.h>

/**
 * A Mapper is an iterator with a function.
 * Use the map() function to call it.
 */
template <typename F, typename C1, typename... Cs>
class Mapper {
	Mapper(F function, C1 collection1, Cs... collections) {}


};

template <typename F, typename C1, typename... Cs>
Mapper<F, C1, Cs...> map(F function, C1 collection1, Cs... collections) {
	return Mapper<F, C1, Cs...>(function, collection1, collections...);
}

#endif  // CORE_FUNCTIONAL_MAP_H
