
#include <iostream>
#include <stdlib.h>

#include "UserAccount.h"
#include "Transaction.h"
#include "FileHandler.h"

using namespace std;

int main() {
    int userCount = 0, accountCapacity = 50;
    UserAccount allUserAccounts[accountCapacity];
    Transaction *transactionHandler = new Transaction;
    FileHandler *fh = new FileHandler;

//    allUserAccounts = fh->loadDataFromFile(accountCapacity);

    int cont;
    int i;

    do {
        cout << endl;
        cout << "------- BANK ACCOUNTING SYSTEM -------\n\n" << endl;
        cout<<"\t1. Create new account"<<endl;
        cout<<"\t2. Deposit Money" << endl;
        cout<<"\t3. Withdraw Money" << endl;
        cout<<"\t4. Transfer Money" << endl;
        cout<<"\t5. View Account" << endl;
        cout<<"\t6. Update Account" << endl;
        cout<<"\t7. Delete Account" << endl;
        cout<<"\t8. View All Account Data." << endl;
        cout<<"\t9. Exit." << endl;
        cout<<"\n\nEnter your choice: ";
        cin >> cont;
        /*for(i=1;i<=9;i++)
        {
        if (cont==i)
        cont=1;
        else
        cont=0;
        }
        if (!cont)
            cout<<"Invalid Input";*/

        switch(cont) {
            case 1: {
                allUserAccounts[userCount].createUserAccount();
                fh->writeDataToFile(allUserAccounts[userCount]);
                userCount++;
            }
            break;
            case 2: {
                long accNo, amt;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter Amount to be deposited: ";
                cin >> amt;
                int acc_exists = 0;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        acc_exists = 1;
                        transactionHandler->depositMoney(allUserAccounts[i], amt);
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number" << endl;
                }
            }
            break;


           case 3: {
                long accNo, amt;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter Amount to be withdrawn: ";
                cin >> amt;
                int acc_exists = 0;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        acc_exists = 1;
                        transactionHandler->withdrawMoney(allUserAccounts[i], amt);
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number" << endl;
                }
            }
            break;
            case 4: {
                long senderNo, receiverNo, amt;
                cout << "Enter sender's account number: ";
                cin >> senderNo;
                cout << "Enter receiver's account number: ";
                cin >> receiverNo;
                cout << "Enter Amount to be withdrawn: ";
                cin >> amt;

                UserAccount *s, *r;
                int acc_exists = 0;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == senderNo) {
                        acc_exists = 1;
                        s = &allUserAccounts[i];
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number: " << senderNo << endl;
                }

                acc_exists = 0;
                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == receiverNo) {
                        acc_exists = 1;
                        r = &allUserAccounts[i];
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number: " << receiverNo << endl;
                }

                transactionHandler->transferMoney(*s, *r, amt);
            }
            break;

            case 5: {
                long int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                int acc_exists = 0;

                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        acc_exists = 1;
                        allUserAccounts[i].displayAccData();
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number" << endl;
                }
            }
            break;

            case 6: {
                long int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                int acc_exists = 0;

                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        acc_exists = 1;
                        allUserAccounts[i].updateUserAccount();
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number" << endl;
                }
            }
            break;

            case 7: {
                long int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                int acc_exists = 0;

                for(int i = 0; i < userCount; i++) {
                    if(allUserAccounts[i].getAccNo() == accNo) {
                        acc_exists = 1;
                        userCount--;
                        allUserAccounts[i].deleteAcc(allUserAccounts, i, userCount);
                        break;
                    }
                }
                if (acc_exists == 0)
                {
                    cout << "Invalid Account Number" << endl;
                }
            }
            break;
            case 8: {
                fh->viewAllDataFromFile();
            }
            break;

            default:
                cout << "\nExiting the Program." << endl;
                exit(0);
        }
    } while (1);

    delete allUserAccounts;
    delete transactionHandler;
    return 0;
}
