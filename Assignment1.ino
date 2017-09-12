#define ASize 13

//INIT MATRICES GLOBAL
int8_t MatrixX[ASize][ASize];
int8_t MatrixY[ASize][ASize];

long MatrixOut[ASize][ASize];
long Sum;

void setup(){

}

void loop(){
  Serial.begin(9600);
  Serial.println("starts");

  //FILL MATRICES
  SetupMatrices();
  unsigned long StartTime = millis();
  for (size_t i = 0; i < 1000; i++) {
    DotProduct();
    Addition();
  }
  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;

  Serial.println(ElapsedTime);

  PrintIt();



  while(1){
  }
}

//SetupMatrices initializes Matrices with random 8-bit numbers.
int SetupMatrices(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      MatrixX[i][j] = random(0,127);
      MatrixY[i][j] = random(0,127);
    }
  }
}

//DotProduct does the DotProduct between the matrices
int DotProduct(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      Sum = 0;
      for (size_t k = 0; k < ASize; k++) {
        Sum = Sum + (MatrixX[i][k]*MatrixY[k][j]);
      }
      MatrixOut[i][j] = Sum;
    }
  }
}

//Addition does the Addition between X and Y
int Addition(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      MatrixOut[i][j] = MatrixOut[i][j] + MatrixX[i][j] + MatrixY[i][j];
    }
  }
}


int PrintIt(){
  //PRINT MATRICES
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      Serial.print(MatrixX[i][j]);
      Serial.print(",");
    }
    Serial.print("\n");
  }

  Serial.print("\n");

  //PRINT MATRICES
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      Serial.print(MatrixY[i][j]);
      Serial.print(",");
    }
    Serial.print("\n");
  }

  Serial.print("\n");

  //PRINT MATRICES
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      Serial.print(MatrixOut[i][j],DEC);
      Serial.print(",");
    }
    Serial.print("\n");
  }

  Serial.print("\n");


  Serial.println(sizeof(MatrixOut[1][1]));
}

