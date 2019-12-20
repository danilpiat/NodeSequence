#pragma once
#include "Sequence.h"


class SortClass 
{
public:
	SortClass();
	~SortClass();
	template<typename TElement, template <typename ...> class Container, class Compare>
	void bubleSort(Container<TElement>& array, int size, Compare comp);
	template<typename TElement, template <typename ...> class Container, class Compare>
	void shellSort(Container<TElement>& vector, int len, Compare comp);
	template<typename TElement, template <typename ...> class Container, class Compare>
	void insert_sort(Container<TElement>& vector, int size, Compare comp);
	


	
};

template<typename TElement, template <typename ...> class Container, class Compare>
void SortClass::bubleSort(Container<TElement>& array, int size, Compare comp)
{
	/*TElement tmp;
	int k;
	while (size > 1)
	{
		k = 0;
		for (int i = 1; i < size; i++)
		{
			if (comp(array, i, i - 1))
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				k = i;
			}
		}
		size = k;
	}*/

	//int i, j;
	//for (i = 0; i < size - 1; i++)

	//	// Last i elements are already in place  
	//	for (j = 0; j < size - i - 1; j++)
	//		if (array[j] > array[j + 1])
	//			array.swap(j, j + 1);

	auto head = array.get(0);
	while (head->next != nullptr)
	{
		head = head->next;
		auto curHead = head;
		while (curHead->next != nullptr)
		{

			if (comp(head->data, curHead->data))
			{
				auto temp = head->data;
		
				head->data = curHead->data;
				curHead->data = temp;

			}
			curHead = curHead->next;
		}
	}
}

template<typename TElement, template <typename ...> class Container, class Compare>
void  SortClass::insert_sort(Container<TElement>& vector, int size, Compare comp)
{
	
	/*for (int i = 1; i < size; i++)
	{
		TElement cur = vector[i];
		int j = i;
		while (j > 0 && comp(vector, i, j - 1))
		{
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = cur;
	}*/

	TElement temp;
	for (int i = 1; i < size; i++)
	{
		temp = vector[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (comp(vector[j], temp))
				break;

			vector[j + 1] = vector[j];
			vector[j] = temp;
		}
	}
}

template<typename TElement, template <typename ...> class Container, class Compare>
void  SortClass::shellSort(Container<TElement> &vector, int len, Compare comp)
{
	//int step = len / 2;
	//while (step > 0)
	//{
	//	int i, j;
	//	for (i = step; i < len; i++)
	//	{
	//		TElement value = vector[i];
	//		for (j = i - step; (j >= 0) && (vector[j] > value); j -= step)
	//			vector[j + step] = vector[j];
	//		vector[j + step] = value;
	//	}
	//	step /= 2;
	//}
	int step = len / 2;
	while (step > 0)
	{
		int i, j;
		auto value_step = vector.get(step);
		i = step;
		for (; value_step != nullptr; )
		{
			auto value = value_step->data;
			for (j = i - step; (j >= 0) && (vector[j] > value); j -= step)
			{
				vector[j + step] = vector[j];
			}
				
			vector[j + step] = value;
			value_step = value_step->next;
			i++;
		}
		step /= 2;
	}
}



