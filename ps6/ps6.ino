#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 
#define BTN_1_PIN       2
#define BTN_2_PIN       3
#define BTN_3_PIN       4
#define BTN_4_PIN       5
#define BTN_ENTER_PIN   A0

#define LED_BLUE_1      6
#define LED_RED_1       7
#define LED_BLUE_2      8
#define LED_RED_2       9
#define LED_BLUE_3      10
#define LED_RED_3       11
#define LED_BLUE_4      12
#define LED_RED_4       13

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_init(){
    lcd.begin();
    lcd.backlight();
}

void lcd_clear(){
    lcd.clear();
}


void lcd_set_cursor(int y, int x){
lcd.setCursor(x,y);
}


void lcd_print(char* text){
    lcd.print(text);
}


void lcd_print_at(int y, int x, char* text){
    lcd_set_cursor(y, x);
    lcd_print(text);
}

char* generate_code(bool repeat, int length){
    if(length<1)
    return NULL;
    if(repeat==false && length>10)
    return NULL;
    
    char string[length];
    srand(time(0));
    if(repeat==false){
for (int i = 0; i < length; i++ )
  string[i] = i + 1;
int i = 0;
 
while ( i < length ) {
  char r = 0x30 | random()%10;
  int j;
 
  for ( j = 0; j < i; j++ ) {
    if ( string[j] == r )
      break;
  }
 
  if ( j == i )
    string[i++] = r;
}
} 
else{
    for(int i=0;i<length;i++){
        string[i]= 0x30 | random()%10;
    }
}
char* ff=string;
    return ff;
}
void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){
  *peg_a=0;
  *peg_b=0;
  char* string=(char*)malloc(4*sizeof(char));
  for(int i=0;secret[i];i++){
     if(secret[i]!=guess[i]){
        string[i]='l';
        
      }
     else{
      string[i]=secret[i];
      *peg_a=*peg_a+1;
        
     }
  }
  for(int j=0;secret[j];j++){
    for(int q=0;guess[q];q++){
      if(secret[j]==guess[q] && string[j]=='l'){
        *peg_b=*peg_b+1;
        break;
      }
    }
  }
  free(string);
}

void turn_off_leds(){
  digitalWrite(LED_BLUE_1, LOW);
    digitalWrite(LED_BLUE_2, LOW);
    digitalWrite(LED_BLUE_3, LOW);
    digitalWrite(LED_BLUE_4, LOW);
    digitalWrite(LED_RED_1, LOW);
    digitalWrite(LED_RED_2, LOW);
    digitalWrite(LED_RED_3, LOW);
    digitalWrite(LED_RED_4, LOW);
}
void render_leds(const int peg_a, const int peg_b){
 if (peg_a==1)
  {
    digitalWrite(LED_RED_1, HIGH);
  }
  if (peg_a==2)
  {
    digitalWrite(LED_RED_1, HIGH);
    digitalWrite(LED_RED_2, HIGH);
  }
  if (peg_a==3)
  {
    digitalWrite(LED_RED_1, HIGH);
    digitalWrite(LED_RED_2, HIGH);
    digitalWrite(LED_RED_3, HIGH);
  }
  if (peg_a==4)
  {
    digitalWrite(LED_RED_1, HIGH);
    digitalWrite(LED_RED_2, HIGH);
    digitalWrite(LED_RED_3, HIGH);
    digitalWrite(LED_RED_4, HIGH);
  }

  if (peg_b==1)
  {
    digitalWrite(LED_BLUE_1, HIGH);
  }
  if (peg_b==2)
  {
    digitalWrite(LED_BLUE_1, HIGH);
    digitalWrite(LED_BLUE_2, HIGH);
  }
  if (peg_b==3)
  {
    digitalWrite(LED_BLUE_1, HIGH);
    digitalWrite(LED_BLUE_2, HIGH);
    digitalWrite(LED_BLUE_3, HIGH);
  }
  if (peg_b==4)
  {
    digitalWrite(LED_BLUE_1, HIGH);
    digitalWrite(LED_BLUE_2, HIGH);
    digitalWrite(LED_BLUE_3, HIGH);
    digitalWrite(LED_BLUE_4, HIGH);
  }
}
void win_leds(){
  digitalWrite(LED_BLUE_1, HIGH);
    digitalWrite(LED_BLUE_2, HIGH);
    digitalWrite(LED_BLUE_3, HIGH);
    digitalWrite(LED_BLUE_4, HIGH);
    digitalWrite(LED_RED_1, HIGH);
    digitalWrite(LED_RED_2, HIGH);
    digitalWrite(LED_RED_3, HIGH);
    digitalWrite(LED_RED_4, HIGH);
    delay(100);
    digitalWrite(LED_BLUE_1, LOW);
    digitalWrite(LED_BLUE_2, LOW);
    digitalWrite(LED_BLUE_3, LOW);
    digitalWrite(LED_BLUE_4, LOW);
    digitalWrite(LED_RED_1, LOW);
    digitalWrite(LED_RED_2, LOW);
    digitalWrite(LED_RED_3, LOW);
    digitalWrite(LED_RED_4, LOW);
    delay(100);
}
void lose_leds(){
  digitalWrite(LED_RED_1, HIGH);
    digitalWrite(LED_RED_2, HIGH);
    digitalWrite(LED_RED_3, HIGH);
    digitalWrite(LED_RED_4, HIGH);
}
void render_history(char* secret, char** history, const int entry_nr){
  int peg_a;
  int peg_b;
  char buffer[33];
  char buffer2[33];
  char A[]="A";
  char B[]="B";
 
  get_score(secret,&history[entry_nr][0],&peg_a,&peg_b);
   itoa (peg_a,buffer,10);
  itoa (peg_b,buffer2,10);
  lcd_print_at( 0, 4, history[entry_nr] );
  lcd_print_at( 0, 9, buffer );
  lcd_print_at( 0, 10, A );
  lcd_print_at( 0, 11, buffer2 );
  lcd_print_at( 0, 12, B );
  render_leds(peg_a, peg_b);
  
}
void play_game(char* secret){
  
  char pb[]="   Press button!!!";
 while(digitalRead(BTN_ENTER_PIN) == LOW) { 
  char welcome[]="Welcome to MasterMind";
lcd_print_at( 0, 0, welcome);
  lcd.scrollDisplayLeft();
  delay(150);
  lcd_print_at( 1, 0, pb);
   }
 lcd_clear();
 delay(500);
while ( digitalRead(BTN_ENTER_PIN)==LOW){
  char yg[]="Guess my secret combination.";
  lcd_print_at( 0, 0, yg);
  lcd.scrollDisplayLeft();
  delay(150);
  lcd_print_at( 1, 0, pb);
  }
lcd_clear(); 
delay(500);
 char nums[]="0000";
while (digitalRead(BTN_ENTER_PIN)==LOW){
  char It[]="Guess a number!!";
  char yg[]="Your guess:";
  
  lcd_print_at( 0, 0, It );
  lcd_print_at( 1, 0, yg);
  lcd_print_at( 1, 11, nums);
  if(digitalRead(BTN_1_PIN)==HIGH){
    if(nums[0]==57)
    nums[0]=47;
  nums[0]=nums[0]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_2_PIN)==HIGH){
    if(nums[1]==57)
    nums[1]=47;
  nums[1]=nums[1]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_3_PIN)==HIGH){
    if(nums[2]==57)
    nums[2]=47;
  nums[2]=nums[2]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_4_PIN)==HIGH){
    if(nums[3]==57)
    nums[3]=47;
  nums[3]=nums[3]+1;
  lcd_clear();
  delay(100);
  }
  }
 lcd_clear();
  delay(500);
  
char** history;
 history=(char **)malloc(9*sizeof(char *));
history[0]=(char*)malloc(4*sizeof(char));
history[0];
history[1]=(char*)malloc(4*sizeof(char));
history[1];
history[2]=(char*)malloc(4*sizeof(char));
history[2];
history[3]=(char*)malloc(4*sizeof(char));
history[3];
history[4]=(char*)malloc(4*sizeof(char));
history[4];
history[5]=(char*)malloc(4*sizeof(char));
history[5];
history[6]=(char*)malloc(4*sizeof(char));
history[6];
history[7]=(char*)malloc(4*sizeof(char));
history[7];
history[8]=(char*)malloc(4*sizeof(char));
history[8];
history[0]=nums;

  
  char por[]="0";
  char por2[]=":";
  char buffer[33];  
  int i=0;
  int buffers=1;
  int hist=0;
  int a=0;
  int b=0;
  int c=0;
  for( i=0;i<10;i++){
    
    if(i==0){
    int peg_f;
  int peg_g;
get_score(secret, history[0], &peg_f, &peg_g);
  if(peg_f==4){
      lcd_clear();
    while (digitalRead(BTN_ENTER_PIN)==LOW){
    char won[]="You win!!!!!";
    lcd_print_at( 1, 3, won);
    win_leds();
   
    }
    break;}
    }
    itoa (i,buffer,10);
    buffer[0]=buffer[0]+1;
    char numss[]="0000";
    int peg_a;
    int peg_b;
    
    
    
    while (digitalRead(BTN_ENTER_PIN)==LOW||a!=0){
    lcd_print_at( 0, 0,por );
    lcd_print_at( 0, 1,buffer );
    
    lcd_print_at( 0, 2,por2 );
    if(i==buffers)
   c=0;
    if(i-1==buffers)
   b=0;
    if(b==0){
    
    render_history(secret,history,i);}
    else
render_history(secret,history,i);
    if(hist==0){
    
    lcd_print_at( 1, 4, numss);}
    if(digitalRead(BTN_1_PIN)==HIGH && digitalRead(BTN_2_PIN)==HIGH&&i>0){
    if(a==0)
    buffers=i;
   
    hist=1;
    i--;
    i--;
    lcd_clear();
    a++;
    b++;
    c++;
    delay(200);
    break;
  }
  
if(digitalRead(BTN_1_PIN)==HIGH && digitalRead(BTN_3_PIN)==HIGH&&i!=buffers&&a!=0){
    if(i==buffers-1){
  hist=0;
    a=0;
    }
    
    lcd_clear();
    delay(200);
    break;
    
    
  }
    
  if(digitalRead(BTN_1_PIN)==HIGH){
    if(numss[0]==57)
    numss[0]=47;
  numss[0]=numss[0]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_2_PIN)==HIGH){
    if(numss[1]==57)
    numss[1]=47;
  numss[1]=numss[1]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_3_PIN)==HIGH){
    if(numss[2]==57)
    numss[2]=47;
  numss[2]=numss[2]+1;
  lcd_clear();
  delay(100);
  }
  if(digitalRead(BTN_4_PIN)==HIGH){
    if(numss[3]==57)
    numss[3]=47;
  numss[3]=numss[3]+1;
  lcd_clear();
  delay(100);
  }
  
    }
    if(c==0)
    strcpy(history[i+1],numss);
    turn_off_leds();
    get_score(secret, history[i+1], &peg_a, &peg_b);
    delay(300);
    if(peg_a==4){
      lcd_clear();
    while (digitalRead(BTN_ENTER_PIN)==LOW){
    char won[]="You win!!!!!";
    lcd_print_at( 1, 3, won);
    win_leds();
   
    }
    break;}
    if(i==8){
      lcd_clear();
    while (digitalRead(BTN_ENTER_PIN)==LOW){
    char lose[]="You loseeer!!!!!";
    lcd_print_at( 1, 2, lose);
    lose_leds();
    }
    break;
    }
  }
    turn_off_leds();
    delay(200);
  }

void setup()
{
   pinMode(BTN_1_PIN, INPUT);
   pinMode(BTN_2_PIN, INPUT);
   pinMode(BTN_3_PIN, INPUT);
   pinMode(BTN_4_PIN, INPUT);
   pinMode(BTN_ENTER_PIN, INPUT);
   pinMode(LED_BLUE_1 , OUTPUT);
   pinMode(LED_BLUE_2 , OUTPUT);
   pinMode(LED_BLUE_3 , OUTPUT);
   pinMode(LED_BLUE_4 , OUTPUT);
   pinMode(LED_RED_1 , OUTPUT);
   pinMode(LED_RED_2 , OUTPUT);
   pinMode(LED_RED_3 , OUTPUT);
   pinMode(LED_RED_4 , OUTPUT);
  lcd_init();
  
  
}
void loop(){
  char code1[]="1234";
    char* code;
    code=code1;
    play_game(code);
    
}