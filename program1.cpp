//*************************************************
//          Natalie Ferraro
//          Program  #1
//          Due 01-25-2022 
//  Program 1 calculates and displays a
//  detailed monthly tax report to the user
//  based on their gross profit input.
//*************************************************

#include <iostream>
using namespace std;

void userIO()
{
    double grossProfit;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Please enter the gross total profit for the month:" << ' ' << "$"; //user input prompt for total gross profit
    cin >> grossProfit; //user input from console

    double countyTax = ((grossProfit * .02) /1.06); //county tax = gross profit * .02 (2% county tax)
    double stateTax = ((grossProfit * .04) /1.06); //state tax = gross profit * .04 (4% state tax)
    double totalTax = (countyTax + stateTax); //total tax = county tax + stat tax 
    double netSales = (grossProfit - totalTax); //net sales = gross profit - total tax
   
    cout <<"\n"; //line break for readability

    cout << "Gross Total:" << ' ' << "$" << grossProfit << endl; //console output representing the gross total profit
    cout << "Net Sales Profit:" << ' ' << "$" << netSales << endl; //console output representing the net sales profit
    cout << "County Sales Tax:" << ' ' << "$" << countyTax << endl; //console output representing the county sales tax
    cout << "State Sales Tax:" << ' ' << "$" << stateTax << endl; //console output representing the state sales tax
    cout << "Total Sales Tax:" << ' ' << "$" << totalTax << endl; //console output representing the total sales tax

    cout <<"\n"; //line break for readability
    cout << "Program completed." << endl; //statement letting the user know the program has completed
}

int main()
{
    userIO();
    return 0;
}