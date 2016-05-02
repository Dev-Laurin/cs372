//fa2.h
//Laurin Fisher
//Software Construction 2-15-16
//Assignment 2 
#ifndef __FA2_H_INCLUDED__
#define __FA2_H_INCLUDED__

#include <random> 
#include <vector>
#include <future>
#include <functional>

using std::vector;
using std::function;  

//Exercise A 
inline vector<double> normRand(size_t n){
	double const SEED = 5; 
	std::mt19937 gen(SEED); 

	vector<double> a; 
	double mean = 100.0; 
	double stdDev = 15.0; 

	std::normal_distribution<> d(mean,stdDev); 

	for(int i=0; i<n; ++i){
		a.push_back(d(gen)); 
	}
	return a; 
}

//Exercise B
inline int square(int n){
	return n*n; 
}

inline vector<int> asyncSquares(size_t n){
	vector<int> a;

	vector<std::future<int>> futures; 
	for(int i=0; i<n; ++i){
		futures.push_back(std::async(std::launch::async,square,i)); 
	}
	for(auto &i : futures){
		a.push_back(i.get()); 
	}
	return a; 
}

//Exercise C
template <typename fn> 
function<int(int)> repeatFunction(fn ff , int n){
	function<int(int)> answer =
	[=](int k){
		for(int i=0; i<n; ++i){
			k=ff(k); 
		}
		return k; 
	};
	return answer; 
}

#endif //__FA2_H_INCLUDED__