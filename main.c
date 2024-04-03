/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1827
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include "mcc_generated_files/mcc.h"

 #include <stdio.h>

#define T_DESEADA 26312
#define q_0 1
#define q_1 -1
#define angulo_deseado 30
#define pulso_ref 34

extern int pulses; 

int uk=0, uk_ant=0;
int error_pos;
static int error_ant=0;
float ciclo_util;
int in; 


bool flag_blink, flag_startTX;

uint16_t T=0;
uint16_t T_deseada;


//static int a = 1;

bool flag_updateT; 

//uint16_t ArregloT[50]={0}; 

uint8_t i=0,j=0; 

long vel;
void derecha(){
    OUT7_SetHigh();
    OUT2_SetLow();
}
void izquierda(){
    OUT2_SetHigh();
    OUT7_SetLow();
}

void parar(){
   OUT2_SetLow();
    OUT7_SetLow();
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
//LED1_SetHigh();
// LED2_SetLow();
    OUT7_SetLow();
    //OUT2_SetHigh();
    OUT2_SetLow();
    flag_startTX=0; 
    while (1)
    {
        //izquierda(); 
        //derecha();
        // Add your application code
        
       
            
           // if(flag_startTX){
              //  T++;
               // printf("%u\n",T);
               // flag_startTX=0;
            
         if (flag_blink){
            flag_blink=0;
           // LED1_Toggle();
           // LED2_Toggle();
            //OUT2_Toggle();
           // OUT7_Toggle();
        }
            
        
        
        if (flag_updateT)
        {
//            flag_updateT=0;
//           // printf("%u\n",T);
//            
//            ArregloT[i]=T; 
//            i++; 
//            if(i==49)
//            {
//                OUT7_SetLow();
//                OUT2_SetLow();
//                flag_startTX=1; 
//                
//                i=0; 
//            }
                   
        }
        //Calcular a qué pulso corresponde el ángulo al que deseo que esté mi motor
        //pulso_ref= 408*angulo_deseado/360;
        
        if(flag_startTX) //Cada 20 microsegundos
        {

        //Implementar mi control
                  
            //Calcular el error entre el pulso que quiero y el pulso en el que estoy
                        error_pos = pulso_ref - pulses; 
                        if(error_pos<0)
                        {
                            izquierda(); 
                        }
                        else
                        {
                            derecha(); 
                        }
            //Calcular la salida de mi controlador
                        uk = uk_ant + q_0*error_pos + q_1*error_ant;
            //Calcular a qué valor del dutycycle corresponde el voltaje que sale de mi controlador
            //La función valor absoluto no funciona, uso un if para ponerlo positivo en caso de que sea negativo
                       
                        in = (83 * uk);   
                         if(in<0)
                        {
                            in=in*(-1); 
                        }
            //Cargar mi duty cycle con ese valor
                        PWM4_LoadDutyValue(in);
            //Actualizar uk y error del pasado
                        uk_ant=uk;                         
                        error_ant =  error_pos;                       
        
            
//          calcula la velocidad a partir de el numero de interrupciones T 
//         vel=((2*314159200)/(T*(long)32));
//         printf("%u,",T);
//         printf("%ld\r\n",vel); 
//         PWM4_LoadDutyValue(1000);
//         if(i<50){
//             i++;
//         }
         flag_startTX=0;
         
//         

            
        }//end flag_stark

//    if(i>=50){
//       for (j = 0; j <= 50; j++) 
//                {
//                  printf("%u\n", j);
//                  parar();
//               } 
//       i=0;
//    }
         
   
         //     funcion corta para cambiar el valor util de pwm4 de manera acendente
         //      y desacendente
//          if(a){
//            in+=16;
//          }
//          
//           else
//            {
//                in-=16;
//            }
//            
//            if(in >= 1024)
//            {
//                a = 0;
//                in = 1023;
//            }
//            if(in < 0){
//                a = 1;
//                in = 0;
//            }
//           
//            
//           PWM4_LoadDutyValue(in);
//     
                     
//            if(T_DESEADA<T)
//            {
//                in=in+5; 
//            }
//            else
//            {
//                in=in-5; 
//            }
//            PWM4_LoadDutyValue(in);
         
    }
            
        }

   
/**
 End of File
 * */