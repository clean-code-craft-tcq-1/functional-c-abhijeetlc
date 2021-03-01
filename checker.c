#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>


#define Mintemp		0
#define maxtemp		45

double temperaturecheck(float a)
{
	return( (a + fabs(a))/2);	 // Trying a pure funtion
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  double TempertureValue = temperaturecheck( temperature);
  
 //Check for low temperature 
  if(TempertureValue == Mintemp) {
    printf("Temperature Low!\n");
    return 0;
  } 
  
  //Check for High temperature 
  if(TempertureValue >= maxtemp) {
    printf("Temperature High!\n");
    return 0;
  } 
  
   if(soc < 20 ) {
    printf("State of Charge Low!\n");
    return 0;
  } 

    if(soc > 80 ) {
    printf("State of Charge High!\n");
    return 0;
  } 
  
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
	
  printf(" Battery OK :) !\n");
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
