#ifndef VEC_LOCAL
#define VEC_LOCAL
#include "Vec.hpp"
#endif

class Ray
{
public:
	Vec o, d;
	Ray(Vec o, Vec d) : o(o), d(d) {}
};