#pragma once

#include <iostream>
#include <vector>
using namespace std;
namespace itertools{

	class range {

		public:
		range(int _a, int _b):a(_a),b(_b){}

		class iterator{
			int iter;

			public:
			iterator(int start) : iter(start) {}

			int operator*() const {return iter;}

			const iterator &operator++() {
				++iter;
				return *this;
			}
			bool operator==(const iterator &other) const {
				return other.iter==iter;
			}
			iterator& operator=(const iterator& other) {
				if (*this != other){
					this->iter = other.iter;
				}
				return *this;
			}

			bool operator!=(const iterator &other) const {
				return other.iter!=iter;
			}
    };

		iterator begin() {return a;}
		iterator end() {return b;}

		typedef int value_type;
		private:
			iterator a;
			iterator b;
	};
}