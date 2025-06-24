<h1>Pool Chemical Analyzer System</h1>


<h2>Description</h2>
This was a simple system that would record data from my above-ground pool and display the data onto four mini OLED screens for the user to read. This device would detect the pool's temperature, pH, chlorine levels, and TDS (total dissolved solids). Each OLED screen would have three corresponding LED lights (red, yellow, and green) that would tell the user if the outputted value was a good, average, or bad value. This device would float in the pool all day, every day, and could be used at any time. The purpose of this device was that, unless you want to spend hundreds to thousands of dollars, there is no affordable device out there that can track all of these readings at once. That is why I built this.
<br/>


<h2>Sensors and Electronics Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>pH Sensor</b>
- <b>Temperature Sensor</b>
- <b>ORP (Oxidation-Reduction Potential) Sensor</b>
- <b>TDS (Total Dissolved Solids) Sensor</b>

<h2>Challenges and Solutions</h2>

- <b>One of the main problems that I dealt with was the method of detecting the chlorine levels in the water. I could not find a chlorine sensor out there that was cheap enough for my liking. Instead, I bought an ORP (Oxidation-Reduction Potential) sensor, which shows readings that correlate with how effectively the chlorine is working in the water. The one issue with the readings from the ORP sensor is that these readings could be easily affected by the pH of the pool. To fix this, I wrote code to consider the pH value when calculating the chlorine values. </b> 

<h2>Photos:</h2>

<p align="center">
Launch the utility: <br/>
<img src="" height="50%" width="50%" />
<br />
<br />
Select the disk:  <br/>
<img src="" height="50%" width="50%" />
<br />
<br />
Enter the number of passes: <br/>
<img src="" height="50%" width="50%" />
<br />
<br />
