/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18313
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

//#define function
#define arduino


#define UD PWM1_LoadDutyValue
#define OC PWM2_LoadDutyValue
#define RL PWM5_LoadDutyValue
#define FB PWM6_LoadDutyValue

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

#ifdef function
bool move_arm( char *num , void *motor( uint16_t ) , bool add ) ;
#endif
uint16_t to_pwm( char angle );

#define MAX 179//0 ~ 811
#define MIN 1//60 ~ 300
#define DELAY __delay_ms(20)

void main(void)
{
  int i = 0 ;
  char v1 = 100 , v2 = 85 , v3 = 83 , v4 = 115 ;
  // initialize the device
  SYSTEM_Initialize();



  // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
  // Use the following macros to:

  // Enable the Global Interrupts
  //INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  //INTERRUPT_PeripheralInterruptEnable();

  // Disable the Global Interrupts
  //INTERRUPT_GlobalInterruptDisable();

  // Disable the Peripheral Interrupts
  //INTERRUPT_PeripheralInterruptDisable();

  FB( to_pwm(v1) );
  RL( to_pwm(v2) );
  OC( to_pwm(v3) );
  UD( to_pwm(v4) );

  while (1)
  {
    // Add your application code
    if ( PIR1bits.RCIF ) {

      switch ( EUSART_Read( ) ) {
      case 'F': //FORWARD
        while ( v1 < MAX )
        {
          #ifdef function
          if ( move_arm( v1 , &FB , 1 ) )
            break;
          #endif
          #ifdef arduino
          v1 += 2 ;
          FB( to_pwm(v1) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'B': //BACK
        while ( v1 > MIN )
        {
          #ifdef function
          if ( move_arm( v1 , &FB , 0 ) )
            break;
          #endif
          #ifdef arduino
          v1 -= 2 ;
          FB( to_pwm(v1) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'R': //RIGHT
        while ( v2 > MIN )
        {
          #ifdef function
          if ( move_arm( v2 , &RL , 0 ) )
            break;
          #endif
          #ifdef arduino
          v2 -= 2 ;
          RL( to_pwm(v2) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'L': //LEFT
        while ( v2 < MAX )
        {
          #ifdef function
          if ( move_arm( v2 , &RL , 1 ) )
            break;
          #endif

          #ifdef arduino
          v2 += 2 ;
          RL( to_pwm(v2) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'O': //OPEN
        while ( v3 > MIN )
        {
          #ifdef function
          if ( move_arm( v3 , &OC , 0 ) )
            break;
          #endif
          #ifdef arduino
          v3 -= 2 ;
          OC(to_pwm(v3));
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'C': //CLOSE
        while ( v3 < MAX )
        {
          #ifdef function
          if ( move_arm( v3 , &OC , 1 ) )
            break;
          #endif
          #ifdef arduino
          v3 += 2 ;
          OC( to_pwm(v3) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'U': // UP
        while ( v4 < MAX )
        {
          #ifdef function
          if ( move_arm( v4 , &UD , 1 ) )
            break;
          #endif
          #ifdef arduino
          v4 += 2 ;
          UD( to_pwm(v4) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      case 'D': // DOWN
        while ( v4 > MIN )
        {
          #ifdef function
          if ( move_arm( v4 , &UD , 0) )
            break;
          #endif
          #ifdef arduino
          v4 -= 2 ;
          UD( to_pwm(v4) );
          if ( PIR1bits.RCIF )
            if ( EUSART_Read( ) == 'S' )
              break;
          DELAY;
          #endif
        }
        break;

      default:
        break;
      }

    }

  }
}
#ifdef function
bool move_arm( char *num , void *motor( uint16_t ) , bool add ) {
  if ( add )
    *num += 2 ;
  else
    *num -= 2 ;

  motor( to_pwm( *num ) ) ;

  if ( PIR1bits.RCIF )
    if ( EUSART_Read( ) == 'S' )
      return 1 ;
  DELAY;
  return 0 ;
}
#endif

uint16_t to_pwm( char angle ) {
  return (( angle / 180.0 ) * 240 ) + 60 ;
}


/**
 End of File
*/