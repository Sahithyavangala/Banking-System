# Banking-System
The Banking System Simulation project is a console-based application designed to replicate essential functionalities of a banking system using C++ and object-oriented principles. It allows users to manage customers and their accounts, facilitating operations like deposits and withdrawals. The Banking System employs a combination of data structures to efficiently manage accounts and transactions. Linked lists are utilized within each account to maintain transaction histories, allowing chronological recording of deposits and withdrawals. Hash maps (unordered_map) play a crucial role in managing multiple accounts for each customer, providing fast access and modification capabilities based on account numbers. These structures ensure that account details can be retrieved swiftly during banking operations. Furthermore, a Binary Search Tree (BST) organizes customers based on unique IDs, facilitating rapid insertion, deletion, and retrieval of customer records. This hierarchical organization enhances scalability and performance, making the system robust enough to handle extensive customer databases effectively.
## Key Features
  - Customer and Account Management:
    -Add Customers: Allows adding new customers with unique IDs, names, and addresses.
    -Manage Accounts: Associates multiple accounts with each customer, specifying account numbers, types, and initial balances.
    -Delete Accounts: Supports deleting accounts associated with a customer, ensuring efficient management of customer data.
  - Transaction Processing:
    -Deposit Funds: Enables customers to deposit money into their accounts, updating account balances and logging transactions.
    -Withdraw Funds: Facilitates withdrawals from accounts, ensuring sufficient balance checks and updating transaction histories accordingly.
    -Transaction Logging: Maintains a record of all financial transactions, providing an audit trail for accountability and transparency.
  - Data Management:
    -Linked List for Transactions: Tracks transaction histories within each account using a linked list, allowing efficient retrieval and modification of transaction records.
    -Hash Map for Account Management: Utilizes an unordered map to manage accounts within each customer, enabling fast lookup and modification operations based on account numbers.
    - Binary Search Tree (BST) for Customer Organization: Organizes customers in a BST based on unique IDs, facilitating efficient insertion, deletion, and search operations.
  - User Interface:
    -Console-Based Interface: Offers a user-friendly menu-driven interface for interacting with the banking system. Users can perform operations such as creating customers, adding accounts, depositing or withdrawing funds, and viewing transaction histories.
    
## Real-World Application
  
  - Banking Operations: Mirrors core functionalities of real-world banking systems, including account management, transaction processing, and customer relationship management.
  - Educational Tool: Serves as a practical educational resource for learning about data structures (linked lists, hash maps, BSTs) and their applications in banking software development.
  - Scalability: Designed to handle large volumes of customer data and transaction records efficiently, making it suitable for scalability in real-world banking environments.
  - Customization and Extension: Provides a foundation that can be extended with additional features such as interest calculation, account closure procedures, and enhanced reporting functionalities to meet specific banking requirements.

## Conclusion
The Banking System project is designed in C++ to manage accounts and transactions effectively. It uses linked lists to track transaction histories per account, ensuring accurate financial records. Hash maps organize multiple accounts per customer, allowing quick access and updates based on account numbers. A Binary Search Tree organizes customers by unique IDs for efficient customer management. The system features a user-friendly console interface for operations like account creation, funds deposit, withdrawal, and transaction history viewing. It ensures data integrity with validation checks and supports scalability for handling large volumes of customer data. This project serves as an educational tool for learning about banking operations and software development practices in the real world.
  


     
