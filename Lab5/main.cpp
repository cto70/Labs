#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std :: string;
using std :: vector;
using std :: ofstream;
using std :: ifstream;
using std :: cout;
using std :: cin;
using std :: endl;
using std :: getline;
void ReadFile( vector< string >& VectorData, const string& FileName )
{
    ifstream fin( FileName );
    if( ! fin.is_open( ) )
    {
    cout << "Can't open file " + FileName << endl;
    exit( 1 );
    }
    string s;
    while( getline( fin, s ))
    {
        VectorData.push_back( s );
    }
    fin.close();
}
void PrintFile( const vector< string >& data, string FileName )
{
    ofstream fout( FileName );
    if( ! fout.is_open() )
    {
        cout  << "Can't open file " + FileName;
        exit( 1 );
    }
    for( auto i : data )
    {
        fout << i << endl;
    }
    fout.close();
}
void PrintVector( const vector< string >& data )
{
    for( auto i : data )
    {
        cout << i << endl;
    }
}
vector< string > Merge( const vector< string >& Vector1, const vector< string >& Vector2)
{
    int i = 0;
    int j = 0;
    vector< string > get;
    while( i < Vector1.size() && i < Vector2.size() )
    {
        if( Vector1[ i ] <= Vector2[ j ] )
        {
            get.push_back( Vector1[ i ] );
            i++;
        }
        else
        {
            get.push_back( Vector2[ j ] );
            j++;
        }
    }
    if( i == Vector1.size() )
    {
        while( j < Vector2.size() )
        {
            get.push_back( Vector2[ j ] );
            j++;
        }
    }
    else
    {
        while( i < Vector1.size() )
        {
            get.push_back( Vector1[ i ] );
            i++;
        }
    }
    return get;
}
int main() {
    string FileName1 = "TestFile1.txt";
    string FileName2 = "TestFile2.txt";
    string FileName3 = "TestFile3.txt";
    vector< string > VectorData1;
    ReadFile( VectorData1, FileName1 );
    cout << "Data from first file" << endl;
    PrintVector( VectorData1 );
    if( VectorData1.size() == 0 )
    {
        cout << "First file is empty" << endl;
    }
    vector< string > VectorData2;
    ReadFile( VectorData2, FileName2 );
    cout << "Data from second file" << endl;
    PrintVector( VectorData2 );
    if( VectorData2.size() == 0 )
    {
        cout << "Second file is empty" << endl;
    }
    vector< string > VectorData3 = Merge( VectorData1, VectorData2 );
    PrintFile( VectorData3, FileName3 );
    cout << "Result file" << endl;
    PrintVector( VectorData3 );
    if( VectorData3.size() == 0 )
    {
        cout << "Result file is empty" << endl;
    }
}
