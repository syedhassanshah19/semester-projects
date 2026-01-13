#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int months;
    double annualTaxRate;
    double balance;
                                                                        // First Asking For All Inputs
    cout << "Enter annual tax deduction rate (in %): ";
    cin >> annualTaxRate;
    cout << "Enter initial account balance: ";
    cin >> balance;
    cout << "Enter total number of months: ";
    cin >> months;
                                                                        // Then Converting annual taxrate to monthly rate
    double monthlyTaxRate = (annualTaxRate / 100) / 12;
                                                                        // Using Dynamic Arrays(Dynamic arrays are arrays whose size can change at runtime)
    double* deposits = new double[months];
    double* withdrawals = new double[months];
    double* taxes = new double[months];
    double totalDeposits = 0.0;
    double totalWithdrawals = 0.0;
    double totalTaxes = 0.0;
                                                                        // Now Monthly Processing
    for (int i = 0; i < months; i++)
    {
    cout << "\n--- Month " << i + 1 << " ---\n";
                                                                        // Then Adding Deposit Input
    do
    {
    cout << "Enter deposit amount: ";
    cin >> deposits[i];
    if (deposits[i] < 0)
    cout << "Invalid input! Deposit cannot be negative.\n";
    }
	while (deposits[i] < 0);
    balance += deposits[i];
    totalDeposits += deposits[i];
                                                                         //Then Withdrawal Input
	do
    {
    cout << "Enter withdrawal amount: ";
    cin >> withdrawals[i];
    if (withdrawals[i] < 0)
    cout << "Invalid input! Withdrawal cannot be negative.\n";
    } 
	while (withdrawals[i] < 0);
    balance -= withdrawals[i];
    totalWithdrawals += withdrawals[i];
                                                                         //Now Tax Calculation
    taxes[i] = balance * monthlyTaxRate;
    balance -= taxes[i];
    totalTaxes += taxes[i];
    }
                                                                         //Then Output Summary
    cout << fixed << setprecision(2);
    cout << "\n====================================\n";
    cout << " Savings Account Summary Report\n";
    cout << "====================================\n";
    cout << "Final Account Balance: Rs. " << balance << endl;
    cout << "Total Deposited:       Rs. " << totalDeposits << endl;
    cout << "Total Withdrawn:       Rs. " << totalWithdrawals << endl;
    cout << "Total Tax Deducted:    Rs. " << totalTaxes << endl;
                                                                         //At last Memory Cleanup
    delete[] deposits;
    delete[] withdrawals;
    delete[] taxes;
    return 0;
} 
