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
<img width="433" height="453" alt="Screenshot 2026-05-04 125400" src="https://github.com/user-attachments/assets/59a44475-e425-428e-908a-8a89ecfb3377" />
<img width="428" height="443" alt="Screenshot 2026-05-04 125347" src="https://github.com/user-attachments/assets/43b53fcb-6ae8-4bc3-bbaa-019c1e5df240" />
<img width="403" height="460" alt="Screenshot 2026-05-04 125333" src="https://github.com/user-attachments/assets/57868f0f-12df-4ce5-848f-0b5b59c73303" />

✅ Display all farms
<img width="358" height="732" alt="Screenshot 2026-05-04 125420" src="https://github.com/user-attachments/assets/d0680acb-2fac-45f2-b216-4921f2aa9074" />
✅ Update farm data
<img width="412" height="449" alt="Screenshot 2026-05-04 125433" src="https://github.com/user-attachments/assets/007edfcc-7d7f-4880-885a-013d6ec71031" />

✅ Delete farms
<img width="386" height="376" alt="Screenshot 2026-05-04 125457" src="https://github.com/user-attachments/assets/55f75b13-20d4-42e0-925f-1303fe603857" />

✅ Add connections (Directed Graph)
<img width="496" height="448" alt="Screenshot 2026-05-04 125607" src="https://github.com/user-attachments/assets/259bab99-3efe-4fdf-83f4-8ba0fd556efd" />

✅ Remove connections
<img width="365" height="430" alt="Screenshot 2026-05-04 125658" src="https://github.com/user-attachments/assets/31a2e5b6-68dd-47e7-be69-8ccc24bb81d4" />

✅ Display adjacency list
<img width="338" height="462" alt="Screenshot 2026-05-04 125726" src="https://github.com/user-attachments/assets/e304d970-41a2-4c46-8048-fb904e722989" />

✅ Search farm by name
<img width="515" height="457" alt="Screenshot 2026-05-04 125758" src="https://github.com/user-attachments/assets/dee1db5b-234c-4400-b6d3-f0cef3e99a1f" />

✅ Count total farms
<img width="352" height="367" alt="Screenshot 2026-05-04 125818" src="https://github.com/user-attachments/assets/3398dd65-35ae-4d62-b13f-435fa5c4588a" />

✅ Dynamic memory management
<img width="466" height="385" alt="Screenshot 2026-05-04 125843" src="https://github.com/user-attachments/assets/0554e91b-0e40-44bd-b4e8-0ca6eb625519" />

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

