/* Write a menu driven program to implement the following sparse matrices using 
1 dimensional array 
(a) Diagonal matrix
(b) Lower triangular Matrix
(c) Upper triangular Matrix
(d) Symmetric Matrix
(e) Tridiagonal Matrix
*/

/*Header Files included*/

#include <iostream>
#include <math.h>

using namespace std;

//Class named "sprase" which will contain all the methods

class sparse
{
    //private members

    int sp[4][4], temp[20];
    // made 2 arrays -> 1. For 2d matrices 2. For 1d alternative arrays
    int n;

public:
    //constructor
    sparse()
    {
        n = 0;
    }

    //insert member function to insert values in the 2d arrays..
    void insert(int m)
    {
        cout << "Enter the sparse matrix:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                cin >> sp[i][j];
    }

    //main diagonal function to map 2d diagonal matrix into 1d array
    void diagonal(int m)
    {
        int n = 0;

        //mapping loops
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    temp[n] = sp[i][j];
                    n++;
                }
            }
        }
        cout << "The resulting matrix is:\n";
        //printing the resulting matrix
        for (int i = 0; i <= n - 1; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    //main lower triangular matrix function to map the 2d array into the 1d array
    void ltm(int m, int n)
    {
        sp[20][20] = {};

        int k = 0; // for storing the mapping value

        //mapping loops
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                k = (i * (i + 1) / 2) + j;
                if ((sp[i][j] != 0) & (i >= j))
                {
                    temp[k] = sp[i][j];
                }
            }
        }

        cout << "The resulting matrix is:\n";
        //printing the resulting matrix
        for (int i = 0; i <= n - 1; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    //main upper triangular matrix function to map the 2d array into the 1d array
    void utm(int m, int n)
    {
        sp[20][20] = {};

        int k = 0; // for storing the mapping value

        //mapping loops
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                k = m * i - (i * (i - 1) / 2) + (j - i);
                if ((sp[i][j] != 0) & (i <= j))
                {
                    temp[k] = sp[i][j];
                }
            }
        }

        cout << "The resulting matrix is:\n";
        //printing the resulting matrix
        for (int i = 0; i <= n - 1; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    //main symmetric matrix function to map the 2d array into the 1d array
    void sym(int m, int n)
    {
        sp[20][20] = {};

        int k = 0; // for storing the mapping value

        //mapping loops
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                k = m * i - (i * (i - 1) / 2) + (j - i);
                if ((sp[i][j] != 0) & (i <= j))
                {
                    temp[k] = sp[i][j];
                }
            }
        }

        cout << "The resulting matrix is:\n";
        //printing the resulting matrix
        for (int i = 0; i <= n - 1; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    //main tridiagonal matrix function to map the 2d array into the id array
    void trid(int m, int n)
    {
        sp[20][20] = {};

        int k = 0; //for storing the mapping value

        //mapping loops
        //for lower diagonal
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i - j) == 1)
                {
                    k = j;
                    temp[k] = sp[i][j];
                }
            }
        }

        //for main diagonal
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i - j) == 0)
                {
                    k = m + i - 1;
                    temp[k] = sp[i][j];
                }
            }
        }

        //for upper diagonal
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                if ((j - i) == 1)
                {
                    k = 2 * m + i - 1;
                    temp[k] = sp[i][j];
                }
            }
        }

        cout << "The resulting matrix is:\n";
        //printing the resulting matrix
        for (int i = 0; i <= n - 1; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

}; //Class ends here

//Main starts here
int main()
{
    int n, cho, m, ctr = 0, temp;
    char ch;

    //do-while loop for making it menu driven .
    do
    {
        sparse s1; //object created

        //menu layout
        cout << "What u want to make:\n1.diagonal\n2.lower triangular\n3.upper triangular\n4.symmetric\n5.tridiagonal matrix\n6.restart\n";
        cin >> cho;

        //switch statement for exact case comparison
        switch (cho)
        {
        //case for diagonal matrix
        case 1:
            cout<<"Enter the order of the matrix"<<endl;
            cin>>m;
            s1.insert(m);
            s1.diagonal(m);
            break;

        //case for Lower triangular matrix
        case 2:
            cout << "Enter the order of matrix:\n";
            cin >> m;
            temp = m;
            ctr = 0;
            //for finding non zero values
            while (temp > 0)
            {
                ctr += temp;
                temp--;
            }
            cout << "number of non zero elements are = " << ctr << endl;
            s1.insert(m);
            s1.ltm(m, ctr);
            break;

        //for upper triangular matrix
        case 3:
            cout << "Enter the order of matrix:\n";
            cin >> m;
            temp = m;
            ctr = 0;
            //for finding non zero values
            while (temp > 0)
            {
                ctr += temp;
                temp--;
            }
            cout << "number of non zero elemnets are = " << ctr << endl;
            s1.insert(m);
            s1.utm(m, ctr);
            break;

        //for symmetric matrices
        case 4:
            cout << "Enter the order of matrix:\n";
            cin >> m;
            temp = m;
            ctr = 0;
            //for finding the number of repeated  values bellow the digonal and above
            while (temp > 0)
            {
                ctr += temp;
                temp--;
            }
            cout << "the repeated values above the diagonal and bellow = " << ctr << endl;
            s1.insert(m);
            s1.sym(m, ctr);
            break;
        
        //for tridiagonal matrix
        case 5:
            cout << " Enter the order of matrix:\n";
            cin >> m;
            temp = m;
            ctr = 0;

            /*number of elements
             we could have also used formula i.e. " 3m * 2" which will give us the 
            exact number but as i have used this approach everywhere so i am just 
            following the same approach for the sake of simplicity for the readers
             hope you understand.*/
            while (temp > 0)
            {
                ctr += temp;
                temp--;
            }
            cout << "the no of elements non zero are =" << ctr << endl;
            s1.insert(m);
            s1.trid(m, ctr);
            break;

        //for restarting again
        case 6:
            continue;
            break;
        
        //default goes here
        default:
            cout << "Enter choice from 1 to 5 only:\n";
        }
        cout << "Want to enter more:\n";
        cin >> ch;
    } while (ch == 'y'); //do-while loop ends here
    return 0;
} //int main () ends here
