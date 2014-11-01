#ifndef CORE_ARITHMETICS
#define CORE_ARITHMETICS

#define MULT_IDENTITY 1

template<typename T>
T mult() {
	return MULT_IDENTITY;
}

template<typename T>
T mult(T arg1) {
	return arg1;
}

template<typename T, typename... Args>
T mult(T arg1, Args... args) {
	return arg1 * mult(args...);
}

#endif  // CORE_ARITHMETICS