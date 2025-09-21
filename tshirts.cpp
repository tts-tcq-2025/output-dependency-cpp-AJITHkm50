#include <iostream>
#include <cassert>

char size(int cms) {
    char sizeName = '\0';
    
    // Handle invalid input
    if (cms < 0) {
        return '\0'; // Return null character for invalid input
    }
    
    if (cms < 38) {
        sizeName = 'S';
    } else if (cms >= 38 && cms <= 42) { // Include 38 and 42 in the range for 'M'
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    
    // Valid cases
    assert(size(37) == 'S'); // Small
    assert(size(38) == 'M'); // Medium
    assert(size(40) == 'M'); // Medium
    assert(size(42) == 'M'); // Medium
    assert(size(43) == 'L'); // Large
    
    // Edge cases
    assert(size(0) == 'S');  // Should be Small for 0
    assert(size(100) == 'L'); // Should be Large for 100

    // Invalid cases
    assert(size(-1) == '\0'); // Invalid input should return null character

    std::cout << "All is well (maybe!)\n";
}
