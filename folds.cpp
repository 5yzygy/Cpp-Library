/*
	Author / Researcher: Ahmet Emre Harsa
	Note: Not entirely written by me but I have 
			brought together different functions 
			from online resources and also utilized
			the help of ChatGPT for convenience.
*/

#include <iostream>

/* Base Case - Return the only remaining element for foldr. */
template<typename Func, typename T>
T foldr(Func func, T v)
{
	std::cout << "Base Function :" << __PRETTY_FUNCTION__ << "\n";
    return v;
}

/* General Case - Apply the Right-Fold function to
   current elements. */
template<typename Func, typename T, typename... Args>
T foldr(Func func, T first, Args... args)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
    return func(first, foldr(func, args...));
}

/* Base Case - Return the only remaining element for foldl. */
template <typename Func, typename T>
T foldl(Func func, T accumulator) 
{
	std::cout << "Base Function :" << __PRETTY_FUNCTION__ << "\n";
    return accumulator;
}

/* General Case - Apply the Left-Fold function to
   current elements. */
template <typename Func, typename T, typename Arg, typename... Args>
T foldl(Func func, T accumulator, Arg arg, Args... args)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
    return foldl(func, func(accumulator, arg), args...);
}

/* Sample addition function for testing purposes. */
template <typename T>
T add(T x, T y)
{
	return x + y;
}

/* Sample multiplication function for testing     
   purposes. */
template<typename T>
T multiply(T x, T y)
{
	return x * y;
}

int main()
{
	std::cout << "Sum with Right Fold: " << foldr(add<double>, 1, 2, 3, 4, 5) << "\n";

	std::cout << "Multiplication with Right Fold: " << foldr(multiply<double>, 1, 2, 3, 4, 5) << "\n";

	std::cout << "Sum with Left Fold: " << foldl(add<int>, 1, 2, 3, 4, 5) << "\n";

	std::cout << "Multiplication with Left Fold: " << foldl(multiply<int>, 1, 2, 3, 4, 5) << "\n";
}