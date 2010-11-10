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
			addPadding(0,0,0,10); addKey('a'); addKey('s'); addKey('d'); addKey('f'); addKey('g'); addKey('h'); addKey('j'); addKey('k'); addKey('l'); addKey(';'); addKey('\''); addKey(OF_KEY_RETURN); newRow();
			addPadding(0,0,0,20); addKey('z'); addKey('x'); addKey('c'); addKey('v'); addKey('b'); addKey('n'); addKey('m'); addKey(','); addKey('.'); addKey('/'); newRow();
			break;
	}
}

//--------------------------------------------------------------
void ofxSoftKeyboard::reset() {
	keys.clear();
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKeyboard::addKey(char c) {
	
	keys.push_back( ofxSoftKey(c) );
	keys.back().setPadding(padding, padding, padding, padding);
	return keys.back();
}

//--------------------------------------------------------------
void ofxSoftKeyboard::newRow() {
	
	keys.back().isLastInRow = true;
}

//--------------------------------------------------------------
void ofxSoftKeyboard::addPadding(int top, int right, int bottom, int left) {
	
	keys.back().setPadding(padding+top, padding+right, padding+bottom, padding+left);
}

//--------------------------------------------------------------
void ofxSoftKeyboard::draw(float x, float y) {
	
	int j=0;
	int xpos = x;
	int ypos = y;
	for(int i=0; i<keys.size(); i++)
	{
		keys[i].setPos(xpos, ypos);
		keys[i].draw();
		if(keys[i].isLastInRow ) {
			j++;
			xpos =  x;
			ypos += keys[i].height+ keys[i].padding[PADDING_BOTTOM];
		} else {
			xpos += keys[i].width;
		}
		
		xpos +=  keys[i].padding[PADDING_RIGHT];
	}
}