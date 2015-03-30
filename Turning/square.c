#include <stdio.h>
#include <stdlib.h>

const float pi = 3.141593;
char *Arduino;

float theta;

void arduinoSend(char);
float absValue(float);
float getYaw();

int main(int argc, char *argv[])
{
	float init_value, tmp; 

	Arduino = "test.txt";
	theta = pi/2;

	printf("A\n");
	arduinoSend('0');
	sleep(2);

	init_value = getYaw();	printf("B\t%.4f\n", init_value);
	arduinoSend('1');

	while (turn == 0)
	{
		diff = absValue(getYaw()-init_value);
		diff = diff % theta;
		
		
	
	
	
	
	if(absValue(init_value)+theta > pi)
		while(( (tmp=absValue(init_value-getYaw())) > (2*pi-theta)) || (tmp<theta));
	else
		while( (tmp=absValue(init_value-getYaw())) < theta);

	printf("A\t%.4f\n",getYaw());
	arduinoSend('0');
	return 0;
}

void arduinoSend(char c)
{
	FILE *ard;

	ard = fopen(Arduino, "w");
	fprintf(ard, "%c", c);
	fclose(ard);
}

float getYaw()
{
	char val[8];
	FILE *nav;

	nav = fopen("tmp", "r");
	fseek(nav, 0, SEEK_END);
	while(fgetc(nav) != '\n')
		fseek(nav, -2, SEEK_CUR);
	fseek(nav, -8, SEEK_CUR);
	fscanf(nav, "%s", val);
	fclose(nav);

	return(atof(val));
}

float absValue(float num)
{
	if(num < 0)
		return(-num);
	else
		return(num);
}
