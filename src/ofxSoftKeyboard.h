/*
 *  ofxSoftKeyboard.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef _OFX_SOFTKEYBOARD
#define _OFX_SOFTKEYBOARD

#include "ofMain.h"
#include "ofxSoftKey.h"

#define OFXSK_LAYOUT_KEYPAD 1
#define OFXSK_LAYOUT_KEYBOARD_FULL 2

class ofxSoftKeyboard   {
public:
	ofxSoftKeyboard();
	~ofxSoftKeyboard();

	void setLayout(int layout);
	void reset();
	void draw(float x, float y);
	ofxSoftKey& addKey(char c);
	void newRow();
	
	
protected:
	
	int padding;
	vector<ofxSoftKey*> keys;
	vector<int> newlines;
};

#endif