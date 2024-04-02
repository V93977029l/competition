#include <math.h> // smallpt, a Path Tracer by Kevin Beason, 2008

class Vec
{ // Usage: time ./smallpt 5000 && xv image.ppm
public:
	Vec(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

public:
	double x, y, z; // position, also color (r,g,b)

	Vec operator+(const Vec &b) const { return Vec(x + b.x, y + b.y, z + b.z); }
	Vec operator-(const Vec &b) const { return Vec(x - b.x, y - b.y, z - b.z); }
	Vec operator*(double num) const { return Vec(x * num, y * num, z * num); }
	Vec mult(const Vec &b) const { return Vec(x * b.x, y * b.y, z * b.z); }
	Vec &norm() { return *this = *this * (1 / sqrt(x * x + y * y + z * z)); }					   // 法向量
	double dot(const Vec &b) const { return x * b.x + y * b.y + z * b.z; }						   // 内积
	Vec operator%(Vec &b) { return Vec(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); } // 叉乘
};