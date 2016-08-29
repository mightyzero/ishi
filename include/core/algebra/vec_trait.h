#ifndef CORE_ALGEBRA_VEC_TRAIT_H
#define CORE_ALGEBRA_VEC_TRAIT_H

namespace ishi {

/**
 * The trait class.
 *
 * This struct is used to pass type information from derived class to the base class in the CRTP hierarchy.
 */
template <typename VecT>
struct VecTrait {
	typedef typename VecT::value_type type;
};

}

#endif //CORE_ALGEBRA_VEC_TRAIT_H
