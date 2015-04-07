/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Paystation GUI using the FLTK library.
		Window containing all of the GUI widgets **/

#ifndef __PSGUI_H
#define __PSGUI_H

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include "PayStation.h"



class PSGui {
private:
	static Fl_Window * win;  ///< the window static object
	static Fl_Output * out;  ///< the output text box

	static PayStation ps;  ///< paystation object, static 

public:
	/// constructor. Size of window and placement of components
	/// is hard-coded here.
	PSGui();

	/// displays the GUI.
	void show();
	
	// various call back functions
private:
	static void cb5cents(Fl_Widget* w, void * d);

	static void cb10cents(Fl_Widget* w, void * d);

	static void cb25cents(Fl_Widget* w, void * d);

	static void cbBuy(Fl_Widget* w, void * d);

	static void cbCancel(Fl_Widget* w, void * d);

	static void menuAlpha(Fl_Widget* w, void * d);

	static void menuBeta(Fl_Widget* w, void * d);

	static void menuGamma(Fl_Widget* w, void * d);

	static void updateDisplay();

};

#endif
