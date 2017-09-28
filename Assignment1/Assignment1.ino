#define ASize 13

//INIT MATRICES GLOBAL
const uint8_t MatrixX[ASize][ASize]={{28,122,80,42,54,122,98,42,99,58,124,29,21},
                                    {113, 85,  30,  35,  41,  98,  103, 68,  15,  50,  31,  80,  54},
                                    {47,  37,  23,  96,  59,  47,  84, 26,  84,  72,  51,  118, 119},
                                    {38,  121, 45,  21,  87,  91,  20,  69,  98,  119, 15,  89,  47},
                                    {40,  71,  105, 76, 31,  65,  109,30,  127, 110, 17,  64,  64},
                                    {45,  20,  113, 86,  86,  51,  104, 115, 61,  103, 60,  113, 44},
                                    {101, 107, 33,  63,  39,  47,  120, 20,  41,  64,  102, 59,  86},
                                    {9, 42,  118, 26,  83,  123, 10,  82,  47,  108, 127, 4, 66},
                                    {75,  26,  117, 80,  47,  111, 38, 22,  98,  101, 92,  100, 48},
                                    {90,  9, 71,  36,  90,  95,  4, 94,  72,  29,  77,  118, 78},
                                    {81,  75,  97,  127, 22,  8, 96,  80,  100, 88,  69,  114, 16},
                                    {25,  109, 74,  3, 126, 56,  99,  15,  69,  73,  76,  19,  97},
                                    {59,  84,  102,53,  30,  34, 33,  105, 75,  102, 60,  121, 93}};
const uint8_t MatrixY[ASize][ASize] = {{102,  61,  111, 79,  99,  3, 25,  50,  33,  48,  5, 94,  28},
                                    {106, 89,  35,  37,  112, 51,  13,  70,  3, 110, 31,  7, 99},
                                    {65,  115, 94,  68,  95,  114, 34,  34,  64,  1, 11,  66,  126},
                                    {114, 37,  42,  3, 88,  35,  124, 50,  74,  95,  25,  34,  24},
                                    {25,  111, 4, 116, 54,  90,  11,  32,  121, 20,  26,  62,  60},
                                    {45,  41,  20,  33,  89,  75,  89,  2, 28,  19,  96,  46,  119},
                                    {39,  68,  87,  59,  33,  82,  94,  14,  115, 0, 0, 92,  85},
                                    {58,  62,  122, 106, 93,  39,  86,  80,  75,  23,  57,  89,  7},
                                    {119, 75,  20,  42,  1, 120, 83,  24,  62,  78,  20,  25,  126},
                                    {121, 42,  78,  45,  8, 17,  52,  38,  44,  13,  104, 57,  62},
                                    {29,  96,  0, 64,  47,  50,  22,  17,  88,  63,  108, 78,  101},
                                    {70,  108, 69,  12,  0, 80,  115, 107, 71,  54,  5, 57,  3},
                                    {123, 72,  56,  5, 30,  45,  2, 11,  124, 84,  63,  47,  104}};


uint32_t MatrixOut[ASize][ASize];
uint32_t Sum;

void setup(){

}

void loop(){
  Serial.begin(9600);
  Serial.println("starts");

  //FILL MATRICES
  //SetupMatrices();
  unsigned long StartTime = millis();
  for (uint16_t i = 0; i < 1000; i++) {
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
/*int SetupMatrices(void){
  for (size_t i = 0; i < ASize; i++) {
    for (size_t j = 0; j < ASize; j++) {
      MatrixX[i][j] = random(0,127);
      MatrixY[i][j] = random(0,127);
    }
  }
}
*/
//DotProduct does the DotProduct between the matrices
int DotProduct(void){
  for (uint8_t i = 0; i < ASize; i++) {
    for (uint8_t j = 0; j < ASize; j++) {
      Sum = 0;
      for (uint8_t k = 0; k < ASize; k++) {
        Sum = Sum + (MatrixX[i][k]*MatrixY[k][j]);
      }
      MatrixOut[i][j] = Sum;
    }
  }
}

//Addition does the Addition between X and Y
int Addition(void){
  for (uint8_t i = 0; i < ASize; i++) {
    for (uint8_t j = 0; j < ASize; j++) {
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

