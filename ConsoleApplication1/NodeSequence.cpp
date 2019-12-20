

#include "Sequence.h"
#include "NodeSequence.h"
#include "SortClass.h"
#include <iostream>
#include "Animal.h"
#include <time.h> 

void testing_sorts()
{
	std::cout << "Starting tests of sorting methods" << std::endl;
	time_t start, end;
	SortClass B;
	NodeSequence<int> a;
	for (int i = 0; i < 10000; i++)
	{
		a.addelem(rand() % 50 - rand() % 50);
	}
	std::cout << "Testing bublesort on 10000 elements" << std::endl;
	time(&start);
	B.bubleSort(a, a.getLength(), [](const int& first, const int& second) -> bool
	{
		return second > first;
	});
	time(&end);
	double seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	NodeSequence<int> b;
	std::cout << "Testing insert_sort on 10000 elements" << std::endl;
	for (int i = 0; i < 10000; i++)
	{
		b.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.insert_sort(b, b.getLength(), [](const int& first, const int& second) -> bool
	{
		return second > first;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	NodeSequence<int> c;
	std::cout << "Testing shell_sort on 10000 elements" << std::endl;
	for (int i = 0; i < 10000; i++)
	{
		c.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.shellSort(c, c.getLength(), [](const int & first, const int & second) -> bool
	{
		return second > first;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;

	NodeSequence<int> a1;
	for (int i = 0; i < 25000; i++)
	{
		a1.addelem(rand() % 50 - rand() % 50);
	}
	std::cout << "Testing bubleSort on 25000 elements" << std::endl;
	time(&start);
	B.bubleSort(a1, a1.getLength(), [](const int& first, const int& second) -> bool
	{
		return second > first;
	}); 
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing insert_sort on 25000 elements" << std::endl;
	NodeSequence<int> b1;
	for (int i = 0; i < 25000; i++)
	{
		b1.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	/*B.insert_sort(b1, b1.getLength(), [](NodeSequence<int>& a, int i, int j) -> bool
		{
			if (a[i] < a[j])
				return true;
			else
				return false;
		});*/
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing shell_sort on 25000 elements" << std::endl;
	NodeSequence<int> c1;
	for (int i = 0; i < 25000; i++)
	{
		b1.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.shellSort(b1, b1.getLength(), [](int i, int j) -> bool
	{
		if (i < j)
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;

	std::cout << "Testing bubleSort on 50000 elements" << std::endl;
	NodeSequence<int> a2;
	for (int i = 0; i < 50000; i++)
	{
		a2.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.bubleSort(a2, a2.getLength(), [](int i, int j) -> bool
	{
		if (i < j)
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing insert_sort on 50000 elements" << std::endl;
	NodeSequence<int> b2;
	for (int i = 0; i < 50000; i++)
	{
		b2.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.insert_sort(b2, b2.getLength(), [](int i, int j) -> bool
	{
		if (i < j)
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing shell_sort on 50000 elements" << std::endl;
	NodeSequence<int> c2;
	for (int i = 0; i < 50000; i++)
	{
		c2.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.shellSort(c2, c2.getLength(), [](int i, int j) -> bool
	{
		if (i < j)
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
}


//template<typename TElement>
int main()
{
	//testing_sorts();
	SortClass B;
	NodeSequence<int> a;
	

	for (int i = 0; i < 10000; i++)
	{
		a.addelem(rand() % 50 - rand() % 50);
	}
	//a.addelem(-3);
	//a.addelem(12);
	//a.addelem(-6);
	//a.addelem(0);
	//a.addelem(10);
	/*B.insert_sort(a, a.getLength(), [](NodeSequence<int>& a, int i, int j) -> bool
		{
			if (a[i] < a[j])
				return true;
			else
				return false;
		});*/
	//B.bubleSort(a, a.getLength(), [](int i, int j) -> bool
	//	{
	//		if (i > j)
	//			return true;
	//		else
	//			return false;
	//	});
	B.shellSort(a, a.getLength(), [](int i, int j) -> bool
		{
			if (i > j)
				return true;
			else
				return false;
		});
	std::cout << "Len : " << a.getLength() << " Full: " << a.getIsEmpty() << std::endl;
	a.printList();
	a.deletelem(0);
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;

	std::cout << "Element by operator " << a[2] << std::endl;
	a[1] = 0;
	a.printList();
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;

	a.printList();
	try
	{
		a.deletelem(5);
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a.printList();
	a.deletelem(0);
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	std::cout << "Len : " << a.getLength() << std::endl;
	a.printList();
	try
	{
		a.deletelem(2);
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	std::cout << "Len : " << a.getLength() << std::endl;
	a.printList();

	int b1(32);
	int b2(4);
	int b3(8);
	int b4(12);
	int b5(23);
	int b6(55);
	int b7(70);
	int b8(1);
	NodeSequence<int> a2;

	a2.addelem(b1);
	a2.addelem(b2);
	a2.addelem(b3);
	a2.addelem(b4);
	a2.addelem(b5);
	a2.addelem(b6);
	a2.addelem(b7);
	a2.addelem(b8);

	/*B.bubleSort(a2, a2.getLength(), [](NodeSequence<int>& a, int i, int j) -> bool
		{
			if (a[i] < a[j])
				return true;
			else
				return false;
		});*/
	a2.printList();
	
	a2.printList();
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	try
	{
		a2.deletelem(-4);
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	a2.deletelem(4);
	a2.printList();
	std::cout << "Len : " << a2.getLength() << "Full: " << a2.getIsEmpty() << std::endl;
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;

	a2.deletelem(1);
	a2.printList();


}
