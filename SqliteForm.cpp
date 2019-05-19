//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SqliteForm.h"
#include "sqlite3.h";

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
 sqlite3* OpenHistory()
 {
	sqlite3 *history = NULL;
	sqlite3_open("History", &history);
	if (history == NULL)
	{
		throw Exception("Error opening History");
	}
	return history;
}
		//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Table->NodeDataSize=sizeof(TableStructure);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenDBClick(TObject *Sender)
{
	sqlite3 *history = OpenHistory();

	const char *openQuery = "select id, url, title from urls";
	sqlite3_stmt *query;
	int resultPreparingQuery = sqlite3_prepare_v2(history, openQuery, -1, &query, NULL);

	if (resultPreparingQuery != SQLITE_OK) {
		throw Exception("Error preparing query");
	}

	Table->Clear();
	int resultQuery = sqlite3_step(query);
	while (resultQuery == SQLITE_ROW) {
		PVirtualNode entryNode = Table->AddChild(Table->RootNode);
		TableStructure *sqlItem = (TableStructure*)Table->GetNodeData(entryNode);
		sqlItem->id = sqlite3_column_int(query, 0);
		sqlItem->URL = (wchar_t*)sqlite3_column_text16(query, 1);
		sqlItem->Title = (wchar_t*)sqlite3_column_text16(query, 2);
		resultQuery = sqlite3_step(query);
	}

	sqlite3_close(history);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
		  TVSTTextType TextType, UnicodeString &CellText)
{
   if (!Node) return;
	TableStructure *sqlRow = (TableStructure*)Sender->GetNodeData(Node)	;
	switch (Column) {
		case 0: CellText = sqlRow->id; break;
		case 1: CellText = sqlRow->URL; break;
		case 2: CellText = sqlRow->Title; break;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteItemClick(TObject *Sender)
{
	sqlite3 *history = OpenHistory();
	PVirtualNode selectedItem = Table->FocusedNode;
	TableStructure *sqlItem = (TableStructure*)Table->GetNodeData(selectedItem);
	int itemIndex = sqlItem->id;

	const char *deleteQuery = "delete from urls where id=?";
	sqlite3_stmt *deleteItem;
	int resultPreparingDeleteItem = sqlite3_prepare_v2(history, deleteQuery, -1, &deleteItem, NULL);
	sqlite3_bind_int(deleteItem, 1, itemIndex);

	if (resultPreparingDeleteItem != SQLITE_OK) {
		throw Exception("Error preparing query");
	}
	else {
		int resultStep = sqlite3_step(deleteItem);

	}

	Table->DeleteNode(selectedItem);

	sqlite3_close(history);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearTableClick(TObject *Sender)
{
	sqlite3 *history = OpenHistory();
	const char *clearTable = "delete from urls";
	int resultClearTable = sqlite3_exec(history, clearTable, NULL, NULL, NULL);

	if (resultClearTable != SQLITE_OK) {
		throw Exception("Error clearing history");;
	}


	Table->Clear();
	ClearTable->Visible = 0;

	sqlite3_close(history);
}
//---------------------------------------------------------------------------
