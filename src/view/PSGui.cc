#include "PSGui.h"
#include "PayStationImpl.h"
#include "AlphaTownFactory.h"
#include "BetaTownFactory.h"
#include "GammaTownFactory.h"

#include <sstream>
#include <iomanip>


// static member variables initialization and declaration
Fl_Window * PSGui::win = NULL; 
Fl_Output * PSGui::out = NULL;
PayStation PSGui::ps = NULL;

PSGui::PSGui() {
	// Paystation software configuration
	ps = new PayStationImpl(new AlphaTownFactory);
	// Gui configuration
	win = new Fl_Window(205, 190, "Pay Station");
	// menus
	Fl_Menu_Bar * menuBar = new Fl_Menu_Bar(0,0, win->w(), 25);
	menuBar->add("Variant Selection/Alphatown", 0/*no shortcut*/,
							 menuAlpha, NULL, FL_MENU_RADIO | FL_MENU_VALUE);
	menuBar->add("Variant Selection/Betatown", 0/*no shortcut*/,
							 menuBeta, NULL, FL_MENU_RADIO);
	menuBar->add("Variant Selection/Gammatown", 0/*no shortcut*/,
							 menuGamma, NULL, FL_MENU_RADIO);
	// buttons
	Fl_Button * b5c = new Fl_Button(5,30, 70, 30, "5 cents");
	b5c->callback(cb5cents);
	Fl_Button * b10c = new Fl_Button(5,65, 70, 30, "10 cents");
	b10c->callback(cb10cents);
	Fl_Button * b25c = new Fl_Button(5,100, 70, 30, "25 cents");
	b25c->callback(cb25cents);

	out = new Fl_Output(80, 30, 120, 30);

	Fl_Button * buy = new Fl_Button(5, 155, 95, 30, "BUY");
	buy->callback(cbBuy);
	Fl_Button * cancel = new Fl_Button(105, 155, 95, 30, "CANCEL");
	cancel->callback(cbCancel);
	
	updateDisplay();
	win->end();
}


void PSGui::show() {
	if (win != NULL)
		win->show();
}


// the callbacks

void PSGui::cb5cents(Fl_Widget* w, void * d) {
	ps->addPayment(5);
	updateDisplay();
}

void PSGui::cb10cents(Fl_Widget* w, void * d) {
	ps->addPayment(10);
	updateDisplay();
}

void PSGui::cb25cents(Fl_Widget* w, void * d) {
	ps->addPayment(25);
	updateDisplay();
}

void PSGui::cbBuy(Fl_Widget* w, void * d) {
	Receipt receipt = ps->buy();
	std::ostringstream ostr;
	receipt->print(ostr);
	fl_alert(ostr.str().c_str());
	delete receipt;
	updateDisplay();
}

void PSGui::cbCancel(Fl_Widget* w, void * d) {
	ps->cancel();
	updateDisplay();
}

void PSGui::menuAlpha(Fl_Widget* w, void * d) {
	if (ps != NULL)
		delete ps;
	ps = new PayStationImpl(new AlphaTownFactory);
	updateDisplay();
}

void PSGui::menuBeta(Fl_Widget* w, void * d) {
	if (ps != NULL)
		delete ps;
	ps = new PayStationImpl(new BetaTownFactory);
	updateDisplay();
}

void PSGui::menuGamma(Fl_Widget* w, void * d) {
	if (ps != NULL)
		delete ps;
	ps = new PayStationImpl(new GammaTownFactory);
	updateDisplay();
}


void PSGui::updateDisplay() {
	std::ostringstream ostr;
	ostr << std::setfill('0') << std::setw(4) << ps->readDisplay();
	out->value(ostr.str().c_str());
}
