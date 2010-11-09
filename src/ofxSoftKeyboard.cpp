/*
 *  ofxSoftKeyboard.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKeyboard.h"

ofxSoftKeyboard::ofxSoftKeyboard() {

	padding = 10;
	setLayout(OFXSK_LAYOUT_KEYBOARD_FULL);
}

//--------------------------------------------------------------
ofxSoftKeyboard::~ofxSoftKeyboard() {
	
	// TO DO:  delete keys
	for(int i=0; i<keys.size(); i++) {
		//delete keys[i];
	}
}

//--------------------------------------------------------------
void ofxSoftKeyboard::setLayout(int layout) {
	
	reset();
	
	switch(layout) {
		case OFXSK_LAYOUT_KEYPAD:
			addKey('1'); addKey('2'); addKey('3'); newRow();
			addKey('4'); addKey('5'); addKey('6'); newRow();
			addKey('7'); addKey('8'); addKey('9'); newRow();
			addKey('*'); addKey('0'); addKey('#');
			break;
		case OFXSK_LAYOUT_KEYBOARD_FULL:
			addKey('q'); addKey('w'); addKey('e'); addKey('r'); addKey('t'); addKey('y'); addKey('u'); addKey('i'); addKey('o'); addKey('p'); addKey('['); addKey(']'); newRow();
			addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OF_KEY_RETURN); newRow();
			addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('/'); newRow();
			break;
	}
}

//--------------------------------------------------------------
void ofxSoftKeyboard::reset() {
	keys.clear();
	newlines.clear();
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKeyboard::addKey(char c) {
	
	ofxSoftKey* key = new ofxSoftKey(c);
	keys.push_back( key );
	return *key;
}

//--------------------------------------------------------------
void ofxSoftKeyboard::newRow() {
	newlines.push_back( keys.size()-1 );
}


//--------------------------------------------------------------
void ofxSoftKeyboard::draw(float x, float y) {
	
	int j=0;
	int xpos = x;
	int ypos = y;
	for(int i=0; i<keys.size(); i++)
	{
		keys[i]->setPos(xpos, ypos);
		keys[i]->draw();
		if(i==newlines[j]) {
			cout << "new line!" << endl;
			j++;
			xpos =  x;
			ypos += keys[i]->height + padding;
		} else {
			xpos += keys[i]->width + padding;
		}
		
	}
}