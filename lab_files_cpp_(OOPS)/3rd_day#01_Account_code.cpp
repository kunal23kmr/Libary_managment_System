/*
Write a class "ACCOUNT" that represent your bank account and then use it.
The class should allow you to deposit money,
withdraw money and send a message if you have insufficient balance.
*/

#include <iostream>
using namespace std;
class ACCOUTN
{
private:
    string name, accountNumber;
    int money = 0;

public:
    void input(string name, string accountNumber, int i)
    {
        this->name = name, this->accountNumber = accountNumber;
    }
    void deposit(int ammount, int i)
    {
        money += ammount;
        cout << ammount << " is depositd to account " << accountNumber << i << "." << endl;
    }
    void withdraw(int ammount, int i)
    {

        cout << "Withdrawing ammount... " << ammount << endl;
        if (ammount <= money)
            money -= ammount;
        else
            cout << "Sorrry :( Insufficient money in your account!!" << endl;
        cout << "Current ammount: " << money << endl;
    }
    void output(int i)
    {
        cout << "Name: " << this->name << endl;
        cout << "Account number: " << this->accountNumber << i << endl;
        cout << "Current Account Balance: " << this->money << endl;
    }
};
int main()
{
    int n, ammount;
    cout << "Enter the number of accounts: ";
    cin >> n;
    ACCOUTN p[n];
    string name, accNUM = "1000000000";
    for (int i = 0; i < n; i++)
    {
        ammount = 0;
        cout << "Input the name of person " << i + 1 << ": ";
        cin >> name;
        p[i].input(name, accNUM, i + 1);
        cout << "Enter the ammount to deposit: ";
        cin >> ammount;
        if (ammount < 0)
            return 0;
        p[i].deposit(ammount, i + 1);
        cout << "Enter the ammount to withdraw: ";
        cin >> ammount;
        if (ammount < 0)
            return 0;
        p[i].withdraw(ammount, i + 1);
        cout << endl;
    }
    cout << "Printing Account details..." << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Person " << i + 1 << endl;
        p[i].output(i + 1);
        cout << endl;
    }
    return 0;
}