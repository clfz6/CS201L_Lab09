//Cristian Lopez

#include "Bag.h"

//this function takes input from input.txt file and calls the appropriate member funtion 
void PerformSequence(istream& is, ostream& os, Bag& my_bag)
{
	char input;
	int item_num;

	is >> input;

	switch (input)
	{
	case 'A':
		is >> item_num;
		os << "Adding " << item_num << ".\t";
		if (my_bag.add_item(item_num) == true)
		{
			os << "Add successful." << endl;
		}
		else
		{
			os << "Add NOT successful." << endl;
		}
		break;
		
	case 'R':
		item_num = my_bag.remove_item();
		os << "Removing item, got " << item_num << endl;
		break;

	case 'D':
		is >> item_num;
		os << "Deleting " << item_num << ".\t";
		if (my_bag.delete_item(item_num) == true)
		{
			os << "Delete successful." << endl;
		}
		else
		{
			os << "Delete NOT successful." << endl;
		}
		break;
		
	case 'Z':
		is >> item_num;
		os << "Deleting all instances of " << item_num << ".\t";
		if (my_bag.delete_all(item_num) == true)
		{
			os << "Delete successful." << endl;
		}
		else
		{
			os << "Delete NOT successful." << endl;
		}
		break;
		
	default:
		break;
	}
}

int main()
{
	Bag mybag;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	if (fin.fail() || fout.fail())
	{
		cout << "Input or output file failed to open." << endl;
	}

	fout << "Beginning processing with regular Bag." << endl;
	while (!fin.eof())
	{
		PerformSequence(fin, fout, mybag);		
	}
	if (mybag.size() == 0)
	{
		fout << "\nAt end of processing, the bag still has 0 items.\n" << endl << endl;
	}
	else
	{
		fout << "\nAt end of processing, the bag has " << mybag.size() << " items.\n" << endl << endl;
	}
	fin.close();
	fin.clear();

	OrderedBag orbag;
	fin.open("input.txt");
	if(fin.fail() || fout.fail())
	{
		cout << "Input or output file failed to open." << endl;
	}

	fout << "Repeating the process, with an Ordered Bag." << endl;
	while (!fin.eof())
	{
		PerformSequence(fin, fout, orbag);
	}
	if (orbag.size() == 0)
	{
		fout << "\nAt end of processing, the bag still has 0 items." << endl;
	}
	else
	{
		fout << "\nAt end of processing, the bag has " << mybag.size() << " items." << endl;
	}

	fin.close();
	fout.close();
	return 0;
}