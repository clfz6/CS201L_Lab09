#pragma once
#ifndef Bag_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Bag
{
public:
	Bag();
	bool add_item(int item);
	virtual int remove_item();
	bool delete_item(const int& item);
	bool delete_all(const int& item);
	int size();
	void clear();

protected:
	vector<int> items;

private:

};

class OrderedBag : public Bag
{
public:
	int remove_item() override;
};

#endif




