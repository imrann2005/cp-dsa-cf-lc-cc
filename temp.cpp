// /**
//  * A* Algorithm Visualization using OpenGL/FreeGLUT
//  *
//  * This program visualizes the A* pathfinding algorithm with detailed heuristic information.
//  * It displays the open set, closed set, current path, and heuristic values for each node.
//  */

// // Use these pragma directives to increase include depth limit
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wdepth-zero-redundant-flags"
// #pragma GCC system_header

// // Include necessary headers
// #include <GL/freeglut.h>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
// #include <sstream>
// #include <iomanip>
// #include <cstdlib>

// // Define math functions directly to avoid cmath issues
// #include <math.h>

// //window dimensions
// const int WINDOW_WIDTH = 1200;
// const int WINDOW_HEIGHT = 800;
// const int INFO_PANEL_WIDTH = 300;
// const int GRID_SIZE = 40;  // Increased from 20 to 40
// const int GRID_WIDTH = (WINDOW_WIDTH - INFO_PANEL_WIDTH) / GRID_SIZE;
// const int GRID_HEIGHT = WINDOW_HEIGHT / GRID_SIZE;

// // Cell types
// enum CellType {
//     EMPTY,
//     OBSTACLE,
//     START,
//     GOAL,
//     PATH,
//     VISITED,
//     CURRENT,
//     OPEN_SET
// };

// // Heuristic types
// enum HeuristicType {
//     MANHATTAN,
//     EUCLIDEAN,
//     DIAGONAL,
//     OCTILE
// };

// // Global variables
// std::vector<std::vector<CellType>> grid(GRID_WIDTH, std::vector<CellType>(GRID_HEIGHT, EMPTY));
// int startX = 2, startY = 2;
// int goalX = GRID_WIDTH - 3, goalY = GRID_HEIGHT - 3;
// bool isRunning = false;
// bool isDrawingObstacle = false;
// bool isErasingObstacle = false;
// HeuristicType currentHeuristic = MANHATTAN;
// float delay = 0.1f; // seconds between steps
// float timeAccumulator = 0.0f;
// int lastUpdateTime = 0;

// // A* algorithm specific structures
// struct Node {
//     int x, y;
//     float g; // Cost from start to this node
//     float h; // Heuristic cost from this node to goal
//     float f; // Total cost (g + h)
//     Node* parent;

//     Node(int _x, int _y, float _g = 0.0f, float _h = 0.0f, Node* _parent = nullptr)
//         : x(_x), y(_y), g(_g), h(_h), f(_g + _h), parent(_parent) {}

//     bool operator==(const Node& other) const {
//         return x == other.x && y == other.y;
//     }

//     bool operator<(const Node& other) const {
//         if (f == other.f) {
//             return h < other.h; // Tie-breaking using h-value
//         }
//         return f < other.f;
//     }

//     bool operator>(const Node& other) const {
//         if (f == other.f) {
//             return h > other.h; // Tie-breaking using h-value
//         }
//         return f > other.f;
//     }
// };

// // Custom hash function for Node pointers
// struct NodePtrHash {
//     std::size_t operator()(const Node* node) const {
//         return std::hash<int>()(node->x) ^ std::hash<int>()(node->y);
//     }
// };

// // Custom equality function for Node pointers
// struct NodePtrEqual {
//     bool operator()(const Node* lhs, const Node* rhs) const {
//         return lhs->x == rhs->x && lhs->y == rhs->y;
//     }
// };

// // A* algorithm state
// std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> openSet;
// std::unordered_set<Node*, NodePtrHash, NodePtrEqual> openSetLookup;
// std::unordered_set<Node*, NodePtrHash, NodePtrEqual> closedSet;
// std::unordered_map<int, std::unordered_map<int, Node*>> allNodes;
// Node* currentNode = nullptr;
// bool pathFound = false;
// bool algorithmComplete = false;
// std::vector<Node*> finalPath;

// // Stats for visualization
// int stepsPerformed = 0;
// int nodesExplored = 0;
// int pathLength = 0;

// // Heuristic functions
// float manhattanDistance(int x1, int y1, int x2, int y2) {
//     return std::abs(x1 - x2) + std::abs(y1 - y2);
// }

// float euclideanDistance(int x1, int y1, int x2, int y2) {
//     return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
// }

// float diagonalDistance(int x1, int y1, int x2, int y2) {
//     int dx = std::abs(x1 - x2);
//     int dy = std::abs(y1 - y2);
//     return dx + dy + (std::sqrt(2) - 2) * std::min(dx, dy);
// }

// float octileDistance(int x1, int y1, int x2, int y2) {
//     int dx = std::abs(x1 - x2);
//     int dy = std::abs(y1 - y2);
//     return std::max(dx, dy) + (std::sqrt(2) - 1) * std::min(dx, dy);
// }

// float calculateHeuristic(int x1, int y1, int x2, int y2) {
//     switch (currentHeuristic) {
//         case MANHATTAN:
//             return manhattanDistance(x1, y1, x2, y2);
//         case EUCLIDEAN:
//             return euclideanDistance(x1, y1, x2, y2);
//         case DIAGONAL:
//             return diagonalDistance(x1, y1, x2, y2);
//         case OCTILE:
//             return octileDistance(x1, y1, x2, y2);
//         default:
//             return manhattanDistance(x1, y1, x2, y2);
//     }
// }

// // Utility functions
// bool isValid(int x, int y) {
//     return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
// }

// bool isObstacle(int x, int y) {
//     return grid[x][y] == OBSTACLE;
// }

// void clearPath() {
//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             if (grid[x][y] == PATH || grid[x][y] == VISITED || grid[x][y] == CURRENT || grid[x][y] == OPEN_SET) {
//                 grid[x][y] = EMPTY;
//             }
//         }
//     }
//     grid[startX][startY] = START;
//     grid[goalX][goalY] = GOAL;
// }

// void clearSearch() {
//     // Clear existing search data
//     while (!openSet.empty()) {
//         openSet.pop();
//     }
//     openSetLookup.clear();
//     closedSet.clear();
//     for (auto& row : allNodes) {
//         for (auto& node : row.second) {
//             delete node.second;
//         }
//     }
//     allNodes.clear();
//     finalPath.clear();
//     currentNode = nullptr;
//     pathFound = false;
//     algorithmComplete = false;
//     stepsPerformed = 0;
//     nodesExplored = 0;
//     pathLength = 0;
//     clearPath();
// }

// void resetGrid() {
//     clearSearch();
//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             grid[x][y] = EMPTY;
//         }
//     }
//     grid[startX][startY] = START;
//     grid[goalX][goalY] = GOAL;
// }

// void reconstructPath() {
//     finalPath.clear();
//     Node* current = currentNode;
//     while (current != nullptr) {
//         finalPath.push_back(current);
//         current = current->parent;
//     }
//     std::reverse(finalPath.begin(), finalPath.end());
//     pathLength = finalPath.size() - 1; // Don't count the start node

//     // Update grid for visualization
//     clearPath();
//     for (Node* node : finalPath) {
//         grid[node->x][node->y] = PATH;
//     }
//     grid[startX][startY] = START;
//     grid[goalX][goalY] = GOAL;
// }

// void initializeAstar() {
//     clearSearch();

//     // Create start node
//     Node* startNode = new Node(startX, startY, 0.0f, calculateHeuristic(startX, startY, goalX, goalY));
//     openSet.push(startNode);
//     openSetLookup.insert(startNode);
//     allNodes[startX][startY] = startNode;
//     grid[startX][startY] = START;
//     grid[goalX][goalY] = GOAL;
//     isRunning = true;
// }

// // A* algorithm step
// bool astarStep() {
//     if (openSet.empty() || algorithmComplete) {
//         algorithmComplete = true;
//         isRunning = false;
//         return false;
//     }

//     ++stepsPerformed;

//     // Get node with lowest f-score
//     currentNode = openSet.top();
//     openSet.pop();
//     openSetLookup.erase(currentNode);
//     closedSet.insert(currentNode);
//     ++nodesExplored;

//     int x = currentNode->x;
//     int y = currentNode->y;

//     // Update grid for visualization
//     if (grid[x][y] != START && grid[x][y] != GOAL) {
//         grid[x][y] = CURRENT;
//     }

//     // Check if goal reached
//     if (x == goalX && y == goalY) {
//         pathFound = true;
//         reconstructPath();
//         algorithmComplete = true;
//         isRunning = false;
//         return true;
//     }

//     // Directions: N, NE, E, SE, S, SW, W, NW
//     const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//     const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

//     // Process neighbors
//     for (int i = 0; i < 8; ++i) {
//         int newX = x + dx[i];
//         int newY = y + dy[i];

//         // Check validity
//         if (!isValid(newX, newY) || isObstacle(newX, newY)) {
//             continue;
//         }

//         // Calculate cost to move to neighbor
//         float moveCost = (i % 2 == 0) ? 1.0f : std::sqrt(2.0f); // Diagonal movement costs more
//         float tentativeG = currentNode->g + moveCost;

//         // Check if this node already exists
//         Node* neighbor = nullptr;
//         if (allNodes.count(newX) > 0 && allNodes[newX].count(newY) > 0) {
//             neighbor = allNodes[newX][newY];
//         }

//         // Check if this is a new path or a better path
//         if (!neighbor) {
//             // Create new node
//             float h = calculateHeuristic(newX, newY, goalX, goalY);
//             neighbor = new Node(newX, newY, tentativeG, h, currentNode);
//             allNodes[newX][newY] = neighbor;

//             // Add to open set
//             openSet.push(neighbor);
//             openSetLookup.insert(neighbor);

//             // Update grid for visualization
//             if (grid[newX][newY] != START && grid[newX][newY] != GOAL) {
//                 grid[newX][newY] = OPEN_SET;
//             }
//         } else if (tentativeG < neighbor->g && closedSet.find(neighbor) == closedSet.end()) {
//             // Found a better path to an existing node
//             neighbor->g = tentativeG;
//             neighbor->f = tentativeG + neighbor->h;
//             neighbor->parent = currentNode;

//             // Check if node is not in open set
//             if (openSetLookup.find(neighbor) == openSetLookup.end()) {
//                 openSet.push(neighbor);
//                 openSetLookup.insert(neighbor);
//             }
//         }
//     }

//     // Mark current node as visited for visualization
//     if (grid[x][y] != START && grid[x][y] != GOAL) {
//         grid[x][y] = VISITED;
//     }

//     return true;
// }

// // Drawing functions
// void drawCell(int x, int y, CellType type) {
//     float cellX = x * GRID_SIZE;
//     float cellY = y * GRID_SIZE;

//     // Set color based on cell type
//     switch (type) {
//         case EMPTY:
//             glColor3f(1.0f, 1.0f, 1.0f); // White
//             break;
//         case OBSTACLE:
//             glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
//             break;
//         case START:
//             glColor3f(0.0f, 0.8f, 0.0f); // Green
//             break;
//         case GOAL:
//             glColor3f(0.8f, 0.0f, 0.0f); // Red
//             break;
//         case PATH:
//             glColor3f(0.0f, 0.0f, 0.8f); // Blue
//             break;
//         case VISITED:
//             glColor3f(0.8f, 0.6f, 0.6f); // Light red
//             break;
//         case CURRENT:
//             glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//             break;
//         case OPEN_SET:
//             glColor3f(0.6f, 0.8f, 0.6f); // Light green
//             break;
//     }

//     // Draw cell
//     glBegin(GL_QUADS);
//     glVertex2f(cellX, cellY);
//     glVertex2f(cellX + GRID_SIZE, cellY);
//     glVertex2f(cellX + GRID_SIZE, cellY + GRID_SIZE);
//     glVertex2f(cellX, cellY + GRID_SIZE);
//     glEnd();

//     // Draw cell border
//     glColor3f(0.5f, 0.5f, 0.5f); // Gray
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(cellX, cellY);
//     glVertex2f(cellX + GRID_SIZE, cellY);
//     glVertex2f(cellX + GRID_SIZE, cellY + GRID_SIZE);
//     glVertex2f(cellX, cellY + GRID_SIZE);
//     glEnd();
// }

// void drawGrid() {
//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             drawCell(x, y, grid[x][y]);
//         }
//     }
// }

// void drawNodeInfo(const Node* node, int x, int y) {
//     if (!node) return;

//     std::stringstream ss;
//     ss << std::fixed << std::setprecision(1);
//     ss << "g:" << node->g;
//     std::string gText = ss.str();
//     ss.str("");

//     ss << "h:" << node->h;
//     std::string hText = ss.str();
//     ss.str("");

//     ss << "f:" << node->f;
//     std::string fText = ss.str();

//     float cellX = x * GRID_SIZE + GRID_SIZE / 2;
//     float cellY = y * GRID_SIZE + GRID_SIZE / 2;

//     glColor3f(0.0f, 0.0f, 0.0f); // Black text

//     // Draw G value (top left)
//     glRasterPos2f(cellX - GRID_SIZE / 2 + 4, cellY - GRID_SIZE / 4);
//     for (char c : gText) {
//         // Using a larger font for better readability
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }

//     // Draw H value (top right)
//     glRasterPos2f(cellX + 2, cellY - GRID_SIZE / 4);
//     for (char c : hText) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }

//     // Draw F value (bottom center)
//     glRasterPos2f(cellX - GRID_SIZE / 4, cellY + GRID_SIZE / 4);
//     for (char c : fText) {
//         // Use an even larger font for the important F value
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//     }
// }

// void drawHeuristicInfo() {
//     // Draw heuristic values for nodes
//     for (const auto& row : allNodes) {
//         for (const auto& cell : row.second) {
//             Node* node = cell.second;
//             drawNodeInfo(node, node->x, node->y);
//         }
//     }
// }

// void drawInfoPanel() {
//     int panelX = WINDOW_WIDTH - INFO_PANEL_WIDTH;

//     // Draw panel background
//     glColor3f(0.9f, 0.9f, 0.9f); // Light gray
//     glBegin(GL_QUADS);
//     glVertex2f(panelX, 0);
//     glVertex2f(WINDOW_WIDTH, 0);
//     glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
//     glVertex2f(panelX, WINDOW_HEIGHT);
//     glEnd();

//     // Draw panel border
//     glColor3f(0.5f, 0.5f, 0.5f); // Gray
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(panelX, 0);
//     glVertex2f(WINDOW_WIDTH, 0);
//     glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
//     glVertex2f(panelX, WINDOW_HEIGHT);
//     glEnd();

//     // Draw panel content
//     glColor3f(0.0f, 0.0f, 0.0f); // Black text

//     int textY = WINDOW_HEIGHT - 30;
//     int lineHeight = 20;

//     // Title
//     glRasterPos2f(panelX + 10, textY);
//     std::string title = "A* Algorithm Visualization";
//     for (char c : title) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//     }
//     textY -= lineHeight * 2;

//     // Controls
//     glRasterPos2f(panelX + 10, textY);
//     std::string controls = "Controls:";
//     for (char c : controls) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight;

//     std::vector<std::string> controlsText = {
//         "Left click: Draw obstacle",
//         "Right click: Erase obstacle",
//         "S key: Set start position",
//         "G key: Set goal position",
//         "Space: Start/Pause search",
//         "R key: Reset grid",
//         "C key: Clear path",
//         "1-4: Change heuristic",
//         "+/-: Adjust simulation speed"
//     };

//     for (const auto& text : controlsText) {
//         glRasterPos2f(panelX + 20, textY);
//         for (char c : text) {
//             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//         }
//         textY -= lineHeight;
//     }
//     textY -= lineHeight;

//     // Current heuristic
//     glRasterPos2f(panelX + 10, textY);
//     std::string heuristicText = "Current Heuristic: ";
//     switch (currentHeuristic) {
//         case MANHATTAN:
//             heuristicText += "Manhattan";
//             break;
//         case EUCLIDEAN:
//             heuristicText += "Euclidean";
//             break;
//         case DIAGONAL:
//             heuristicText += "Diagonal";
//             break;
//         case OCTILE:
//             heuristicText += "Octile";
//             break;
//     }
//     for (char c : heuristicText) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight * 2;

//     // Statistics
//     glRasterPos2f(panelX + 10, textY);
//     std::string statsTitle = "Statistics:";
//     for (char c : statsTitle) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight;

//     std::vector<std::string> statsText = {
//         "Steps performed: " + std::to_string(stepsPerformed),
//         "Nodes explored: " + std::to_string(nodesExplored),
//         "Open set size: " + std::to_string(openSetLookup.size()),
//         "Closed set size: " + std::to_string(closedSet.size()),
//         "Path length: " + std::to_string(pathLength)
//     };

//     for (const auto& text : statsText) {
//         glRasterPos2f(panelX + 20, textY);
//         for (char c : text) {
//             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//         }
//         textY -= lineHeight;
//     }
//     textY -= lineHeight;

//     // Status
//     glRasterPos2f(panelX + 10, textY);
//     std::string statusText = "Status: ";

//     if (pathFound) {
//         statusText += "Path found!";
//         glColor3f(0.0f, 0.7f, 0.0f); // Green text
//     } else if (algorithmComplete) {
//         statusText += "No path exists!";
//         glColor3f(0.7f, 0.0f, 0.0f); // Red text
//     } else if (isRunning) {
//         statusText += "Searching...";
//         glColor3f(0.0f, 0.0f, 0.7f); // Blue text
//     } else {
//         statusText += "Paused";
//         glColor3f(0.7f, 0.7f, 0.0f); // Yellow text
//     }

//     for (char c : statusText) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight * 2;

//     // Legend
//     glColor3f(0.0f, 0.0f, 0.0f); // Black text
//     glRasterPos2f(panelX + 10, textY);
//     std::string legendTitle = "Legend:";
//     for (char c : legendTitle) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight;

//     // Draw legend items
//     struct LegendItem {
//         std::string text;
//         CellType type;
//     };

//     std::vector<LegendItem> legendItems = {
//         {"Start", START},
//         {"Goal", GOAL},
//         {"Obstacle", OBSTACLE},
//         {"Current", CURRENT},
//         {"Open Set", OPEN_SET},
//         {"Visited", VISITED},
//         {"Path", PATH}
//     };

//     for (const auto& item : legendItems) {
//         // Draw color square
//         switch (item.type) {
//             case START:
//                 glColor3f(0.0f, 0.8f, 0.0f); // Green
//                 break;
//             case GOAL:
//                 glColor3f(0.8f, 0.0f, 0.0f); // Red
//                 break;
//             case OBSTACLE:
//                 glColor3f(0.2f, 0.2f, 0.2f); // Dark gray
//                 break;
//             case CURRENT:
//                 glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//                 break;
//             case OPEN_SET:
//                 glColor3f(0.6f, 0.8f, 0.6f); // Light green
//                 break;
//             case VISITED:
//                 glColor3f(0.8f, 0.6f, 0.6f); // Light red
//                 break;
//             case PATH:
//                 glColor3f(0.0f, 0.0f, 0.8f); // Blue
//                 break;
//             default:
//                 glColor3f(1.0f, 1.0f, 1.0f); // White
//         }

//         glBegin(GL_QUADS);
//         glVertex2f(panelX + 20, textY - 10);
//         glVertex2f(panelX + 35, textY - 10);
//         glVertex2f(panelX + 35, textY + 5);
//         glVertex2f(panelX + 20, textY + 5);
//         glEnd();

//         // Draw border
//         glColor3f(0.0f, 0.0f, 0.0f); // Black
//         glBegin(GL_LINE_LOOP);
//         glVertex2f(panelX + 20, textY - 10);
//         glVertex2f(panelX + 35, textY - 10);
//         glVertex2f(panelX + 35, textY + 5);
//         glVertex2f(panelX + 20, textY + 5);
//         glEnd();

//         // Draw text
//         glRasterPos2f(panelX + 45, textY);
//         for (char c : item.text) {
//             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//         }
//         textY -= lineHeight;
//     }

//     // Draw node heuristic explanation
//     textY -= lineHeight;
//     glRasterPos2f(panelX + 10, textY);
//     std::string heuristicExplain = "Node Values:";
//     for (char c : heuristicExplain) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//     }
//     textY -= lineHeight;

//     std::vector<std::string> nodeExplanation = {
//         "g: Cost from start",
//         "h: Heuristic to goal",
//         "f: Total cost (g + h)"
//     };

//     for (const auto& text : nodeExplanation) {
//         glRasterPos2f(panelX + 20, textY);
//         for (char c : text) {
//             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//         }
//         textY -= lineHeight;
//     }
// }

// // GLUT callback functions
// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     drawGrid();
//     drawHeuristicInfo();
//     drawInfoPanel();

//     glutSwapBuffers();
// }

// void reshape(int width, int height) {
//     glViewport(0, 0, width, height);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0, width, height, 0, -1, 1);
//     glMatrixMode(GL_MODELVIEW);
// }

// void timer(int value) {
//     int currentTime = glutGet(GLUT_ELAPSED_TIME);
//     float deltaTime = (currentTime - lastUpdateTime) / 1000.0f;
//     lastUpdateTime = currentTime;

//     if (isRunning) {
//         timeAccumulator += deltaTime;
//         while (timeAccumulator >= delay && isRunning) {
//             astarStep();
//             timeAccumulator -= delay;
//         }
//     }

//     glutPostRedisplay();
//     glutTimerFunc(16, timer, 0); // ~60 FPS
// }

// void keyboard(unsigned char key, int x, int y) {
//     switch (key) {
//         case ' ': // Space bar - start/pause search
//             if (algorithmComplete) {
//                 initializeAstar();
//             } else {
//                 isRunning = !isRunning;
//             }
//             break;
//         case 'r': // Reset grid
//             resetGrid();
//             break;
//         case 'c': // Clear path
//             clearSearch();
//             break;
//         case 's': // Set start position
//             {
//                 int gridX = x / GRID_SIZE;
//                 int gridY = y / GRID_SIZE;
//                 if (isValid(gridX, gridY) && grid[gridX][gridY] != OBSTACLE && grid[gridX][gridY] != GOAL) {
//                     grid[startX][startY] = EMPTY;
//                     startX = gridX;
//                     startY = gridY;
//                     grid[startX][startY] = START;
//                     clearSearch();
//                 }
//             }
//             break;
//         case 'g': // Set goal position
//             {
//                 int gridX = x / GRID_SIZE;
//                 int gridY = y / GRID_SIZE;
//                 if (isValid(gridX, gridY) && grid[gridX][gridY] != OBSTACLE && grid[gridX][gridY] != START) {
//                     grid[goalX][goalY] = EMPTY;
//                     goalX = gridX;
//                     goalY = gridY;
//                     grid[goalX][goalY] = GOAL;
//                     clearSearch();
//                 }
//             }
//             break;
//         case '1': // Manhattan heuristic
//             currentHeuristic = MANHATTAN;
//             clearSearch();
//             break;
//         case '2': // Euclidean heuristic
//             currentHeuristic = EUCLIDEAN;
//             clearSearch();
//             break;
//         case '3': // Diagonal heuristic
//             currentHeuristic = DIAGONAL;
//             clearSearch();
//             break;
//         case '4': // Octile heuristic
//             currentHeuristic = OCTILE;
//             clearSearch();
//             break;
//         case '+': // Increase speed
//             delay = std::max(0.01f, delay * 0.75f);
//             break;
//         case '-': // Decrease speed
//             delay = std::min(1.0f, delay * 1.5f);
//             break;
//     }

//     glutPostRedisplay();
// }

// void motion(int x, int y) {
//     int gridX = x / GRID_SIZE;
//     int gridY = y / GRID_SIZE;

//     if (gridX >= GRID_WIDTH) return; // In info panel

//     // Place or remove obstacle based on mouse state
//     if (isValid(gridX, gridY) && grid[gridX][gridY] != START && grid[gridX][gridY] != GOAL) {
//         if (isDrawingObstacle) {
//             grid[gridX][gridY] = OBSTACLE;
//         } else if (isErasingObstacle) {
//             grid[gridX][gridY] = EMPTY;
//         }
//         clearSearch();
//     }

//     glutPostRedisplay();
// }

// // Create some predefined maze patterns
// void createRandomObstacles(float density = 0.3f) {
//     clearSearch();

//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             if (grid[x][y] != START && grid[x][y] != GOAL) {
//                 if (static_cast<float>(rand()) / RAND_MAX < density) {
//                     grid[x][y] = OBSTACLE;
//                 } else {
//                     grid[x][y] = EMPTY;
//                 }
//             }
//         }
//     }
// }

// void createMazePattern() {
//     clearSearch();

//     // Reset grid first
//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             if (grid[x][y] != START && grid[x][y] != GOAL) {
//                 grid[x][y] = EMPTY;
//             }
//         }
//     }

//     // Create a maze-like pattern
//     for (int x = 0; x < GRID_WIDTH; ++x) {
//         for (int y = 0; y < GRID_HEIGHT; ++y) {
//             // Create a grid-like maze pattern
//             if ((x % 4 == 0 || y % 4 == 0) &&
//                 (x != startX || y != startY) &&
//                 (x != goalX || y != goalY)) {
//                 grid[x][y] = OBSTACLE;
//             }

//             // Add some random passages
//             if (grid[x][y] == OBSTACLE && (rand() % 10 < 3)) {
//                 grid[x][y] = EMPTY;
//             }
//         }
//     }
// }

// // Forward declaration for mouse function
// void mouse(int button, int state, int x, int y);

// // Special key handler (for arrow keys, etc.)
// void specialKeyboard(int key, int x, int y) {
//     switch (key) {
//         case GLUT_KEY_F1: // Random obstacles
//             createRandomObstacles(0.3f);
//             break;
//         case GLUT_KEY_F2: // Create maze pattern
//             createMazePattern();
//             break;
//         case GLUT_KEY_UP: // Move goal up
//             if (isValid(goalX, goalY - 1) && grid[goalX][goalY - 1] != OBSTACLE && grid[goalX][goalY - 1] != START) {
//                 grid[goalX][goalY] = EMPTY;
//                 goalY -= 1;
//                 grid[goalX][goalY] = GOAL;
//                 clearSearch();
//             }
//             break;
//         case GLUT_KEY_DOWN: // Move goal down
//             if (isValid(goalX, goalY + 1) && grid[goalX][goalY + 1] != OBSTACLE && grid[goalX][goalY + 1] != START) {
//                 grid[goalX][goalY] = EMPTY;
//                 goalY += 1;
//                 grid[goalX][goalY] = GOAL;
//                 clearSearch();
//             }
//             break;
//         case GLUT_KEY_LEFT: // Move goal left
//             if (isValid(goalX - 1, goalY) && grid[goalX - 1][goalY] != OBSTACLE && grid[goalX - 1][goalY] != START) {
//                 grid[goalX][goalY] = EMPTY;
//                 goalX -= 1;
//                 grid[goalX][goalY] = GOAL;
//                 clearSearch();
//             }
//             break;
//         case GLUT_KEY_RIGHT: // Move goal right
//             if (isValid(goalX + 1, goalY) && grid[goalX + 1][goalY] != OBSTACLE && grid[goalX + 1][goalY] != START) {
//                 grid[goalX][goalY] = EMPTY;
//                 goalX += 1;
//                 grid[goalX][goalY] = GOAL;
//                 clearSearch();
//             }
//             break;
//     }

//     glutPostRedisplay();
// }

// // Main function
// int main(int argc, char** argv) {
//     // Initialize GLUT
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//     glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("A* Algorithm Visualization");

//     // Set up callbacks
//     glutDisplayFunc(display);
//     glutReshapeFunc(reshape);
//     glutKeyboardFunc(keyboard);
//     glutSpecialFunc(specialKeyboard);
//     glutMouseFunc(mouse);
//     glutMotionFunc(motion);
//     glutTimerFunc(0, timer, 0);

//     // Initialize OpenGL
//     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

//     // Initialize random seed
//     srand(static_cast<unsigned int>(time(NULL)));

//     // Initialize grid with start and goal points
//     resetGrid();

//     // Start main loop
//     lastUpdateTime = glutGet(GLUT_ELAPSED_TIME);
//     glutMainLoop();

//     return 0;
// }

// #pragma GCC diagnostic pop  // End of pragma directives

// void mouse(int button, int state, int x, int y) {
//     int gridX = x / GRID_SIZE;
//     int gridY = y / GRID_SIZE;

//     if (gridX >= GRID_WIDTH) return; // Clicked in info panel

//     if (button == GLUT_LEFT_BUTTON) {
//         if (state == GLUT_DOWN) {
//             isDrawingObstacle = true;
//         } else if (state == GLUT_UP) {
//             isDrawingObstacle = false;
//         }
//     } else if (button == GLUT_RIGHT_BUTTON) {
//         if (state == GLUT_DOWN) {
//             isErasingObstacle = true;
//         } else if (state == GLUT_UP) {
//             isErasingObstacle = false;
//         }
//     }

//     // Place or remove obstacle at the clicked location
//     if (isValid(gridX, gridY) && grid[gridX][gridY] != START && grid[gridX][gridY] != GOAL) {
//         if (isDrawingObstacle) {
//             grid[gridX][gridY] = OBSTACLE;
//         } else if (isErasingObstacle) {
//             grid[gridX][gridY] = EMPTY;
//         }
//         clearSearch();
//     }

//     glutPostRedisplay();
// }























1
0
10
11
00
01
100
101
110
111
000
001
010
011
1000
1001
1010
1011
1100
1101
1110
1111
0000
0001
0010
0011
0100
0101
0110
0111
10000
10001
10010
10011
10100
10101
10110
10111
11000
11001
11010
11011
11100
11101
11110
11111
00000
00001
00010
00011
00100
00101
00110
00111
01000
01001
01010
01011
01100
01101
01110
01111
100000
100001
100010
100011
100100
100101
100110
100111
101000
101001
101010
101011
101100
101101
101110























0 1
0 1
0 1
1 2
1 2
0 1
1 2
0 1
1 2
2 6
2 6
1 2
0 1
1 2
2 6
1 2
0 1
1 2
2 8
1 2
2 6
3 24
3 24
2 6
1 2
2 8
1 2
0 1
1 2
2 6
3 24
2 6
1 2
2 8
1 2
0 1
1 2
2 6
3 36
2 8
1 2
2 8
3 36
2 6
3 24
4 120
4 120
3 24
2 6
3 36
2 8
1 2
2 8
3 36
2 6
1 2
0 1
1 2
2 8
1 2
2 6
3 24
4 120
3 24
2 6
3 36
2 8
1 2
2 8
3 36
2 6
1 2
0 1
1 2
2 8
1 2
2 6
3 24
4 192
3 36
2 8
3 48
2 8
1 2
2 8
3 36
4 216
3 36
2 6
3 36
4 192
3 24
4 120
5 720
5 720..