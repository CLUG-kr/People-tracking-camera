#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture("mitsubishi_768x576.avi"); //���ÿ� �����ϴ� ������ ����Ѵ�. 
	//capture.set(CAP_PROP_FRAME_WIDTH, 480);
	//capture.set(CAP_PROP_FRAME_HEIGHT, 320); 
	//ī�޶� ����� �� ���� ũ�� �����ϴ� �κ�

	Mat frame;
	Mat gray;
	vector<Rect> found;
	namedWindow("input", 1);

	String fullbody_cascade = "haarcascade_fullbody.xml"; //����� �н��� ������ 

	CascadeClassifier fullbody;

	fullbody.load(fullbody_cascade);

	capture >> frame;
	int count = 0;
	while(1)
	{
		capture >> frame;
		
		if(count % 30 == 0){
			cvtColor(frame, gray, CV_BGR2GRAY); // �ش� ������ �̹����� ���� Gray scale�� ��ȯ

			if (frame.empty())
				cout << "hello" << endl;

			fullbody.detectMultiScale(gray, found, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(10,10)); // cascade�� �̿��� ���󿡼� ���ϴ� �����͸� ����

			for(int i=0; i < (int)found.size(); i++){
				rectangle(frame, found[i], Scalar(0,255,0),2); // ����� ������ �ֺ��� �簢���� �׸�
			}
			imshow("input",frame);
			if (waitKey(1) == 'q')  break;
			count = 1;
		}
		else{
			imshow("input",frame);
			count++;
		}
		
	}
	return 0;
}
