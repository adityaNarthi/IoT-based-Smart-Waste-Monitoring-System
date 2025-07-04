# ♻️ IoT-based Smart Waste Monitoring System

A smart city project that leverages IoT and cloud services to **monitor urban waste bins in real-time**, helping optimize collection schedules, reduce overflows, and enhance sustainability.  
🏆 **Shortlisted in Top 5** at a national-level hackathon – Sep 2024.

---

## 🎯 Project Overview

This system uses an **ESP32 microcontroller** with **ultrasonic sensors** to measure the fill-level of public bins. Data is transmitted via **MQTT** to an **AWS-based backend**, where it is processed, stored, and visualized. Alerts are sent to municipal authorities when bins are full, enabling data-driven waste collection.

---

## 🛠️ Features

- 📡 Real-time bin monitoring with ESP32 and ultrasonic sensors
- ☁️ MQTT-based communication to AWS EC2
- 📊 Data storage with **AWS DynamoDB**
- 📩 Auto-alerts via **AWS SNS (SMS)** and **SES (Email)**
- 📈 Live dashboards with **AWS Grafana**
- 🏆 Shortlisted in the Top 5 projects at a national-level smart city hackathon

---

## 🖼️ Demo & Workflow

- 📽️ **Video Demonstration**: [Watch here](link-to-video)
- 🧾 **Project Presentation**: [View PPT](link-to-ppt)
- 🔁 **Workflow Overview**:

| Hardware Layer | Cloud Layer | Alert & Dashboard |
|----------------|-------------|--------------------|
| ESP32 + HC-SR04 | MQTT → AWS EC2 | SNS/SES + Grafana |
| WiFi + Battery | DynamoDB | Web Visualization |

> ![System Diagram](assets/system_architecture.png)

---

## 🧰 Tech Stack

| Component      | Tech Used                  |
|----------------|----------------------------|
| Microcontroller| ESP32                      |
| Sensors        | Ultrasonic (HC-SR04)       |
| Protocol       | MQTT                       |
| Cloud          | AWS EC2, SNS, SES, DynamoDB|
| Dashboard      | AWS Grafana                |
| Language       | C++ (ESP32), Python (AWS)  |

---

## 📂 Repository Structure

