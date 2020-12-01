
## What's robosys_raspi?
This is device module for Raspberry Pi 3 to put on LED.

![イメージ](https://github.com/kentokura/robosys_raspi/blob/img/raspi.png)

## Environment
OS: Linux ubuntu 4.15.0-1038-raspi2 #40-Ubuntu SMP PREEMPT Thu Jun 6 07:34:33 UTC 2019 armv7l armv7l armv7l GNU/Linux  

## How to use
### Download:  
Please download from here on Raspberry Pi.Raspberry Pi OS is Ubuntu.

Please type this.
```
git clone https://github.com/kentokura/robosys_raspi.git
```

### Before use:

Please prepare Raspberry Pi 3, LED, Resistor and Jump wire.

- 300Ω Resistor
- LED:

  | color |  typ(V) |  IF(mA)   |
  | ---- | ---- | ---- |
  | red  | 2.0V  | 20mA |

LED and Resistor was connect between pin22(GPIO25) to pin39(GND) on Raspberry Pi 3.

Please type this.
```
make
sudo insmod myled.ko
sudo chmod 666 /dev/myled0
```


### Use:  
led power on
```
echo 1 > /dev/myled0
```
led power off
```
echo 0 > /dev/myled0
```

sushi read 🍣

note : if you read this driver, your terminal output 🍣.
```
cat /dev/myled0
```
### After use:  
remove device.
```
sudo rmmod myled
```

## License

Copyright (c) 2020 KenTokura and ryuichi Ueda.
Please see [This](https://github.com/kentokura/robosys_raspi/blob/master/LICENSE).


