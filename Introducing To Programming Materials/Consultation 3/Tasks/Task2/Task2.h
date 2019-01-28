#pragma once

double Abs(const double a)
{
	return a >= 0 ? a : -a;
}

double formula(const double a, const double xOld)
{
	return 0.5*(xOld + a / xOld);
}

double sqrt_a(const double a, const double eps)
{
	if (a <= 0)
	{
		return 0;
	}

	double xOld = a;
	double xNew = formula(a, xOld);
	while (Abs(xOld - xNew) >= eps)
	{
		xOld = xNew;
		xNew = formula(a, xOld);
	}
	return xNew;
}