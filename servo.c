#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define SERVO 1

int main(){
	char sel;

	if(wiringPiSetup() == -1)
		return 1;
	softPwmCreate(SERVO, 0, 200);

	while(1){
		fputs("select c, r, l, q :", stdout);
		scanf("%c", &sel);
		getchar();
		if(sel == 'c') softPwmWrite(SERVO, 15);
		else if( sel == 'r') softPwmWrite(SERVO, 24);
		else if(sel == 'l') softPwmWrite(SERVO, 5);
		else if(sel == 'q') return 0;
	}
	return 0;

}
