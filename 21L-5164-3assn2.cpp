//#include<iostream>
//#include<conio.h>
//#include<cstring>
//#include<fstream>
//
//#define KEY_UP 72
//
//#define KEY_DOWN 80
//
//#define KEY_LEFT 75
//
//#define KEY_RIGHT 77
//
//using namespace std;
//
//int checker = 0;
//char user = 1;
//char devil = 6;
//char gasper = 2;
//char treas = 4;
//int roomNo = 0;
//
//template<class T>
//class Stack
//{
//	T* arr;
//	int maxsize;
//	int stkptr;
//public:
//
//	Stack(int s = 100)
//	{
//		arr = new T[100];
//		maxsize = s;
//		stkptr = 0;
//	}
//	bool IsFull()
//	{
//		return (stkptr == maxsize);
//	}
//	int size()
//	{
//		return stkptr;
//	}
//	bool IsEmpty()
//	{
//		return(stkptr == 0);
//	}
//	bool top(T& d)
//	{
//		if (!IsEmpty())
//		{
//			d = arr[stkptr - 1];
//			return true;
//		}
//		else
//			return false;
//	}
//	/// <summary>
//	/// moves the value of array in data parameter and decrements stack pointer
//	/// </summary>
//	/// <param name="d">Value of data that is popped </param>
//	bool pop(T& d)
//	{
//		if (!IsEmpty())
//		{
//			d = arr[--stkptr];
//			return true;
//		}
//		else
//			return false;
//	}
//	/// <summary>
//	/// inserts element in stack array and increments stack pointer
//	/// </summary>
//	/// <param name="d">Element to be inserted</param>
//	/// <returns>false if stack is full</returns>
//	bool push(T d)
//	{
//		if (!IsFull())
//		{
//			arr[stkptr] = d;
//			stkptr++;
//			return true;
//		}
//		return false;
//	}
//};
//class Room
//{
//	int totalRows;
//	int totalCols;
//	int startRow;
//	int startCol;
//	Stack<int>cRow;
//	Stack<int>cCol;
//	char** matrix;
//	char** display;
//public:
//	Room()
//	{
//		totalRows = 0;
//		totalCols = 0;
//		startRow = 0;
//		startCol = 0;
//		matrix = 0;
//		display = 0;
//	}
//	void SetTotalRows(int r)
//	{
//		totalRows = r;
//	}
//	void SetTotalCols(int c)
//	{
//		totalCols = c;
//	}
//	int GetStartRow()
//	{
//		return startRow;
//	}
//	int GetStartCol()
//	{
//		return startCol;
//	}
//	void SetMatrix(char** m)
//	{
//		matrix = m;
//	}
//	/// <summary>
//	/// Reads data from file and insetrs it in the maze matrix
//	/// </summary>
//	/// <param name="filename">Name of text file</param>
//	void LoadRoom(string filename)
//	{
//		ifstream fin;
//		fin.open(filename);
//		if (fin.is_open())
//		{
//			fin >> totalRows;
//			fin >> totalCols;
//			fin.ignore();
//			fin >> startRow;
//			fin >> startCol;
//			matrix = new char* [totalRows + 1];
//			for(int i=0;i<totalRows;i++)
//			{
//				matrix[i] = new char[totalCols+1];
//				for (int j = 0; j < totalCols; j++)
//				{
//					fin >> matrix[i][j];
//				}
//				matrix[i][totalCols] = -1;
//			}
//			matrix[totalRows] = nullptr;
//		}
//	}
//	/// <summary>
//	/// Takes a row and column and displays a rectangular layout with a user at that location
//	/// </summary>
//	/// <param name="row">Row No. of user's location</param>
//	/// <param name="col">Col No. of user's location</param>
//	void Display(int row,int col)
//	{
//		display = new char* [totalRows + 2];
//		for (int i = 0; i <= totalRows+1; i++)
//		{
//			display[i] = new char[totalCols+2];
//			for (int j = 0; j <= totalCols+1; j++)
//			{
//				if (j == 0||j==totalCols+1)
//				{
//					display[i][j] = '|';
//				}
//				else if (i == 0||i==totalRows+1)
//				{
//					display[i][j] = '-';
//				}
//				else if((i==row+1)&&(j==col+1))
//				{
//					display[i][j] = user;
//				}
//				else
//				{
//					display[i][j] = ' ';
//				}
//			}
//		}
//		for (int i = 0; i <= totalRows+1; i++)
//		{
//			for (int j = 0; j <= totalCols+1; j++)
//			{
//				cout << display[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	/// <summary>
//	/// iterates in the maze by using arrow keys
//	/// </summary>
//	void Maze()
//	{
//		int row = startRow;
//		int col = startCol;
//		bool specialKey = false;
//		int c = 0;
//		int key=0;
//		while ((row>=0)&&(col>=0)&& (row < totalRows)&& (col < totalCols)&&(matrix[row][col]!='D') && (matrix[row][col] != 'T'))
//		{
//			cRow.push(row);
//			cCol.push(col);
//			if (matrix[row][col] == 'G') //checking gasper condition
//			{
//				checker = 1;
//				cout << "You have encountered the gasper " << gasper << endl;
//				break;
//			}
//			if (matrix[row][col] == 'P') //checking portal condition
//			{
//				checker = 2;
//				cout << "You have encountered a portal O" << endl;
//				break;
//			}
//			Display(row, col);
//			c = _getch();
//			if (c && c != 224)
//			{
//				if(c==81)
//				{
//					break;
//				}
//				cout << endl << "Not arrow: " << (char)c << endl;
//			}
//			else
//			{
//				switch ((key = _getch()))
//				{
//					if (_kbhit())
//					{
//				case KEY_DOWN:
//				{
//					if ((row + 1 < totalRows))
//					{
//						if ((matrix[row + 1][col] != 'X'))
//							row++;
//					}
//					system("CLS");
//					break;
//				}
//				case KEY_RIGHT:
//				{
//					if ((col + 1 < totalCols))
//					{
//						if ((matrix[row][col + 1] != 'X'))
//							col++;
//					}
//					system("CLS");
//					break;
//				}
//				case KEY_UP:
//				{
//					if ((row - 1 >= 0))
//					{
//						if ((matrix[row - 1][col] != 'X'))
//							row--;
//					}
//					system("CLS");
//					break;
//				}
//				case KEY_LEFT:
//				{
//					if ((col - 1 >= 0))
//					{
//						if ((matrix[row][col - 1] != 'X'))
//							col--;
//					}
//					system("CLS");
//					break;
//				}
//					}
//				}
//			}
//		}
//		if (matrix[row][col] == 'D') //checking devil condition
//		{
//			cout << "You have been killed by the devil " << devil << endl;
//			checker = 3;
//		}
//		if (c == 81) //checking quit condition
//		{
//			cout << "You have left the game" << endl;
//			checker = 3;
//		}
//		if (matrix[row][col] == 'T') //checking treasure condition
//		{
//			cout << "Congrats! You have found the treasure " << treas << endl;
//			cout << "Room Number " << roomNo + 1 << " : (" << totalRows << "," << totalCols << ")" << endl;
//			cout << "Path: ";
//			cout << "(" << row << "," << col << ") ";
//			checker = 4;
//		}
//	}
//	/// <summary>
//	/// Pops elements in row and column stacks and prints them as coordinates
//	/// </summary>
//	void Pop()
//	{
//		int rowC = 0;
//		int colC = 0;
//		while (rowC != startRow || colC != startCol)
//		{
//			if ((cRow.pop(rowC)) && (cCol.pop(colC)))
//			{
//				cRow.pop(rowC);
//				cCol.pop(colC);
//				cout << "(" << rowC << "," << colC << ") ";
//			}
//		}
//	}
//	/// <summary>
//	/// Searches in the maze matrix
//	/// </summary>
//	/// <returns>true if treasure is found</returns>
//	bool SearchT()
//	{
//		for (int i = 0; i < totalRows; i++)
//		{
//			for (int j = 0; j < totalCols; j++)
//			{
//				if (matrix[i][j] == 'T')
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//};
//class HauntedHouse
//{
//	int totalRooms;
//	Room** rooms;
//	Stack<int> roomNos;
//public:
//	HauntedHouse()
//	{
//		totalRooms = 0;
//		rooms = 0;
//	}
//	/// <summary>
//	/// Reads data from file and inserts it in the array of rooms
//	/// </summary>
//	/// <param name="filename">Name of text file</param>
//	void LoadData(string filename)
//	{
//		string roomName;
//		ifstream fin;
//		fin.open(filename);
//		if (fin.is_open())
//		{
//			fin >> totalRooms;
//			rooms = new Room * [totalRooms + 1];
//			for (int i = 0; i < totalRooms; i++)
//			{
//				fin >> roomName;
//				rooms[i] = new Room;
//				rooms[i]->LoadRoom(roomName);
//			}
//			rooms[totalRooms] = nullptr;
//			fin.close();
//		}
//	}
//	/// <summary>
//	/// Starts the game by taking to the maze of a room
//	/// </summary>
//	void Play()
//	{
//		int i = 0;
//		int idx = 0;
//		while ((checker!=3)&& (checker != 4)) //checking ending conditions
//		{
//			if (checker == 0)
//			{
//				srand(time(0));
//				idx = rand() % totalRooms;
//				rooms[idx]->Maze();
//				roomNos.push(idx);
//			}
//			if (checker == 1) //checking gasper condition
//			{
//				checker = 0;
//				while (i < totalRooms)
//				{
//					if (rooms[i]->SearchT()) 
//					{
//						roomNo = 1;
//						rooms[i]->Maze();
//					}
//					i++;
//				}
//			}
//			if (checker == 2) //checking portal condition
//			{
//				checker = 0;
//				cout << "Coin is flipped" << endl;
//				srand(time(0));
//				int coin = rand() % 2;
//				if (coin == 0) //checking if coin gave head or tail
//				{
//					cout << "You got tail" << endl;
//					if (roomNo == 0)
//					{
//						cout << "You have been kicked out" << endl;
//						checker = 3;
//					}
//					else //moving to previous room
//					{
//						roomNos.pop(roomNo);
//						rooms[roomNo]->Maze();
//						roomNos.push(roomNo);
//					}
//				}
//				else //moving to random room
//				{
//					cout << "You got head" << endl;
//					roomNo = 1;
//					srand(time(0));
//					idx = rand() % totalRooms;
//					rooms[idx]->Maze();
//					roomNos.push(idx);
//				}
//			}
//			if (checker == 4) //checking treasure condition
//			{
//				for (int i = (totalRooms - 1); i >= 0; i--)
//				{
//					rooms[i]->Pop();
//				}
//			}
//		}
//	}
//};
//int main()
//{
//	HauntedHouse h;
//	h.LoadData("hauntedhouse.txt");
//	h.Play();
//	system("pause");
//	return 0;
//}