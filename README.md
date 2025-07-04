# 🗑️ IoT-Based Smart Waste Monitoring System

**🏆 Shortlisted in the Top 5 Teams at a National-Level Hackathon (Sep 2024)**

This project focuses on smart urban waste management using an end-to-end IoT solution. Waste bins equipped with sensors and ESP32 microcontrollers send real-time data to AWS. The system monitors bin levels, triggers alerts when bins are full, and displays data trends on a dashboard—helping cities reduce operational costs and respond faster.

---

## 🔍 Overview

The system works as follows:

1. **ESP32** microcontrollers read bin levels using ultrasonic sensors.
2. Data is transmitted wirelessly via **MQTT** to an AWS-hosted backend.
3. An **EC2 instance** receives this data, processes it, and stores it in **DynamoDB**.
4. When bin levels exceed a certain threshold, **SMS and Email alerts** are sent using **AWS SNS and SES**.
5. A **Grafana dashboard** visualizes bin status and usage trends for smart monitoring.

---

## ⚙️ Technologies Used

- **Microcontroller**: ESP32
- **Sensors**: HC-SR04 (Ultrasonic)
- **Protocols**: MQTT
- **Cloud Services**: AWS EC2, DynamoDB, SNS, SES, Grafana
- **Backend**: Python
- **Visualization**: Grafana (AWS-hosted)

---



## 🚀 How It Works – Setup Summary

1. **ESP32 Hardware Setup**  
   Flash the microcontroller with code to read sensor data and connect to WiFi and MQTT broker.

2. **AWS Backend Configuration**  
   - Launch an **EC2 instance** to host a Python MQTT listener.
   - Create a **DynamoDB table** to store incoming sensor data.

3. **Notification System**  
   - Use **SNS** to send SMS alerts.
   - Set up **SES** to send emails when bin thresholds are crossed.

4. **Dashboard Monitoring**  
   - Connect the data source to **AWS Grafana**.
   - Import a dashboard layout to view bin levels and activity history.

---

## 🏁 Hackathon Achievement

- **Date**: September 2024
- **Result**: Top 5 Finalist (out of 100+)
- **Focus Areas**: Urban development, IoT, sustainability

---




## 📬 Contact

Have questions or want to collaborate?

- 📧 Email: [anarthi2004@gmail.com]
- 🔗 LinkedIn: (linkedin.com/in/aditya-narthi-2523a42a2/)

---

⭐ Star this repo if you find the project interesting or helpful!
