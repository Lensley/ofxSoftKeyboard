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
#define OFXSK_LAYOUT_KEYBOARD_EMAIL 3

class testApp;

class ofxSoftKeyboard   {
public:
	ofxSoftKeyboard();
	~ofxSoftKeyboard();

	void setup( ofBaseApp* testapp, int layout );
	void setLayout(int layout);
	void addPadding(int top, int right, int bottom, int left);
	void reset();
	void draw(float x, float y);
	ofxSoftKey& addKey(int c);
	void newRow();

	void setPadding(int top, int right, int bottom, int left);
	void setTextColor(ofColor c);
	void setTextBGColor(ofColor c);
	void setBorderColor(ofColor c);
	void setHoverColor(ofColor c);
	void setClickColor(ofColor c);
	
	
protected:
	ofBaseApp* testapp;
	vector<ofxSoftKey*> keys;
	
};

#endif