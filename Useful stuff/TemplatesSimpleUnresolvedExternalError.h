#pragma once

template <class T>
void error(const T&);

template<class T>
inline void error(T&)
{
	return;
}

/*
even though VS is telling you that error is defined, it actually isn't and during compilation you will receive an unresolved externals error,
this tiny error can cause you a lot of troubles and it is hard to find in a big project, so check carefully that the declaration and the definition are the same
*/