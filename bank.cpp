/*
PROJECT - BANK MANAGEMENT SYSTEM
KEEPSAFE BANK
CODED BY - AKANKSHA KEJRIWAL
STARTED ON - 21st MAY 2022
ENDED ON - 29th MAY 2022
*/

//======================================================
//                  HEADER FILES
//======================================================
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void gotoxy(int, int);
void draw_box(int);
void draw_modify_box();

//======================================================
//                  ACCOUNT CLASS
//======================================================
class Account
{
    int accNo;
    char fname[11], lname[11];
    char phone[11];
    char email[30];
    char accType;
    int bal;

public:
    void input();
    void display();
    void display_tabular();
    void modify();
    int get_acno() { return accNo; }
    int get_bal() { return bal; }
    void deposit_amount(int amt) { bal += amt; }
    void withdraw_amount(int amt) { bal -= amt; }
};

void Account ::input()
{
    srand(time(0));
    accNo = rand() % 999990 + 10; // account range 10 - 999999

    gotoxy(33, 12);
    cout << "FIRST NAME : __________";
    gotoxy(33, 13);
    cout << "LAST NAME : __________";
    gotoxy(33, 14);
    cout << "MOBILE NUMBER : __________";
    gotoxy(33, 15);
    cout << "EMAIL ADDRESS : _________________________";
    gotoxy(33, 16);
    cout << "ACCOUNT TYPE [C/S] : _";
    gotoxy(33, 17);
    cout << "STARTING AMOUNT : __________";
    gotoxy(33, 18);
    cout << "ACCOUNT NUMBER : ______";

    gotoxy(46, 12);
    cin >> fname;
    gotoxy(45, 13);
    cin >> lname;
    gotoxy(49, 14);
    cin >> phone;
    gotoxy(49, 15);
    cin >> email;
    while (1)
    {
        gotoxy(54, 16);
        cout << "_\b";
        fflush(stdin);
        accType = cin.get();
        if (accType == 'c' || accType == 'C' || accType == 's' || accType == 'S')
        {
            if (accType == 'c' || accType == 's')
                accType -= 32;
            break;
        }
        gotoxy(31, 21);
        cout << "ACCOUNT TYPE CAN BE [C/S]. ENTER CORRECTLY!";
    }

    gotoxy(31, 21);
    cout << "  MINIMUM AMOUNT CAN BE : [C=500 / S=1000]  ";
    do
    {
        gotoxy(51, 17);
        cout << "___\b\b\b";
        cin >> bal;
    } while ((accType == 'C' && bal < 500) || (accType == 'S' && bal < 1000));

    gotoxy(31, 21);
    for (int i = 1; i <= 44; i++)
        cout << " ";
    gotoxy(43, 21);
    cout << "Opening Account...";
    gotoxy(31, 21);
    for (int j = 1; j <= 44; j++)
    {
        cout << char(178);
        Sleep(60);
    }

    gotoxy(50, 18);
    cout << accNo;
}

void Account ::display()
{
    // Display account details in form format
    draw_box(9);

    // Display title
    gotoxy(44, 9);
    cout << "ACCOUNT DETAILS";

    // Display details
    gotoxy(33, 12);
    cout << "ACCOUNT NUMBER : " << accNo;
    gotoxy(33, 13);
    cout << "FIRST NAME : " << fname;
    gotoxy(33, 14);
    cout << "LAST NAME : " << lname;
    gotoxy(33, 15);
    cout << "MOBILE NUMBER : " << phone;
    gotoxy(33, 16);
    cout << "EMAIL ADDRESS : " << email;
    gotoxy(33, 17);
    cout << "ACCOUNT TYPE : ";
    if (accType == 'C')
        cout << "Current";
    else
        cout << "Savings";
    gotoxy(33, 18);
    cout << "BALANCE : " << bal;

    gotoxy(36, 21);
    cout << "PRESS ENTER TO GO BACK TO MENU!!";
    getch();
}

void Account ::display_tabular()
{
    cout << setw(10) << accNo << "    ";
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(20) << strcat(strcat(fname, " "), lname) << "    ";
    cout << setw(28) << email << "    ";
    cout.setf(ios::right, ios::adjustfield);
    cout << setw(10) << phone << "    ";
    cout << setw(4) << accType << "    ";
    cout << setw(14) << bal << "    ";
}

void Account ::modify()
{
    draw_modify_box();

    gotoxy(42, 9);
    cout << "CURRENT DETAILS";

    // Display details
    gotoxy(33, 12);
    cout << "ACCOUNT NUMBER : " << accNo;
    gotoxy(33, 13);
    cout << "FIRST NAME : " << fname;
    gotoxy(33, 14);
    cout << "LAST NAME : " << lname;
    gotoxy(33, 15);
    cout << "MOBILE NUMBER : " << phone;
    gotoxy(33, 16);
    cout << "EMAIL : " << email;
    gotoxy(33, 17);
    cout << "ACCOUNT TYPE : ";
    if (accType == 'C')
        cout << "Current";
    else
        cout << "Savings";
    gotoxy(33, 18);
    cout << "BALANCE : " << bal;

    //============================================
    //============================================
    gotoxy(86, 9);
    cout << "NEW DETAILS";

    gotoxy(74, 12);
    cout << "ACCOUNT NUMBER : " << accNo;
    gotoxy(74, 13);
    cout << "FIRST NAME : __________";
    gotoxy(74, 14);
    cout << "LAST NAME : __________";
    gotoxy(74, 15);
    cout << "MOBILE NUMBER : __________";
    gotoxy(74, 16);
    cout << "EMAIL : _________________________";
    gotoxy(74, 17);
    cout << "ACCOUNT TYPE : ";
    if (accType == 'C')
        cout << "Current";
    else
        cout << "Savings";
    gotoxy(74, 18);
    cout << "BALANCE : " << bal;

    gotoxy(87, 13);
    cin >> fname;
    gotoxy(86, 14);
    cin >> lname;
    gotoxy(90, 15);
    cin >> phone;
    gotoxy(82, 16);
    cin >> email;

    gotoxy(31, 21);
    for (int i = 1; i <= 81; i++)
        cout << " ";
    gotoxy(56, 21);
    cout << "Modifying Account Details...";
    gotoxy(31, 21);
    for (int j = 1; j <= 81; j++)
    {
        cout << char(178);
        Sleep(60);
    }

    gotoxy(31, 21);
    for (int i = 1; i <= 81; i++)
        cout << " ";
    gotoxy(57, 21);
    cout << "ACCOUNT DETAILS MODIFIED!!";
    getch();
}

//==============================================================================
//                       FUNCTION FOR THE AXIS (GOTOXY)
//==============================================================================
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//==============================================================================
//                       DISPLAY LOADING SCREEN
//==============================================================================
void loading_screen()
{
    // First draw the basic layout of the box
    // Along with the bank info to be displayed
    draw_box(7);

    // Display bank info
    gotoxy(31, 9);
    cout << "          WELCOME TO KEEPSAFE BANK          ";
    gotoxy(31, 12);
    cout << " KEEPSAFE BANK WAS FOUNDED IN THE YEAR 1996 ";
    gotoxy(31, 13);
    cout << "  BY ALEXIS FORBES OF MYSTIC FALLS. WE ARE  ";
    gotoxy(31, 14);
    cout << "HERE TO ENSURE MAXIMUM SECURITY & CONVENIENT";
    gotoxy(31, 15);
    cout << "               TRANSACTIONS.                ";
    gotoxy(31, 16);
    cout << "         CONTACT : +91 99887 22534          ";

    // Now Loading animation
    for (int i = 1; i <= 3; i++)
    {
        gotoxy(44, 19);
        if (i == 1)
            cout << "Loading Server...";
        else if (i == 2)
            cout << "Checking Files...";
        else
            cout << "Loading System...";

        gotoxy(31, 19);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
        gotoxy(31, 19);
        for (int j = 1; j <= 44; j++)
            cout << " ";
    }
}

//==============================================================================
//                         DRAW A BOX FOR INFO
//==============================================================================
void draw_box(int n)
{
    // Draw a box with n lines of information
    system("cls");

    // Combining individual characters to draw box structures
    // Top border
    gotoxy(30, 8);
    cout << char(201);
    for (int i = 1; i <= 44; i++)
        cout << char(205);
    cout << char(187);

    // Title space
    gotoxy(30, 9);
    cout << char(186);
    for (int j = 1; j <= 44; j++)
        cout << " ";
    cout << char(186);

    // Line between title and info/menu
    gotoxy(30, 10);
    cout << char(204);
    for (int i = 1; i <= 44; i++)
        cout << char(205);
    cout << char(185);

    // Info/menu with n lines
    int i;
    for (i = 11; i < 11 + n; i++)
    {
        gotoxy(30, i);
        cout << char(186);
        for (int j = 1; j <= 44; j++)
            cout << " ";
        cout << char(186);
    }

    // line between info and prompt
    gotoxy(30, i++);
    cout << char(204);
    for (int i = 1; i <= 44; i++)
        cout << char(205);
    cout << char(185);

    // User Prompt
    gotoxy(30, i++);
    cout << char(186);
    for (int j = 1; j <= 44; j++)
        cout << " ";
    cout << char(186);

    // Bottom border
    gotoxy(30, i);
    cout << char(200);
    for (int i = 1; i <= 44; i++)
        cout << char(205);
    cout << char(188);
}

//==============================================================================
//                            LOGIN FUNCTION
//==============================================================================
void login()
{
    // The user can be an administrator or an account holder
    int ch;

    do
    {
        // Menu has 3 options so drawing box with 5 lines of info
        draw_box(5);

        // Display login menu
        gotoxy(49, 9);
        cout << " LOGIN ";
        gotoxy(33, 12);
        cout << "[1] ADMINISTRATOR";
        gotoxy(33, 13);
        cout << "[2] ACCOUNT HOLDER";
        gotoxy(33, 14);
        cout << "[3] EXIT";

        // Enter user's choice
        gotoxy(41, 17);
        cout << "YOUR CHOICE [1-3] ? ";
        cin >> ch;

        // clear prompt bar
        gotoxy(31, 17);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        if (ch >= 1 && ch <= 3)
        {
            // Display loading
            gotoxy(47, 17);
            cout << "Loading...";
            gotoxy(31, 17);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }

        switch (ch)
        {
        case 1:
            admin_login();
            break;

        case 2:
            account_holder_login();
            break;

        case 3:
            return;

        default:
            gotoxy(31, 20);
            cout << "INVALID INPUT!! ENTER A VALUE IN RANGE [1-3]";
            getch();
        }
    } while (1);
}

//==============================================================================
//                             ADMIN LOGIN FUNCTION
//==============================================================================
void admin_login()
{
    // Accept username and password from user
    // Then check if user entered correctly
    draw_box(4);
    gotoxy(41, 9);
    cout << "ADMINISTRATOR LOGIN";
    gotoxy(35, 12);
    cout << "USERNAME : ________";
    gotoxy(35, 13);
    cout << "PASSWORD : ________";
    gotoxy(39, 16);
    cout << "ENTER USERNAME AND PASSWORD!";

    string usn;
    char p[10] = {0}, pass[10] = "swift";
    gotoxy(46, 12);
    cin >> usn;
    gotoxy(46, 13);
    char c;

    // password replaced with asterisk
    for (int i = 0; i >= 0;)
    {
        c = getch();
        if (c <= 126 && c >= 32)
        {
            cout << "*";
            p[i] = c;
            i++;
        }
        else if (c == 8)
        {
            cout << "\b \b";
            i--;
        }
        else if (c == 13)
        {
            // p[i] = '\0';
            break;
        }
    }

    // clear prompt bar
    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    // Display new message
    // If username and password are correct load admin menu
    if (usn == "taylor" && strcmp(p, "swift") == 0)
    {
        gotoxy(44, 16);
        cout << "Loading Menu...";
        gotoxy(31, 16);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
        admin_menu();
    }

    // If incorrect username or password ask if user wants to enter again
    else
    {
        gotoxy(42, 16);
        if (usn != "taylor")
            cout << "INCORRECT USERNAME!!";
        else
            cout << "INCORRECT PASSWORD!!";
        getch();
        gotoxy(36, 16);
        cout << "DO YOU WANT TO TRY AGAIN ? [y/n] ";
        fflush(stdin);
        c = cin.get();
        if (c == 'y' || c == 'Y')
            admin_login();
        else
        {
            gotoxy(31, 16);
            for (int i = 1; i <= 44; i++)
                cout << " ";
            gotoxy(45, 16);
            cout << "Going Back...";
            gotoxy(31, 16);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }
    }
}

//==============================================================================
//                          ADMIN MENU FUNCTION
//==============================================================================
void admin_menu()
{
    // An admin can perform following operations:
    // opening an account , closing an account , checking a list of all accounts
    // checking a specific account , modifying an account and log out
    int ch;

    do
    {
        draw_box(8);
        gotoxy(44, 9);
        cout << "ADMINISTRATOR MENU";
        gotoxy(33, 12);
        cout << "[1] OPEN AN ACCOUNT";
        gotoxy(33, 13);
        cout << "[2] CHECK A SPECIFIC ACCOUNT";
        gotoxy(33, 14);
        cout << "[3] LIST ALL ACCOUNTS";
        gotoxy(33, 15);
        cout << "[4] MODIFY AN ACCOUNT";
        gotoxy(33, 16);
        cout << "[5] CLOSE AN ACCOUNT";
        gotoxy(33, 17);
        cout << "[6] LOG OUT";
        gotoxy(41, 20);
        cout << "YOUR CHOICE [1-6] ? ";
        cin >> ch;

        // clear prompt bar
        gotoxy(31, 20);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        if (ch >= 1 && ch <= 6)
        {
            // Display loading
            gotoxy(47, 20);
            cout << "Loading...";
            gotoxy(31, 20);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }

        switch (ch)
        {
        case 1:
            open_acc();
            break;

        case 2:
            check_acc();
            break;

        case 3:
            list_all_acc();
            break;

        case 4:
            modify_acc();
            break;

        case 5:
            close_acc();
            break;

        case 6:
            return;

        default:
            gotoxy(31, 20);
            cout << "INVALID INPUT!! ENTER A VALUE IN RANGE [1-6]";
            getch();
        }
    } while (1);
}

//==============================================================================
//                          ADD A NEW ACCOUNT FUNCTION
//==============================================================================
void open_acc()
{
    // First draw a box and input account information for new account
    draw_box(9);

    // Display title and prompt
    gotoxy(42, 9);
    cout << "OPEN AN ACCOUNT";
    gotoxy(41, 21);
    cout << "ENTER THE DETAILS";

    // Create an account object and call input function
    Account ac;
    ac.input();

    // Write the account details on file
    fstream file;
    file.open("AccountList.dat", ios::app | ios::binary);
    file.write((char *)&ac, sizeof(ac));
    file.close();

    // Display message
    gotoxy(31, 21);
    cout << "       ACCOUNT OPENED SUCCESSFULLY!!        ";
    getch();

    gotoxy(31, 21);
    for (int i = 1; i <= 44; i++)
        cout << " ";
    gotoxy(45, 21);
    cout << "Back To Menu...";
    gotoxy(31, 21);
    for (int j = 1; j <= 44; j++)
    {
        cout << char(178);
        Sleep(60);
    }
}

//==============================================================================
//                          CHECK A SPECIFIC ACCOUNT
//==============================================================================
void check_acc()
{
    draw_box(3);
    gotoxy(41, 9);
    cout << "CHECK ACCOUNT DETAILS";
    gotoxy(35, 12);
    cout << "ACCOUNT NUMBER : ";
    gotoxy(41, 15);
    cout << "ENTER ACCOUNT NUMBER!";

    int acno;
    gotoxy(52, 12);
    cin >> acno;

    // Check account number in file
    // Open file
    ifstream inf;
    Account ac;
    int f = 0;
    inf.open("AccountList.dat", ios::binary);
    while (inf.read((char *)&ac, sizeof(ac)))
        if (ac.get_acno() == acno)
        {
            f = 1;
            break;
        }
    inf.close();

    // clear prompt bar
    gotoxy(31, 15);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    // Display new message
    // If account exists display account details
    if (f)
    {
        gotoxy(42, 15);
        cout << "Fetching Details...";
        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
        ac.display();
    }

    // If account does not exist
    else
    {
        gotoxy(40, 15);
        cout << "ACCOUNT DOES NOT EXIST!!";
        getch();
        gotoxy(36, 15);
        cout << "DO YOU WANT TO TRY AGAIN ? [y/n] ";
        char c;
        fflush(stdin);
        c = cin.get();
        if (c == 'y' || c == 'Y')
            check_acc();
        else
        {
            gotoxy(31, 15);
            for (int i = 1; i <= 44; i++)
                cout << " ";
            gotoxy(45, 15);
            cout << "Going Back...";
            gotoxy(31, 15);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }
    }
}

//==============================================================================
//                          LIST ALL ACCOUNTS FUNCTION
//==============================================================================
void list_all_acc()
{
    system("cls");
    // title at top
    // Top border
    gotoxy(65, 6);
    cout << char(201);
    for (int i = 1; i <= 22; i++)
        cout << char(205);
    cout << char(187);

    // Title
    gotoxy(65, 7);
    cout << char(186);
    cout << " LIST OF ALL ACCOUNTS ";
    cout << char(186);

    // Bottom border
    gotoxy(65, 8);
    cout << char(200);
    for (int i = 1; i <= 22; i++)
        cout << char(205);
    cout << char(188);

    // Double line border for data
    // Top border
    gotoxy(20, 10);
    cout << char(201);
    for (int i = 1; i <= 110; i++)
        cout << char(205);
    cout << char(187);

    // Info line
    gotoxy(20, 11);
    cout << char(186);
    cout << setw(10) << "AC/NO";
    cout << setw(16) << "NAME";
    cout << setw(28) << "EMAIL";
    cout << setw(26) << "MOBILE NO.";
    cout << setw(12) << "ACC. TYPE";
    cout << setw(18) << "BALANCE    ";
    cout << char(186);

    // line between info and details
    gotoxy(20, 12);
    cout << char(186) << "  ";
    for (int i = 1; i <= 106; i++)
        cout << char(196);
    cout << "  " << char(186);

    // Open file to read
    ifstream inf("AccountList.dat");
    // Create account object
    Account ac;

    if (!inf)
    {
        cout << "ERROR IN OPENING FILE!!";
        return;
    }

    // display all account details
    int line = 13;
    while (inf.read((char *)&ac, sizeof(ac)))
    {
        gotoxy(20, line);
        cout << char(186);
        ac.display_tabular();
        cout << char(186);
        line++;
    }

    // close file
    inf.close();

    // bottom border
    gotoxy(20, line);
    cout << char(200);
    for (int i = 1; i <= 110; i++)
        cout << char(205);
    cout << char(188);

    line += 2;
    // prompt at bottom
    // Top border
    gotoxy(61, line);
    cout << char(201);
    for (int i = 1; i <= 30; i++)
        cout << char(205);
    cout << char(187);
    line++;

    // Message
    gotoxy(61, line);
    cout << char(186);
    cout << " PRESS ANY KEY TO CONTINUE :  ";
    cout << char(186);
    line++;

    // Bottom border
    gotoxy(61, line);
    cout << char(200);
    for (int i = 1; i <= 30; i++)
        cout << char(205);
    cout << char(188);
    line--;

    gotoxy(90, line);
    getch();
}

//==============================================================================
//                           MODIFY ACCOUNT FUNCTION
//==============================================================================
void modify_acc()
{
    // Enter account number from user
    draw_box(3);
    gotoxy(41, 9);
    cout << "CHECK ACCOUNT DETAILS";
    gotoxy(35, 12);
    cout << "ACCOUNT NUMBER : ";
    gotoxy(41, 15);
    cout << "ENTER ACCOUNT NUMBER!";

    int acno;
    gotoxy(52, 12);
    cin >> acno;

    // clear prompt bar
    gotoxy(31, 15);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    // Check account number in file
    // Open file
    // D:\Projects\Bank_Management_System
    fstream file;
    file.open("AccountList.dat", ios::ate | ios::binary | ios::in | ios::out);

    if (!file)
    {
        gotoxy(40, 15);
        cout << "ERROR IN OPENING FILE !!";
        getch();
        return;
    }

    file.seekg(0);
    Account ac;
    int f = 0;

    while (file.read((char *)&ac, sizeof(ac)))
        if (ac.get_acno() == acno)
        {
            gotoxy(42, 15);
            cout << "Fetching Details...";
            gotoxy(31, 15);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
            ac.modify();

            int loc = file.tellg();
            file.seekp(loc - sizeof(ac));
            file.write((char *)&ac, sizeof(ac));
            f = 1;
            break;
        }

    file.close();
    if (f)
        return;

    // If account does not exist
    gotoxy(40, 15);
    cout << "ACCOUNT DOES NOT EXIST!!";
    getch();
    gotoxy(36, 15);
    cout << "DO YOU WANT TO TRY AGAIN ? [y/n] ";
    char c;
    fflush(stdin);
    c = cin.get();
    if (c == 'y' || c == 'Y')
        modify_acc();
    else
    {
        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";
        gotoxy(45, 15);
        cout << "Going Back...";
        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
    }
}

void draw_modify_box()
{
    system("cls");

    // Top border
    gotoxy(30, 8);
    cout << char(201);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(203);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(187);

    // Title space
    gotoxy(30, 9);
    cout << char(186);
    for (int j = 1; j <= 40; j++)
        cout << " ";
    cout << char(186);
    for (int j = 1; j <= 40; j++)
        cout << " ";
    cout << char(186);

    // Line between title and info/menu
    gotoxy(30, 10);
    cout << char(204);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(206);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(185);

    // Info/menu
    for (int i = 11; i <= 19; i++)
    {
        gotoxy(30, i);
        cout << char(186);
        for (int j = 1; j <= 40; j++)
            cout << " ";
        cout << char(186);
        for (int j = 1; j <= 40; j++)
            cout << " ";
        cout << char(186);
    }

    // line between info and prompt
    gotoxy(30, 20);
    cout << char(204);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(202);
    for (int i = 1; i <= 40; i++)
        cout << char(205);
    cout << char(185);

    // User Prompt
    gotoxy(30, 21);
    cout << char(186);
    for (int j = 1; j <= 81; j++)
        cout << " ";
    cout << char(186);

    // Bottom border
    gotoxy(30, 22);
    cout << char(200);
    for (int i = 1; i <= 81; i++)
        cout << char(205);
    cout << char(188);
}

//==============================================================================
//                          CLOSE ACCOUNT FUNCTION
//==============================================================================
void close_acc()
{
    // Enter account number from user
    draw_box(3);
    gotoxy(41, 9);
    cout << "CHECK ACCOUNT DETAILS";
    gotoxy(35, 12);
    cout << "ACCOUNT NUMBER : ";
    gotoxy(41, 15);
    cout << "ENTER ACCOUNT NUMBER!";

    int acno;
    gotoxy(52, 12);
    cin >> acno;

    // clear prompt bar
    gotoxy(31, 15);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    // Copy all accounts except account with account number "acno" in a temporary file
    ifstream inf;
    ofstream outf;
    inf.open("AccountList.dat", ios::binary);

    if (!inf)
    {
        gotoxy(40, 15);
        cout << "ERROR IN OPENING FILE !!";
        getch();
        return;
    }

    outf.open("temp.dat", ios::binary);
    Account ac;
    int f = 0;
    char c;

    while (inf.read((char *)&ac, sizeof(ac)))
    {
        if (ac.get_acno() != acno)
            outf.write((char *)&ac, sizeof(ac));
        else
        {
            // If account find confirm from user
            gotoxy(31, 15);
            cout << "DO YOU WANT TO CLOSE AC/NO " << acno << " ? [y/n] ";
            fflush(stdin);
            c = cin.get();
            if (c != 'y' && c != 'Y')
            {
                f = 2;
                break;
            }

            f = 1; // If user wants to delete account
        }
    }

    inf.close();
    outf.close();

    if (f == 2) // account found but user does not want to delete
    {
        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        gotoxy(42, 15);
        cout << "ACCOUNT NOT CLOSED!!";
        getch();

        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        gotoxy(45, 15);
        cout << "Back To Menu...";
        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }

        return;
    }

    if (f == 1) // Delete the account
    {
        // rename("temp.dat", "AccountList.dat");
        inf.open("temp.dat", ios::binary);

        if (!inf)
        {
            gotoxy(40, 15);
            cout << "ERROR IN OPENING FILE !!";
            getch();
            return;
        }

        outf.open("AccountList.dat", ios::binary);
        Account ac;
        int f = 0;
        char c;

        while (inf.read((char *)&ac, sizeof(ac)))
            outf.write((char *)&ac, sizeof(ac));

        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        gotoxy(43, 15);
        cout << "Closing Account...";

        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }

        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
            cout << " ";

        gotoxy(38, 15);
        cout << "ACCOUNT SUCCESSFULLY CLOSED!";
        getch();
        return;
    }

    // If account does not exist
    gotoxy(40, 15);
    cout << "ACCOUNT DOES NOT EXIST!!";
    getch();
    gotoxy(36, 15);
    cout << "DO YOU WANT TO TRY AGAIN ? [y/n] ";
    fflush(stdin);
    c = cin.get();
    if (c == 'y' || c == 'Y')
        close_acc();
    else
    {
        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";
        gotoxy(45, 15);
        cout << "Back To Menu...";
        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
    }
}

//==============================================================================
//                          ACCOUNT HOLDER LOGIN FUNCTION
//==============================================================================
void account_holder_login()
{
    draw_box(3);
    gotoxy(42, 9);
    cout << "ACCOUNT HOLDER LOGIN";
    gotoxy(35, 12);
    cout << "ACCOUNT NUMBER : ";
    gotoxy(41, 15);
    cout << "ENTER ACCOUNT NUMBER!";

    int acno;
    gotoxy(52, 12);
    cin >> acno;

    // Check account number in file
    // Open file
    ifstream inf;
    Account ac;
    int f = 0;
    inf.open("AccountList.dat" , ios::binary);
    while (inf.read((char *)&ac, sizeof(ac)))
        if (ac.get_acno() == acno)
        {
            f = 1;
            break;
        }
    inf.close();

    // clear prompt bar
    gotoxy(31, 15);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    // Display new message
    // If account exists load account holder menu
    if (f)
    {
        gotoxy(44, 15);
        cout << "Loading Menu...";
        gotoxy(31, 15);
        for (int j = 1; j <= 44; j++)
        {
            cout << char(178);
            Sleep(60);
        }
        account_holder_menu(ac);
    }

    // If account does not exist
    else
    {
        gotoxy(40, 15);
        cout << "ACCOUNT DOES NOT EXIST!!";
        getch();
        gotoxy(36, 15);
        cout << "DO YOU WANT TO TRY AGAIN ? [y/n] ";
        char c;
        fflush(stdin);
        c = cin.get();
        if (c == 'y' || c == 'Y')
            account_holder_login();
        else
        {
            gotoxy(31, 15);
            for (int i = 1; i <= 44; i++)
                cout << " ";
            gotoxy(45, 15);
            cout << "Going Back...";
            gotoxy(31, 15);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }
    }
}

//==============================================================================
//                          ACCOUNT HOLDER MENU FUNCTION
//==============================================================================
void account_holder_menu(Account &ac)
{
    // An account holder can perform following operations:
    // Checking account status , Deposit , withdraw , transfer , logout
    int ch;

    do
    {
        draw_box(7);
        gotoxy(42, 9);
        cout << "ACCOUNT HOLDER MENU";
        gotoxy(33, 12);
        cout << "[1] CHECK ACCOUNT DETAILS";
        gotoxy(33, 13);
        cout << "[2] DEPOSIT AMOUNT";
        gotoxy(33, 14);
        cout << "[3] WITHDRAW AMOUNT";
        gotoxy(33, 15);
        cout << "[4] TRANSFER AMOUNT";
        gotoxy(33, 16);
        cout << "[5] LOG OUT";
        gotoxy(41, 19);
        cout << "YOUR CHOICE [1-5] ? ";
        cin >> ch;

        // clear prompt bar
        gotoxy(31, 19);
        for (int i = 1; i <= 44; i++)
            cout << " ";

        if (ch <= 1 && ch >= 5)
        {
            // Display loading
            gotoxy(47, 19);
            cout << "Loading...";
            gotoxy(31, 19);
            for (int j = 1; j <= 44; j++)
            {
                cout << char(178);
                Sleep(60);
            }
        }

        switch (ch)
        {
        case 1:
            ac.display();
            break;

        case 2:
            deposit(ac);
            break;

        case 3: withdraw(ac);
            break;

        case 4: transfer(ac);
            break;

        case 5:
            return;

        default:
            gotoxy(31, 19);
            cout << "INVALID INPUT!! ENTER A VALUE IN RANGE [1-5]";
            getch();
            break;
        }
    } while (1);
}

void deposit(Account &ac)
{
    draw_box(4);

    int amt;
    gotoxy(45, 9);
    cout << "ACCOUNT " << ac.get_acno();
    gotoxy(35, 12);
    cout << "CURRENT BALANCE : " << ac.get_bal();
    gotoxy(35, 13);
    cout << "AMOUNT : ______________";
    gotoxy(40, 16);
    cout << "ENTER AMOUNT TO DEPOSIT!";
    gotoxy(44, 13);
    cin >> amt;

    ac.deposit_amount(amt);

    // Update on file
    fstream file;
    Account ac1;
    file.open("AccountList.dat", ios::ate | ios::out | ios::in | ios::binary);
    file.seekg(0);
    while (file.read((char *)&ac1, sizeof(ac1)))
        if (ac1.get_acno() == ac.get_acno())
        {
            int x = file.tellg();
            x -= sizeof(ac);
            file.seekp(x);
            file.write((char *)&ac, sizeof(ac));
            break;
        }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy(45, 16);
    cout << "Processing ...";

    gotoxy(31, 16);
    for (int j = 1; j <= 44; j++)
    {
        cout << char(178);
        Sleep(60);
    }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy (36 , 16);
    cout << "AMOUNT DEPOSITED SUCCESSFULLY!";
    getch();
}

void withdraw(Account &ac)
{
    draw_box(4);

    int amt;
    gotoxy(45, 9);
    cout << "ACCOUNT " << ac.get_acno();
    gotoxy(35, 12);
    cout << "CURRENT BALANCE : " << ac.get_bal();
    gotoxy(35, 13);
    cout << "AMOUNT : ______________";
    gotoxy(40, 16);
    cout << "ENTER AMOUNT TO WITHDRAW!";
    gotoxy(44, 13);
    cin >> amt;

    if (amt > ac.get_bal())
    {
        gotoxy (31 , 16);
        for (int i=1 ; i<=44 ; i++)
            cout << " ";
        gotoxy (42 , 16);
        cout << "NOT ENOUGH BALANCE!!";
        getch();
        return;
    }

    ac.withdraw_amount(amt);

    // Update on file
    fstream file;
    Account ac1;
    file.open("AccountList.dat", ios::ate|ios::out|ios::in|ios::binary);
    file.seekg(0);
    while (file.read((char *)&ac1, sizeof(ac1)))
        if (ac1.get_acno() == ac.get_acno())
        {
            int x = file.tellg();
            x -= sizeof(ac);
            file.seekp(x);
            file.write((char *)&ac, sizeof(ac));
            break;
        }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy(45, 16);
    cout << "Processing ...";

    gotoxy(31, 16);
    for (int j = 1; j <= 44; j++)
    {
        cout << char(178);
        Sleep(60);
    }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy (36 , 16);
    cout << "AMOUNT WITHDRAWN SUCCESSFULLY!";
    getch();

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy (39 , 16);
    cout << "PLEASE COLLECT YOUR CASH!";
    getch();
}

void transfer(Account &ac)
{
    //get reciever's account
    draw_box(3);

    int acno;
    gotoxy(45, 9);
    cout << "ACCOUNT " << ac.get_acno();
    gotoxy(35, 12);
    cout << "ACCOUNT NUMBER : ______";
    gotoxy(37, 15);
    cout << "ENTER RECIEVER'S ACCOUNT NUMER";
    gotoxy(52, 12);
    cin >> acno;
    
    // Check account number in file
    // Open file
    ifstream inf;
    Account ac1;
    int f = 0;
    inf.open("AccountList.dat" , ios::binary);
    while (inf.read((char *)&ac1, sizeof(ac1)))
        if (ac1.get_acno() == acno)
        {
            f = 1;
            break;
        }
    inf.close();

    //If reciever's account number not found
    if (!f)
    {
        gotoxy(31, 15);
        for (int i = 1; i <= 44; i++)
            cout << " ";
        gotoxy(39, 15);
        cout << "ACCOUNT " << acno << " NOT FOUND!!";
        getch();
        return;
    }    

    draw_box(4);

    int amt;
    gotoxy(45, 9);
    cout << "ACCOUNT " << ac.get_acno();
    gotoxy(35, 12);
    cout << "CURRENT BALANCE : " << ac.get_bal();
    gotoxy(35, 13);
    cout << "AMOUNT : ______________";
    gotoxy(40, 16);
    cout << "ENTER AMOUNT TO TRANSFER!";
    gotoxy(44, 13);
    cin >> amt;

    if (amt > ac.get_bal())
    {
        gotoxy (31 , 16);
        for (int i=1 ; i<=44 ; i++)
            cout << " ";
        gotoxy (42 , 16);
        cout << "NOT ENOUGH BALANCE!!";
        getch();
        return;
    }

    ac.withdraw_amount(amt);
    ac1.deposit_amount(amt);

    // Update on file
    fstream file;
    Account ac2;
    file.open("AccountList.dat", ios::ate|ios::out|ios::in|ios::binary);
    file.seekg(0);
    while (file.read((char *)&ac2, sizeof(ac2)))
        if (ac2.get_acno() == ac.get_acno())
        {
            int x = file.tellg();
            x -= sizeof(ac);
            file.seekp(x);
            file.write((char *)&ac, sizeof(ac));
        }
        else if (ac1.get_acno() == ac2.get_acno())
        {
            int x = file.tellg();
            x -= sizeof(ac1);
            file.seekp(x);
            file.write((char *)&ac1, sizeof(ac1));
        }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy(45, 16);
    cout << "Processing ...";

    gotoxy(31, 16);
    for (int j = 1; j <= 44; j++)
    {
        cout << char(178);
        Sleep(60);
    }

    gotoxy(31, 16);
    for (int i = 1; i <= 44; i++)
        cout << " ";

    gotoxy (38 , 16);
    cout << "AMOUNT TRANSFER SUCCESSFUL!!";
    getch();
}

void exit()
{
    draw_box(3);

    gotoxy (45 , 9);
    cout << "KEEPSAFE BANK";

    gotoxy (37 , 12);
    cout << "THANK YOU FOR BANKING WITH US!";

    gotoxy (47 , 15);
    cout << "Exiting...";

    gotoxy (31 , 15);
    for (int i=1 ; i<=44 ; i++)
    {
        cout << char(178);
        Sleep(60);
    }

    cout << "\n\n\n\n";
}


//========================================================
//                   MAIN FUNCTION
//========================================================
main()
{
    system("color 09");
    // Display the loading screen
    loading_screen();
    // Login as administrator or bank account holder
    login();
    // Exit function
    exit();

    return 0;
}
