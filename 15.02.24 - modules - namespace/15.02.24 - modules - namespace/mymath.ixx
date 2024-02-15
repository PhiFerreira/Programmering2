export module mymath;

export{
	template <typename T> T square(const T& x);
	const double lambda{ 1.4325353 }; //Just example, not real lambda
	enum class Oddity { Even, Odd };
	Oddity getOddity(int x);

	}

	
	


bool isOdd(int x) {
	return x % 2 != 0;
}


Oddity getOddity(int x) {
	if (isOdd(x)) {
		return Oddity::Odd;
	}
	return Oddity::Even;
}

template <typename T>
T square(const T& x) {
	return x * x;
}

