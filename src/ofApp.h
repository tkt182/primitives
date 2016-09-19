#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
        ofVboMesh _yuka, _tenjyo;
        int _polygonNum;
        deque<ofVec3f> yuka_points;
    
        ofBoxPrimitive _box;
        ofEasyCam _cam;
        float _baseZ;
        float _zMove;
        float _zMove2[400];

        //current state of the rotation
        ofQuaternion curRot;
    
        //a place to store the mouse position so we can measure incremental change
        ofVec2f lastMouse;
    
        //slows down the rotation 1 = 1 degree per pixel
        float dampen;

};
