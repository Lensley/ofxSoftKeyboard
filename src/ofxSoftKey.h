/*
 *  ofxSoftKey.h
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef _OFX_SOFTKEY
#define _OFX_SOFTKEY

#define OFXSK_PADDING_TOP		0
#define OFXSK_PADDING_RIGHT		1
#define OFXSK_PADDING_BOTTOM	2
#define OFXSK_PADDING_LEFT		3

#define OFXSK_SPECIAL_KEYS 9999
#define OFXSK_KEY_SHIFT 10000
#define OFXSK_KEY_TAB 10001
#define OFXSK_KEY_CAPS 10002
#define OFXSK_KEY_DELETE 10003
#define OFXSK_KEY_RETURN 10004
#define OFXSK_KEY_AT 10005
#define OFXSK_KEY_DOTCOM 10100
#define OFXSK_KEY_DOTNET 10101
#define OFXSK_KEY_DOTORG 10102

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class testApp;
class ofxSoftKey : public ofxMSAInteractiveObject {
public:
	
	bool isLastInRow;
	int* padding;
	
	ofxSoftKey(int key, ofBaseApp* testapp);

	ofxSoftKey& setPadding(int top, int right, int bottom, int left);
	ofxSoftKey& padLeft(int left);
	ofxSoftKey& padRight(int right);
	
	ofxSoftKey& setKey(const char key);
	ofxSoftKey& setTextColor(ofColor c);
	ofxSoftKey& setTextBGColor(ofColor c);
	ofxSoftKey& setBorderColor(ofColor c);
	ofxSoftKey& setHoverColor(ofColor c);
	ofxSoftKey& setClickColor(ofColor c);
	
	//void setup();
	//void update();
	void draw();
	//void exit();
	
	//void onRollOver(int x, int y);
	//void onRollOut();
	//void onMouseMove(int x, int y);
	//void onDragOver(int x, int y, int button);
	//void onDragOutside(int x, int y, int button);
	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);
	void onReleaseOutside(int x, int y, int button);
	//void keyPressed( int key );
	//void keyReleased( int key );

protected:
	
	ofBaseApp* testapp;
	int key;
	string label;
	ofColor textColor, textBGColor, borderColor, hoverColor, clickColor;
	
	
};

#endif