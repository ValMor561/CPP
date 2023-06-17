#pragma once
#include "Task10Api.hpp"

#define TEMPLATE_SORT_BY_BUBBLE(Type) \
void SortByBubble_##Type(Type *arr, int size) \
{\
	Type temp; \
	for (int i = 0;i < size - 1;++i) \
		for (int j = 0; j < size - i - 1; ++j) \
			if (arr[j] > arr[j + 1]) \
			{ \
				temp = arr[j]; \
				arr[j] = arr[j + 1]; \
				arr[j + 1] = temp; \
			} \
}