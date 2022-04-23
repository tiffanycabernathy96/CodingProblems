//Tiffany Abernathy Implementation of Number Of Islands Solution

//Problem::Given a grid of size n* m(n is number of rowsand m is number of columns grid has) consisting of '0's(Water) and '1's(Land).Find the number of islands.
//Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

//Solution::For each 1 found in the matrix increment the number of islands by 1 then call dfs on that node. Set the value in the matrix to 0 to indicate it has been 
//visited. (If no changes are allowed to the matrix create another matrix to keep track of what has been visited). Then call dfs on all the adjacent nodes. 

#include <iostream>
#include <vector>
using namespace std;

class NumberOfIslands {
	vector<vector<char>> matrix;
	void dfs(int n, int m) {
		//Check if at edges or if the value is already 0
		if (n < 0 || m < 0 || n == matrix.size() || m == matrix[0].size() || matrix[n][m] == 0)
			return;

		//Set to 0 to mark it as visited. 
		//If need to leave the matrix unmodified create another matrix for marking as visited. 
		matrix[n][m] = 0;

		//Call dfs on ALL nodes that would be adjacent to this one
		
		//| (n-1, m-1) | (n-1, m) | (n-1, m+1) |
		//|  (n, m-1)  |  (n, m)  |  (n, m+1)  |
		//| (n+1, m-1) | (n+1, m) | (n+1, m+1) |

		dfs(n - 1, m - 1);
		dfs(n - 1, m);
		dfs(n - 1, m + 1);
		dfs(n, m - 1);
		dfs(n, m + 1);
		dfs(n + 1, m - 1);
		dfs(n + 1, m);
		dfs(n + 1, m + 1);
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		//Set starting number of islands to 0
		int numIslands = 0;
		//Set the class variable matrix equal to the grid passed in. 
		matrix = grid;
		//Go through the grid and find each 1
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 1) {
					//Increase the number of islands then call dfs on this position
					numIslands++;
					dfs(i, j);
				}
			}
		}
		//Return the found number of islands
		return numIslands;
	}
};

class NumberOfIslandsArrays {
	int** matrix; 
	int rows, columns;
	void dfs(int n, int m) {
		//Check if at edges or if the value is already 0
		if (n < 0 || m < 0 || n == rows || m == columns || matrix[n][m] == 0)
			return;

		//Set to 0 to mark it as visited. 
		//If need to leave the matrix unmodified create another matrix for marking as visited. 
		matrix[n][m] = 0;

		//Call dfs on ALL nodes that would be adjacent to this one

		//| (n-1, m-1) | (n-1, m) | (n-1, m+1) |
		//|  (n, m-1)  |  (n, m)  |  (n, m+1)  |
		//| (n+1, m-1) | (n+1, m) | (n+1, m+1) |

		dfs(n - 1, m - 1);
		dfs(n - 1, m);
		dfs(n - 1, m + 1);
		dfs(n, m - 1);
		dfs(n, m + 1);
		dfs(n + 1, m - 1);
		dfs(n + 1, m);
		dfs(n + 1, m + 1);
	}
public:
	NumberOfIslandsArrays(int rows, int cols) {
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
		}
		this->rows = rows;
		this->columns = cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	int numberOfIslands() {
		//Set starting number of islands to 0
		int numIslands = 0;
		//Go through the grid and find each 1
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (matrix[i][j] == 1) {
					//Increase the number of islands then call dfs on this position
					numIslands++;
					dfs(i, j);
				}
			}
		}
		//Return the found number of islands
		return numIslands;
	}
	void addEdge(int n, int m) {
		matrix[n][m] = 1;
	}
};

int main() {
	cout << "Using Vectors" << endl;
	cout << "Grid 1: " << endl;
	cout << "0 1 1 1 0 0 0" << endl << "0 0 1 1 0 1 0" << endl << endl;
	NumberOfIslands islandsClass;
	vector<vector<char>> grid = { {0,1,1,1,0,0,0},{0,0,1,1,0,1,0} };
	cout << "Number of Islands in Grid 1: " << islandsClass.numIslands(grid) << endl << endl;

	cout << "Grid 2: " << endl;
	cout << "0 1" << endl << "1 0" << endl << "1 1" << endl << "1 0" << endl;
	grid = { {0,1},{1,0},{1,1},{1,0} };
	cout << "Number of Islands in Grid 2: " << islandsClass.numIslands(grid) << endl << endl;

	cout << "Using Arrays" << endl;
	cout << "Grid 3: " << endl;
	cout << "1 1 0 1 1" << endl << "1 0 0 0 1" << endl << "0 0 1 0 0" << endl << "1 0 0 0 1" << endl 
		<< "1 1 0 1 1" << endl;
	NumberOfIslandsArrays islandsArrayClass(5, 5);
	islandsArrayClass.addEdge(0, 0);
	islandsArrayClass.addEdge(0, 1);
	islandsArrayClass.addEdge(0, 3);
	islandsArrayClass.addEdge(0, 4);
	islandsArrayClass.addEdge(1, 0);
	islandsArrayClass.addEdge(1, 4);
	islandsArrayClass.addEdge(2, 2);
	islandsArrayClass.addEdge(3, 0);
	islandsArrayClass.addEdge(3, 4);
	islandsArrayClass.addEdge(4, 0);
	islandsArrayClass.addEdge(4, 1);
	islandsArrayClass.addEdge(4, 3);
	islandsArrayClass.addEdge(4, 4);

	cout << "Number of Islands in Grid 3: " << islandsArrayClass.numberOfIslands() << endl;
}