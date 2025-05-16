#include    <16F628A.h>
#fuses      INTRC_IO
#fuses      NOWDT,NOBROWNOUT,PUT,MCLR,NOLVP
#fuses      NOPROTECT,NOCPD

#use        delay(clock=4M)

#use        fast_io(A)
#use        fast_io(B)

void main()
{
   long valor=19;   //Variable de 16 bits para el ciclo de trabajo de 45%
   long valor2=38;
   
   set_tris_A(0xFF);
   set_tris_B(0x00);
   
   output_A(0);
   output_B(0);
   
   while(1)
   {
      if(input(PIN_A0==0))
      {
         set_pwm1_duty(valor);
         
         setup_timer_2(T2_DIV_BY_16,9,4); //Ciclo de trabajo de 45%, pr2=9,osc=4MHz, Tpwm=167us
         
         setup_ccp1(CCP_PWM);
      }
      else
      {
         set_pwm1_duty(valor2);
      
         setup_timer_2(T2_DIV_BY_16,9,4); //Ciclo de trabajo de 90%, pr2=9,osc=4MHz, Tpwm=167us
         
         setup_ccp1(CCP_PWM);
      }
   }
}
