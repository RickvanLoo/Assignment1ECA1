#define ASize 13

//INIT MATRICES GLOBAL
uint8_t MatrixX[ASize][ASize];
uint8_t MatrixY[ASize][ASize];
uint32_t MatrixOut[ASize][ASize];
int SetupMatrices(void);
void setup(){
}

void loop(){
  Serial.begin(9600);
  Serial.println("starts");

  //FILL MATRICES
  SetupMatrices();
  uint16_t StartTime = millis();
  for (uint16_t iteration = 0; iteration < 1000; iteration++) {
    for (uint8_t i = 0; i < ASize; i++) {
      //force local array in cache
      uint8_t MatX[ASize];
      memcpy(MatX, MatrixX[i], ASize);
      uint8_t MatY[ASize];
      memcpy(MatY, MatrixY[i], ASize);
      for (uint8_t j = 0; j < ASize; j++) {
          uint32_t Sum = 0;
          for (uint8_t k = 0; k < ASize; k++) {
              Sum = Sum + (MatX[k]*MatrixY[k][j]);
          }
          MatrixOut[i][j] = Sum + MatX[j] + MatY[j];
       }
    }
  }
  uint16_t CurrentTime = millis();
  uint16_t ElapsedTime = CurrentTime - StartTime;

  Serial.println(ElapsedTime);
  PrintIt();

  while(1){}
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

