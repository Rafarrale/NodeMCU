import time
import machine
#Instanciar variables
led = machine.Pin(16,machine.Pin.OUT)
finish = machine.Pin(5,machine.Pin.IN, machine.Pin.PULL_UP)   #Usamos Pull.UP para que no mantega el valor en alta impedancia
i = 1
termina = 1
print('Hola mundo! ejecutemos!')

def leer():
     adc = machine.ADC(0)
     res = adc.read()
     print(res)

def led_con_parpadeo_y_lectura():
     for i in range(3):
        print(i)
        i += 1
        led.high()
        time.sleep(1) # Delay for 1 second.
        led.low()
        time.sleep(1)
        leer()

def pwm_led():
     p12 = machine.Pin(12)
     pwm12 = machine.PWM(p12)
#     pwm12.freq(100)
     pwm12.duty(20)

def control_led_pwm_potenciometro():
     p12 = machine.Pin(12)
     pwm12 = machine.PWM(p12)
     adc = machine.ADC(0)
     res = adc.read()
     pwm12.duty(res)

def comprueba_estado_pulsador_digital():
     for i in range(10):
          termina = finish.value()
          print(termina)
          time.sleep(1)

if __name__ == '__main__':
#     leer()
#     pwm_led()
     led_con_parpadeo_y_lectura()
#     comprueba_estado_pulsador_digital()
#     while (termina == 1):
#          termina = finish.value()
#          control_led_pwm_potenciometro()





   














