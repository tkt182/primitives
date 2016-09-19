#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofHideCursor();
    
    //_cam.setFov(80.0f);
    _cam.setNearClip(0.1);
    
    //this slows down the rotate a little bit
    dampen = .4;
    
    _polygonNum = 300;
    _baseZ      = 150;
    
    _yuka.setUsage(GL_DYNAMIC_DRAW);
    _yuka.setMode(OF_PRIMITIVE_LINES);
    _yuka.getVertices().resize(_polygonNum * _polygonNum * 8);
    _tenjyo.setUsage(GL_DYNAMIC_DRAW);
    _tenjyo.setMode(OF_PRIMITIVE_LINES);
    _tenjyo.getVertices().resize(_polygonNum * _polygonNum * 8);
    
    _box.set(4);
    
    _zMove = 0;
    for(int i = 0; i < 400; i++){
        _zMove2[i] = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    _cam.begin();
    _cam.setFov(40.0f);
    _cam.setPosition(0, 0, 10);
    //_cam.lookAt(ofVec3f(0), ofVec3f(0, -1, 0));
    _cam.setTarget(ofVec3f(0, 0, 20));
    //_cam.setTarget(ofVec3f(0));
    
    int i, j, k = 0;
    ofPushMatrix();
    
    ofVec3f axis;
    float angle;
    curRot.getRotate(angle, axis);
    ofRotate(angle, axis.x, axis.y, axis.z);  
    /*
    ofMatrix4x4 matrix;
    angle = rollCam.getAngle();
    matrix.makeRotationMatrix(angle, rollCam.getPosN(), angle, rollCam.getPosS(), angle, rollCam.getPosT());
    */
     
    for(i = 0; i < _polygonNum; i++){
        
        float z;
        z = _zMove2[i] + _baseZ;
        //cout << _zMove2[i] << endl;
        
        for(j = 0; j < _polygonNum; j++){
            ofVec3f p1, p2, p3, p4;
            ofVec3f q1, q2, q3, q4;
            //p1 = ofVec3f((float)(i - _polygonNum / 2), 4.0, (float)(j - _polygonNum / 2) - _zMove + _baseZ);
            //p2 = ofVec3f((float)(i - _polygonNum / 2), 4.0, (float)(j + 1 - _polygonNum / 2) - _zMove + _baseZ);
            //p3 = ofVec3f((float)(i + 1 - _polygonNum / 2), 4.0, (float)(j + 1 - _polygonNum / 2) - _zMove + _baseZ);
            //p4 = ofVec3f((float)(i + 1 - _polygonNum / 2), 4.0, (float)(j - _polygonNum / 2) - _zMove + _baseZ);
            p1 = ofVec3f((float)(i - _polygonNum / 2), 4.0, (float)(j - _polygonNum / 2) - _zMove2[i] + _baseZ);
            p2 = ofVec3f((float)(i - _polygonNum / 2), 4.0, (float)(j + 1 - _polygonNum / 2) - _zMove2[i] + _baseZ);
            p3 = ofVec3f((float)(i + 1 - _polygonNum / 2), 4.0, (float)(j + 1 - _polygonNum / 2) - _zMove2[i] + _baseZ);
            p4 = ofVec3f((float)(i + 1 - _polygonNum / 2), 4.0, (float)(j - _polygonNum / 2) - _zMove2[i] + _baseZ);
            q1 = ofVec3f((float)(i - _polygonNum / 2), -4.0, (float)(j - _polygonNum / 2) - _zMove2[i] + _baseZ);
            q2 = ofVec3f((float)(i - _polygonNum / 2), -4.0, (float)(j + 1 - _polygonNum / 2) - _zMove2[i] + _baseZ);
            q3 = ofVec3f((float)(i + 1 - _polygonNum / 2), -4.0, (float)(j + 1 - _polygonNum / 2) - _zMove2[i] + _baseZ);
            q4 = ofVec3f((float)(i + 1 - _polygonNum / 2), -4.0, (float)(j - _polygonNum / 2) - _zMove2[i] + _baseZ);
        
            if(p1.z < -150) {
                _zMove2[i] = 0;
            }

            
            _yuka.getVertices()[i * (_polygonNum) + k + j].set(p1);
            _yuka.getVertices()[i * (_polygonNum) + k + j + 1].set(p2);
            
            _yuka.getVertices()[i * (_polygonNum) + k + j + 2].set(p2);
            _yuka.getVertices()[i * (_polygonNum) + k + j + 3].set(p3);
            
            _yuka.getVertices()[i * (_polygonNum) + k + j + 4].set(p3);
            _yuka.getVertices()[i * (_polygonNum) + k + j + 5].set(p4);
            
            _yuka.getVertices()[i * (_polygonNum) + k + j + 6].set(p4);
            _yuka.getVertices()[i * (_polygonNum) + k + j + 7].set(p1);
            
            _tenjyo.getVertices()[i * (_polygonNum) + k + j].set(q1);
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 1].set(q2);
            
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 2].set(q2);
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 3].set(q3);
            
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 4].set(q3);
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 5].set(q4);
            
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 6].set(q4);
            _tenjyo.getVertices()[i * (_polygonNum) + k + j + 7].set(q1);
            
            
            //cout << i * (_polygonNum) + k + j << endl;
            //cout << i * (_polygonNum) + k + j + 1 << endl;
            //cout << i * (_polygonNum) + k + j + 2 << endl;
            //cout << i * (_polygonNum) + k + j + 3 << endl;
            k += 7;
            
        }
        
        _zMove2[i] += 0.4;
        
    }
    
    
    
    _yuka.draw();
    _tenjyo.draw();
    ofPushMatrix();
    //ofDrawBox(0, 0, 20, 2, 2, 2);
    //_box.setPosition(0, 0, 20);
    //_box.drawWireframe();
    ofPopMatrix();
    
    ofPopMatrix();
    
    
    /* 地面 */
    
    /*
    ofPushMatrix();
    ofRotateZ(20);
    ofSetColor(255, 255, 255);
    glBegin(GL_LINES);
    glNormal3d(0.0, 1.0, 0.0);
    for (j = -10; j < 10; ++j) {
        for (i = -10; i < 10; ++i) {
            ofVec3f p1, p2, p3, p4;
            p1 = ofVec3f((float)i, 3.0, (float)j + 20 + _zMove);
            p2 = ofVec3f((float)i, 3.0, (float)(j + 1) + 20 + _zMove) ;
            p3 = ofVec3f((float)(i + 1), 3.0, (float)(j + 1) + 20 + _zMove);
            p4 = ofVec3f((float)(i + 1), 3.0, (float)j + 20 + _zMove);
            
            //glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
            //glVertex3d((GLdouble)i, -0.5, (GLdouble)j);
            //glVertex3d((GLdouble)i, -0.5, (GLdouble)(j + 1));
            //glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)(j + 1));
            //glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)j);
            glVertex3d(p1.x, p1.y, p1.z);
            glVertex3d(p2.x, p2.y, p2.z);
            
            glVertex3d(p2.x, p2.y, p2.z);
            glVertex3d(p3.x, p3.y, p3.z);
            
            glVertex3d(p3.x, p3.y, p3.z);
            glVertex3d(p4.x, p4.y, p4.z);
            
            glVertex3d(p4.x, p4.y, p4.z);
            glVertex3d(p1.x, p1.y, p1.z);
        }
    }
    glEnd();
    
    
    
    glBegin(GL_LINES);
    glNormal3d(0.0, 1.0, 0.0);
    for (j = -10; j < 10; ++j) {
        for (i = -10; i < 10; ++i) {
            ofVec3f p1, p2, p3, p4;
            p1 = ofVec3f((float)i, -3.0, (float)j + _zMove);
            p2 = ofVec3f((float)i, -3.0, (float)(j + 1) + _zMove);
            p3 = ofVec3f((float)(i + 1), -3.0, (float)(j + 1) + _zMove);
            p4 = ofVec3f((float)(i + 1), -3.0, (float)j + _zMove);
            
            //glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
            //glVertex3d((GLdouble)i, -0.5, (GLdouble)j);
            //glVertex3d((GLdouble)i, -0.5, (GLdouble)(j + 1));
            //glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)(j + 1));
            //glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)j);
            glVertex3d(p1.x, p1.y, p1.z);
            glVertex3d(p2.x, p2.y, p2.z);
            
            glVertex3d(p2.x, p2.y, p2.z);
            glVertex3d(p3.x, p3.y, p3.z);
            
            glVertex3d(p3.x, p3.y, p3.z);
            glVertex3d(p4.x, p4.y, p4.z);
            
            glVertex3d(p4.x, p4.y, p4.z);
            glVertex3d(p1.x, p1.y, p1.z);
        }
    }
    glEnd();
    ofPopMatrix();
    */
    _cam.end();
    

    _zMove  += 0.3;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofVec2f mouse(x,y);
    ofQuaternion yRot((x-lastMouse.x)*dampen, ofVec3f(0,1,0));
    ofQuaternion xRot((y-lastMouse.y)*dampen, ofVec3f(-1,0,0));
    curRot *= yRot*xRot;
    lastMouse = mouse;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    lastMouse = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
