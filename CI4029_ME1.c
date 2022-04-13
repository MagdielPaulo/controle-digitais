#define CLOCK_pin  RA0_bit
#define UPDOWN_pin RA1_bit

bit up_down;
bit clock_release, up_down_release;

void main() {
     TRISA0_bit = 1;
     TRISA1_bit = 1;
     TRISB = 0x00;
     PORTB = 0x00;

     up_down = 1;
     clock_release = 0;
     up_down_release = 0;

     while(1){

         if(!CLOCK_pin) clock_release = 1; //Se o o botão CLOCK for pressionado. Seta o clock_release como 1.
         if(CLOCK_pin && clock_release){   //O botão foi solto?
              clock_release = 0;           //Reseta a flag clock_release

              if (up_down){                //A flag que indica a ordem crescente é 1
                  PORTB++;                 //Incrementa o PORTB
              } else{
                  PORTB--;                 //Decrementa o PORTB
              }
         }

         if(!UPDOWN_pin) up_down_release = 1; //Se o o botão UP/DOWN for pressionado. Seta o up_down_release como 1.
         if(UPDOWN_pin && up_down_release){   //O botão foi solto?
              up_down_release = 0;            //Reseta a flag up_down_release
              up_down = ~up_down;             //Inverte o estado da flag up_down
         }
     }
}