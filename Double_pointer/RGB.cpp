#include <iostream>
#include <cmath> // for round
using namespace std;

// Structure to hold RGB values
struct RGB {
    int R, G, B;
};

// Structure to hold YUV values
struct YUV {
    double Y, U, V;
};

// Function to convert RGB to YUV
YUV rgbToYuv(const RGB &rgb) {
    YUV yuv;
    yuv.Y = 0.299 * rgb.R + 0.587 * rgb.G + 0.114 * rgb.B;
    yuv.U = -0.14713 * rgb.R - 0.28886 * rgb.G + 0.436 * rgb.B;
    yuv.V = 0.615 * rgb.R - 0.51499 * rgb.G - 0.10001 * rgb.B;
    return yuv;
}

// Function to convert YUV to RGB
RGB yuvToRgb(const YUV &yuv) {
    RGB rgb;
    rgb.R = static_cast<int>(round(yuv.Y + 1.13983 * yuv.V));
    rgb.G = static_cast<int>(round(yuv.Y - 0.39465 * yuv.U - 0.58060 * yuv.V));
    rgb.B = static_cast<int>(round(yuv.Y + 2.03211 * yuv.U));

    // Clamp values to 0-255 range
    rgb.R = min(255, max(0, rgb.R));
    rgb.G = min(255, max(0, rgb.G));
    rgb.B = min(255, max(0, rgb.B));
    return rgb;
}

int main() {
    RGB rgb;

    // User input for RGB values
    cout << "Enter RGB values (0-255) separated by space: ";
    cin >> rgb.R >> rgb.G >> rgb.B;

    // Input validation
    if (rgb.R < 0 || rgb.R > 255 || rgb.G < 0 || rgb.G > 255 || rgb.B < 0 || rgb.B > 255) 
        cout << "Invalid input! RGB values must be in the range [0, 255]." << endl;
    

    // Convert RGB to YUV
    YUV yuv = rgbToYuv(rgb);
    cout << "Converted YUV: (Y: " << yuv.Y << ", U: " << yuv.U << ", V: " << yuv.V << ")" << endl;

    // Convert back from YUV to RGB
    RGB convertedRgb = yuvToRgb(yuv);
    cout << "Converted back to RGB: (R: " << convertedRgb.R << ", G: " << convertedRgb.G << ", B: " << convertedRgb.B << ")" << endl;

    return 0;
}
