#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===================== STRUCT DEFINITIONS ===================== */

/* Edge Structure (Represents connection between farms) */
typedef struct Edge {
    int dest;                   // Destination farm index
    struct Edge* next;          // Pointer to next connection
} Edge;

/* Farm Structure (Vertex of Graph) */
typedef struct Farm {
    char *name;                 // Dynamic string for farm name
    float temperature;          // Temperature data
    float moisture;             // Moisture level
    Edge* head;                 // Pointer to adjacency list
} Farm;

/* Graph Structure */
typedef struct Graph {
    int totalFarms;             // Number of farms
    Farm* farms;                // Dynamic array of farms
} Graph;

/* ===================== FUNCTION DECLARATIONS ===================== */

Graph* createGraph();
void addFarm(Graph*);
void displayFarms(Graph*);
void updateFarm(Graph*);
void deleteFarm(Graph*);
void addConnection(Graph*);
void removeConnection(Graph*);
void displayConnections(Graph*);
void searchFarm(Graph*);
void countFarms(Graph*);
void freeGraph(Graph*);

/* ===================== CREATE GRAPH ===================== */
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->totalFarms = 0;
    graph->farms = NULL;
    return graph;
}

/* ===================== ADD FARM ===================== */
void addFarm(Graph* graph) {
    char tempName[100];

    printf("Enter Farm Name: ");
    scanf("%s", tempName);

    graph->totalFarms++;

    graph->farms = (Farm*)realloc(
        graph->farms,
        graph->totalFarms * sizeof(Farm)
    );

    Farm* newFarm = &graph->farms[graph->totalFarms - 1];

    newFarm->name = (char*)malloc(strlen(tempName) + 1);
    strcpy(newFarm->name, tempName);

    printf("Enter Temperature: ");
    scanf("%f", &newFarm->temperature);

    printf("Enter Moisture Level: ");
    scanf("%f", &newFarm->moisture);

    newFarm->head = NULL;

    printf("Farm Added Successfully!\n");
}

/* ===================== DISPLAY FARMS ===================== */
void displayFarms(Graph* graph) {

    if (graph->totalFarms == 0) {
        printf("No farms available.\n");
        return;
    }

    for (int i = 0; i < graph->totalFarms; i++) {
        printf("\nID: %d", i);
        printf("\nName: %s", graph->farms[i].name);
        printf("\nTemperature: %.2f", graph->farms[i].temperature);
        printf("\nMoisture: %.2f\n", graph->farms[i].moisture);
    }
}

/* ===================== UPDATE FARM ===================== */
void updateFarm(Graph* graph) {
    int id;

    printf("Enter Farm ID to update: ");
    scanf("%d", &id);

    if (id < 0 || id >= graph->totalFarms) {
        printf("Invalid ID!\n");
        return;
    }

    printf("Enter New Temperature: ");
    scanf("%f", &graph->farms[id].temperature);

    printf("Enter New Moisture: ");
    scanf("%f", &graph->farms[id].moisture);

    printf("Farm Updated Successfully!\n");
}

/* ===================== DELETE FARM ===================== */
void deleteFarm(Graph* graph) {
    int id;

    printf("Enter Farm ID to delete: ");
    scanf("%d", &id);

    if (id < 0 || id >= graph->totalFarms) {
        printf("Invalid ID!\n");
        return;
    }

    /* Free dynamic string */
    free(graph->farms[id].name);

    /* Free adjacency list */
    Edge* temp = graph->farms[id].head;
    while (temp) {
        Edge* del = temp;
        temp = temp->next;
        free(del);
    }

    /* Shift remaining farms */
    for (int i = id; i < graph->totalFarms - 1; i++) {
        graph->farms[i] = graph->farms[i + 1];
    }

    graph->totalFarms--;

    graph->farms = realloc(
        graph->farms,
        graph->totalFarms * sizeof(Farm)
    );

    printf("Farm Deleted Successfully!\n");
}

/* ===================== ADD CONNECTION ===================== */
void addConnection(Graph* graph) {
    int src, dest;

    printf("Enter Source ID: ");
    scanf("%d", &src);

    printf("Enter Destination ID: ");
    scanf("%d", &dest);

    if (src < 0 || dest < 0 ||
        src >= graph->totalFarms ||
        dest >= graph->totalFarms) {
        printf("Invalid IDs!\n");
        return;
    }

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->farms[src].head;
    graph->farms[src].head = newEdge;

    printf("Connection Added Successfully!\n");
}

/* ===================== REMOVE CONNECTION ===================== */
void removeConnection(Graph* graph) {
    int src, dest;

    printf("Enter Source ID: ");
    scanf("%d", &src);

    printf("Enter Destination ID: ");
    scanf("%d", &dest);

    Edge* temp = graph->farms[src].head;
    Edge* prev = NULL;

    while (temp) {
        if (temp->dest == dest) {
            if (prev == NULL)
                graph->farms[src].head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Connection Removed!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Connection Not Found!\n");
}

/* ===================== DISPLAY CONNECTIONS ===================== */
void displayConnections(Graph* graph) {
    for (int i = 0; i < graph->totalFarms; i++) {
        printf("\n%s -> ", graph->farms[i].name);

        Edge* temp = graph->farms[i].head;
        while (temp) {
            printf("%s ",
                   graph->farms[temp->dest].name);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ===================== SEARCH FARM ===================== */
void searchFarm(Graph* graph) {
    char name[100];

    printf("Enter Farm Name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < graph->totalFarms; i++) {
        if (strcmp(graph->farms[i].name, name) == 0) {
            printf("Farm Found!\n");
            printf("Temperature: %.2f\n",
                   graph->farms[i].temperature);
            printf("Moisture: %.2f\n",
                   graph->farms[i].moisture);
            return;
        }
    }

    printf("Farm Not Found!\n");
}

/* ===================== COUNT FARMS ===================== */
void countFarms(Graph* graph) {
    printf("Total Farms: %d\n", graph->totalFarms);
}

/* ===================== FREE MEMORY ===================== */
void freeGraph(Graph* graph) {

    for (int i = 0; i < graph->totalFarms; i++) {
        free(graph->farms[i].name);

        Edge* temp = graph->farms[i].head;
        while (temp) {
            Edge* del = temp;
            temp = temp->next;
            free(del);
        }
    }

    free(graph->farms);
    free(graph);
}

/* ===================== MAIN ===================== */
int main() {
    int choice;
    Graph* graph = createGraph();

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Add Farm\n");
        printf("2. Display Farms\n");
        printf("3. Update Farm\n");
        printf("4. Delete Farm\n");
        printf("5. Add Connection\n");
        printf("6. Remove Connection\n");
        printf("7. Display Connections\n");
        printf("8. Search Farm\n");
        printf("9. Count Farms\n");
        printf("10. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addFarm(graph); break;
            case 2: displayFarms(graph); break;
            case 3: updateFarm(graph); break;
            case 4: deleteFarm(graph); break;
            case 5: addConnection(graph); break;
            case 6: removeConnection(graph); break;
            case 7: displayConnections(graph); break;
            case 8: searchFarm(graph); break;
            case 9: countFarms(graph); break;
            case 10:
                freeGraph(graph);
                printf("Memory Freed. Program Exited.\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 10);

    return 0;
}
