#include "Bag.h"

//constructor
Bag::Bag()
{
	while (items.size() != 0)
	{
		items.pop_back();
	}
}

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

int Bag::remove_item()
{
	int removedItem;
	removedItem = items.at(items.size() - 1);
	items.pop_back();
	return removedItem;
}

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

int Bag::size()
{
	int size = items.size();
	return size;
}

void Bag::clear()
{
	while (items.size() != 0)
	{
		items.pop_back();
	}
}


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