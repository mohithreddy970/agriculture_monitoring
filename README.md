🌾 Agriculture Monitoring System (C Programming)

A console-based Agriculture Monitoring System built using C Programming and Graph Data Structure (Adjacency List Representation).

This system manages farms, monitors environmental conditions, and handles connections between farms efficiently using dynamic memory allocation.

📌 Project Overview

This project simulates a smart agriculture monitoring system where:

Each Farm is represented as a vertex
Each Connection between farms is represented as a directed edge
Farm data includes:
Name
Temperature
Moisture Level

The system is fully menu-driven and supports CRUD operations.

✨ Features

✅ Add new farms
✅ Display all farms
✅ Update farm data
✅ Delete farms
✅ Add connections (Directed Graph)
✅ Remove connections
✅ Display adjacency list
✅ Search farm by name
✅ Count total farms
✅ Dynamic memory management
✅ Proper memory cleanup

🧠 Data Structures Used
Graph
Adjacency List
Linked List
Structures
Dynamic Memory Allocation (malloc, realloc, free)
🏗️ Project Structure
Agriculture-Monitoring-System/
│
├── main.c
├── README.md
└── screenshots/
    ├── menu.png
    ├── add_farm.png
    ├── display_farms.png
    └── connections.png

🖥️ Menu Interface
=========== MENU ===========
1. Add Farm
2. Display Farms
3. Update Farm
4. Delete Farm
5. Add Connection
6. Remove Connection
7. Display Connections
8. Search Farm
9. Count Farms
10. Exit

📸 Screenshots

📌 Create a folder named screenshots in your repository and add terminal screenshots there.

🟢 Main Menu

🌱 Adding a Farm

📋 Displaying Farms

🔗 Farm Connections

⚙️ How It Works
🔹 Graph Representation

Each farm is stored in a dynamic array.
Connections are stored using a linked list (Adjacency List).

🔹 Farm Structure
typedef struct Farm {
    char *name;
    float temperature;
    float moisture;
    Edge* head;
} Farm;

🔹 Edge Structure
typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

🚀 How to Compile and Run
🔹 Compile
gcc main.c -o farm

🔹 Run

Linux / Mac

./farm


Windows

farm.exe

🧪 Sample Execution
Input:
Add Farm → FarmA
Add Farm → FarmB
Add Connection from 0 → 1
Output:
FarmA -> FarmB
FarmB ->

📚 Learning Outcomes

This project helps understand:

Graph implementation in C
Adjacency list representation
Linked list operations
Dynamic memory management
Menu-driven application design
CRUD operations in C
⚠️ Important Notes
Farm IDs are automatically assigned.
Connections are directed.
Deleting a farm shifts indices.
Memory is properly freed before exiting.
🔮 Future Improvements
Save and load data using file handling
Add temperature history tracking
Add BFS / DFS traversal
Add alert system for extreme conditions
Convert to GUI version
Add IoT sensor integration simulation
👨‍💻 Authors
Mohan
Mohith
📜 License

This project is created for academic and educational purposes.

📌 How to Add Screenshots (Important)
Run your program
Take screenshots of:
Menu
Adding farm
Display farms
Connections

Create a folder in your repo named:

screenshots

Upload images inside it
Make sure file names match:
menu.png
add_farm.png
display_farms.png
connections.png

