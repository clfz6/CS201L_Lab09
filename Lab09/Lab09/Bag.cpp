#include "Bag.h"

//constructor
Bag::Bag()
{
	while (items.size() != 0)
	{
		items.pop_back();
	}
}

//adds an item to the vector and returns true if it successfully did so
bool Bag::add_item(int item)
{
	int expectedSize;
	expectedSize = size() + 1;
	items.push_back(item);
	if (size() == expectedSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns the last item in the vector and erases it
int Bag::remove_item()
{
	int removedItem;
	removedItem = items.at(items.size() - 1);
	items.pop_back();
	return removedItem;
}

//searches for one instance of a given integer in the vector, moves it to the back of the vector and pops it
bool Bag::delete_item(const int& item)
{
	int expectedSize;
	expectedSize = size() - 1;
	for (int i = 0; i < size(); i++)
	{
		if (items[i] == item)
		{
			items[i] = items[items.size() - 1];
			items.pop_back();
		}
		if (size() == expectedSize)
		{
			return true;
			break;
		}
	}
	if (size() != expectedSize)
	{
		return false;
	}
}

//searches for all instances of a given integer in the vector, moves it to the back of the vector and pops it
bool Bag::delete_all(const int& item)
{
	int lastSize;
	lastSize = size();
	for (int i = 0; i < size(); i++)
	{
		if (items[i] == item)
		{
			items.erase(items.begin() + i);
		}
	}
	if (size() != lastSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns the current size of the vector
int Bag::size()
{
	int size = items.size();
	return size;
}

//removes all elements in the vector
void Bag::clear()
{
	while (items.size() != 0)
	{
		items.pop_back();
	}
}


//searches fot the smallest integer in the vector, moves it to the back, and pops it
int OrderedBag::remove_item()
{
	int removedItem, indexSmallest = 0;

	for (int i = 0; i < size(); i++)
	{
		if (items[i] < items[indexSmallest])
			indexSmallest = i;
	}

	swap(items[indexSmallest], items[items.size() - 1]);
	removedItem = items.at(items.size() - 1);
	items.pop_back();
	return removedItem;
}