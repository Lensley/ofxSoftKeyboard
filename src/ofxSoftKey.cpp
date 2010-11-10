/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKey.h"
#include "testApp.h"


#pragma mark CONSTRUCTORS

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(char _key, testApp* _testapp) {
	
	testapp = _testapp;
	
	setKey(_key);
	setSize(40, 40);
	
	textColor = 0x000000;;
	textBGColor = 0xCCCCCC;
	borderColor = 0x000000;
	hoverColor = 0x999999;
	clickColor = 0xFF0000;
	isLastInRow = false;
	
	disableAppEvents();
	enableMouseEvents();
	enableKeyEvents();
	
	padding = new int[4];
	setPadding(5, 5, 5, 5);
}

#pragma mark PADDING

//--------------------------------------------------------------
void ofxSoftKey::setPadding(int top, int right, int bottom, int left) {
	padding[PADDING_TOP] = top;
	padding[PADDING_RIGHT] = right;
	padding[PADDING_BOTTOM] = bottom;
	padding[PADDING_LEFT] = left;
}

//--------------------------------------------------------------
void ofxSoftKey::padLeft(int left) {
	padding[PADDING_LEFT] += left;
}
	
//--------------------------------------------------------------
void ofxSoftKey::padRight(int right) {
	padding[PADDING_RIGHT] += right;
}

#pragma mark APP EVENTS


//--------------------------------------------------------------
void ofxSoftKey::setup() {
	
}


//--------------------------------------------------------------
void ofxSoftKey::update() {
	
}


//--------------------------------------------------------------
void ofxSoftKey::draw() {
	
	// Draw the background
	ofFill();
	if(_mouseOver) ofSetColor(hoverColor);
	else ofSetColor(textBGColor);
	ofRect(x, y, width, height);
	
	// Draw the outline.
	ofNoFill();
	ofSetColor(borderColor);
	ofRect( x, y, width, height );
	
	// Draw the actual letter
	ofSetColor(textColor);
	ofDrawBitmapString(string(1, key), x+width-20, y+height-10);
}


//--------------------------------------------------------------
void ofxSoftKey::exit() {
	
}



#pragma mark SETTERS

//--------------------------------------------------------------
ofxSoftKey &ofxSoftKey::setKey(char key) {
	this->key = key;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey &ofxSoftKey::setTextColor(int c) {
	this->textColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey &ofxSoftKey::setTextBGColor(int c) {
	this->textBGColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey &ofxSoftKey::setBorderColor(int c) {
	this->borderColor = c;
	return *this;
}



#pragma mark MOUSE INTERACTION


//--------------------------------------------------------------
void ofxSoftKey::onRollOver(int x, int y) {
	cout << "over!" << endl;
}

//--------------------------------------------------------------
void ofxSoftKey::onRollOut() {

}

//--------------------------------------------------------------
void ofxSoftKey::onMouseMove(int x, int y) {

}

//--------------------------------------------------------------
void ofxSoftKey::onDragOver(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofxSoftKey::onDragOutside(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofxSoftKey::onPress(int x, int y, int button) {

	testapp->keyPressed((int)key);
	//ofNotifyEvent(ofEvents.keyPressed, (int)key, testapp);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button) {
	
	testapp->keyReleased((int)key);
	//ofNotifyEvent(ofEvents.keyReleased, (int)key, testapp));
}

//--------------------------------------------------------------
void ofxSoftKey::onReleaseOutside(int x, int y, int button) {

}


#pragma mark KEYBOARD INTERACTION

//--------------------------------------------------------------
void ofxSoftKey::keyPressed( int key ) {
	
}

//--------------------------------------------------------------
void ofxSoftKey::keyReleased( int key ) {
	

}