/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKey.h"

#pragma mark CONSTRUCTORS

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(int _key, ofBaseApp* _testapp) {
	
	testapp = _testapp;
	key = _key;
	
	
	
	textColor = ofColor(0);
	textBGColor = ofColor(204);
	borderColor = ofColor(0);
	hoverColor = ofColor(153);
	clickColor = ofColor(255, 0, 0);
	isLastInRow = false;
	
	disableAppEvents();
	enableMouseEvents();
	
	padding = new int[4];
	setPadding(5, 5, 5, 5);

	switch(_key) {
		case OFXSK_KEY_SHIFT:
			label = "shift";
			setSize(115, 40);
			break;
		case OFXSK_KEY_TAB: 
			label = "tab";
			setSize(70, 40);
			break;
		case OFXSK_KEY_CAPS: 
			label = "caps";
			setSize(85, 40);
			break;
		case OFXSK_KEY_DELETE: 
			label = "delete";
			setSize(85, 40);
			break;
		case OFXSK_KEY_RETURN: 
			label = "return";
			setSize(85, 40);
			break;
		case OFXSK_KEY_AT:
			label = "@";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTCOM:
			label = ".COM";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTNET:
			label = ".NET";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTORG:
			label = ".ORG";
			setSize(40, 40);
			break;
		default:
			label = string(1, key);
			setSize(40, 40);
			break;
	}
}


#pragma mark PADDING

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setPadding(int top, int right, int bottom, int left) {
	padding[OFXSK_PADDING_TOP] = top;
	padding[OFXSK_PADDING_RIGHT] = right;
	padding[OFXSK_PADDING_BOTTOM] = bottom;
	padding[OFXSK_PADDING_LEFT] = left;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padLeft(int left) {
	padding[OFXSK_PADDING_LEFT] += left;
	return *this;
}
	
//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padRight(int right) {
	padding[OFXSK_PADDING_RIGHT] += right;
	return *this;
}



#pragma mark APP EVENTS



//--------------------------------------------------------------
void ofxSoftKey::draw() {
	
	// Draw the background
	ofFill();
	if(isMouseOver()) ofSetColor(hoverColor);
	else ofSetColor(textBGColor);
	ofRect(x, y, width, height);
	
	// Draw the outline.
	ofNoFill();
	ofSetColor(borderColor);
	ofRect( x, y, width, height );
	
	// Draw the actual letter
	ofSetColor(textColor);
	ofDrawBitmapString(label, x+10, y+height-10);

}




#pragma mark SETTERS

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setKey(char key) {
	this->key = key;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextColor(ofColor c) {
	this->textColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextBGColor(ofColor c) {
	this->textBGColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setBorderColor(ofColor c) {
	this->borderColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setHoverColor(ofColor c) {
	this->hoverColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setClickColor(ofColor c) {
	this->clickColor = c;
	return *this;
}



#pragma mark MOUSE INTERACTION


//--------------------------------------------------------------
void ofxSoftKey::onPress(int x, int y, int button) {
	
	
	switch(key) {
		case OFXSK_KEY_SHIFT:
			
			break;
		case OFXSK_KEY_TAB: 
			testapp->keyPressed('\t');
			break;
		case OFXSK_KEY_CAPS: 
			
			break;
		case OFXSK_KEY_DELETE: 
			testapp->keyPressed(OF_KEY_BACKSPACE);
			break;
		case OFXSK_KEY_RETURN: 
			testapp->keyPressed('\n');
			break;
		case OFXSK_KEY_AT:
			testapp->keyPressed('@');
			break;
		case OFXSK_KEY_DOTCOM:
			testapp->keyPressed('.');
			testapp->keyPressed('c');
			testapp->keyPressed('o');
			testapp->keyPressed('m');
			break;
		case OFXSK_KEY_DOTNET:
			testapp->keyPressed('.');
			testapp->keyPressed('n');
			testapp->keyPressed('e');
			testapp->keyPressed('t');
			break;
		case OFXSK_KEY_DOTORG:
			testapp->keyPressed('.');
			testapp->keyPressed('o');
			testapp->keyPressed('r');
			testapp->keyPressed('g');
			break;
		default:
			testapp->keyPressed((int)key);
			break;
	}
	//ofNotifyEvent(ofEvents.keyPressed, (int)key, testapp);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button) {
	
	switch(key) {
		case OFXSK_KEY_SHIFT:
			
			break;
		case OFXSK_KEY_TAB: 
			testapp->keyReleased('\t');
			break;
		case OFXSK_KEY_CAPS: 
			
			break;
		case OFXSK_KEY_DELETE: 
			testapp->keyReleased(OF_KEY_BACKSPACE);
			break;
		case OFXSK_KEY_RETURN: 
			testapp->keyReleased('\n');
			break;
		case OFXSK_KEY_AT:
			testapp->keyReleased('@');
			break;
		case OFXSK_KEY_DOTCOM:
			testapp->keyReleased('.');
			testapp->keyReleased('c');
			testapp->keyReleased('o');
			testapp->keyReleased('m');
			break;
		case OFXSK_KEY_DOTNET:
			testapp->keyReleased('.');
			testapp->keyReleased('n');
			testapp->keyReleased('e');
			testapp->keyReleased('t');
			break;
		case OFXSK_KEY_DOTORG:
			testapp->keyReleased('.');
			testapp->keyReleased('o');
			testapp->keyReleased('r');
			testapp->keyReleased('g');
			break;
		default:
			testapp->keyReleased((int)key);
			break;
	}
	//ofNotifyEvent(ofEvents.keyReleased, (int)key, testapp));
}

//--------------------------------------------------------------
void ofxSoftKey::onReleaseOutside(int x, int y, int button) {

}
