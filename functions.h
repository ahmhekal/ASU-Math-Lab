#include "matrix.h"
#include "math.h"

/*
 * Part 0: Introduction
 * ====================
 *
 * We need to write functions for `sin`, `cos`, `sqrt`, etc that take a matrix
 * and return a matrix, whose elements are the result of applying the function
 * on the each element in the input matrix.
 * eg, `sqrt([1 4; 9 16])` = `[1 2; 3 4]`.
 *
 * We implement all Trigonometry functions and most of Exponents and Logarithms
 * functions: https://www.mathworks.com/help/matlab/functionlist.html
 *
 * All these functions are element-wise, so we need to have these functions
 * take double and return double, first, then overload them to accept matrices.
 *
 * But, not all the required functions are available in C++ standard library,
 * So we need to make those first.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Part 1: Trigonometry functions
 * ==============================
 *
 * Section 0: Introduction
 * -----------------------
 *
 * We need to implement 41 functions:
 *   sin      cos      tan      csc      sec      cot
 *   sind     cosd     tand     cscd     secd     cotd
 *   sinh     cosh     tanh     csch     sech     coth
 *   asin     acos     atan     acsc     asec     acot
 *   asind    acosd    atand    acscd    asecd    acotd
 *   asinh    acosh    atanh    acsch    asech    acoth
 *   deg2rad  rad2deg
 *   atan2    atan2d   hypot
 *
 * We assume that we have all these implemented on numbers (`double`), but
 * because this is not the case, we need to fill in the gaps first.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * Section 1: Defining the reciprocals
 * -----------------------------------
 *
 * We already have `sin`, `sinh`, `asin`, and `asinh`. But we don't have their
 * reciprocals: `csc`, `csch`, `acsc`, and `acsch`. Similarly, we don't have
 * any `sec` or `cot` functions; we need to define those first, for `double`s.
 *
 */

double sec(double n)
{
	return 1 / cos(n);
}

double asec(double n)
{
	return acos(1 / n);
}

double sech(double n)
{
	return 1 / cosh(n);
}

double asech(double n)
{
	return acosh(1 / n);
}

double csc(double n)
{
	return 1 / sin(n);
}

double acsc(double n)
{
	return asin(1 / n);
}

double csch(double n)
{
	return 1 / sinh(n);
}

double acsch(double n)
{
	return asinh(1 / n);
}

double cot(double n)
{
	return 1 / tan(n);
}

double acot(double n)
{
	return atan(1 / n);
}

double coth(double n)
{
	return 1 / tanh(n);
}

double acoth(double n)
{
	return atanh(1 / n);
}


/*
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * Section 2: Defining the degrees functions
 * -----------------------------------------
 *
 * In MATLAB, `sin` takes radians. Great! That's exactly how C++ `sin` works.
 * Also, MATLAB presents `sind`, which take degrees. That means: for every trig
 * function, you need another function that takes or returns degrees instead of
 * radians.
 *
 */

double sind(double n)
{
	return sin(n * M_PI / 180);
}

double asind(double n)
{
	return asin(n) * 180 / M_PI;
}

double cosd(double n)
{
	return cos(n * M_PI / 180);
}

double acosd(double n)
{
	return acos(n) * 180 / M_PI;
}

double tand(double n)
{
	return tan(n * M_PI / 180);
}

double atand(double n)
{
	return atan(n) * 180 / M_PI;
}

double cotd(double n)
{
	return cot(n * M_PI / 180);
}

double acotd(double n)
{
	return acot(n) * 180 / M_PI;
}

double secd(double n)
{
	return sec(n * M_PI / 180);
}

double asecd(double n)
{
	return asec(n) * 180 / M_PI;
}

double cscd(double n)
{
	return csc(n * M_PI / 180);
}

double acscd(double n)
{
	return acsc(n) * 180 / M_PI;
}

/*
 *- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 * Section 3: All one-argument trig functions
 * --------------------------------------------
 * Now, it is the time! We can now implement  the 36 trig functions easily.
 * all 36 trig functions will have the same syntax .
 * each function will take CMatrix and returns the matrix after apllying element wise operation on it.
*/
 
asu::CMatrix sin(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sin(m(i));
	return r;
}


asu::CMatrix asin(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asin(m(i));
	return r;
}

asu::CMatrix sind(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sind(m(i));
	return r;
}

asu::CMatrix asind(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asind(m(i));
	return r;
}

asu::CMatrix sinh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sinh(m(i));
	return r;
}

asu::CMatrix asinh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asinh(m(i));
	return r;
}

asu::CMatrix cos(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cos(m(i));
	return r;
}

asu::CMatrix acos(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acos(m(i));
	return r;
}

asu::CMatrix cosd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cosd(m(i));
	return r;
}

asu::CMatrix acosd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acosd(m(i));
	return r;
}

asu::CMatrix cosh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cosh(m(i));
	return r;
}

asu::CMatrix acosh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acosh(m(i));
	return r;
}

asu::CMatrix tan(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = tan(m(i));
	return r;
}

asu::CMatrix atan(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = atan(m(i));
	return r;
}

asu::CMatrix tand(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = tand(m(i));
	return r;
}

asu::CMatrix atand(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = atand(m(i));
	return r;
}

asu::CMatrix tanh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = tanh(m(i));
	return r;
}

asu::CMatrix atanh(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = atanh(m(i));
	return r;
}

asu::CMatrix cot(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cot(m(i));
	return r;
}

asu::CMatrix acot(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acot(m(i));
	return r;
}

asu::CMatrix cotd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cotd(m(i));
	return r;
}

asu::CMatrix acotd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acotd(m(i));
	return r;
}

asu::CMatrix coth(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = coth(m(i));
	return r;
}

asu::CMatrix acoth(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acoth(m(i));
	return r;
}

asu::CMatrix sec(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sec(m(i));
	return r;
}

asu::CMatrix asec(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asec(m(i));
	return r;
}

asu::CMatrix secd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = secd(m(i));
	return r;
}

asu::CMatrix asecd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asecd(m(i));
	return r;
}

asu::CMatrix sech(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sech(m(i));
	return r;
}

asu::CMatrix asech(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = asech(m(i));
	return r;
}

asu::CMatrix csc(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = csc(m(i));
	return r;
}

asu::CMatrix acsc(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acsc(m(i));
	return r;
}

asu::CMatrix cscd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = cscd(m(i));
	return r;
}

asu::CMatrix acscd(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acscd(m(i));
	return r;
}

asu::CMatrix csch(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = csch(m(i));
	return r;
}

asu::CMatrix acsch(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = acsch(m(i));
	return r;
}

/*
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * Section 4: Radians-degrees Converters
 * -------------------------------------
 *
 * MATLAB defines two functions to convert between radians and degrees.
 * We first define the `double` functions, then generate the overloaded matrix.
 *
 */

double rad2deg(double r)
{
	return r * 180 / M_PI;
}

double deg2rad(double d)
{
	return d * M_PI / 180;
}

asu::CMatrix rad2deg(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = rad2deg(m(i));
	return r;
}

asu::CMatrix deg2rad(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = deg2rad(m(i));
	return r;
}

/*
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * Section 5: The two-argument functions
 * -------------------------------------
 *
 * `atan2`, `atan2d`, and `hypot` take two arguments. We write an element-wise
 * functions like the earlier, but make the implemented functions accept
 * two arguments.
 *
 * As we don't have `atan2d` defined on `double`s yet, we need to define it
 * before we implement the corresponding element-wise function.
 *
 */

double atan2d(double x, double y)
{
	return atan2(x, y) * 180 / M_PI;
}

asu::CMatrix atan2(const asu::CMatrix& a, const asu::CMatrix& b)
{
	if (a.getnRows() != b.getnRows() || a.getnColumns() != b.getnColumns())
		throw std::invalid_argument("Invalid matrix dimensions in atan2()");
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = atan2(a(i), b(i));
	return r;
}

asu::CMatrix atan2d(const asu::CMatrix& a, const asu::CMatrix& b)
{
	if (a.getnRows() != b.getnRows() || a.getnColumns() != b.getnColumns())
		throw std::invalid_argument("Invalid matrix dimensions in atan2d()");
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = atan2d(a(i), b(i));
	return r;
}

asu::CMatrix hypot(const asu::CMatrix& a, const asu::CMatrix& b)
{
	if (a.getnRows() != b.getnRows() || a.getnColumns() != b.getnColumns())
		throw std::invalid_argument("Invalid matrix dimensions in hypot()");
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = hypot(a(i), b(i));
	return r;
}

/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Part 2: Exponents and Logarithms functions
 * ==========================================
 *
 * Section 0: Introduction
 * -----------------------
 *
 * We'll implement the following functions:
 *   exp     log     log10   log2    log1p   sqrt    power
 *
 * Interestingly, all of them are available in C++ standard library, except
 * `power`, which is called `pow`.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * Section 1: Implementation
 * -------------------------
 *
 * For more symmetric code, we implement the element-wise `pow` first, then
 * write two `power` functions that returns the result of `pow`.
 * An optimizing complier should inline these `power` functions, among others,
 * so it should not cause a performance issue.
 *
 */

asu::CMatrix exp(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = exp(m(i));
	return r;
}

asu::CMatrix log(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = log(m(i));
	return r;
}

asu::CMatrix log10(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = log10(m(i));
	return r;
}

asu::CMatrix log2(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = log2(m(i));
	return r;
}

asu::CMatrix log1p(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = log1p(m(i));
	return r;
}

asu::CMatrix sqrt(const asu::CMatrix& m)
{
	asu::CMatrix r(m.getnRows(), m.getnColumns());
	for (size_t i = 0; i < m.getn(); i++)
		r(i) = sqrt(m(i));
	return r;
}

asu::CMatrix pow(const asu::CMatrix& a, const asu::CMatrix& b)
{
	if (a.getnRows() != b.getnRows() || a.getnColumns() != b.getnColumns())
		throw std::invalid_argument("Invalid matrix dimensions in pow()");
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = pow(a(i), b(i));
	return r;
}

double power(double n, double m)
{
	return pow(n, m);
}

asu::CMatrix power(const asu::CMatrix& n, const asu::CMatrix& m)
{
	return pow(n, m);
}
/*
 *modified element wise power which takes matrix and double and apply element wise  power operation on the matrix 
 */
asu::CMatrix power_modified_elementwise(const asu::CMatrix& n, double m)
{
	asu::CMatrix r(n.getnRows(), n.getnColumns());
	for (unsigned int i = 0; i < n.getnRows(); i++) {
		for (unsigned int j = 0; j < n.getnColumns(); j++) {
			r(i, j) = pow(n(i, j), m);
		}
	}
	return r;


}
/* 
 * power modified whiche takes matrix and double and returns matrix to the power double.
 * ex matrix^3 ----> matrix * matrix * matrix .
 */
asu::CMatrix power_modified(const asu::CMatrix& n, double m)
{
	asu::CMatrix r = n;
	for (int i = 0; i < m - 1; i++) {
		r.CopyMatrix(mul(r, n));
	}
	return r;
}
//atan2 modified using double
asu::CMatrix atan2_modified(const asu::CMatrix& a, double m)
{
	
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = atan2(a(i), m);
	return r;
}
//atan2d modified using double
asu::CMatrix atan2d_modified(const asu::CMatrix& a, double m )
{
	
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = atan2d(a(i), m);
	return r;
}
//hypot modified using double
asu::CMatrix hypot_modified(const asu::CMatrix& a,double m )
{
	
	asu::CMatrix r(a.getnRows(), a.getnColumns());
	for (size_t i = 0; i < a.getn(); i++)
		r(i) = hypot(a(i), m);
	return r;
}
