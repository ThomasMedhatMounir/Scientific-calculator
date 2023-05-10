#include<iostream>
#include <cmath>
using namespace std;
//  factorial
double fact(int n) {
	double fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}
//   square root
double square(double x)
{
	double l = 0;
	double u = x;
	double ans = 0;

	int i = 50;

	while (i != 0)
	{
		ans = (l + u) / 2;
		if (ans * ans == x)
		{
			return ans;
		}
		else if (ans * ans > x)

		{
			u = ans;
		}
		else
		{
			l = ans;
		}
		i--;
	}
	return ans;
}
//  needed for the cubic root
double diff(double x, double m)
{
	if (x > (m * m * m))
		return (x - (m * m * m));
	else
		return ((m * m * m) - x);
}

// Returns cube root of a no n
double cubic(double x)
{
	double n1 = 0, n2 = x;  //  n1 is start and n2 is end for search

	double E = 0.0000001;  //  precision

	while (true)
	{
		double m = (n1 + n2) / 2;
		double error = diff(x, m);

		// If error is less than e then m is the answer
		if (error <= E)
			return m;

		// If m is not the answer then the answer between the m and the start
		if ((m * m * m) > x)
			n2 = m;

		// If mid*mid*mid is less than n set
		// start = mid
		else
			n1 = m;
	}
}
double pospower(double x, double y) {
	 double ans = 1;
	for (int i = 0; i < y; i++) {
		ans *= x;
	}
	return ans;
}
double negpower(double x,double  y)
{
	double p = 1.00;
	double xx = x;
	if (y < 0) {
		y = -1 * y;
		xx = 1 / xx;
	}
	for (int i = 0; i < y; i++)
	{
		p = p * xx;
	}

	return p;
}
int main()
{
	// variable decleration
	const double pi = 3.14159;   //  used in sin , cos and tan
	const double e =  2.71828;   // used in e^x
	double x = 0.0;
	double y = 0.0;
	double term = 0.0;
	double sin = 0.0;
	double cos = 0.0;
	int c = 0;
	int a = 0;
	double ans = 0.0;
	double p = 0, prev = 0;
	int i = 0, n = 100;
	cout << "\t\t\t\tScientific Calculator\n\n";
	cout << "You can find :\n\n";
	cout << "1)value of pi\n2)square root of x \n3)cubic root of x \n4) round x\n5)floor x\n6) ceil x\n7) sin x\n8) cos x\n9) tan x\n10) e^x\n11)x^y\n12)Addition \n13)Subtraction \n14)Multiplication \n15)Division \n16)Average \n\n";
	cout << "Enter your choice : \t";
	cin >> c;
	cout << endl;
	switch (c)
	{
		// pi
	case 1:
		do {
			prev = p;
			p += pospower(-1.0, i) / (1 + 2 * i);
			i++;
		} while (fabs(p - prev) > 0.0001);
		cout << "The value of pi = " << 4 * p << endl;
		break;
		// square root
	case 2:
		cout << "Enter the value of x\n";
		cin >> x;
		if (x < 0)
		{
			cout << "Error: Negative number!\n";
			return 0;
		}
		cout << "Square roots are: +" << square(x)<< " and -" << square(x)<<endl;
		break;
		// cubic root
	case 3:
		cout << "Enter the value of x\n";
		cin >> x;
		if (x >0) {
			cout << "cubic root = " << cubic(x) << endl;
		}
		else
		{
			cout << "cubic root = -" << cubic(fabs(x)) << endl;
		}
		break;
		// round
	case 4:
		cout << "Enter the value of x\n";
		cin >> x;
		if(x>0)
		  a= (int)(x + 0.5);
		else
		{
			a = (int)(x - 0.5);
		}
			cout <<"The round of "<<x<<" = " <<a << endl;
		break;
		// floor
	case 5:
		cout << "Enter the value of x\n";
		cin >> x;
		a = (x)-((x) != 0)+1;
		cout << "The flooring of " << x << " = " << a << endl;
		break;
		// ceil
	case 6:
		cout << "Enter the value of x\n";
		cin >> x;
		a = (x) + ((x ) != 0);
		cout << "The ceiling of "<<x<<" = "<< a << endl;
		break;
		// sin x
	case 7:
		cout << "Enter angle in degree" << endl;
		cin >> y;
		x = y * pi / 180;
		for (int i = 0; i < 100; i++) {
			term = pospower(-1, i) * pospower(x, 2 * i + 1) / fact(2 * i + 1);
			sin+= term;
		}
		cout << "sin ( " << y << " ) = " << sin << endl;
		break;
		// cos x
	case 8:
		cout << "Enter angle in degree" << endl;
		cin >> y;
		x = y * pi / 180;
		for (int i = 0; i < 100; i++)
			term += pospower(-1, i) * pospower(x, 2 * i) / fact(2 * i);
			cos += term;
			cout << "cos ( " << y << " ) = " << cos << endl;
		break;
		// tan x
	case 9:
		cout << "Enter angle in degree" << endl;
		cin >> y;
		x = y * pi / 180;
		for (int i = 0; i < 100; i++) {
			term = pospower(-1, i) * pospower(x, 2 * i + 1) / fact(2 * i + 1);
			sin += term;
		}
		for (int i = 0; i < 100; i++)
			term += pospower(-1, i) * pospower(x, 2 * i) / fact(2 * i);
		cos += term;
		cout<< "tan ( " << y << " ) = " << sin/cos << endl;
		break;
		//  e^x
	case 10:
		cout << "Enter the value of x where x is the power \n";
		cin >> x;
		if (x > 0) {
			cout << " e ^ " << x << " = " << pospower(e,x) << endl;
		}
		else
		{
			cout << " e ^ " << x << " = " << negpower(e, x) << endl;
		}
		break;
		//  power  x^y
	case 11:
		cout << "Enter the value of x where x is the base \n";
		cin >> x;
		cout << "Enter the value of y where y is the power\n";
		cin >> y;
		if (y > 0) {
			cout << x << " ^ " << y << " = " << pospower(x,y) << endl;
		}
		else
		{
			cout << x << " ^ " << y << " = " << negpower(x, y) << endl;
		}
		break;
		// sum
	case 12:
		cout << "Enter the value of x\n";
		cin >> x;
		cout << "Enter the value of y\n";
		cin >> y;
		ans = x + y;
		cout << x << " + " << y << " = " << ans << endl;
		break;
		// difference
	case 13:
		cout << "Enter the value of x\n";
		cin >> x;
		cout << "Enter the value of y\n";
		cin >> y;
		ans = x - y;
		cout << x << " - " << y << " = " << ans << endl;
		break;
		// multiplication
	case 14:
		cout << "Enter the value of x\n";
		cin >> x;
		cout << "Enter the value of y\n";
		cin >> y;
		ans = x * y;
		cout << x << " * " << y << " = " << ans << endl;
		break;
		// division
	case 15:
		cout << "Enter the value of x\n";
		cin >> x;
		cout << "Enter the value of y\n";
		cin >> y;
		ans = x / y;
		cout << x << " / " << y << " = " << ans << endl;
		break;
		// average
	case 16:
		cout << "Enter the value of x\n";
		cin >> x;
		cout << "Enter the value of y\n";
		cin >> y;
		ans = (x + y) / 2;
		cout << "average = " << ans << endl;
		break;
	    // if the user input is not correct
	default:
		cout << "\t\t\t\tWrong choice\n\n";
		break;
	}
	cout << endl;
	return 0;
}
