#pragma once

template <class T>
struct Pair
{
	Pair()
	{

	};
	Pair(T x, T y)
	{
		Set(x, y);
	};

	void Set(T x, T y)
	{
		_X = x;
		_Y = y;
	};

	T _X;
	T _Y;
};

typedef Pair<float> PairFloat;
typedef Pair<int> PairInt;
