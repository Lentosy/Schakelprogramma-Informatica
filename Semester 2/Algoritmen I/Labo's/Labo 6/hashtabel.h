#pragma once

#include <vector>
#include <list>
#include <ostream>

template<class T,int(* hashindex)(const T&,int n)>
class hashtabel : public std::vector<std::list<T>> {
	public:
		hashtabel(int n);
		void voegToe(const T &);
		void print(std::ostream&) const;
		double berekenEfficientie() const;
};


