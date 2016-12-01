ACCOUNT MANAGEMENT SYSTEM
ABSTRACT:
The Account Management System consists of a Stock Portfolio Account and a Bank Account. The
Stock Portfolio Account deals with buying shares, selling shares, viewing current share value,
sorting the available share values, viewing a graph of total portfolio, viewing transaction history
and viewing current portfolio. The Bank Account deals with viewing available balance,
withdrawing and depositing cash in the account. The actions performed in either of these accounts
should reflect the change in Cash Balance.

DESCRIPTION:
This project is done using an abstract base class ACCOUNT and two derived classes StockAccount
and BankAccount. The objects of both the derived classes are declared in main as stockaccount
and bankaccount which are used to carry on the operations. A detailed description of every function
and file is explained below:

main():
The main() function had a nested switch structure in order to accept user’s choice and to switch
between Stock Portfolio Account and Bank Account. To redisplay the menu, goto statements are
used by labeling the start of each menu. The variables in this function accepts any kind of input
and uses the functions of derived classes to operate. While the main function is terminated, all the
information is prompted to store in various files for future correspondence.
FILES USED:
The following files are used in this project:
i. BankAccount_Info.txt:
This file is used to store the cash balance, total portfolio value, time and date whenever the
user exits the program.
ii. Bank_transaction_history.txt:
This file is used to record the transactions of BankAccount upon withdrawal and deposit
in order to print out the transaction history. Whenever stocks are bought or sold in the
StockAccount, those actions are stored in it as cash withdrawal and deposit along with the
time and date of action.
iii. StockAccount_Info.txt:
This file is used to record the number of shares available in the StockAccount. This file is
updated whenever the user quits the program and is used to initialize the stock values upon
restarting.iv. stock_transaction_history.txt:
This file is used to store the actions of buying and selling the shares in order to print out
the history. This file is updated when a user is willing to buy or sell shares.

ACCOUNT:
This project consists of an abstract base class known as ACCOUNT which is used to initialize the
variable CASH_BALANCE whenever a program is started. Various functions used in it are:
I. ACCOUNT():
This function acts as constructor of the abstract base class ACCOUNT. The constructor initializes
the CASH_BALANCE when a program starts by reading the contents of “BankAccount_Info.txt”
file. If there is no such file it initializes CASH_BALANCE to $10,000.
II. virtual void set_cashbalance(double) = 0:
A base class is said to be an abstract class if it has at least one pure virtual function. To make the
base class ACCOUNT an abstract class this virtual function is used and is updated in derived
classes.
III. double get_cashbalance():
This function is used to return the value of variable CASH_BALANCE of type double.
IV. string get_time():
This function is used to return the current time of the system in the form of string.
V. string get_date():
This function is used to return the current date of the system in the form of string.

BankAccount:
This is a derived class of the base class ACCOUNT which inherits the public data members of
base class. This class has the following public member functions:
I. void get_balance():
This function is used to display the current cash balance available in the account.
II. void set_cashbalance(double):
This function is used to update the variable CASH_BALANCE. It has the argument of type double
which is equivalent to the updated cash balance.III. double deposit_money():
This function is used to deposit amount into the account. This function prompts the user to enter
an amount which is accepted through a variable of type double and returns this amount to the main
so as to update the cash balance of stock account. It saves this action into a file
“Bank_transaction_history.txt” for printing the history.
IV. double withdraw_money():
This function is used to withdraw amount from the account. It prompts the user to input an amount
for withdrawing. If the amount user is willing to display is greater than the available cash balance,
it displays an error message. It returns the amount of type double so as to update the cash balance
of stock account. It saves this action into a file “Bank_transaction_history.txt” for printing the
history.
V. void printout_history():
This function reads the data from the file “Bank_transaction_history.txt” and displays the
information. It is used to display the history of transactions. The file here is used in “append” mode
so that each and every transaction is appended to the previous information.
VI. void save_bank_info():
This function is used to save the available cash balance in “BankAccount_Info.txt” file so that
whenever the program is restarted, it uses the updated cash balance. The file here is used in “out”
mode so that previous contents are replaced by updated contents.

StockAccount:
The StockAccount is maintained by a data structure of doubly linked list type. An object of the
class DoublyLinkedList known as doublylinkedlist is created and the stocks are managed through
it. The StockAccount uses the following public member functions:
I. StockAccount():
This function serves as a constructor for StockAccount so that it updates the linked list whenever
a program is started from the file “StockAccount_Info.txt”. If no such file is present no action is
taken.
II. void price_of_stock():
This function display the current price of a stock symbol entered. This function randomly chooses
a file from “Results1.txt” and “Results2.txt” and searches for the symbol to display the current
stock price by prompting the user to enter a symbol. If the symbol entered is not found, it displays
a message that the symbol is not found.III. void current_portfolio():
This function is used to display the current stock shares available in the account. It is done by
calling the function print() of DoublyLinkedList. It displays the available stock along with the
number of stocks available, price per share and total value. Apart from this it also displays the
current cash balance and total portfolio value.
IV. double Buy_shares():
This function allows the user to buy share by randomly choosing the stock value from the two
result files provided. It prompts the user to enter the symbol of the stock, the number of shares the
user is willing to buy and the maximum amount the user is willing to spend per share. It calls a
function insert() of DoublyLinkedList and performs the operations over there. It returns a value of
type double which is the value of number of shares multiplied by the stock value in order to update
the cash balance in bank account. It saves this action into a file “Stock_transaction_history.txt” for
printing the history.
V. double Sell_shares():
This function allows the user to sell share by randomly choosing the stock value from the two
result files provided. It prompts the user to enter the symbol of the stock, the number of shares the
user is willing to sell and the minimum amount the user is willing to sell per share. It calls a
function remove() of DoublyLinkedList and performs the operations over there. It returns a value
of type double which is the value of number of shares multiplied by the stock value in order to
update the cash balance in bank account. It saves this action into a file
“Stock_transaction_history.txt” for printing the history.
VI. void view_a_graph():
This function is used to plot the values of total portfolio which are saved in
“BankAccount_Info.txt” while exiting the program. It reads the total portfolio values from this file
and stores in an array of C++. The values of this array are copied to the values of array of
MATLAB through the function known as memcpy(). The MATLAB is then opened using a pointer
which is pointed to the Engine and the values are then plotted. The standard MatLab directories
libmx.lib, libmex.lib, libmat.lib, etc. are used in this function.
VII. void view_transaction_history():
This function is used to display the transaction history of the stock account. This function reads
the data from “stock_transaction_history.txt” file and displays the data. The files here are used in
“out” mode.
VIII. void sort_stock_list():
This function calls the sortlist() function of DoublyLinkedList in order to sort the nodes according
to their highest total value.IX. void save_stock_info():
This function calls the save() function of DoublyLinkedList in order to save the stock account
information so that the data can be used when the program is executed next time. The information
is stored in “StockAccount_Info.txt” file when the program exits.
X. void save_totalportfoliovalue():
This function calls the saveportfolio(double) of DoublyLinkedList in order to save the total
portfolio value in “BankAccount_Info.txt” file when the program exits. It passes an argument of
type double which is equivalent to cash balance value in order to save the total portfolio value.

Node:
The name and the number of stocks of each symbol are stored in doubly linked list data structure.
In order to use this doubly linked list structure, a class ‘Node’ was defined which has the data
members ‘stocksymbol’ to store the symbol of stock and ‘numofshares’ in order to store the
number of shares of the stock. It also declares two pointers known as ‘forward’ and ‘backward’
which are used for traversing the doubly linked list to and fro.

DoublyLinkedList:
The private data members of DoublyLinkedList are ‘firstptr’ and ‘lastptr’ which are used to hold
the address of first and last nodes of the doubly linked list. Whenever the list needs to be traversed,
a temporary pointer of type Node known as ‘currentptr’ is used by initializing its value to firstptr.
A second pointer known as ‘tempptr’ is also used when necessary.
The member functions of DoublyLinkedList used are:
I. DoublyLinkedList():
This function acts as a constructor for the class DoublyLinkedList. It initializes the value of firstptr
and lastptr to ‘NULL’ whenever the user starts the program.
II. void insert(Node *) :
The insert() function is used whenever the user buys stocks. After the user enters the stock symbol,
number of shares willing to buy and the maximum he is interested in spending on each share, the
doublylinkedlist object in the StockAccount class calls the function insert() by passing the name
of symbol and number of shares in the form of Node. The insert() function accepts the Node
through argument and checks whether the symbol’s stocks are already bought. If the symbol is
found in the doubly linked list, it simply adds the number of shares of the argument node with that
of existing number of shares or else it will create a new Node and adds it at the beginning of
DoublyLinkedList. The implementation of adding the new Node at the beginning of list varies
with the size of existing list.III. void remove(Node*):
The remove() function is used whenever the user sells stocks. After the user enters the stock
symbol, number of shares willing to sell and the minimum he is interested in selling on each share,
the doublylinkedlist object in the StockAccount class calls the function remove() by passing the
name of symbol and number of shares in the form of Node. The remove() function accepts the
Node through argument and checks for the symbol in the doubly linked list. If the symbol is found
in the doubly linked list, it simply subtracts the number of shares of the argument node with that
of existing number of shares or else it displays an error message. If the number of shares are equal
to zero, the node is deleted in order to free the memory space. The deletion of the node varies
according to the size of the list and the position of the node.
IV. void sortlist():
When the doublylinkedlist object of class StockAccount calls this function, the nodes of the doubly
linked list are sorted according to the total value of shares from higher value to the lower value.
For this implementation selection sorting method was used and proper care was taken such that
for every iteration the big value is updated by reading the stock value randomly and the total share
value was also chosen randomly from the given two text files of “Results_1.txt” and
“Results_2.txt”.
V. int get_numofshares(string):
This function is used to return the number of share of a symbol. Since, StockAccount class cannot
directly access the number of shares of a symbol, this function was implemented so that it can
check error cases while buying and selling shares.
VI. void print(double);
The print() unction is used to print the symbol and number of shares of nodes of the doubly
linked list. This function uses a temporary pointer known as current pointer which was initialized
to first pointer and is traversed using a ‘for’ loop to print out the data. Special cases were taken
into consideration like if the list is empty or not. A variable known as sum is used to calculate the
total value of shares so that the total portfolio value can be displayed.
VII. double pricepershare(string):
The pricepershare() function returns the value of the share by looking for the symbol randomly
from one of the two text files “Results_1.txt” and “Results_2.txt”. This function is used while
implementing the print() function.
VIII. void save():
This function saves the stock symbol along with its number of shares in a text file
“StockAccount_Info.txt” so that this data is used when the user reenters the program using the
constructor of StockAccount.IX. void initialize():
The initialize function is called by the constructor of StockAccount. This function reads the data
from the “StockAccount_Info.txt” file and creates a new doubly linked list whenever a program is
restarted. This function uses the insert() function to create the doubly linked list and this updated
information is used further.
X. void saveportfolio(double):
The saveportfolio() function is used to save the total portfolio value along with the current cash
balance, date and time so that it can be used when a program is restarted. The information is stored
in “BankAccount_Info.txt” file. The function accepts an argument of type double which is
equivalent to current cash balance in order to calculate the total portfolio value.

RESULT:
An Account Management System was implemented using an abstract base class ACCOUNT and
two derived classes StockAccount and BankAccount which share a common cash balance. The
StockAccount was implemented in order that a user can buy and sell the stocks by choosing a
random value from the two text files provided and several other functions like sorting, viewing a
graph, viewing stock value, etc. were also implemented. In BankAccount, cash withdrawal and
deposit actions were implemented. Both of these accounts were implemented such that each
activity reflects the updated current cash balance in two of them. Various information from both
the accounts was stored into files for future correspondence as well as to display the history.
