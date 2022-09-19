
#!/bin/bash


#Download python and latex templates

#svn co https://github.com/gadepall/training/trunk/math  /sdcard/Download/math

#Test Latex Installation
#Uncomment only the following lines and comment the above line

cd /Tabassum/IDE/Assignment
pdflatex K-map.tex
xdg-open K-map.pdf
pio run
pio run -t upload



#Test Python Installation
#Uncomment only the following line

#python3 /sdcard/Download/anusha1/python1/asgn1.py
