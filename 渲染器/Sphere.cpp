#include "Sphere.hpp"


double Sphere::intersect(const Ray &r) const
{
	Vec op = position - r.o; // Solve t^2*d.d + 2*t*(o-p).d + (o-p).(o-p)-R^2 = 0
	double eps = 1e-4;
	double b = op.dot(r.d);
	double temp = pow(b, 2) - op.dot(op) + pow(radius, 2);

	if (temp < 0)
		return 0;
	else
	{
		double det = sqrt(temp);
		double t = b - det;
		if (t > eps)
			return t;
		else
		{
			t = b + det;
			if (t > eps)
				return t;
			else
				return 0;
		}
	}
}