#include <iostream>
#include <sstream>
#include <cassert>

std::string generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::ostringstream oss; // Use string stream to capture output

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n"; // Corrected minor color index
        }
    }
    return oss.str(); // Return the generated color map as a string
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    std::string result = generateColorMap();
    
    // Expected output for the color map
    std::string expectedOutput = 
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";

    assert(result == expectedOutput); // Check if the generated output matches the expected output
    std::cout << "All is well (maybe!)\n";
}
