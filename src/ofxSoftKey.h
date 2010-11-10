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

#define PADDING_TOP 0
#define PADDING_RIGHT 1
#define PADDING_BOTTOM 2
#define PADDING_LEFT 3

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"


class ofxSoftKey : public ofxMSAInteractiveObject {
public:
	
	bool isLastInRow;
	int* padding;
	
	ofxSoftKey(char key);

	void setPadding(int top, int right, int bottom, int left);
	
	ofxSoftKey& setKey(const char key);
	ofxSoftKey& setTextColor(int c);
	ofxSoftKey& setTextBGColor(int c);
	ofxSoftKey& setBorderColor(int c);
	ofxSoftKey& setHoverColor(int c);
	ofxSoftKey& setClickColor(int c);
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void onRollOver(int x, int y);
	void onRollOut();
	void onMouseMove(int x, int y);
	void onDragOver(int x, int y, int button);
	void onDragOutside(int x, int y, int button);
	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);
	void onReleaseOutside(int x, int y, int button);
	void keyPressed( int key );
	void keyReleased( int key );

protected:
	
	char key;
	int textColor, textBGColor, borderColor, hoverColor, clickColor;
	
	
};

#endif