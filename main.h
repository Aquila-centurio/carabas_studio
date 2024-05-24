#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.Dialogs.hpp>
#include "sqlite3.h"
//---------------------------------------------------------------------------
struct Entry
{
	int id;
	UnicodeString date;
	UnicodeString url;
	UnicodeString title;
	UnicodeString visit_count;
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *tree;
	TButton *Open_file;
	TButton *Deletefile;
	TOpenDialog *file_open;
	TLabel *label;
	void __fastcall Open(TObject *Sender);
	void __fastcall Open_fileClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DeletefileClick(TObject *Sender);
	void __fastcall add_to_selection(TBaseVirtualTree *Sender, PVirtualNode Node);
	void __fastcall get_text(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	sqlite3 *data_base;
	Entry *Nowdata; // текущая данные
	PVirtualNode NowEntry;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

