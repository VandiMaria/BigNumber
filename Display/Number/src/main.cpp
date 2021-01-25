/* ========================================================================================================
 
   Caracteres Gigantes em Display LCD 16x2
    
   Autor: Vandilson  Data: 24/01/2021
   
   Referencia:https://www.youtube.com/watch?v=rvoLtTSLi6s&t=2s

     
======================================================================================================== */

// --- Bibliotecas Auxiliares ---
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


 

// ========================================================================================================
// --- Constantes ---
LiquidCrystal_I2C lcd(0x27,20,4);

// ========================================================================================================
// --- Protótipo das Funções ---
void DisplayNum(int Num);
void Char0();
void Char1();
void Char2();
void Char3();
void Char4();
void Char5();
void Char6();
void Char7();
void Char8();
void Char9();

// ========================================================================================================
// --- Variáveis Globais ---
int Num = 0;

// Segmentos personalizados
byte segF[8] = 
{
  B00111,  
  B01111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111
};

byte segA[8] =
{
  B11111,  
  B11111,  
  B11111,  
  B00000,  
  B00000,  
  B00000,  
  B00000,  
  B00000
};

byte segB[8] =
{
  B11100,  
  B11110,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111
};

byte segC[8] =
{
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11110,  
  B11100
};


byte segD[8] =
{
  B00000,  
  B00000,  
  B00000,  
  B00000,  
  B00000,  
  B11111,  
  B11111,  
  B11111
};


byte segE[8] =
{
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B01111,  
  B00111
};


byte segG[8] =
{
  B11111,  
  B11111,  
  B11111,  
  B00000,  
  B00000,  
  B00000,  
  B11111,  
  B11111
};


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Wire.begin(22,23);
  Serial.begin(115200);
   
  lcd.createChar(0,segF);
  lcd.createChar(1,segA);
  lcd.createChar(2,segB);
  lcd.createChar(3,segE);
  lcd.createChar(4,segD);
  lcd.createChar(5,segC);
  lcd.createChar(6,segG);
  
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{
  
  DisplayNum(Num);
  delay(741);

  Num += 1;
  if(Num > 9) Num = 0;
  lcd.clear();
 

} //end loop


// ========================================================================================================
// --- Desenvolvimento das Funções ---


void DisplayNum(int Num)  
{  
   switch(num)
   {
      case 0: char0(); break;
      case 1: char1(); break;
      case 2: char2(); break;
      case 3: char3(); break;
      case 4: char0(); break;
      case 5: char1(); break;
      case 6: char2(); break;
      case 7: char3(); break;
      case 8: char1(); break;
      case 9: char2(); break;  
   } //end switch
   
} // end disp_num




// ========================================================================================================
// --- Gera os "segmentos" para o caractere 0 ---
void Char0()
{ 
  lcd.setCursor(5, 0);   //linha 1
  lcd.write((byte)0);    //segmento F
  lcd.write((byte)1);    //segmento A
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5, 1);   //linha 2
  lcd.write((byte)3);    //segmento E
  lcd.write((byte)4);    //segmento D
  lcd.write((byte)5);    //segmento C  
} //end char0


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 1 ---
void Char1()
{ 
  lcd.setCursor(5+2, 0);   //linha 1
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+2, 1);   //linha 2
  lcd.write((byte)5);    //segmento C
  
} //end char1


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 2 ---
void Char2()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5, 1);   //linha 2
  lcd.write((byte)3);    //segmento E
  lcd.write((byte)4);    //segmento D
  
} //end char2


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 3 ---
void Char3()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+1, 1);   //linha 2
  lcd.write((byte)4);    //segmento D
  lcd.write((byte)5);    //segmento C
  
} //end char3

// ========================================================================================================
// --- Gera os "segmentos" para o caractere 4 ---
void Char4()
{ 
  lcd.setCursor(5+2, 0);   //linha 1
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+2, 1);   //linha 2
  lcd.write((byte)5);    //segmento C
  
} //end char4


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 5---
void Char5()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5, 1);   //linha 2
  lcd.write((byte)3);    //segmento E
  lcd.write((byte)4);    //segmento D
  
} //end char5


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 6 ---
void Char6()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+1, 1);   //linha 2
  lcd.write((byte)4);    //segmento D
  lcd.write((byte)5);    //segmento C
  
} //end char6

// ========================================================================================================
// --- Gera os "segmentos" para o caractere 7 ---
void Char7()
{ 
  lcd.setCursor(5+2, 0);   //linha 1
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+2, 1);   //linha 2
  lcd.write((byte)5);    //segmento C
  
} //end char7


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 8 ---
void Char8()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5, 1);   //linha 2
  lcd.write((byte)3);    //segmento E
  lcd.write((byte)4);    //segmento D
  
} //end char8


// ========================================================================================================
// --- Gera os "segmentos" para o caractere 9 ---
void Char9()
{ 
  lcd.setCursor(5+1, 0);   //linha 1
  lcd.write((byte)6);    //segmento G
  lcd.write((byte)2);    //segmento B
  lcd.setCursor(5+1, 1);   //linha 2
  lcd.write((byte)4);    //segmento D
  lcd.write((byte)5);    //segmento C
  
} //end char9

