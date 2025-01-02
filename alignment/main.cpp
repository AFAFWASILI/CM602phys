#include "Mille.h"
#include <iostream>

int main() {
    // Define the output file name
    const char* fileName = "output.bin";

    // Create an instance of Mille
    Mille mille(fileName, true, false);

    // Sample data for local and global derivatives
    const int NLC = 3; // Number of local derivatives
    const float derLc[NLC] = {1.1f, 2.2f, 3.3f}; // Local derivatives
    
    const int NGL = 2; // Number of global derivatives
    const float derGl[NGL] = {0.9f, 1.8f}; // Global derivatives
    const int label[NGL] = {1, 2}; // Labels for global derivatives
    
    // Measurement and its uncertainty
    float rMeas = 5.0f;
    float sigma = 0.5f;

    // Call the mille method to store the data
    mille.mille(NLC, derLc, NGL, derGl, label, rMeas, sigma);

    // Call the end method to write the buffered data to the file
    mille.end();

    // Close the Mille instance
    mille.kill();

    std::cout << "Binary file generated successfully." << std::endl;
    return 0;
}
