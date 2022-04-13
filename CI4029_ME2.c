int up_down;
int clock_release;
int up_down_release;

void main() {
     TRISA0_bit = 1;
     TRISA1_bit = 1;
     TRISB = 0x00;
     PORTB = 0x00;

     up_down = 1;
     clock_release = 0;
     up_down_release = 0;

     while(1){

         if(RA0_bit == 0){      //Se o o botão CLOCK for pressionado.
            clock_release = 1;  //Seta o clock_release como 1.
         }
         if(RA0_bit == 1 && clock_release == 1){   //O botão foi solto?
              clock_release = 0;                   //Reseta a flag clock_release

              if (up_down == 1){                   //A flag que indica a ordem crescente é 1
                  PORTB++;                         //Incrementa o PORTB
              } else{
                  PORTB--;                         //Decrementa o PORTB
              }
         }

         if(RA1_bit == 0){         //Se o o botão UP/DOWN for pressionado.
             up_down_release = 1;  //Seta o up_down_release como 1.
         }
         if(RA1_bit == 1 && up_down_release == 1){   //O botão foi solto?
              up_down_release = 0;                   //Reseta a flag up_down_release

              //Inverte o estado da flag up_down
              if (up_down == 1){
                  up_down = 0;
              } else {
                  up_down = 1;
              }
         }
     }
}