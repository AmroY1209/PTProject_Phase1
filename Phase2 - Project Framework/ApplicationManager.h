#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxSelecCount = 40 };
	//Max no of figures

private:

	int FigCount;		//Actual number of figures
	int SelecFigCount;	//selected figure counter
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFigList[MaxSelecCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure** Clipboard;      //Clipboard which the selected figures will be copied/cut to (array of pointers)
	int TempCount;
	//CFigure* Clipboard[MaxSelecCount];
	int ClipboardCount;
	bool IsInClipboard;      //Used to check that there is a figure in clipboard or not
	bool IsFigCut;           //To know whether the figure in Clipboard is cut or copied

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void AddSelectedFigure(CFigure* s);
	void UNSelectFigure(CFigure* s);
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	CFigure* *GetSelectedFigs();
	int  GetSelectedCount();
	void clearselcFig();
	void OnlyclearselcFig();  //Only clears selected figure without selected figure count

	void removeFig(int id);
	CFigure** GetDrawnFigs();      //Gets the list of drawn figures
	int GetFigCount();             //Gets the number of actual drawn figures
	void ClearFigList();                //Deletes all figures in the list of figures

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void UpdateInterface_PlayMode() const; //Redraws all the drawing window in the play mode
	virtual void printinfo(CFigure* s);

	// -- Clipboard Functions
	void SetClipboard(CFigure**);
	CFigure** GetClipboard();
	void ClearClipboard();  //Clears Clipboard shakly msh mehtagha khals
	void SetIsFigCut(bool);
	bool GetIsFigCut();    //To know whether the figure in Clipboard is cut or copied
	void SetCount(int x);
	int GetCount();
};

#endif