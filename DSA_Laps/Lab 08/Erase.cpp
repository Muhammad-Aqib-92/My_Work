#include "iostream"
#include "fstream"

using namespace std;


void eraseObject(int** ar, int r, int c, int i, int j)
{
   
    if (i < 0 || i >= r || j < 0 || j >= c || ar[i][j] == 0)
    {
        return;
    } 
    ar[i][j] = 0;

    eraseObject(ar, r, c, i - 1, j); 
    eraseObject(ar, r, c, i + 1, j); 
    eraseObject(ar, r, c, i, j - 1); 
    eraseObject(ar, r, c, i, j + 1); 
}


int main(void)
{
    // Opening the input file
    ifstream inf("input_0.txt");

    // Checking if the file opened successfully
    if(!inf.is_open())
    {
        cout << "Failed to open the file" << endl;
        exit(0);
    }

    int ROWS, COLS, p_x, p_y;

    // Reading image dimensions and target pixel coordinates from the file
    inf >> ROWS >> COLS;
    inf >> p_x >> p_y;

    // Allocating memory for a 2D array
    int **ar = new int*[ROWS];
    for(int i = 0; i < ROWS; i++)
    {
        ar[i] = new int[COLS];
    }

    // Reading the image data into the array
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            inf >> ar[i][j];
        }
    }

    // Closing the input file
    inf.close();

    // Calling the function to process the image
    eraseObject(ar, ROWS, COLS, p_x, p_y);

    // Displaying the updated image data
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating the memory for the 2D array
    for(int i = 0; i < ROWS; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;

    return 0;
}