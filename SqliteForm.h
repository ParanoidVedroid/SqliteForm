//---------------------------------------------------------------------------

#ifndef SqliteFormH
#define SqliteFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.hpp"
//---------------------------------------------------------------------------
 typedef struct
 {
   int id;
   UnicodeString URL;
   UnicodeString Title;
 }TableStructure;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *Table;
	TButton *OpenDB;
	TButton *DeleteItem;
	TButton *ClearTable;
	void __fastcall OpenDBClick(TObject *Sender);
	void __fastcall OnGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall DeleteItemClick(TObject *Sender);
	void __fastcall ClearTableClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
