#include<iostream>
#include<Windows.h>
#include<iomanip>
int CategorySelection();
int SubCategorySelection(int CategoryChoice);
void MoneyAndChange(long Money, int ItemNumber);
HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
int main()
{
    int CategoryChoice, ItemNumber;
    long Money;
    CategoryChoice = CategorySelection();
    ItemNumber = SubCategorySelection(CategoryChoice);
    SetConsoleTextAttribute(k, 1);
    cout << endl << setw(65) << "Enter the amount of money: ";
    SetConsoleTextAttribute(k, 7);
    cin >> Money;
    while (cin.fail() || Money <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        SetConsoleTextAttribute(k, 13);
        cout << endl << setw(65) << "Invalid amount, try again: ";
        SetConsoleTextAttribute(k, 7);
        cin >> Money;
    }
    MoneyAndChange(Money, ItemNumber);
    SetConsoleTextAttribute(k, 7);
    return 0;
}
int CategorySelection()
{
    int CategoryChoice;
    SetConsoleTextAttribute(k, 1);
    cout << endl << setw(71) << "Please select an appropriate category: " << endl;
    SetConsoleTextAttribute(k, 7);
    cout << setw(63) << "-----------------------\n";
    cout << setw(40) << "|";
    SetConsoleTextAttribute(k, 13);
    cout << setw(13) << "1. Tea";
    SetConsoleTextAttribute(k, 7);
    cout << setw(10) << "|\n";
    cout << setw(40) << "|";
    SetConsoleTextAttribute(k, 13);
    cout << setw(15) << "2. Coffee";
    SetConsoleTextAttribute(k, 7);
    cout << setw(8) << "|\n";
    cout << setw(63) << "-----------------------\n";
    SetConsoleTextAttribute(k, 1);
    cout << endl << setw(63) << "I need category number: ";
    SetConsoleTextAttribute(k, 7);
    cin >> CategoryChoice;
    while (cin.fail() || (CategoryChoice != 1 && CategoryChoice != 2))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        SetConsoleTextAttribute(k, 13);
        cout << endl << setw(65) << "Invalid choice, try again: ";
        SetConsoleTextAttribute(k, 7);
        cin >> CategoryChoice;
    }
    return CategoryChoice;
}
int SubCategorySelection(int CategoryChoice)
{
    string Menu[6] = { "Ice Tea", "Milk Tea", "Black Tea","Ice Coffee", "Milk Coffee", "Black Coffee" };
    int Price[6] = { 3,2,1,3,2,1 }, ItemNumber;
    SetConsoleTextAttribute(k, 7);
    cout << endl << setw(41) << "Codes" << setw(12) << "Items" << setw(12) << "Price" << endl;
    cout << setw(69) << "----------------------------------\n";
    SetConsoleTextAttribute(k, 13);
    if (CategoryChoice == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << setw(39) << i << setw(15) << Menu[i] << setw(8) << Price[i] << " dhs" << setw(9) << endl;
        }
    }
    else
    {
        for (int i = 3; i < 6; i++)
        {
            cout << setw(39) << i << setw(15) << Menu[i] << setw(8) << Price[i] << " dhs" << setw(9) << endl;
        }
    }
    SetConsoleTextAttribute(k, 7);
    cout << setw(69) << "----------------------------------\n";
    SetConsoleTextAttribute(k, 1);
    cout << endl << setw(60) << "I need item code: ";
    SetConsoleTextAttribute(k, 7);
    cin >> ItemNumber;
    while (cin.fail() || (CategoryChoice == 1 && ItemNumber != 0 && ItemNumber != 1 && ItemNumber != 2) || (CategoryChoice == 2 && ItemNumber != 3 && ItemNumber != 4 && ItemNumber != 5))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        SetConsoleTextAttribute(k, 13);
        cout << endl << setw(65) << "Invalid choice, try again: ";
        SetConsoleTextAttribute(k, 7);
        cin >> ItemNumber;
    }
    return ItemNumber;
}
void MoneyAndChange(long Money, int ItemNumber)
{
    string Menu[6] = { "Ice Tea", "Milk Tea", "Black Tea","Ice Coffee", "Milk Coffee", "Black Coffee" }, Answer;
    int Basket = 0;
    switch (ItemNumber)
    {
    case 0:
    case 3:
    {
        if (Money >= 3)
        {
            Money -= 3;
            Basket++;
        }
        break;
    }
    case 1:
    case 4:
    {
        if (Money >= 2)
        {
            Money -= 2;
            Basket++;
        }
        break;
    }
    case 2:
    case 5:
    {
        if (Money >= 1)
        {
            Money -= 1;
            Basket++;
        }
        break;
    }
    default:
        break;
    }
    if (Basket > 0)
    {
        SetConsoleTextAttribute(k, 1);
        cout << endl << setw(68) << "Do you want to add sugar? (Y/N): ";
        SetConsoleTextAttribute(k, 7);
        cin >> Answer;
        while (Answer != "y" && Answer != "Y" && Answer != "N" && Answer != "n")
        {
            cin.clear();
            cin.ignore(1000, '\n');
            SetConsoleTextAttribute(k, 13);
            cout << endl << setw(68) << "Invalid answer, try again (Y/N): ";
            SetConsoleTextAttribute(k, 7);
            cin >> Answer;
        }
        if (Answer == "y" || Answer == "Y")
        {
          SetConsoleTextAttribute(k, 13);
          cout << endl << setw(54) << "Alright, Here's your ";
          SetConsoleTextAttribute(k, 7);
          cout << Menu[ItemNumber];
          SetConsoleTextAttribute(k, 13);
          cout << " with sugar" << endl;
          cout << endl << setw(65) << "and your remaining money is : ";
          SetConsoleTextAttribute(k, 7);
          cout << Money << " dhs" << endl;
        }
        else
        {
          SetConsoleTextAttribute(k, 13);
          cout << endl << setw(54) << "Alright, Here's your ";
          SetConsoleTextAttribute(k, 7);
          cout << Menu[ItemNumber];
          SetConsoleTextAttribute(k, 13);
          cout << " without sugar" << endl;
          cout << endl << setw(65) << "and your remaining money is : ";
          SetConsoleTextAttribute(k, 7);
          cout << Money << " dhs" << endl;
        }
    }
    else
    {
        SetConsoleTextAttribute(k, 13);
        cout << endl << setw(65) << "You don't have enough money" << endl;
    }
}