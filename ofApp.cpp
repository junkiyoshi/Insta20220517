#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0);
	ofNoFill();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto max_loop = 5;
	auto max_radius = 480;
	for (int deg_start = 0; deg_start < 360; deg_start += 45) {

		auto loop = ofMap(ofNoise(cos(deg_start * DEG_TO_RAD) * 0.2, sin(deg_start * DEG_TO_RAD) * 0.2, ofGetFrameNum() * 0.01), 0, 1, -1.5, max_loop);

		ofBeginShape();
		for (int deg = deg_start; deg <= deg_start + 360 * loop; deg++) {

			auto radius = ofMap(deg, deg_start, deg_start + 360 * max_loop, 50, max_radius);
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			ofVertex(location);

			if (deg == deg_start) {

				ofFill();
				ofDrawCircle(location, 3);
				ofNoFill();
			}
		}
		ofEndShape();
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}