#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Table
{
  private :
    vector<int> LineCount; //number of text lines in each row
    vector<int> maxchar; //max character at each column
    vector<vector<string>> array ;

     char leftUp = '╔';
     char vertical = '║';
     char rightUp = '╗';
     char rightDown = '╝';
     char horizontal = '═';
     char leftDown = '╚';
     char cross = '╬';
     char rightWing = '╠';
     char DownWing = '╦';
     char leftWing = '╣';
     char upWing = '╩';

   public:
   	Table(){
      array[0][0] = "";
    }
   	Table(int columns, int rows){
      for(int x=0; x<columns; x++){
        for(int y=0; y<rows; y++)
        {
          array[x][y]="";
        }
      }

    }

   	/**
   	 *  generate table with even columns
   	 *  you can use mutiline here :)
   	 *  its for lazy people to use insted of
   	 *  Table t = new Table();
   	 *  t.setContent([...]);
   	 *  t.draw();
   	 *
   	 *  u use
   	 *  Table t = new Table();
   	 * t.flatTable([...]);
   	 *
   	 * @param input_data
   	 */
   void flatTable(vector<vector<wstring>> &input_data){
     //local variables
     int LoopCounter = 0;
     int rowCounter = 0;
     int longestRow = 0;
     bool FRun = true;

     for(vector<wstring> input_datum  : input_data)
     {
       if(input_datum.size() > longestRow)
       {
         longestRow = input_datum.size();
       }
     }


   }

   private:
   	static int getColumnWidth(vector<vector<wstring>> &input_data, int col);
   	static vector<vector<wstring>> Split2dArray(vector<vector<wstring>> &array);
   	static int CalcHight(vector<vector<wstring>> &array);

   	/**
   	 * get back to default table style
   	 */
   public:
   	virtual void DefaultStyle();

   	/**
   	 *  generate all table using only one character
   	 * @param character
   	 */
   	virtual void ChangeStyleForOneCharacter(char character);

   	/**
   	 *  single line style [+ , -, |]
   	 */
   	virtual void SingleLineStyle();

   	/**
   	 * set your own style
   	 * @param leftUp
   	 */
   	virtual void setLeftUpCorner(char leftUp);
   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setVertical(char vertical);
   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setRightUpCorner(char rightUp);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setRightDownCorner(char rightDown);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setHorizontal(char horizontal);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setLeftDownCorner(char leftDown);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setCross(char cross);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setRightWing(char rightWing);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setDownWing(char downWing);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setLeftWing(char leftWing);

   	/**
   	 * set your own style
   	 *
   	 */
   	virtual void setUpWing(char upWing);

   	/**
   	 * draw content
   	 */
   	virtual void Draw();

   private:
   	int getMaxLengthOfArrayRows();

   	void extendArrayRows(vector<string> &row);

   	void extendArrayColumn(vector<string> &Col);

   	/**
   	 * add row at the bottom of the table
   	 * @param row
   	 */
   public:
   	virtual void addRow(vector<string> &row);

   	/**
   	 * add column at the end of table
   	 * @param col
   	 */
   	virtual void addColumn(vector<wstring> &col);

   	/**
   	 * set content of table (much faster than extending table)
   	 * @param content
   	 */
   	virtual void setContent(vector<vector<string>> &content);

   	/**
   	 * edit cell of table
   	 * @param column starts from 0
   	 * @param row starts from 0
   	 * @param text new content
   	 * @return returns if operation was succesfull
   	 */
   	virtual bool edit(int column, int row, const string &text);


   };
