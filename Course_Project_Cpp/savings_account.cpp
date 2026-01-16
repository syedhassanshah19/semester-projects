#include <iostream>
#include <iomanip>
using namespace std;

void getInputs(double &annualTaxRate, double &balance, int &months)
{
    cout << "Enter annual tax deduction rate (in %): ";
    cin >> annualTaxRate;

    cout << "Enter initial account balance: ";
    cin >> balance;

    cout << "Enter total number of months: ";
    cin >> months;
}

void processMonths(int months, double monthlyTaxRate, double &balance,
    double deposits[], double withdrawals[], double taxes[],
    double &totalDeposits, double &totalWithdrawals, double &totalTaxes)
{
    for (int i = 0; i < months; i++)
{
    cout << "\n--- Month " << i + 1 << " ---\n";

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

    taxes[i] = balance * monthlyTaxRate;
    balance -= taxes[i];
    totalTaxes += taxes[i];
}
}

void displaySummary(double balance, double totalDeposits, double totalWithdrawals, double totalTaxes)
{
    cout << fixed << setprecision(2);
    cout << "\n====================================\n";
    cout << " Savings Account Summary Report\n";
    cout << "====================================\n";
    cout << "Final Account Balance: Rs. " << balance << endl;
    cout << "Total Deposited:       Rs. " << totalDeposits << endl;
    cout << "Total Withdrawn:       Rs. " << totalWithdrawals << endl;
    cout << "Total Tax Deducted:    Rs. " << totalTaxes << endl;
}

int main()
{
    int months;
    double annualTaxRate, balance;

    getInputs(annualTaxRate, balance, months);

    double monthlyTaxRate = (annualTaxRate / 100) / 12;

    double* deposits = new double[months];
    double* withdrawals = new double[months];
    double* taxes = new double[months];

    double totalDeposits = 0.0;
    double totalWithdrawals = 0.0;
    double totalTaxes = 0.0;

    processMonths(months, monthlyTaxRate, balance, deposits, withdrawals, taxes, totalDeposits, totalWithdrawals, totalTaxes);

    displaySummary(balance, totalDeposits, totalWithdrawals, totalTaxes);

    delete[] deposits;
    delete[] withdrawals;
    delete[] taxes;

    return 0;
}
