
#include <Wire.h>
#include "Rtc_Pcf8563.h"
#include <EEPROM.h>
#include <Adafruit_NeoMatrix.h>

#define PIN 6

#define DELAY_BT (unsigned long)1

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);


uint16_t update_hour;
uint16_t go_on;
uint16_t serial_cmd;
uint16_t serial_cmd2;
uint16_t Serial_receive(uint16_t*);
uint16_t phone_day;
uint16_t phone_hour;
uint16_t phone_minute;
uint16_t led_intensite=0;
uint16_t led_r;
uint16_t led_g;
uint16_t led_b;
uint16_t time_debug;
unsigned long tempo;
unsigned long time_var;
Rtc_Pcf8563 rtc;


uint16_t alarm1_tab[35][7];
uint16_t i,j,a,b,addr_offset;

void setup() {
  Serial.begin(9600); 
  EEPROM.write(0,(uint8_t)170);
  matrix.begin();
  tempo=millis();
  flash(255,0,0,25);
  delay(2000);
  flash(0,0,0,0);
  time_var=getTimeMin();
  update_hour=0;
}
void loop() {
/* Receive from consol */
/* ------------------- */
  uint16_t toto;
  if(Serial.available()<1)
  {
    /* Nothing received*/ 
  }else{
    /* Receive order */
    tempo=millis();
    go_on=Serial_receive(&serial_cmd);
   
    switch(serial_cmd){
      case 0:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(0));
        }else{
          /* write content received */
        }
       break;
       case 1:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(1);
          if(toto>2){EEPROM.write(1,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(1));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(1,(uint8_t)serial_cmd2);
        }
       break;
       case 2:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(2);
          if(toto>1){EEPROM.write(2,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(2));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(2,(uint8_t)serial_cmd2);
        }
       break;
       case 3:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(3);
          if(toto>1){EEPROM.write(3,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(3));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(3,(uint8_t)serial_cmd2);
        }
       break;
       case 4:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(4);
          if(toto>24){EEPROM.write(4,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(4));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(4,(uint8_t)serial_cmd2);
        }
       break;
       case 5:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(5);
          if(toto>59){EEPROM.write(5,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(5));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(5,(uint8_t)serial_cmd2);
        }
       break;
       case 6:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(6);
          if(toto>24){EEPROM.write(6,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(6));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(6,(uint8_t)serial_cmd2);
        }
       break;
       case 7:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(7);
          if(toto>59){EEPROM.write(7,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(7));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(7,(uint8_t)serial_cmd2);
        }
       break;
       case 8:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(8);
          if(toto>24){EEPROM.write(8,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(8));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(8,(uint8_t)serial_cmd2);
        }
       break;
       case 9:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(9);
          if(toto>59){EEPROM.write(9,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(9));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(9,(uint8_t)serial_cmd2);
        }
       break;
       case 10:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(10);
          if(toto>2){EEPROM.write(10,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(10));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(10,(uint8_t)serial_cmd2);
        }
       break;
       case 11:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(11);
          if(toto>2){EEPROM.write(11,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(11));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(11,(uint8_t)serial_cmd2);
        }
       break;
       case 12:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(12);
          if(toto>2){EEPROM.write(12,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(12));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(12,(uint8_t)serial_cmd2);
        }
       break;
       case 13:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(13);
          if(toto>2){EEPROM.write(13,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(13));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(13,(uint8_t)serial_cmd2);
        }
       break;
       case 14:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(14);
          if(toto>2){EEPROM.write(14,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(14));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(14,(uint8_t)serial_cmd2);
        }
       break;
       case 15:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(15);
          if(toto>2){EEPROM.write(15,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(15));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(15,(uint8_t)serial_cmd2);
        }
       break;
       case 16:
        if(go_on==0){
          /* return addr content */
          toto=EEPROM.read(16);
          if(toto>2){EEPROM.write(16,0);}
          delay(DELAY_BT);
          Serial.print(EEPROM.read(16));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(16,(uint8_t)serial_cmd2);
        }
       break;
       case 17:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(17));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(17,(uint8_t)serial_cmd2);
        }
       break;
       case 18:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(18));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(18,(uint8_t)serial_cmd2);
        }
       break;
       case 19:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(19));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(19,(uint8_t)serial_cmd2);
        }
       break;
       case 20:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(20));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(20,(uint8_t)serial_cmd2);
        }
       break;
       case 21:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(21));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(21,(uint8_t)serial_cmd2);
        }
       break;
       case 22:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(22));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(22,(uint8_t)serial_cmd2);
        }
       break;
       case 23:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(23));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(23,(uint8_t)serial_cmd2);
        }
       break;
       case 24:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(24));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(24,(uint8_t)serial_cmd2);
        }
       break;
       case 25:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(25));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(25,(uint8_t)serial_cmd2);
        }
       break;
       case 26:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(26));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(26,(uint8_t)serial_cmd2);
        }
       break;
       case 27:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(27));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(27,(uint8_t)serial_cmd2);
        }
       break;
       case 28:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(28));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(28,(uint8_t)serial_cmd2);
        }
       break;
       case 29:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(29));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(29,(uint8_t)serial_cmd2);
        }
       break;
       case 30:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(30));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(30,(uint8_t)serial_cmd2);
        }
       break;
       case 31:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(31));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(31,(uint8_t)serial_cmd2);
        } 
       break;
       case 32:
        if(go_on==0){
          /* return addr content */
          delay(DELAY_BT);
          Serial.print(EEPROM.read(32));
        }else{
          /* write content received */
          Serial_receive(&serial_cmd2);
          EEPROM.write(32,(uint8_t)serial_cmd2);
        }
       break;
       case 33:
       if(go_on==1){
          go_on=Serial_receive(&phone_day);
          if(go_on==1){
            go_on=Serial_receive(&phone_hour);
            if(go_on==1){
              Serial_receive(&phone_minute);
            }else{
              phone_minute=0; 
            }
          }else{
            phone_hour=0;
            phone_minute=0;           
          }
       }else{
        phone_day=0;
        phone_hour=0;
        phone_minute=0;
       }
       /* put global var to set date */
       update_hour=1;
               
       break;
       case 253:
        if(go_on==1){
          Serial_receive(&time_debug);
          //setTime(time_debug*60);
          //Serial.print("T: ");
          //Serial.println(time_debug);
        }
       break;
       case 254:
          time_var=getTimeMin();
          Serial.println();
          Serial.println(time_var);
          Serial.print("Weekday:");
          Serial.println(rtc.getWeekday());
          Serial.print("Hour:");
          Serial.println(rtc.getHour());
          Serial.print("Minute:");
          Serial.println(rtc.getMinute());
          Serial.print("Second:");
          Serial.println(rtc.getSecond());
          Serial.println();

          Serial.print("I: ");
          Serial.println(led_intensite);
          Serial.print("R: ");
          Serial.println(led_r);
          Serial.print("G: ");
          Serial.println(led_g);
          Serial.print("B: ");
          Serial.println(led_b);        
       break;
       case 255:
         for(i=0;i<35;i++){
            if((i%5)==0){Serial.println("");}
            for(j=0;j<7;j++){
             Serial.print( alarm1_tab[i][j]);
             Serial.print(" ");
            }
            Serial.println("");
        }
        Serial.println("----------------");
       break;  
    }
  }
  //delay(300);
  /* delete tab */
  for(i=0;i<35;i++){
    for(j=0;j<7;j++){
          alarm1_tab[i][j]=0;
    }
  }
 /* Recuperationdonnées alarm 1 */
 addr_offset=0;
 for(a=0;a<7;a++){
  for(b=0;b<5;b++){
    i=(a*5)+b;
    /*update colonne 0 - actif */
    if( (EEPROM.read(addr_offset+10+a)) && (EEPROM.read(addr_offset+2)==1)){
      if(b==4){
      alarm1_tab[i][0]=0;        
      }else{ 
       alarm1_tab[i][0]=1;       
      }
    }else{
      alarm1_tab[i][0]=0;
    }
    /* update colonne 1 - temps */
    if(b==0){
      alarm1_tab[i][1]=(a*24*60)+(EEPROM.read(addr_offset+4)*60)+EEPROM.read(addr_offset+5);
      //if(alarm1_tab[i][0]==0){alarm1_tab[i][1]=20000;}
      if(alarm1_tab[i][0]==0){
        if(a==0){
          alarm1_tab[i][1]=0;
        }else{
          alarm1_tab[i][1]=alarm1_tab[i-1][1];
        }
      } 
    }
    if(b==3){
      alarm1_tab[i][1]=(a*24*60)+(EEPROM.read(addr_offset+6)*60)+EEPROM.read(addr_offset+7);
      if(alarm1_tab[i][1]<alarm1_tab[i-3][1]){alarm1_tab[i][1]+=(60*24);}
      if(alarm1_tab[i][0]==0){alarm1_tab[i][1]=alarm1_tab[i-3][1];}

      /* b==1 */
     alarm1_tab[i-2][1] = alarm1_tab[i-3][1] + ((alarm1_tab[i][1]-alarm1_tab[i-3][1])/3);
     if(alarm1_tab[i-2][0]==0){alarm1_tab[i-2][1]=alarm1_tab[i-3][1];}
     /* b==2*/
     alarm1_tab[i-1][1] = alarm1_tab[i-3][1] + (((alarm1_tab[i][1]-alarm1_tab[i-3][1])/3)*2);
     if(alarm1_tab[i-1][0]==0){alarm1_tab[i-1][1]=alarm1_tab[i-3][1];}

    }
    if(b==4){
      alarm1_tab[i][1]=(a*24*60)+(EEPROM.read(addr_offset+8)*60)+EEPROM.read(addr_offset+9);
      if(alarm1_tab[i][1]<alarm1_tab[i-1][1]){alarm1_tab[i][1]+=(60*24);}
      if(alarm1_tab[i-4][0]==0){alarm1_tab[i][1]=alarm1_tab[i-4][1];}     
    }
    /* update colonne 2- Luminosité et couleur 3-4-5 et lampe 6*/
    if(b==0){
      alarm1_tab[i][2]=EEPROM.read(addr_offset+17);
      alarm1_tab[i][3]=EEPROM.read(addr_offset+18);
      alarm1_tab[i][4]=EEPROM.read(addr_offset+19);
      alarm1_tab[i][5]=EEPROM.read(addr_offset+20);
      alarm1_tab[i][6]=1;
    }
    if(b==1){
      alarm1_tab[i][2]=EEPROM.read(addr_offset+21);
      alarm1_tab[i][3]=EEPROM.read(addr_offset+22);
      alarm1_tab[i][4]=EEPROM.read(addr_offset+23);
      alarm1_tab[i][5]=EEPROM.read(addr_offset+24);
      alarm1_tab[i][6]=1;
    }
    if(b==2){
      alarm1_tab[i][2]=EEPROM.read(addr_offset+25);
      alarm1_tab[i][3]=EEPROM.read(addr_offset+26);
      alarm1_tab[i][4]=EEPROM.read(addr_offset+27);
      alarm1_tab[i][5]=EEPROM.read(addr_offset+28);
      alarm1_tab[i][6]=1;
    }
    if(b==3){
      alarm1_tab[i][2]=EEPROM.read(addr_offset+29);
      alarm1_tab[i][3]=EEPROM.read(addr_offset+30);
      alarm1_tab[i][4]=EEPROM.read(addr_offset+31);
      alarm1_tab[i][5]=EEPROM.read(addr_offset+32);
      alarm1_tab[i][6]=0;
    }
    if(b==4){
      alarm1_tab[i][2]=0;
      alarm1_tab[i][3]=0;
      alarm1_tab[i][4]=0;
      alarm1_tab[i][5]=0;
      alarm1_tab[i][6]=0;
    }    
  }
 }
 
 
 if(millis()-tempo>500){
  tempo=millis();
  
  if(update_hour==1){
    
    rtc.setDate(19+phone_day, phone_day, 6, 0, 17);
    rtc.setTime(phone_hour, phone_minute, 0);
    time_var=getTimeMin();
    update_hour=0;
    
  }else{
    time_var=getTimeMin();
  }
  if(time_var<alarm1_tab[0][1]){
    /* check avant premier element /!\dimanche overflow */
    led_intensite=0;  
  }else{
    if(time_var>=alarm1_tab[34][1]){
      /* check apres dernier element */  
      led_intensite=0;  
    }else{
      /* check element du tableau */
       for(i=0;i<34;i++){  
          if( (time_var>=alarm1_tab[i][1]) && (time_var<alarm1_tab[i+1][1]) && (alarm1_tab[i][0]==1)){ 
              led_r=alarm1_tab[i][3];
              led_g=alarm1_tab[i][4];
              led_b=alarm1_tab[i][5];
              if(alarm1_tab[i][6]==0){
                led_intensite=alarm1_tab[i][2];        
              }else{
                if(alarm1_tab[i][2]<=alarm1_tab[i+1][2]){
                 if((alarm1_tab[i+1][1]-alarm1_tab[i][1])!=0){
                    led_intensite= alarm1_tab[i][2] + ( (time_var-alarm1_tab[i][1]) * (alarm1_tab[i+1][2]-alarm1_tab[i][2]) / (alarm1_tab[i+1][1]-alarm1_tab[i][1]) );
                  }else{
                    led_intensite= alarm1_tab[i][2];
                 }                      
                }else{
                  if((alarm1_tab[i+1][1]-alarm1_tab[i][1])!=0){
                    led_intensite= alarm1_tab[i][2] - ( (time_var-alarm1_tab[i][1]) * (alarm1_tab[i][2]-alarm1_tab[i+1][2]) / (alarm1_tab[i+1][1]-alarm1_tab[i][1]) );
                  }else{
                    led_intensite= alarm1_tab[i][2];
                  }
               }
            }  
            i=35;  
        }else{
          led_intensite=0;
        }
      }
    }  
 }

  if(led_intensite==0){
    flash(0,0,0,0);
  }else{
    //led_intensite=(led_intensite*1950)/(led_r+led_g+led_b);
    led_intensite=(led_intensite*255/100);
    /*Serial.println(led_intensite);*/
    if(led_intensite>255){led_intensite=255;}
    flash(led_r,led_g,led_b,(led_intensite));
    /* allumage rgb a jour, intensité valeur brut a retravailler en fct de rgb */
    /* a faire */
  }
  }
}

unsigned long getTimeMin(void){
  return (unsigned long)((rtc.getWeekday()*24*60) +(rtc.getHour()*60) + rtc.getMinute());
  /*return 0;*/
   
} 


uint16_t Serial_receive(uint16_t* receive) {
  uint8_t exit_loop=1;
  uint16_t message=0;
  uint8_t i=0;
  uint8_t byte_read;
  *receive = 0;
  while ((Serial.available() > 0) && exit_loop) {
    byte_read = Serial.read();
    if (byte_read >= 48 && byte_read <= 57) {
      if(i==0){ 
        (*receive) = (byte_read - 48);
      }else{
        (*receive) = ((*receive) * 10) + (byte_read - 48);
      }
      i++;
    }
    if((byte_read==58) || (byte_read==59)){
      exit_loop=0;
      if(byte_read==59){
        message=1;
      } 
    }
    delay(2);
  }
  return message;
}

void flash(int R,int G,int B,int I){

  uint8_t row;
  uint8_t column;
  for(row=0;row<8;row++){
    for(column=0;column<8;column++){
      matrix.drawPixel(column, row, matrix.Color(R,G, B)); 
      matrix.setBrightness(I);
      matrix.show();     
    }
  }
 
}



