// =================================================================
//
// File: bubble.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				bubble sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>
#include <string>

// =================================================================
// Performs the bubble sort algorithm on an array
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void bubbleSort(T *arr, int size) {
	for(int i = size - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr, j, j + 1);
			}
		}
	}
}

// =================================================================
// Performs the bubble sort algorithm on an vector.
//
// @param v, a vector of T elements.
// =================================================================
template <class T>
void bubbleSort(std::vector<T> &v) {
	std::string y1,y2,m1,m2,d1,d2;
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			y1=v[i].substr(6,2);
			m1=v[i].substr(3,2);
			d1=v[i].substr(0,2);

			y2=v[i+1].substr(6,2);
			m2=v[i+1].substr(3,2);
			d2=v[i+1].substr(0,2);

			if(y1==y2){
				if(m1==m2){
					if(d1<d2){
						swap(v, j, j + 1);
					}
				}
				else{
					swap(v, j, j + 1);
				}
			}
			else{
				swap(v, j, j + 1);
			}
		}
	}
}

#endif /* BUBBLE_H */
