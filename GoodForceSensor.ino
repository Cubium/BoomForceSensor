int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 1000000;
float R2= 0;
float buffer= 0;

void setup()
{
Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
//Serial.print("Vout: ");
//Serial.println(Vout);
//Serial.print("R2: ");
//Serial.println(1000000/R2);

double conductance = 1000000/R2;
double weight = (conductance - 0.2492) / 2.2624;

Serial.println(weight);
delay(100);
}
}

