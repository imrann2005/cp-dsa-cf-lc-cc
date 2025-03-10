#include <iostream>
#include <fstream>
#include <string>
#include <cstring>  // For strncpy

using namespace std;

int main() {

    // 1. Read the file input.txt line by line and display output on screen
    {
        cout << "Task 1: Read the file line by line and display output on screen" << endl;
        ifstream inputFile("input.txt");  // Open the input file
        string line;

        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {  // Read line by line
                cout << line << endl;  // Output the line to the screen
            }
            inputFile.close();  // Close the file after reading
        } else {
            cerr << "Unable to open file!" << endl;
        }
        cout << endl;  // Add space between tasks
    }

    // 2. Store line from input.txt file into buffer and display buffer output on screen
    {
        cout << "Task 2: Store line into buffer and display buffer output on screen" << endl;
        ifstream inputFile("input.txt");  // Open the input file
        char buffer[256];  // Create a buffer with a size of 256 characters

        if (inputFile.is_open()) {
            while (inputFile.getline(buffer, sizeof(buffer))) {  // Store line into buffer
                cout << buffer << endl;  // Output the buffer content
            }
            inputFile.close();  // Close the file after reading
        } else {
            cerr << "Unable to open file!" << endl;
        }
        cout << endl;  // Add space between tasks
    }

    // 3. Store buffer content into external memory location 00 (simulated)
    {
        cout << "Task 3: Store buffer content into external memory location 00" << endl;

        // Simulating external memory (using a simple array for this example)
        char externalMemory[100][4];  // External memory is 100 by 4
        ifstream inputFile("input.txt");
        char buffer[256];  // Buffer to hold a line from the file

        if (inputFile.is_open()) {
            int memoryIndex = 0;  // To keep track of the external memory block

            while (inputFile.getline(buffer, sizeof(buffer)) && memoryIndex < 100) {
                // Copy content from buffer to external memory
                strncpy(externalMemory[memoryIndex], buffer, 4);  // Store the first 4 characters of the buffer
                memoryIndex++;  // Increment the memory index for the next line
            }
            inputFile.close();  // Close the file after reading
        } else {
            cerr << "Unable to open file!" << endl;
        }

        // Displaying the content of the external memory
        cout << "External Memory Content: " << endl;
        for (int i = 0; i < 100; ++i) {
            cout << "Block " << i << ": " << externalMemory[i] << endl;
        }
        cout << endl;  // Add space between tasks
    }

    // 4. Write content into output.txt from external memory
    {
        cout << "Task 4: Write content into output.txt from external memory" << endl;

        // Simulating external memory (using a simple array for this example)
        char externalMemory[100][4];  // External memory is 100 by 4

        // Open the output file to write
        ofstream outputFile("output.txt");

        if (outputFile.is_open()) {
            // Writing content from external memory into the output file
            for (int i = 0; i < 100; ++i) {
                outputFile << externalMemory[i] << endl;
            }
            outputFile.close();  // Close the output file
            cout << "Content written to output.txt successfully!" << endl;
        } else {
            cerr << "Unable to open output file!" << endl;
        }
        cout << endl;  // Add space after the last task
    }

    return 0;
}
