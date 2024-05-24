#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <string>
#include "main.h"
#include "sqlite3.h"

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees.AncestorVCL"
#pragma link "VirtualTrees.BaseAncestorVCL"
#pragma link "VirtualTrees.BaseTree"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	tree->NodeDataSize = sizeof(Entry);
}
//---------------------------------------------------------------------------
void Zapoln(sqlite3 *data_base, TVirtualStringTree *tree)
{
	tree->Clear();

	sqlite3_stmt *pStatement;
	int rc = sqlite3_prepare_v2(data_base, "SELECT id, datetime(last_visit_time/1000000-11644473600,'unixepoch','localtime'), url, title, visit_count FROM urls;", -1, &pStatement, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(data_base) << std::endl;
		return;
	}

	while(true)
	{
		int step = sqlite3_step(pStatement);

		if(step != SQLITE_ROW) { break; }

		PVirtualNode Nowentry = tree->AddChild(tree->RootNode);
		Entry *data = (Entry*)tree->GetNodeData(Nowentry);

		data->id = sqlite3_column_int(pStatement, 0);
		data->date = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 1));
		data->url = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 2));
		data->title = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 3));
		data->visit_count = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 4));
	}
	
	sqlite3_finalize(pStatement);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Open_fileClick(TObject *Sender)
{
	wstring file;

	if(file_open->Execute()){
	   file = file_open->FileName.c_str();
	   sqlite3_open16(file.c_str(), &data_base);
	}

	Zapoln(data_base, tree);
}

//---------------------------------------------------------------------------
void DeleteZap(Entry* Data, sqlite3* data_base)
{
	sqlite3_stmt* pos;
	string query = "DELETE FROM urls WHERE (id = "+to_string(Data->id)+");";
	sqlite3_prepare_v2(data_base, query.c_str(), -1, &pos, NULL);
	sqlite3_step(pos);
	sqlite3_finalize(pos);
}

void __fastcall TForm1::DeletefileClick(TObject *Sender)
{
	DeleteZap(Nowdata, data_base);
	tree->DeleteNode(NowEntry);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::get_text(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)
{
	Entry *data = (Entry*)Sender->GetNodeData(Node);
	if (Column == 0) { CellText = data->url; return; }
	else if (Column == 1) { CellText = data->title; return; }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::add_to_selection(TBaseVirtualTree *Sender, PVirtualNode Node)
{
	Nowdata = (Entry*)Sender->GetNodeData(Node);
	label->Caption = UnicodeString("Дополнительная информация \nПоследнее время посещения: ") + Nowdata->date + UnicodeString("\nКоличество посещений: ") + Nowdata->visit_count;
}
//---------------------------------------------------------------------------

