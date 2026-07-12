# Jazz

Jazz is a bluetooth speaker that uses ESP32 for bluetooth connection

It focuses on minimalism and uses Audiophile grade equipments for good soundquality

### Features:

 - Compact design 
 - Capacitive Sensor to enter pairing mode
 - Toggle switch to On-Off speaker.
 - Daytone Speaker and Passive Radiator

### CAD Model:
It has 3 separate printed pieces. The Enclousure, the Speaker Holder to support driver and passive radiator, and Top mesh to cover driver.
Made in Autodesk Fusion.

### PCB:
Here's my PCB! It was made in KiCad. 

Schematic : ![Complete Jazz](Assets/Schematic.png)
PCB Footprint : ![Complete Jazz](Assets/PCB.png)

### Firmware Overview:
Currently Firmware is underdevelopment so there is some time to finished product.
This speaker uses C++ firmware and Arduino IDE for Flashing.

### Assembly Instructions :
1. Flash Firmware in XIAO ESO32
2. Solder Pairing Switch, Kill Switch, Speaker, Battery
3. Test everything works
4. Apply Epoxy layer(not neccessary though but better if we do) inside shell to prevent air from leaking
5. Glue togetther the Speaker and Passive Radiater to Speaker holder (to prevent air from leaking) along with screws
6. Screw Speaker holder and Top Mesh to Encloudure.

### BOM Table
|Name|Use|Quantity|Link|Distributer|
|----|---|--------|----|-----------|
|Passive Radiator| For Depth| [Link](https://www.daytonaudio.com/product/1552/nd65-pr-2-1-2-aluminum-cone-passive-radiator)|Dayton Audio|
|Speaker|Main Driver|1|[Link](https://www.amazon.in/Dayton-Audio-DMA45-4-Aluminum-Full-Range/dp/B07N1YW3SV?crid=3V7R0WFBODGVD&dib=eyJ2IjoiMSJ9.ZovJ2FRQs3pmwyzB_tD3JRq4LaJKzlhPqWikw9393H10BYXCIcvu9hzi35ROTbgVzwRGON-UKmSIxJZb096X-t3fNUy7ZwafTm0j-v9W8j7VAd_8-LCThV547bfVhP9NJ7Wi9YgXWHFZLfnOVMGbUS30ZCycVPFoQHI8esF8xiJo9Ei9W604bymV5dHSm5gL.1QMB5W2LyaJ6eF8SeeBaS8edQjG50gg-gWsAIbsoJMA&dib_tag=se&keywords=dayton+audio+dma45-4&nsdOptOutParam=true&qid=1783793906&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=dayton+Audio+DMA%2Caps%2C292&sr=8-1)|Amazon|
|PCB|Main-Circuit|1|-|JLCPCB|
|Battery|Power Source|1|[Link](https://robu.in/product/nova-125785-10000mah-3-7v-lipo-battery-pack/)|Robu|
|Toggle switch|On-Off|1|[Link](https://www.amazon.in/RoboComp-Center-Rocker-Toggle-Switch/dp/B0GW1SK6Y5?dib=eyJ2IjoiMSJ9.1CwHqbAUYwizY1Z1K0WZdKre8CLLDpprYbmEb_9PNTWqyjohjF5RvFQHYgcRSr029HxOQ9XFU9Yd2WoFSByQLTZC4mpo1z00oP6VspIr7XqntChIDTYswrf3dJoaJTSpmRr7esG0u7r-XJnCxbD7MD168vrldx863bm8NWvZ2WL-OKQtGgTEFOjLlDHG3WGsgi2VIhzc2M38_9MY_n1VyhJtiu9AZsDnKbQQZl6pZYEsnpHDEuILOJHanJcoKXVOJf6PUo8NBcmJ2H5TxdEh0F4194ktdUkxSr8JhkX-HH0.AAfvh377-khgNbQY7kIIHbfBj4w8bifQznZzReEkcW0&dib_tag=se&qid=1781184118&refinements=p_n_g-1003565985111%3A61707331031&s=industrial&xpid=CJ1-0rXLg6M1t&th=1)|Amazon|
