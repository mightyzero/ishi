#ifndef CORE_ALGEBRA_BLITZ_VEC_H
#define CORE_ALGEBRA_BLITZ_VEC_H

#include <blitz/tinyvec-et.h>

#include <core/algebra/vec.h>

namespace ishi {

template<typename ScalarT, int length>
class BlitzVecImpl : public blitz::TinyVector<ScalarT, length> {

};

//template<typename ScalarT, int length>
//using BlitzVec = Vec<ScalarT, length, BlitzVecImpl>;

template<typename ScalarT, int length>
using BlitzVec = Vec<ScalarT, length, blitz::TinyVector>;


}  //namespace ishi


#endif //CORE_ALGEBRA_BLITZ_VEC_H
