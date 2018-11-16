//------------------------------------------------------------------------
// Name:  
//Nicole Hall : Nicole - 50 % , A Rezin - 50 %
//Ariel Rezin : N Hall -  , Ariel - 
//
// Course:  CS 1430, Section 6
//
// Purpose: 
//
// Input:  
// Output:  
//------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int CARTCAPACITY = 20;
const int WIDTHITEM = 10;
const int WIDTHQUANTITY = 5;
const int WIDTHUNITPRICE = 10;


void Add(string items[], int quantities[], float unitprices[], int & cartcount);
int Find(const string items[], int num, string name);
void Remove(string items[], int quantities[], float unitprices[], int & cartcount);
void Sort(string items[], int quantities[], float unitprices[], int cartcount);
void Upd(string items[], int quantities[], float unitprices[], int cartcount);
void Print(const string items[], const int quantities[], float unitprices[], int cartcount);


int main()
{
	string items[CARTCAPACITY];
	int quantities[CARTCAPACITY];
	float unitprices[CARTCAPACITY];
	int cartcount = 0;
	char commands;

	cout << "Enter command to manage your shopping cart..." << endl;

	cout << "Enter A to add an item into your cart" << endl
		<< "Enter R to remove an item from your cart" << endl
		<< "Enter U to update an item in your cart" << endl
		<< "Enter S to sort items in your cart" << endl
		<< "Enter P to print out your cart information" << endl;

	cin >> commands;
	while (cin)
	{
		if (commands == 'A')
		{
			Add(items, quantities, unitprices, cartcount);
		}

		else
		{
			if (commands == 'R')
			{
				Remove(items, quantities, unitprices, cartcount);
			}
			else
			{
				if (commands == 'U')
				{
					Upd(items, quantities, unitprices, cartcount);
				}
				else
				{
					if (commands == 'S')
					{

						Sort(items, quantities, unitprices, cartcount);
					}
					else
					{
						if (commands == 'P')
						{
							Print(items, quantities, unitprices, cartcount);
						}
						else
						{
							cout << "Invalid Command!" << endl;
						}
					}
				}
			}
		}

		cin >> commands;
	

	}

	if (cartcount >= 1)
	{
		cout << "Normal Termination of Program 4." << endl;
	}
	else
	{

		cout << "Your shopping cart is empty!" << endl;
		cout << "Normal Termination of Program 4." << endl;
	}

	return 0;
}



void Add(string items[], int quantities[], float unitprices[], int & cartcount)
{

	string itemname;
	int quantity;
	int price;

	if (cartcount < CARTCAPACITY)
	{

		cout << "Please enter item name, quantity, and unit price :" << endl;
		cin >> itemname >> quantity >> price;

		int index = Find(items, cartcount, itemname);
		
		if (index >= 0) 
		{
			quantities[index] = quantity;
			unitprices[index] = price;

			cout << "Unit price is updated to " << price << endl;
			
		}
		else
		{

			cartcount++;
			items[cartcount - 1] = itemname;
			quantities[cartcount - 1] = quantity;
			unitprices[cartcount - 1] = price;

			cout << itemname << " was added to the fleet." << endl;
			/////////// Add sortName
		}
	}
	else
	
		cout << itemname << "is not added.The shopping cart is full." << endl;

}

int Find(const string items[], int num, string name)
{
	for (int a = 0; a < num; a++)
	{
		if (items[a] == name)
			return a;
	}
	return -1;
}

void Remove(string items[], int quantities[], float unitprices[], int & cartcount)
{
	string itemname;

	cin >> itemname;

	if (cartcount != 0)
	{

		int index = Find(items, cartcount, itemname);

		if (index >= 0)
		{
			for (int a = index; a < cartcount; a++)
			{
				items[a] = items[a + 1];
				quantities[a] = quantities[a + 1];
				unitprices[a] = unitprices[a + 1];
			}

			cartcount--;
			cout << itemname << " has been removed from your cart." << endl;

		}
		else
			cout << " Cannot find "<<itemname<<" in your cart." << endl;
	}
	else
		cout << "Your shopping cart is empty!" << endl;
}

void Sort(string items[], int quantities[], float unitprices[], int cartcount) 
{																					    	//Should we make separate functions for the 
																						   //different commands, so then we could use 
																						  // the sortNames command for the add function.
	char sortcommands;

	cout << "How do you like to sort your cart ?" << endl
		<< "Enter N to sort by name" << endl
		<< "Enter Q to sort by quantity" << endl
		<< "Enter P to sort by price" << endl;


	if (sortcommands == 'N')
	{
		//sortNames
		Print(items, quantities, unitprices, cartcount);
		cout << "Items sorted by name." << endl;
	}
	else
	{
		if (sortcommands == 'P') 
		{
			//sortPrice
			Print(items, quantities, unitprices, cartcount);
			cout << "Items sorted by price." << endl;
		}
		else
		{
			if (sortcommands == 'Q')
			{
				//sortQuantity
				Print(items, quantities, unitprices, cartcount);
				cout << "Items sorted by quantity." << endl;
			}
			else
			{
				cout << "Invalid Command!";
			}
		}
	}
	
}

void Upd(string items[], int quantities[], float unitprices[], int cartcount) 
{
	string itemname;
	int quantity;

	if (cartcount = !0)
	{

		cout << "Which item do you like to update quantity for?" << endl;
		cin >> itemname;

		int index = Find(items, cartcount, itemname);

		if (index >= 0)
		{

			cout << "How many " << itemname << " do you want ?" << endl;
			cin >> quantity;
			//we need to check if the quantity is alread the one we cin'ed, so should we make another find to check or check in this function.
			//if they are the same cout << "The quantity of " << itemname << " remains " << quantity << "." << endl;
			//if they are not the same quantity use the code below.
			quantities[index] = quantity;

			cout << "The quantity of" <<itemname << "is updated to" << quantity << " ." << endl;

		}
		else
			cout << "Cannot find" << itemname << "in your cart." << endl;
	}
	else
		cout << "Your shopping cart is empty!" << endl;
}

void Print(const string items[], const int quantities[], float unitprices[], int cartcount)
{
	float totalprice = 0;

	cout << "Items in your shopping cart:" << endl;

	for (int a = 0; a < cartcount; a++)
	{

		cout << setw(WIDTHITEM) << right << items[a]
			<< setw(WIDTHQUANTITY) << right << quantities[a]
			<< setw(WIDTHUNITPRICE) <<right << unitprices[a]<< endl;

	}

	for (int a = 0; a < cartcount; a++)
	{
		totalprice = totalprice + quantities[a] * unitprices[a];
		
	}
	cout << "The total price of items in your cart is " << totalprice;
	
}