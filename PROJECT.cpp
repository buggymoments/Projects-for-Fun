#include <iostream>
#include <cstdlib>
using namespace std;
//help legit// 
//stuff to add
//1. yung case 3 and 4 sa main menu
//2. some other fail input things
//3. yung buy again for some of the fails and end.
//4. the prices
//HEYYYYYYY WAIT COMBINE BREAD AND PASTRIES INTO ONE*
//basically 1. Buy tapos 1. Bread 2. Pastries and so on. although magaging apat options sa main menu
//*maybe
//there are some infinite loops here lalo na kapag yung input mo is letter (since we ask for number)
//the prices me not understand
//maybe too many functions
int BuyChoice, mochaCake, navi;
float moneyBalance, totalAmount;
char yesn;
string product_names[2][3] = {
    {"Bread", // First element in column contains category
        // Items
        "Pandesal", // Size only one - pieces
        "Wheat Loaf Bread", // Size  - slice or one whole
    },
    {"Pastries",
        "Chocolate Cookies"
        "Mocha Cake",
    }
};

// product_prices[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices
float product_prices[2][2][3] = {
    { // Bread
        //{price per slice, stock in slices, slices per whole (1 means 1 whole )}
        {5, 50, 1}, // Pandesal
        {11, 45, 10} // Wheat Loaf
    }, // Pastries
    {
        {18, 33, 1}, // Choco cookies
        {30, 60, 6} // Mocha cake
    }
};

void cakerMochs()
{
	cout<<"1. Slice\n";
	cout<<"2. Whole";
	cout<<"\nWhat size of Mocha Cake would you like to buy?: ";
	cin>>mochaCake;
	switch(mochaCake)
	{
	case 1:
		int cakeSlice;
		cout<<"How many slices would you like to buy?: ";
		cin>>cakeSlice;
		moneyBalance += cakeSlice * 30;
		cout<<"Would you like to buy again:(Y/N) ";
		cin>>yesn;
		if (yesn == 'Y' || yesn == 'y'){
			cakerMochs(); //Supposedly dapat option to go to Bread section or Pastry section pero they not declared??
		}
		else if (yesn == 'N' || yesn == 'n'){
			cout<<"Your current Total is: "<<moneyBalance;
		}
		else {
			cout<<"Invalid Input";
		}
		break;
	case 2:
		int wholeCake;
		cout<<"How many Mocha Cake would you like to buy?: ";
		cin>>wholeCake;
		moneyBalance += wholeCake * 180;
		cout<<"Your current total is "<<moneyBalance;
		break;
        }
	}
void cookieQuants()
{
	int cookieQuanti;
	
	cout<<"How many Cookies would you like to buy?: ";
	cin>>cookieQuanti;
	moneyBalance += cookieQuanti * 18; 
	cout<<"Your current total is: "<<moneyBalance;
}

void pastryChoices()
{
	int pastryChoice;
    cout<<"LOCATION: PASTRIES\n";
	cout<<"\nWhich pastry would you like to buy: ";
	cout<<"\n1. Chocolate Cookies";
	cout<<"\n2. Mocha Cake";
	cout<<"Enter option: ";
	cin>>pastryChoice;
	switch(pastryChoice)
	{
		case 1:
			cookieQuants();
            break;
		case 2:
			cakerMochs();
            break;
	}
}
void wlb ()
{
	
	int wlbSize;
	cout<<"1. Slice\n";
	cout<<"2. Whole";
	cout<<"\nWhat size of Wheat Loaf Bread would you like to buy?: ";
	cin>>wlbSize;
	switch(wlbSize)
	{
		case 1:
			int wlbSlices;
			cout<<"How many slices would you like to buy?: ";
			cin>>wlbSlices;
			moneyBalance += wlbSlices * 11;
			cout<<"Your current Total is: "<<moneyBalance;
			break;
			case 2:
			int wholeLoaf;
			cout<<"How many Wheat Loaf Bread would you like to buy?: ";
			cin>>wholeLoaf;
			moneyBalance += wholeLoaf * 5; 
			cout<<"Your current Total is: "<<moneyBalance; //PAY THINGY
			break;
			}
}
	

void quantiPande()
{
	int pandeQuanti;
	cout<<"How many Pandesal would you like to buy?: ";
	cin>>pandeQuanti;
    moneyBalance += pandeQuanti * 5; // change price pls
	cout<<moneyBalance;
}
void breadChoices()
{
	int breadChoice;
    cout<<"LOCATION: BREAD\n";
	cout<<"\n1. Pandesal";
	cout<<"\n2. Wheat Loaf Bread";
	cout<<"\nWhich bread would you like to buy: ";
	cin>>breadChoice;

	if (breadChoice != 1 && breadChoice != 2)
	{
		cout<<"Wrong Input! Please Try Again. \n";
		breadChoices();
	}
	else
	{
		switch (breadChoice)
		{
			case 1:
				quantiPande();
				break;
			case 2:
				wlb();
				break;
							
		}
	}
} 
void buyChoices()
{
	cout<<"Main Menu\n";
	cout<<"1. Bread";
	cout<<"\n2. Pastries";
	cout<<"\n3. Reset Cart\n";
	cout<<"4. Checkout\n";
	cout<<"5. Exit Program";
	cout<<"\nWhat would you like to buy/do: ";
	cin>>BuyChoice;

	if (BuyChoice != 1 && BuyChoice != 2 && BuyChoice != 3 && BuyChoice != 4 && BuyChoice !=5)
	{
		cout<<"Try Again\n";
		buyChoices();
	}
	else{

	
	switch(BuyChoice)
	{
		case 1: 
		breadChoices();
		break;
		case 2:
		pastryChoices();
		break;
		case 3:
		//help
		break;
		case 4:
		//help
		cout<<moneyBalance;
		break;
		case 5:
		cout<<"Thank You!. Please Come Again.";
		exit(0);
	}
	}
}

int main() 
{
    
	buyChoices();
    
}
