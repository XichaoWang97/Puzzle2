#include <iostream>
#include <vector>
using namespace std;

void setActive(int& p)  //set the point to active
{
    p = 1;
}

void draw8points(vector<vector<int>>& matrix, int cx, int cy, int x, int y) {
    // draw the 8 symmetric points
    int dx[8] = { x, -x,  x, -x,  y, -y,  y, -y };
    int dy[8] = { y,  y, -y, -y,  x,  x, -x, -x };

    for (int i = 0; i < 8; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx >= 0 && nx < (int)matrix.size() &&        //check bounds
            ny >= 0 && ny < (int)matrix[0].size())
        {
            setActive(matrix[nx][ny]);
        }
    }
}

void drawCircle(vector<vector<int>>& matrix, int cx, int cy, int radius) {
    //Bresenham circle drawing algorithm
    //cx, cy are the coordinate value of center; x and y are offsets from center.
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius; //init decision parameter

    while (x <= y) {
        draw8points(matrix, cx, cy, x, y);
        // update decision parameter and coordinates
        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    vector<vector<int>> matrix(100, vector<int>(100, 0));
    drawCircle(matrix, 50, 50, 5);
    // Print the matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}