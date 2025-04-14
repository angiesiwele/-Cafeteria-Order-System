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
 int item_number,quantity;
 double total, final_total;
 int main() {
 //Prompt the user to enter their name and surname.(2 marks)
 cout << "Enter your Name: " << endl;
 cin >> name ;
 cout << "Enter your Surname: " << endl;
 cin >> surname ;
 //Display the menu and prompt the user to select up to 8 items.(3 marks)
 bool isRunning = true;
 while(isRunning == true) {
 for (int n=1;n<=8;n++) {
 cout << "\nMenu:\n"
 << "1. Coffee-R15.00\n"
 << "2. Sandwich-R30.00\n"
 << "3. Salad-R25.00\n"
 << "4. Juice-R10.00\n"
 << "5. Muffin-R20.00\n"
 << "6. Pizza Slice-R35.00\n"
 << "7. Soup-R18.00\n"
 << "8. Burger-R40.00\n"
 << "x. Exit" << endl;
 cout << "Select Item " << n << " (1-8): \n";
 cin >> item_number ;
 //Get quantity for the selected items
 cout << "Enter quantity for item" << item_number << ": \n";
 cin >> quantity;
 switch (item_number) {
 case 1: total += COFFEE_PRICE*quantity; break;
case 2: total += SANDWICH_PRICE*quantity; break;
 case 3: total += SALAD_PRICE*quantity; break;
 case 4: total += JUICE_PRICE*quantity; break;
 case 5: total += MUFFIN_PRICE*quantity; break;
 case 6: total += PIZZA_PRICE*quantity; break;
 case 7: total += SOUP_PRICE*quantity; break;
 case 8: total += BURGER_PRICE*quantity; break;
 default:
 cout << "Exiting selection.\n";
 isRunning = false;
 break;
 }
 }
 if(total>=DISCOUNT_THRESHOLD) {
 final_total = total-total*DISCOUNT_RATE;
 cout << "\nTotal Bill: R" << total << endl;
 cout << "10% Discount Applied." << endl;
 cout << "Final Bill: R" << final_total << endl;
 }
 else if(total>=DISCOUNT_RATE) {
 final_total = total;
 cout << "\nTotal Bill: R" << total << endl;
 cout << "No Discount Applied." << endl;
 cout << "Final Bill: R" << total << endl;
 }
 // Create and open a text file
 ofstream MyFile("CafeteriaBill.txt");
 // Write to the file
 MyFile << "Customer Name: "<< name << "\nCustomer Surname: " << surname<<
 "\nFinal Total Bill: R" << final_total << endl;
 // Close the file
 MyFile.close();
 cout << "The bill has been written to CafeteriaBill.txt " << endl;
 break;
 }
 return 0;
 }
