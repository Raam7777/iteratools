#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace itertools{

	typedef struct {
		template <typename T>
		T operator ()(T x, T y) const{
			return x+y;
		}
	}plus;

	
	template <typename T, typename Function = plus>
	class accumulate{
		T container;
		Function f;
		public:	
		typedef typename T::value_type value_type;
		accumulate(T c, Function f=plus()):container(c),f(f){}
		

		class iterator{
			typename T::iterator b;
			typename T::iterator e;
			typename T::value_type sum;
			Function f;

			public:
			iterator(typename T::iterator _b, typename T::iterator _e, Function _F): 
				b(_b),e(_e),f(_F){
					if(b != e)
						sum = *b;
				}

			auto operator*(){
				return sum;
			}
			const iterator& operator++(){
				++b;
				if(b!=e)
          sum=f(sum,*b);
				return *this;
      }
			const iterator& operator=(const iterator& other){
        if (*this != other){
          this->e = other.e;
          this->sum = other.sum;
          this->b = other.b;
          this->f = other.f;
        }
        return *this;
      }

			bool operator!=(const iterator& other) const {
				return b!=other.b;
			}   

		};

		
		iterator begin(){return iterator(container.begin(),container.end(),f);}
		iterator end(){return iterator(container.end(),container.end(),f);}

	};

}