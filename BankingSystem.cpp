#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// Transaction class to represent individual transactions
class Transaction {
public:
    string transaction_type;
    double amount;

    Transaction(string type, double amt) : transaction_type(type), amount(amt) {}
};

// Account class to represent a bank account
class Account {
public:
    string account_number;
    string account_type;
    double balance;
    list<Transaction> transactions;  // Linked list of transactions

    Account(string number, string type, double bal) : account_number(number), account_type(type), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            return true;
        } else {
            cout << "Insufficient balance" << endl;
            return false;
        }
    }

    double get_balance() const {
        return balance;
    }

    void display_transactions() const {
        cout << "Transactions for Account " << account_number << ":" << endl;
        for (const auto& transaction : transactions) {
            cout << transaction.transaction_type << " of " << transaction.amount << endl;
        }
    }
};

// Customer class to represent a bank customer
class Customer {
public:
    string customer_id;
    string name;
    string address;
    unordered_map<string, Account*> accounts_map;  // Hash map to store accounts

    Customer(string id, string n, string addr) : customer_id(id), name(n), address(addr) {}

    void add_account(Account* account) {
        accounts_map[account->account_number] = account;
    }

    Account* get_account(string account_number) {
        if (accounts_map.find(account_number) != accounts_map.end()) {
            return accounts_map[account_number];
        } else {
            return nullptr;
        }
    }

    void delete_account(string account_number) {
        if (accounts_map.find(account_number) != accounts_map.end()) {
            delete accounts_map[account_number];
            accounts_map.erase(account_number);
        }
    }

    void display_accounts() const {
        cout << "Accounts for Customer " << customer_id << " - " << name << ":" << endl;
        for (const auto& pair : accounts_map) {
            cout << "Account Number: " << pair.first << ", Type: " << pair.second->account_type << ", Balance: " << pair.second->get_balance() << endl;
        }
    }

    ~Customer() {
        for (auto& pair : accounts_map) {
            delete pair.second; // Delete each account object
        }
        accounts_map.clear();
    }
};

// TreeNode class for Binary Search Tree (BST)
class TreeNode {
public:
    Customer* customer;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Customer* cust) : customer(cust), left(nullptr), right(nullptr) {}
};

// CustomerBST class to manage customers using BST
class CustomerBST {
private:
    TreeNode* root;

    void insert_helper(TreeNode*& node, Customer* cust) {
        if (node == nullptr) {
            node = new TreeNode(cust);
        } else {
            if (cust->customer_id < node->customer->customer_id) {
                insert_helper(node->left, cust);
            } else {
                insert_helper(node->right, cust);
            }
        }
    }

    Customer* search_helper(TreeNode* node, string customer_id) {
        if (node == nullptr || node->customer->customer_id == customer_id) {
            return node ? node->customer : nullptr;
        } else if (customer_id < node->customer->customer_id) {
            return search_helper(node->left, customer_id);
        } else {
            return search_helper(node->right, customer_id);
        }
    }

    void delete_helper(TreeNode*& node, string customer_id) {
        if (node == nullptr) {
            return;
        }

        if (customer_id < node->customer->customer_id) {
            delete_helper(node->left, customer_id);
        } else if (customer_id > node->customer->customer_id) {
            delete_helper(node->right, customer_id);
        } else {
            // Case 1: No child or only one child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                node = temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                node = temp;
            } else {
                // Case 2: Two children
                TreeNode* temp = find_min(node->right);
                node->customer = temp->customer;
                delete_helper(node->right, temp->customer->customer_id);
            }
        }
    }

    TreeNode* find_min(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorder_traversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder_traversal(node->left);
        node->customer->display_accounts();
        inorder_traversal(node->right);
    }

public:
    CustomerBST() : root(nullptr) {}

    ~CustomerBST() {
        cleanup(root);
    }

    void insert(Customer* cust) {
        insert_helper(root, cust);
    }

    Customer* search(string customer_id) {
        return search_helper(root, customer_id);
    }

    void remove(string customer_id) {
        delete_helper(root, customer_id);
    }

    void display_all_customers() {
        inorder_traversal(root);
    }

    void cleanup(TreeNode* node) {
        if (node) {
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        }
    }
};

// Function to display menu and get user choice
int get_user_choice() {
    int choice;
    cout << "\n===== Banking System Menu =====" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. Add Account to Customer" << endl;
    cout << "3. Deposit to Account" << endl;
    cout << "4. Withdraw from Account" << endl;
    cout << "5. Display All Customers and Accounts" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    CustomerBST customer_bst;

    int choice;
    do {
        choice = get_user_choice();

        switch (choice) {
            case 1: {
                string customer_id, name, address;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Address: ";
                getline(cin, address);

                Customer* new_customer = new Customer(customer_id, name, address);
                customer_bst.insert(new_customer);
                break;
            }
            case 2: {
                string customer_id, account_number, account_type;
                double initial_balance;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cout << "Enter Account Number: ";
                cin >> account_number;
                cout << "Enter Account Type: ";
                cin >> account_type;
                cout << "Enter Initial Balance: ";
                cin >> initial_balance;

                Customer* cust = customer_bst.search(customer_id);
                if (cust) {
                    if (cust->get_account(account_number) == nullptr) {
                        Account* new_account = new Account(account_number, account_type, initial_balance);
                        cust->add_account(new_account);
                        cout << "Account added successfully" << endl;
                    } else {
                        cout << "Account already exists for this customer!" << endl;
                    }
                } else {
                    cout << "Customer not found!" << endl;
                }
                break;
            }
            case 3: {
                string customer_id, account_number;
                double amount;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cout << "Enter Account Number: ";
                cin >> account_number;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;

                Customer* cust = customer_bst.search(customer_id);
                if (cust) {
                    Account* acc = cust->get_account(account_number);
                    if (acc) {
                        acc->deposit(amount);
                    } else {
                        cout << "Account not found for this customer!" << endl;
                    }
                } else {
                    cout << "Customer not found!" << endl;
                }
                break;
            }
            case 4: {
                string customer_id, account_number;
                double amount;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cout << "Enter Account Number: ";
                cin >> account_number;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;

                Customer* cust = customer_bst.search(customer_id);
                if (cust) {
                    Account* acc = cust->get_account(account_number);
                    if (acc) {
                        acc->withdraw(amount);
                    } else {
                        cout << "Account not found for this customer!" << endl;
                    }
                } else {
                    cout << "Customer not found!" << endl;
                }
                break;
            }
            case 5: {
                customer_bst.display_all_customers();
                break;
            }
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
