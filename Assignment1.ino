#define ASize 12

//INIT MATRICES GLOBAL
int8_t MatrixX[ASize][ASize];
int8_t MatrixY[ASize][ASize];
long MatrixXY[ASize][ASize];
int16_t MatrixXpY[ASize][ASize];
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
  for (size_t i = 0; i < 1; i++) {
    DotProduct();
    Addition1();
    Addition2();
  }
  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;

  Serial.println(ElapsedTime);

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


  Serial.println(sizeof(MatrixXY[1][1]));

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
      MatrixXY[i][j] = Sum;
    }
  }
}

//Addition1 does the Addition between X and Y
int Addition1(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      MatrixXpY[i][j] = MatrixX[i][j] + MatrixY[i][j];
    }
  }
}


//Addition2 does the Addition between XY and XpY
int Addition2(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      MatrixOut[i][j] = MatrixXpY[i][j] + MatrixXY[i][j];
    }
  }
}
