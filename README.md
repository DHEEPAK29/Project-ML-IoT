#  	Real-time-Proximity-AND-health-monitoring-cum-alert-system-with-ML-Enabled-Predicting-Model<br>
[![Project](![image](https://user-images.githubusercontent.com/83426515/166098441-87b5ac4d-e396-41d4-9e39-90164a697370.png))](https://youtu.be/M4vS_2_sTk4)<br>
 YouTube link of a Project with a Detailed demonstration - [Link](https://youtu.be/M4vS_2_sTk4) <br>

# Implementation of the project in detail <br>
- [x] The ‘README.md’ file  -  [README.md](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/blob/main/README.md) <br>
- [x] Introduction - [Paper](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/blob/main/Introduction.pdf) <br>
- [x] Modules implemented and their explanation - [Modules](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/tree/main/Modules%20implemented) <br>
- [x] Screenshots of the project - [Work Flow](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/tree/main/Screenshots_of_the_project)<br>
- [x] Step-by-step installation guide - [Installation Guide](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/blob/main/Step-by-step%20installation%20guide.png)<br>
- [x] YouTube video link - [Youtube Link For Project Demonstration](https://youtu.be/M4vS_2_sTk4)<br>

- [x] Description	<br> To design a prototype with an ML-Enabled application to monitor Kids, Senior citizens, especially differently-abled individuals, or anyone who needs supervision in such a way that it can alarm the concerned person and use the acquisition of data for further predicting the condition of similar patients.<br>
- [x]  Hardware used	: 
 ESP32(Wi-Fi module), DHT11(Temperature and humidity sensor), MAX30102(SpO2 and Heart Rate monitor), ADXL345(Accelerometer), HC42(Bluetooth Low-Energy).<br>
- [x]  Back end	 : MySQL.<br>
- [x]  Deep Network used	: VGG-16.<br>
- [x]  Software used	:Android studio (Flutter).<br>
- [x]  Tool		: Arduino IDE 1.8.15.<br><br>

 
Implementation of the project in detail in the following segments:
<p align="center">
  <img src="https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/blob/main/Step-by-step%20installation%20guide.png" width="350" title="hover text">
</p>

![](https://github.com/DHEEPAK29/HackCoVIT2022_G-DHEEPAK-G-DHEEPAK-G-/blob/main/Gif.gif)

See also [Youtube Link For Project Demonstration](https://youtu.be/M4vS_2_sTk4)

# SYNOPSIS
- [x] ABSTRACT<br>
- [x] INTRODUCTION<br>
- [x] RESEARCH AREA<br>
- [x] MOTIVATION AND SIGNIFICANCE OF WORK<br>
- [x] CATEGORIZATION OF CASES<br>
- [x] PROTOTYPE DESIGN<br>
- [x] PARAMETER BASED ALERT CASES <br>
- [x] PROTOTYPE DEVELOPMENT <br>
- [x] DEEP LEARNING PREDICTION <br>
- [x] CONCLUSIONS<br>
- [x] REFERENCES<br>

## ABSTRACT
The main objective of this project is to help Doctors (or) Supervisors remotely monitor the Condition of the ambiance, Health condition, and the proximity from the set location of a Patient (or) Person under observation. This project imbibes the concept of the Internet of Things (IoT) and so the data is accessible seamlessly even if the supervisor is remote. Using range detection techniques and health parameters, Manipulations are done in the backend such that the alerts are notified based on set conditions to the respective person in case of emergency, we can conclusively predict the condition of a Patient (or) Person under observation remotely and accurately. Further, the data received from a patient is integrated into the database for analytics in Machine Learning (ML) to predict the reaction of another patient who suffers from the same disease or condition in the future. In addition, the product is feasible to be designed as a Handy and User-Friendly prototype, Cost-Efficient model, Less power-consuming mechanism, and Alterable Design.

## I.	INTRODUCTION
In the health sector, Because of its direct impact on life, Doctors need to follow a lot of precautions, thereby abiding by safety measures is obvious. Taking this as motivation, Frequent problems that Hospitals face is during the observation of a patient (or) monitoring the health status of the patients regularly. The possibilities are resolved into three cases and the solution is envisioned as a smart yet affordable one. The plan is to develop a technology-based device for Kids, Senior citizens, especially differently-abled individuals, or anyone who needs supervision in such a way that it can alarm the concerned person in case the person who needs supervision is crossing a specified boundary or his/her health condition turns adverse. The solution is centered around the field of Internet of Technologies (IoT) and Machine Learning (ML) and the scope is viable in the domain of Smart Home, Security and Authentication, Automation, Data Science and Machine Learning, Data analytics. 

## II.	  RESEARCH AREA
The research area of this project concerns is healthcare and smart automation. The domain of technologies employed for this project is the Internet of things (IoT) and Deep Learning to facilitate the user with a sophisticated model/Prototype, accurate prediction for their respective application. The possibilities/ Problematic factors are resolved into three cases and the solution is envisioned as a smart yet affordable model which hospitals and people opt to employ for their wards or in their homes. The key idea is to develop a technology-based solution for Kids, Senior citizens, especially differently-abled individuals, or anyone who needs supervision.

## III.	MOTIVATION AND SIGNIFICANCE OF WORK
The motivations were observed from multiple difficulties which are being faced by hospitals on daily basis. When planning, the cases have been resolved for two different applications. They are, 

A) Hospital Application 
i. In recent years, we have seen a lot of patients missing from hospitals when they are in treatment due to the misconception of COVID-19.
ii. Special and constant care is always needed for mentally unstable patients as they are prone to be absconded from their wards.
iii. In some hospitals due to lack of security, we see newborn babies being kidnapped.
iv. Due to insufficient Doctors, nurses or workers, there is a compromise in timely check for each patient which further brings a big threat to the lives of patients.
B)	 Home Applications
i.	 Aged people definitely need strict supervision.
ii. Monitoring Babies while WFH became a tedious task to many housewives in recent days.

## IV.	CATEGORIZATION OF CASES
By Research, the patients are categorized into two types. (A) Immobile patients, (B) Mobile and mentally unstable patients. The mandatory services for both (A)and (B) patients are SpO2 cum Heart rate monitoring, Accelerometer Module for motion capture, Temperature, and Humidity Sensor for monitoring Room Condition. The purpose of Bluetooth exclusively lies in keeping track of limits set to type (B) users as there are possibilities for them to be missing.
## V.	PROTOTYPE DESIGN
The prototype design structure is split into three parts. The prototype (Raspberry pi/ ESP32) with the patient under observation(i), Prototype fixed by the Doctor within the boundary (in proximity to the patient) (ii), A monitoring device (i.e., PC/iOS/Android Application) (iii). SpO2 sensor cum Heart rate sensor and Bluetooth are interfaced with (i)module, Accelerometer Module for motion capture, Temperature, and Humidity Sensor for monitoring Room Condition and Bluetooth are interfaced with (ii)module. Both the split prototypes are connected to the user Internet and data is received simultaneously in the USER END (iii). The dimension of working is as a whole receiving data given by the sensors and is displayed for alarming the doctors and for boundary monitoring, we use Bluetooth signal as a key by sensing the distance between the Bluetooth modules of the prototype (i) and (ii).

## VI.	 PARAMETER BASED ALERT CASES 
The alert cases that the supervisor receives are when the person under supervision/ Patient 
i) Moves above the set distance. 
ii) SpO2 /Heart Rate/Body Temperature is undesirable. 
iii): Room Temperature /Room Humidity is undesirable. iv)Motion (For necessary Observations).

## VII.	PROTOTYPE DEVELOPMENT <br>
 ![image](https://user-images.githubusercontent.com/83426515/165928089-c33d05c4-57f6-4751-ac8a-806516597e0c.png)<br>

Fig.1 Prototype placed by supervisor<br>
  ![image](https://user-images.githubusercontent.com/83426515/165928102-9aed7824-381d-4ef1-a0c5-ba690c45cf5b.png)<br>

Fig.2 Prototype with patient<br>
## VIII.	DEEP LEARNING PREDICTION <br>
 ![image](https://user-images.githubusercontent.com/83426515/165928122-6da449db-07fb-4572-b6cb-e41e18ab05d1.png)<br>

Fig.3 Patient Database<br>
The data which are collected while monitoring the patient is stored in a database (SQL/ Firebase) and these data are further processed with a Machine learning model to predict the condition of another patient with similar ailments and provide the result of what would be the survival rate, the health condition in the process of undergoing treatment, and possible movement of the person under test.
## IX.	CONCLUSIONS
Thus, A technology-based solution for Kids, Senior citizens, especially differently-abled individuals, or anyone who needs supervision is developed in such a way that it can alarm the concerned person in case the person who needs supervision is crossing a specified boundary or his/her health condition turns adverse. The solution is centered around the field of Internet of Technologies (IoT) and Deep Learning (DL), and the scope is viable in the domain of Smart Home, Security and Authentication, Automation, Data Science and Machine Learning, Data analytics.

## X.	REFERENCES
[1]	Hu, F., Xie, D., & Shen, S. On the application of the internet of things in the field of medical and health care. In Green Computing and Communications (GreenCom), 2013 IEEE and Internet of Things (iThings/CPSCom), IEEE International Conference on and IEEE Cyber, Physical and Social Computing (pp. 2053-2058). IEEE, 2013.<br>
[2]	Who, J., & Consultation, F. E. Diet, nutrition and the prevention of chronic diseases. World Health Organ Tech Rep Ser, 916(i-viii),2003.<br>
[3]	Swan, M. Sensor mania! the internet of things, wearable computing, objective metrics, and the quantified self-2.0. Journal of Sensor and Actuator Networks, 1(3), 217-253, 2012<br>
[4]	Strollo, S. E., Caserotti, P., Ward, R. E., Glynn, N. W., Goodpaster, B. H., & Strotmeyer, E. S. A review of the relationship between leg power and selected chronic disease in older adults. The journal of nutrition, health & aging, 19(2), 240-248, 2015.<br>
[5]	Gómez, J., Huete, J. F., Hoyos, O., Perez, L., & Grigori, D. Interaction System based on Internet of Things as Support for Education. Procedia Computer Science, 21, 132-139, 2013<br>


