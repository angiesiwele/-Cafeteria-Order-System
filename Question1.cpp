//Question 1
/*Cafeteria Order System
You are a software developer working for a university cafeteria. The cafeteria wants to automate
the process of calculating bills for customers based on the items they purchase. The program should
ask the user to input their name, surname, and the number of items they have ordered, along with the
price for each item. The program will then calculate the total bill, apply a discount if applicable,
and write the customer's details and their total bill to a text file for record-keeping.
*/

#include <iostream>
#include <fstream>
using namespace std;
const double DISCOUNT_RATE = 0.10; // 10% discount
const double DISCOUNT_THRESHOLD = 100.00; // Discount applies if bill is over R100
//Menu Prices
const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;
char name,surname,menu;
char answer;
int item_number;
double total, final_total;


int main() {

    //Prompt the user to enter their name and surname.(2 marks)
    cout << "Enter your Name: " << endl;
    cin >> name ;
    cout << "Enter your Surname: " << endl;
    cin >> surname ;
    //Display the menu and prompt the user to select up to 8 items.(3 marks)
    bool isRunning =true;
    while(isRunning == true) {
        for (int n=1;n<=8;n++) {
            cout << "\nMenu:\n"
            << "1. Coffee - R15.00\n"
            << "2. Sandwich - R30.00\n"
            << "3. Salad - R25.00\n"
            << "4. Juice - R10.00\n"
            << "5. Muffin - R20.00\n"
            << "6. Pizza Slice - R35.00\n"
            << "7. Soup - R18.00\n"
            << "8. Burger - R40.00\n"
            << "x. Exit" << endl;
            cout << "Select Item " << n << " (1-8):";
            cin >> item_number ;
            if(item_number==1) {
                total = total + COFFEE_PRICE;
            }
            if(item_number==2) {
                total = total + SANDWICH_PRICE;
            }
            if(item_number==3) {
                total = total + SALAD_PRICE;
            }
            if(item_number==4) {
                total = total + JUICE_PRICE;
            }
            if(item_number==5) {
                total = total + MUFFIN_PRICE;
            }
            if(item_number==6) {
                total = total + PIZZA_PRICE;
            }
            if(item_number==7) {
                total = total + SOUP_PRICE;
            }
            if(item_number==8) {
                total = total + BURGER_PRICE;
            }
            if(item_number=='x') {
                isRunning = false;
                break;
            }
    }

        if(total>=DISCOUNT_THRESHOLD) {
            final_total = total-total*DISCOUNT_RATE;
            cout << "Total Bill: R" << total << endl;
            cout << "10% Discount Applied." << endl;
            cout << "Final Bill: R" << final_total << endl;
        }
        else if(total>=DISCOUNT_RATE) {
            final_total = total;
            cout << "Total Bill: R" << total << endl;
            cout << "No Discount Applied." << endl;
            cout << "Final Bill: R" << total << endl;
        }
        // Create and open a text file
        ofstream MyFile("CafeteriaBill.txt");
        // Write to the file
        MyFile << "Customer Name: "<< name << "\nCustomer Surname: " << surname<< "\nFinal Total Bill: R" << final_total << endl;
        // Close the file
        MyFile.close();
        cout << "The bill has been written to CafeteriaBill.txt :" << endl;
        break;

    }

    //For each selection, validate the input and calculate the total bill by summing the prices of the selected items.(4 marks)
    //Apply a 10% discount if the total bill exceeds R100. (3 marks)
    //Display the total bill, discount applied (if applicable), and the final bill after discount.(3 marks)
    //Write the customer's name, surname, and the final total bill (after discount if applicable) to a text file named CafeteriaBill.txt.(3 marks)
    //Display a message indicating that the bill has been written to the file, or display an error message if the file could not be opened.

    return 0;
}
